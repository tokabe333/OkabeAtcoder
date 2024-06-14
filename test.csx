#pragma warning disable

using System;
using System.IO;
using System.Linq;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using System.Text.RegularExpressions;
using static System.Console;
using static System.Math;
using static System.ComponentModel.TypeDescriptor;



/// <summary>AVL木</summary>
public class AVLTree<T> : IEnumerable<T> where T : IComparable<T> {
	/// <summary>AVL木を構成するノード1個分</summary>
	public class Node {
		public T key { get; set; }
		public Node left { get; set; }
		public Node right { get; set; }
		public int height { get; set; }
		public int count { get; set; }

		public Node(T key) {
			this.key = key;
			this.height = 1;
			this.count = 1;
		} // end of constructor
	} // end of class

	/// <symmary>木の根、ここから全ノードを辿っていく</summary>
	public Node root;

	public AVLTree() { }

	public AVLTree(T[] array) {
		for (int i = 0; i < array.Length; ++i) this.Insert(array[i]);
	} // end of constructor

	public AVLTree(List<T> list) {
		foreach (T value in list) this.Insert(value);
	} // end of constructor

	// -------------------------------- 挿入 --------------------------------

	/// <summary>ノード挿入(公開用、外部からはこれを呼ぶ)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void Insert(T key) => root = this.Insert(root, key);

	/// <summary>ノード挿入処理、回転した結果を今の注目ノードに置き換える</summary>
	private Node Insert(Node node, T key) {
		if (node == null) return new Node(key);

		int compare = key.CompareTo(node.key);
		// 注目ノードより小さいので左の子に挿入
		if (compare < 0) node.left = this.Insert(node.left, key);

		// 注目ノードより大きいので右の子に挿入
		else if (compare > 0) node.right = this.Insert(node.right, key);

		// 注目ノードと同じ(すでにkeyが含まれている)ので個数をカウント
		else node.count += 1;

		// 左右の個の深い方+1が現在のノードの高さ
		node.height = 1 + Max(this.GetHeight(node.left), this.GetHeight(node.right));

		// 高さを揃える
		return this.Balance(node);
	} // end of method

	// -------------------------------- 削除 --------------------------------

	/// <summary>ノード削除(公開用、外部からはこれを呼ぶ)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void Remove(T key) => root = this.Remove(root, key);

	/// <summary>ノード削除処理、削除した結果を今の注目ノードに置き換える</summary>
	private Node Remove(Node node, T key) {
		if (node == null) return null;

		int compare = key.CompareTo(node.key);
		// 注目ノードより小さいので削除は左に流す
		if (compare < 0) node.left = this.Remove(node.left, key);

		// 注目ノードより大きいので削除は右に流す
		else if (compare > 0) node.right = this.Remove(node.right, key);

		// 注目ノードが削除対象
		else {
			// 値が重複しているので個数を減らして終わり
			if (node.count > 1) {
				node.count -= 1;
				return node;
			}
			// 値が1つなのでノードを削除する
			// 片方または両方の子がない場合は、子で置き換える(子ノードが高々1子なので)
			if (node.left == null || node.right == null) {
				var tmp = node.left != null ? node.left : node.right;
				// 両方なければ自身を削除、片方あればそれで置き換える
				return tmp;
			}
			// 両方の子がある場合は、右部分木から最小値のノードを探して置き換える
			else {
				var minRight = this.FindMin(node.right);
				node.key = minRight.key;
				node.count = minRight.count;
				node.right = this.Remove(node.right, minRight.key);
			}
		}

		// 高さを揃える
		node.height = 1 + Max(this.GetHeight(node.left), this.GetHeight(node.right));
		return this.Balance(node);
	} // end of method

	// -------------------------------- 検索 --------------------------------

	/// <summary>keyが存在するか</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public bool Contains(T key) => this.Contains(this.root, key);

	/// <summary>再帰的に検索対象を探す</summary>
	private bool Contains(Node node, T key) {
		if (node == null) return false;

		int compare = key.CompareTo(node.key);
		if (compare == 0) return true;
		else if (compare < 0) return this.Contains(node.left, key);
		else return this.Contains(node.right, key);
	} // end of method

	// -------------------------------- LowerBound --------------------------------

