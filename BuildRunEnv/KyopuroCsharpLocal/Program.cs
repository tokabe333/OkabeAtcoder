using System;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using static System.Console;
using static System.Math;
using static Util;
using System.Runtime.CompilerServices;
using System.Reflection;

/// <summary>
/// 通常のセグメント木(範囲検索、1つ更新をlogN) <br/>
/// </summary>
class SegmentTreeGeneric<T, F, T_op> where T : IComparable, IFormattable, IConvertible, IComparable<T>, IEquatable<T>
									 where F : IComparable, IFormattable, IConvertible, IComparable<T>, IEquatable<T>
									 where T_op : struct, ILazySegmentTreeOperator<T, F> {
	/// 一番下の葉の数 (2のべき乗になってるはず)
	public int LeafNum { get; set; }

	/// <summary>ノード全体の要素数</summary>
	public int Count { get => this.Node.Length; }

	/// 実際に木を構築するノード
	public T[] Node { get; set; }

	/// <summary>
	/// 遅延評価をまとめた配列<br/>
	/// 更新時はここをいじる
	/// </summary>
	public F[] Lazy { get; set; }


	/// 作用素 (TとTに対する演算結果Tを返す min, max, sumなど)
	/// 単位元もここに含まれている
	private readonly T_op Operator = default(T_op);


	/// 元配列を渡してセグメントツリーの作成
	/// 初期値はminやmaxなどで変わると思うので与える(デフォルト=0のはず)
	public SegmentTreeGeneric(T[] arr) {
		// // 作用素を保存
		// this.Operator = op;

		// ノード数を　2^⌈log2(N)⌉　にする
		this.LeafNum = 1;
		while (this.LeafNum < arr.Length) this.LeafNum <<= 1;

		// 葉の初期化
		this.Node = new T[this.LeafNum * 2 - 1];
		for (int i = 0; i < this.Count; ++i) this.Node[i] = this.Operator.Identity;
		for (int i = 0; i < arr.Length; ++i) this.Node[this.LeafNum - 1 + i] = arr[i];
		// write("葉の初期化 : ");
		// printlist(this.Node);

		// 遅延配列の初期化
		this.Lazy = new F[this.LeafNum * 2 - 1];
		for (int i = 0; i < this.Count; ++i) this.Lazy[i] = this.Operator.FIdentity;

		// 親ノードの値を決めていく
		for (int i = this.LeafNum - 2; i >= 0; --i) {
			// 左右と比較
			this.Node[i] = this.Operator.Operate(this.Node[2 * i + 1], this.Node[2 * i + 2]);
		}

		// write("親の初期化 : ");
		// printlist(this.Node);
	} // end of constructor

	/// <summary>
	/// k番目のノードを遅延評価する(ACLではApply) <br/>
	/// 着目ノードkに対して Node[k] = f(Node[k]) <br/>
	/// 着目ノードを更新したら、1つしたの子に伝播 <br/>
	/// </summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void Evaluate(int k, int l, int r) {
		// 遅延配列が空の時は更新内容がない
		if (EqualityComparer<F>.Default.Equals(this.Lazy[k], this.Operator.FIdentity)) return;

		// 注目ノードに遅延評価の写像を作用させる
		this.Node[k] = this.Operator.Mapping(this.Lazy[k], this.Node[k]);

		// 子を持っているなら(最下段の葉で無いなら)
		if (r - l > 1) {
			// composittionで遅延評価の写像を子に合成する
			this.Lazy[2 * k + 1] = this.Operator.Composition(this.Lazy[k], this.Lazy[2 * k + 1]);
			this.Lazy[2 * k + 2] = this.Operator.Composition(this.Lazy[k], this.Lazy[2 * k + 2]);
		}

		// 伝播が終わったので自ノードの遅延評価を単位元に戻す
		this.Lazy[k] = this.Operator.FIdentity;
	} // end of method



	/// <summary>
	/// [l, r)の範囲を更新する
	/// [l, r) は求めたい半開区間
	/// x は作用させたい値
	///</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void Update(int l, int r, F x) {
		this.Update(l, r, 0, 0, this.LeafNum, x);
	} // end of Method

	/// <summary>
	/// [l, r)の範囲を更新する
	/// [l, r) は求めたい半開区間
	/// k は現在のノード番号
	/// [a, b) はkに対応する半開区間
	/// T x は更新したい値 min,maxならxと比較, addならxを足す
	///</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void Update(int l, int r, int k, int a, int b, F x) {
		// 着目ノードを評価する
		this.Evaluate(k, a, b);

		// 現在の対応ノード区間が求めたい区間に含まれないときは更新なし
		if (r <= a || b <= l) return;

		// 現在の対応ノード区間が求めたい区間に完全に含まれるとき
		// → 遅延配列を評価
		if (l <= a && b <= r) {
			this.Lazy[k] = this.Operator.Composition(x, this.Lazy[k]);
			this.Evaluate(k, a, b);
		}

		// そうでないなら左右の子のノードを再帰的に計算
		// → 計算済みの値をもらって自信を更新
		else {
			int m = (a + b) / 2;
			this.Update(l, r, k * 2 + 1, a, m, x);
			this.Update(l, r, k * 2 + 2, m, b, x);
			this.Node[k] = this.Operator.Operate(this.Node[2 * k + 1], this.Node[2 * k + 2]);
		}
	} // end of method



	/// [l, r) の区間◯◯値を求める(求まる値はOperatorで指定されてる)
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public T Query(int l, int r) {
		return this.Query(l, r, 0, 0, this.LeafNum);
	} // end of method

	/// [l, r) は求めたい半開区間
	/// k は現在のノード番号
	/// [a, b) はkに対応する半開区間
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private T Query(int l, int r, int k, int a, int b) {
		// 現在の対応ノード区間が求めたい区間に含まれないとき
		// → 単位元を返す
		if (r <= a || b <= l) return this.Operator.Identity;

		// 着目ノードを評価する
		this.Evaluate(k, a, b);

		// 現在の対応ノード区間が求めたい区間に完全に含まれるとき
		// → 現在のノードの値を返す
		if (l <= a && b <= r) return this.Node[k];

		// 左半分と右半分で見る
		int m = (a + b) / 2;
		T leftValue = Query(l, r, k * 2 + 1, a, m);
		T rightValue = Query(l, r, k * 2 + 2, m, b);
		return this.Operator.Operate(leftValue, rightValue);
	} // end of method
} // end of class