	/// <summary>key以上の最小値を返す(存在しなければエラー)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public T LowerBound(T key) {
		T result = default(T);
		bool found = this.LowerBound(this.root, key, ref result);
		if (found) return result;
		else throw new InvalidOperationException($"{key}以上の値が存在しません");
	} // end of method

	/// <summary>key以上の最小値を返す(存在しなければdefault)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public T LowerBound(T key, out bool found) {
		T result = default(T);
		found = this.LowerBound(this.root, key, ref result);
		return result;
	} // end of method

	/// <summary>LowerBoundを実装する</summary>
	private bool LowerBound(Node node, T key, ref T result) {
		if (node == null) return false;
		int compare = node.key.CompareTo(key);
		// 現在のノードのkeyが探索対象以上の値
		if (0 <= compare) {
			// 現在のノードか、左を見ると必ず存在する
			result = node.key;
			bool foundInLeft = this.LowerBound(node.left, key, ref result);
			return true;
		}
		// 現在のノードのkeyが探索対象未満の値
		else {
			// 右を見ると存在するかもしれない
			return this.LowerBound(node.right, key, ref result);
		}
	} // end of method

	// -------------------------------- UpperBound --------------------------------

	/// <summary>key超過の最小値を探す(存在しなければエラー)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public T UpperBound(T key) {
		T result = default(T);
		bool found = this.UpperBound(this.root, key, ref result);
		if (found) return result;
		else throw new InvalidOperationException($"{key}超過の値が存在しません");
	} // end of method

	/// <summary>key超過の最小値を探す(存在しなければdefault)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public T UpperBound(T key, out bool found) {
		T result = default(T);
		found = this.UpperBound(this.root, key, ref result);
		return result;
	} // end of method

	/// <summary>UpperBoundを実装する</summary>
	private bool UpperBound(Node node, T key, ref T result) {
		if (node == null) return false;

		int compare = node.key.CompareTo(key);
		// 現在のノードのkeyが探索対象超過の値
		if (0 < compare) {
			// 現在のノードか、左を見ると必ず存在する
			result = node.key;
			bool foundInLeft = this.UpperBound(node.left, key, ref result);
			return true;
		}
		// 現在のノードのkeyが探索対象以下の値
		else {
			// 右を見ると存在するかもしれない
			return this.UpperBound(node.right, key, ref result);
		}
	} // end of method

	// -------------------------------- FindLessThanMax --------------------------------

	/// <summary>key未満の最大要素を返す(存在しなければエラー)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public T FindLessThanMax(T key) {
		T result = default(T);
		bool found = this.FindLessThanMax(this.root, key, ref result);
		if (found) return result;
		else throw new InvalidOperationException($"{key}より小さい要素が存在しません");
	} // end of method

	/// <summary>key未満の最大要素を返す(存在しなければdefault)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public T FindLessThanMax(T key, out bool found) {
		T result = default(T);
		found = this.FindLessThanMax(this.root, key, ref result);
		return result;
	} // end of method

	/// <summary>key未満の最大要素を探索する</summary>
	private bool FindLessThanMax(Node node, T key, ref T result) {
		if (node == null) return false;

		int compare = node.key.CompareTo(key);
		// ノードがkey以上の場合は左側を探す
		if (0 <= compare) return this.FindLessThanMax(node.left, key, ref result);

		// ノードがX未満の場合は現在のノード or 右のノードが対象
		else {
			result = node.key;
			bool foundInRight = this.FindLessThanMax(node.right, key, ref result);
			// 右の部分木があってもなくても答えは見つかっているはず
			return true;
		}
	} // end of method

	// -------------------------------- 表示 --------------------------------

	/// <summary>中身表示用(公開用、外部からはこれを呼ぶ)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void PrintTree() => this.PrintTree(this.root, "", true);

	/// <summary>整形して中身を表示する</summary>
	private void PrintTree(Node node, String indent, bool last) {
		if (node == null) return;
		Console.WriteLine($"{indent}+- {node.key} (Count: {node.count})");
		indent += last ? "   " : "|  ";

		this.PrintTree(node.left, indent, false);
		this.PrintTree(node.right, indent, true);
	} // end of method

	/// <summary>通りがけ順、中間順、inorder tree walk で表示 (左・中・右)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void PrintTreeInOrder() {
		this.PrintTreeInOrder(this.root);
		Console.WriteLine();
	} // end of method

	/// <summary>通りがけ順、中間順、inorder tree walk で表示 (左・中・右)</summary>
	private void PrintTreeInOrder(Node node) {
		if (node == null) return;

		// 左、中、右
		this.PrintTreeInOrder(node.left);
		for (int i = 0; i < node.count; ++i) Console.Write(node.key + " ");
		this.PrintTreeInOrder(node.right);
	} // end of method

	/// <summary>行きがけ順、先行順、preorder tree walk で表示 (中・左・右)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void PrintTreePreOrder() {
		this.PrintTreePreOrder(this.root);
		Console.WriteLine();
	} // end of method

	/// <summary>行きがけ順、先行順、preorder tree walk で表示 (中・左・右)</summary>
	private void PrintTreePreOrder(Node node) {
		if (node == null) return;

		// 中、左、右		
		for (int i = 0; i < node.count; ++i) Console.Write(node.key + " ");
		this.PrintTreePreOrder(node.left);
		this.PrintTreePreOrder(node.right);
	} // end of method

	// -------------------------------- 内部処理用 (Util) --------------------------------

	/// <summary>ノードの高さを取得</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private int GetHeight(Node node) => node != null ? node.height : 0;

	/// <summary>バランスファクタ(左右の高さの差)を取得、nullなら0</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private int GetBalance(Node node) => node != null ? this.GetHeight(node.left) - this.GetHeight(node.right) : 0;

	/// <summary>指定されたノード以下の部分木から最小値のノードを返す
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private Node FindMin(Node node) {
		while (node.left != null) node = node.left;
		return node;
	} // end of method

	/// <summary>左回転</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private Node RotateLeft(Node x) {
		// > この形が     (上がx, 右がy, 下がt2)
		// < この形になる (上がy, 左がx, 下がt2)
		Node y = x.right;
		Node t2 = y.left;

		y.left = x;
		x.right = t2;

		x.height = Max(this.GetHeight(x.left), this.GetHeight(x.right)) + 1;
		y.height = Max(this.GetHeight(y.left), this.GetHeight(y.right)) + 1;

		return y;
	} // end of method

	/// <summary>右回転</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private Node RotateRight(Node y) {
		// < この形が     (上がy, 左がx, 下がt2)
		// > この形になる (上がx, 右がy, 下がt2)
		Node x = y.left;
		Node t2 = x.right;

		x.right = y;
		y.left = t2;

		y.height = Max(this.GetHeight(y.left), this.GetHeight(y.right)) + 1;
		x.height = Max(this.GetHeight(x.left), this.GetHeight(x.right)) + 1;

		return x;
	} // end of method

	/// <summary>木のバランスを取る</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private Node Balance(Node node) {
		// 左右差を取得
		int balance = this.GetBalance(node);

		// 左の子の方が大きい (1, 0, -1)ならば偏りがないので 1超過
		if (balance > 1) {
			// 左の子の右の子が大きい場合 < この形
			// L-R回転になるので先にL回転
			if (this.GetBalance(node.left) < 0) node.left = this.RotateLeft(node.left);
			return this.RotateRight(node);
		}

		// 右の子の方が大きい (1, 0, -1)ならば偏りがないので -1未満
		if (balance < -1) {
			// 右の子の左の子が大きい場合 > この形
			// R-L回転になるので先にR回転
			if (this.GetBalance(node.right) > 0) node.right = this.RotateRight(node.right);
			return this.RotateLeft(node);
		}

		return node;
	} // end of method

	/// <summary>foreachをサポート</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public IEnumerator<T> GetEnumerator() => this.InOrderTraversal(this.root).GetEnumerator();


	/// <summary>foreachをサポート</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	IEnumerator IEnumerable.GetEnumerator() => this.GetEnumerator();

	/// <summary>foreachを実装</summary>
	private IEnumerable<T> InOrderTraversal(Node node) {
		if (node == null) yield break;
		// 通りがけ順なので左から
		foreach (var num in this.InOrderTraversal(node.left)) yield return num;

		// node
		for (int i = 0; i < node.count; ++i) yield return node.key;

		// right
		foreach (var num in this.InOrderTraversal(node.right)) yield return num;
	} // end of method
} // end of class




/// <summary>
/// 遅延評価セグメント木 <br/>
/// 区間検索、区間更新がO(logN) <br/>
/// </summary>
class LazySegmentTree<T, F, T_op>
								// where T : IComparable, IFormattable, IConvertible, IComparable<T>, IEquatable<T>
								// where F : IComparable, IFormattable, IConvertible, IComparable<T>, IEquatable<T>
								where T_op : struct, ILazySegmentTreeOperator<T, F> {
	/// <summary>一番下の葉の数 (2のべき乗になってるはず)</summary>
	public int LeafNum { get; set; }

	/// <summary>ノード全体の要素数</summary>
	public int Count { get => this.Node.Length; }

	/// <summary実際に木を構築するノード</summary>
	public T[] Node { get; set; }

	/// <summary>
	/// 遅延評価をまとめた配列 <br/>
	/// 更新時はここをいじる <br/>
	/// </summary>
	public F[] Lazy { get; set; }

	/// <summary>
	/// 作用素 (TとTに対する演算結果Tを返す min, max, sumなど) <br/>
	/// 単位元、恒等写像、mapping, compositionがまとまっている <br/>
	/// </summary>
	private readonly T_op Operator = default(T_op);

	/// <summary>
	/// 元配列を渡してセグメントツリーの作成 <br/>
	/// それ以外はOperatorに定義  <br/>
	/// </summary>
	public LazySegmentTree(T[] arr) {
		// ノード数を　2^⌈log2(N)⌉　にする
		this.LeafNum = 1;
		while (this.LeafNum < arr.Length) this.LeafNum <<= 1;

		// 葉の初期化
		this.Node = new T[this.LeafNum * 2 - 1];
		for (int i = 0; i < this.Count; ++i) this.Node[i] = this.Operator.Identity;
		for (int i = 0; i < arr.Length; ++i) this.Node[this.LeafNum - 1 + i] = arr[i];

		// 遅延配列の初期化
		this.Lazy = new F[this.LeafNum * 2 - 1];
		for (int i = 0; i < this.Count; ++i) this.Lazy[i] = this.Operator.FIdentity;

		// 親ノードの値を決めていく
		for (int i = this.LeafNum - 2; i >= 0; --i) {
			// 左右と比較
			this.Node[i] = this.Operator.Operate(this.Node[2 * i + 1], this.Node[2 * i + 2]);
		}

	} // end of constructor

	/// <summary>
	/// k番目のノードを遅延評価する(ACLではApply) <br/>
	/// 着目ノードkに対して Node[k] = f(Node[k]) <br/>
	/// 着目ノードを更新したら、1つしたの子に伝播 <br/>
	/// </summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void Evaluate(int k, int l, int r) {
		// 遅延配列が恒等写像の時は更新内容がない
		if (EqualityComparer<F>.Default.Equals(this.Lazy[k], this.Operator.FIdentity)) return;

		// 注目ノードに遅延評価の写像を作用させる
		this.Node[k] = this.Operator.Mapping(this.Lazy[k], this.Node[k]);

		// 子を持っているなら(最下段の葉で無いなら)
		if (r - l > 1) {
			// composittionで遅延評価の写像を子に合成する
			this.Lazy[2 * k + 1] = this.Operator.Composition(this.Lazy[k], this.Lazy[2 * k + 1]);
			this.Lazy[2 * k + 2] = this.Operator.Composition(this.Lazy[k], this.Lazy[2 * k + 2]);
		}

		// 伝播が終わったので自ノードの遅延評価を恒等写像に戻す
		this.Lazy[k] = this.Operator.FIdentity;
	} // end of method



	/// <summary>
	/// [l, r)の範囲を更新する <br/>
	/// x は更新に使用する写像 min,maxならxと比較、addならxを足す <br/>
	///</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void Update(int l, int r, F x) {
		this.Update(l, r, 0, 0, this.LeafNum, x);
	} // end of Method

	/// <summary>
	/// [l, r)の範囲を更新する
	/// k は現在のノード番号 <br/>
	/// [a, b) はkが対応する半開区間 <br/>	
	/// x は更新に使用する写像 min,maxならxと比較、addならxを足す <br/>
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
		// → 計算済みの値をもらって自身を更新
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

	/// [l, r) は求めたい半開区間 <br/>
	/// k は現在のノード番号 <br/>
	/// [a, b) はkに対応する半開区間 <br/>
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
/// T → データの型 <br/>
/// F → 写像の型 <br/>
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