/// <summary>
/// セグメント木の要素となるモノイド <br/>
/// 結合律 : Tの任意の元 a,b,c に対して (a・b)・c = a・(b・c) <br/>
/// 単位元 : Tの元 e が存在し、Tの任意の元 a に対して e・a = a・e = a <br/>
/// </summary>
/// <typeparam name="T">データの型</typeparam>
/// <typeparam name="F">写像の型</typeparam>
interface ILazySegmentTreeOperator<T, F> {
	/// <summary>
	/// 単位元 <br />
	/// minならばinf, maxならば-inf, sumならば0 <br />
	/// </summary>
	T Identity { get; }

	/// <summary>
	/// Mapping(<paramref name="FIdentity"/>, x) = x を満たす恒等写像。
	/// </summary>
	F FIdentity { get; }

	/// Tの元 x,y の演算を定義する
	/// min, max, sum などはモノイド
	T Operate(T x, T y);

	/// <summary>
	/// 写像　<paramref name="f"/> を <paramref name="x"/> に作用させる関数。
	/// </summary>
	T Mapping(F f, T x);

	/// <summary>
	/// 写像　<paramref name="nf"/> を既存の写像 <paramref name="cf"/> に対して合成した写像 <paramref name="nf"/>∘<paramref name="cf"/>。
	/// </summary>
	F Composition(F nf, F cf);
} // end of interface

class Kyopuro {
	public static void Main() {
		preprocess();
		var kyopuro = new Kyopuro();
		kyopuro.Solve();
		finalprocess();
	} // end of func

	static readonly long linf = (1l << 31) - 1;

	// モノイドを定義 区間最大値、範囲更新
	struct op : ILazySegmentTreeOperator<long, long> {
		public long Identity { get => linf; }
		public long FIdentity { get => linf; }
		public long Operate(long a, long b) => Min(a, b);
		public long Mapping(long f, long x) => f;
		public long Composition(long f, long g) => f;
	}

	public void Solve() {
		// https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_F&lang=ja
		var (n, q) = readintt2();
		var segtree = new SegmentTreeGeneric<long, long, op>(makearr(n, linf));

		for (int i = 0; i < q; ++i) {
			var s = ReadLine().Split(' ');
			if (s[0] == "0") {
				int l = int.Parse(s[1]);
				int r = int.Parse(s[2]) + 1;
				long x = long.Parse(s[3]);
				segtree.Update(l, r, x);
			} else {
				int l = int.Parse(s[1]);
				int r = int.Parse(s[2]) + 1;
				WriteLine(segtree.Query(l, r));
			}
		}


	} // end of func
} // end of class



public class Util {

	/// 読み込んだint2つをタプルで返す(分解代入用)
	public static (int, int) readintt2() {
		var arr = ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
		return (arr[0], arr[1]);
	}

	/// 出力のflush削除
	public static void preprocess() {
		var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
		System.Console.SetOut(sw);
	} // end of func

	/// 出力をflush
	public static void finalprocess() {
		System.Console.Out.Flush();
	} // end of func

	/// 任意の要素数・初期値の配列を作って初期化する
	public static T[] makearr<T>(int num, T value) {
		var arr = new T[num];
		for (int i = 0; i < num; ++i) arr[i] = value;
		return arr;
	} // end of func
} // end of func