// モノイドを定義 区間最小、範囲更新
struct op_max : ILazySegmentTreeOperator<long, long> {
	public long Identity { get => -1l; }
	public long FIdentity { get => -1l; }
	public long Operate(long a, long b) => Max(a, b);
	public long Mapping(long f, long x) => f;
	public long Composition(long f, long g) => f;
}


class Kyopuro {
	public static void Main() {
		var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
		System.Console.SetOut(sw);
		var kyopuro = new Kyopuro();
		kyopuro.Solve2();
		System.Console.Out.Flush();
	} // end of func

	public void Solve2() {
		var nm = Console.ReadLine().Split(' ').Select(x => int.Parse(x)).ToArray();
		int n = nm[0];
		int m = nm[1];

		var xrr = new long[n];
		var dict = new SortedDictionary<long, int>();
		for (int i = 0; i < n; ++i) {
			xrr[i] = long.Parse(Console.ReadLine());
			if (xrr[i] != 0) dict[xrr[i]] = i;
		}

		var seg = new LazySegmentTree<long, long, op_max>(xrr);
		var avl = new AVLTree<int>();
		avl.Insert(0);
		avl.Insert(n);
		var ans = new HashSet<long>();
		foreach (var kv in dict) {
			int index = kv.Value;
			long height = kv.Key;
			// 左を見る
			int li = avl.FindLessThanMax(index);
			long lm = seg.Query(li, index);
			if (lm - height >= m) ans.Add(lm);
			// 右を見る
			int ri = avl.UpperBound(index);
			long rm = seg.Query(index + 1, ri);
			if (rm - height >= m) ans.Add(rm);

			// WriteLine($"index:{index} li:{li} lm:{lm} ri:{ri} rm:{rm}");
			avl.Insert(index);
		}

		// WriteLine();
		// foreach (var s in ans) WriteLine(s);
		WriteLine(ans.Count);


	}

} // end of class
