#pragma warning disable

using System;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using static System.Console;
using static System.Math;
using static Util;
using System.Runtime.ExceptionServices;
using System.Reflection.Metadata.Ecma335;
using System.Security.Cryptography.X509Certificates;
using System.Data;

// using pii = (int, int);
// using pll = (long, long);
// using pdd = (double, double);
// using pss = (string, string);
// using pis = (int, string);
// using psi = (string, int);
// using pls = (long, string);
// using psl = (string, long);
// using pds = (double, string);
// using psd = (string, double);
// using pid = (int, double);
// using pdi = (double, int);
// using pld = (long, double);
// using pdl = (double, long);
// using vb = bool[];
// using vvb = bool[][];
// using vvvb = bool[][][];
// using vi = int[];
// using vvi = int[][];
// using vvvi = int[][][];
// using vl = long[];
// using vvl = long[][];
// using vvvl = long[][][];
// using vd = double[];
// using vvd = double[][];
// using vvvd = double[][][];
// using vs = string[];
// using vvs = string[][];
// using vvvs = string[][][];
// using listb = System.Collections.Generic.List<bool>;
// using llistb = System.Collections.Generic.List<System.Collections.Generic.List<bool>>;
// using lllistb = System.Collections.Generic.List<System.Collections.Generic.List<System.Collections.Generic.List<bool>>>;
// using listi = System.Collections.Generic.List<int>;
// using llisti = System.Collections.Generic.List<System.Collections.Generic.List<int>>;
// using lllisti = System.Collections.Generic.List<System.Collections.Generic.List<System.Collections.Generic.List<int>>>;
// using listl = System.Collections.Generic.List<long>;
// using llistl = System.Collections.Generic.List<System.Collections.Generic.List<long>>;
// using lllistl = System.Collections.Generic.List<System.Collections.Generic.List<System.Collections.Generic.List<long>>>;
// using listd = System.Collections.Generic.List<double>;
// using llistd = System.Collections.Generic.List<System.Collections.Generic.List<double>>;
// using lllistd = System.Collections.Generic.List<System.Collections.Generic.List<System.Collections.Generic.List<double>>>;
// using lists = System.Collections.Generic.List<string>;
// using llists = System.Collections.Generic.List<System.Collections.Generic.List<string>>;
// using lllists = System.Collections.Generic.List<System.Collections.Generic.List<System.Collections.Generic.List<string>>>;
// using mii = System.Collections.Generic.SortedDictionary<int, int>;
// using mll = System.Collections.Generic.SortedDictionary<long, long>;
// using mss = System.Collections.Generic.SortedDictionary<string, string>;
// using mis = System.Collections.Generic.SortedDictionary<int, string>;
// using msi = System.Collections.Generic.SortedDictionary<string, int>;
// using mls = System.Collections.Generic.SortedDictionary<long, string>;
// using msl = System.Collections.Generic.SortedDictionary<string, long>;
// using umii = System.Collections.Generic.Dictionary<int, int>;
// using umll = System.Collections.Generic.Dictionary<long, long>;
// using umss = System.Collections.Generic.Dictionary<string, string>;
// using umis = System.Collections.Generic.Dictionary<int, string>;
// using umsi = System.Collections.Generic.Dictionary<string, int>;
// using umls = System.Collections.Generic.Dictionary<long, string>;
// using umsl = System.Collections.Generic.Dictionary<string, long>;
// using seti = System.Collections.Generic.SortedSet<int>;
// using setl = System.Collections.Generic.SortedSet<long>;
// using sets = System.Collections.Generic.SortedSet<string>;
// using useti = System.Collections.Generic.HashSet<int>;
// using usetl = System.Collections.Generic.HashSet<long>;
// using usets = System.Collections.Generic.HashSet<string>;


public class Util {
	public static double PI = 3.141592653589793;
	public static long m107 = 1000000007;
	public static long m998 = 998244353;
	public static int a10_9 = 1000000000;
	public static long a10_18 = 1000000000000000000;

	/// 打ちやすいように
	public static string read() => ReadLine();
	public static string readln() => ReadLine();
	public static string readline() => ReadLine();
	public static void write() => Write("");
	public static void write(string s) => Write(s);
	public static void write(char c) => Write(c);
	public static void write(int num) => Write(num);
	public static void write(long num) => Write(num);
	public static void write(double num) => Write(num);
	public static void writeln() => WriteLine("");
	public static void writeln(string s) => WriteLine(s);
	public static void writeln(char c) => WriteLine(c);
	public static void writeln(int num) => WriteLine(num);
	public static void writeln(long num) => WriteLine(num);
	public static void writeln(double num) => WriteLine(num);
	public static void writeline() => WriteLine("");
	public static void writeline(string s) => WriteLine(s);
	public static void writeline(char c) => WriteLine(c);
	public static void writeline(int num) => WriteLine(num);
	public static void writeline(long num) => WriteLine(num);
	public static void writeline(double num) => WriteLine(num);
	public static void print() => Write("");
	public static void print(string s) => Write(s);
	public static void print(char c) => Write(c);
	public static void print(int num) => Write(num);
	public static void print(long num) => Write(num);
	public static void print(double num) => Write(num);
	public static void println() => WriteLine("");
	public static void println(string s) => WriteLine(s);
	public static void println(char c) => WriteLine(c);
	public static void println(int num) => WriteLine(num);
	public static void println(long num) => WriteLine(num);
	public static void println(double num) => WriteLine(num);
	public static void printline() => WriteLine("");
	public static void printline(string s) => WriteLine(s);
	public static void printline(char c) => WriteLine(c);
	public static void printline(int num) => WriteLine(num);
	public static void printline(long num) => WriteLine(num);
	public static void printline(double num) => WriteLine(num);

	/// 任意の要素数・初期値の配列を作って初期化する
	public static T[] makearr<T>(int num, T value) {
		var arr = new T[num];
		for (int i = 0; i < num; ++i) arr[i] = value;
		return arr;
	} // end of func

	/// 任意の要素数・初期値の２次元配列を作って初期化する
	public static T[][] makearr2<T>(int height, int width, T value) {
		var arr = new T[height][];
		for (int i = 0; i < height; ++i) {
			arr[i] = new T[width];
			for (int j = 0; j < width; ++j) {
				arr[i][j] = value;
			}
		}
		return arr;
	} // end of func

	/// 任意の要素数・初期値の3次元配列を作って初期化する
	public static T[][][] makearr3<T>(int height, int width, int depth, T value) {
		var arr = new T[height][][];
		for (int i = 0; i < height; ++i) {
			arr[i] = new T[width][];
			for (int j = 0; j < width; ++j) {
				arr[i][j] = new T[depth];
				for (int k = 0; k < depth; ++k) {
					arr[i][j][k] = value;
				}
			}
		}
		return arr;
	} // end of func

	/// 任意の要素数・初期値のListを作って初期化する
	public static List<T> makelist<T>(int num, T value) {
		return new List<T>(makearr(num, value));
	} // end of func

	/// 任意の要素数・初期値の2次元Listを作って初期化する
	public static List<List<T>> makelist2<T>(int height, int width, T value) {
		var arr = new List<List<T>>();
		for (int i = 0; i < height; ++i) {
			arr.Add(makelist(width, value));
		}
		return arr;
	} // end of func

	/// 任意の要素数・初期値の3次元Listを作って初期化する
	public static List<List<List<T>>> makelist3<T>(int height, int width, int depth, T value) {
		var arr = new List<List<List<T>>>();
		for (int i = 0; i < height; ++i) {
			arr[i] = new List<List<T>>();
			for (int j = 0; j < width; ++j) {
				arr[i].Add(makelist(depth, value));
			}
		}
		return arr;
	} // end of func

	/// 1次元配列のディープコピーを行う
	public static T[] copyarr<T>(T[] arr) {
		T[] brr = new T[arr.Length];
		Array.Copy(arr, brr, arr.Length);
		return brr;
	} // end of func 

	/// 2次元配列のディープコピーを行う
	public static T[][] copyarr2<T>(T[][] arr) {
		T[][] brr = new T[arr.Length][];
		for (int i = 0; i < arr.Length; ++i) {
			brr[i] = new T[arr[i].Length];
			Array.Copy(arr[i], brr[i], arr[i].Length);
		}
		return brr;
	} // end of func

	/// 1次元Listのディープコピーを行う
	public static List<T> copylist<T>(List<T> list) {
		return new List<T>(list);
	} // end of func

	/// 2次元Listのディープコピーを行う
	public static List<List<T>> copylist2<T>(List<List<T>> list) {
		List<List<T>> list2 = new List<List<T>>();
		for (int i = 0; i < list.Count; ++i) {
			List<T> tmp = new List<T>(list[i]);
			list2.Add(tmp);
		}
		return list2;
	} // end of func

	/// 1次元Listを出力
	public static void printlist<T>(List<T> list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// 1次元配列を出力
	public static void printlist<T>(T[] list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// 2次元リストを出力
	public static void printlist2<T>(List<List<T>> list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func

	/// 2次元配列を出力
	public static void printlist2<T>(T[][] list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func	

	/// 1次元Listを出力
	public static void printarr<T>(List<T> list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// 1次元配列を出力
	public static void printarr<T>(T[] list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// 2次元リストを出力
	public static void printarr2<T>(List<List<T>> list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func

	/// 2次元配列を出力
	public static void printarr2<T>(T[][] list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func

	/// 数字を1つint型で読み込み
	public static int readint() {
		return int.Parse(ReadLine());
	} // end of func

	/// 数字を1つlong型で読み込み
	public static long readlong() {
		return long.Parse(ReadLine());
	} // end of func

	/// 数字をスペース区切りでint型で入力
	public static int[] readints() {
		return ReadLine().Split(' ').Select(_ => int.Parse(_)).ToArray();
	} // end of func

	/// 数字をスペース区切りでlong型で入力
	public static long[] readlongs() {
		return ReadLine().Split(' ').Select(_ => long.Parse(_)).ToArray();
	} // end of func

	/// 数字をスペース区切りでfloat型で入力
	public static float[] readfloats() {
		return ReadLine().Split(' ').Select(_ => float.Parse(_)).ToArray();
	} // end of func

	/// 数字をスペース区切りでdouble型で入力
	public static double[] readdoubles() {
		return ReadLine().Split(' ').Select(_ => double.Parse(_)).ToArray();
	} // end of func

	/// 文字列をスペース区切りで入力
	public static string[] readstrings() {
		return ReadLine().Split(' ');
	} // end of func

	/// 読み込んだint2つをタプルで返す(分解代入用)
	public static (int, int) readintt2() {
		var arr = readints();
		return (arr[0], arr[1]);
	} // end of func

	/// 読み込んだint3つをタプルで返す(分解代入用)
	public static (int, int, int) readintt3() {
		var arr = readints();
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// 読み込んだint4つをタプルで返す(分解代入用)
	public static (int, int, int, int) readintt4() {
		var arr = readints();
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// 読み込んだlong2つをタプルで返す(分解代入用)
	public static (long, long) readlongt2() {
		var arr = readlongs();
		return (arr[0], arr[1]);
	} // end of func

	/// 読み込んだ数long3つをタプルで返す(分解代入用)
	public static (long, long, long) readlongt3() {
		var arr = readlongs();
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// 読み込んだ数long4つをタプルで返す(分解代入用)
	public static (long, long, long, long) readlongt4() {
		var arr = readlongs();
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// 読み込んだfloat2つをタプルで返す(分解代入用)
	public static (float, float) readfloatt2() {
		var arr = readfloats();
		return (arr[0], arr[1]);
	} // end of func

	/// 読み込んだfloat3つをタプルで返す(分解代入用)
	public static (float, float, float) readfloatt3() {
		var arr = readfloats();
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// 読み込んだfloat4つをタプルで返す(分解代入用)
	public static (float, float, float, float) readfloatt4() {
		var arr = readfloats();
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// 読み込んだdouble2つをタプルで返す(分解代入用)
	public static (double, double) readdoublet2() {
		var arr = readdoubles();
		return (arr[0], arr[1]);
	} // end of func

	/// 読み込んだdouble3つをタプルで返す(分解代入用)
	public static (double, double, double) readdoublet3() {
		var arr = readdoubles();
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// 読み込んだdouble4つをタプルで返す(分解代入用)
	public static (double, double, double, double) readdoublet4() {
		var arr = readdoubles();
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// 読み込んだstring2つをタプルで返す(分解代入用)
	public static (string, string) readstringt2() {
		var arr = ReadLine().Split(' ');
		return (arr[0], arr[1]);
	} // end of func

	/// 読み込んだstring3つをタプルで返す(分解代入用)
	public static (string, string, string) readstringt3() {
		var arr = ReadLine().Split(' ');
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// 読み込んだstring3つをタプルで返す(分解代入用)
	public static (string, string, string, string) readstringt4() {
		var arr = ReadLine().Split(' ');
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// 先頭に要素数(int)と次にでかい数字1つ
	public static (int, long) readintlongt2() {
		var arr = ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
		return ((int)arr[0], arr[1]);
	} // end of func

	/// 先頭に要素数(int)と次にでかい数字2つ
	public static (int, long, long) readintlongt3() {
		var arr = ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
		return ((int)arr[0], arr[1], arr[2]);
	} // end of func

	/// 先頭に要素数(int)と次にでかい数字2つ
	public static (int, long, long, long) readintlongt4() {
		var arr = ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
		return ((int)arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// 小数点以下を16桁で表示(精度が厳しい問題に対応)
	public static void WriteLine16<T>(T num) {
		WriteLine(string.Format("{0:0.################}", num));
	} // end of func

	/// 出力のflush削除
	public static void preprocess() {
		var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
		System.Console.SetOut(sw);
	} // end of func

	/// 出力をflush
	public static void finalprocess() {
		System.Console.Out.Flush();
	} // end of func
} // end of class

/// 通常のセグメント木(一つ更新できる)
public class SegmentTree<T> where T : struct, IComparable, IFormattable, IConvertible, IComparable<T>, IEquatable<T> {
	/// 一番下の葉の数 (2のべき乗になってるはず)
	public int LeafNum { get; set; }

	/// ノード全体の要素数
	public int Count { get => this.Node.Length; }

	/// 実際に木を構築するノード
	public T[] Node { get; set; }

	/// 作用素 (TとTに対する演算結果Tを返す min, max, sumなど)
	private Func<T, T, T> Operator;

	/// モノイドの単位元 (オペレーターの演算に影響を及ぼさない)
	private T Identity;

	/// 元配列を渡してセグメントツリーの作成
	/// 初期値はminやmaxなどで変わると思うので与える(デフォルト=0のはず)
	public SegmentTree(Func<T, T, T> op, T[] arr, T identity = default(T)) {
		// 作用素を保存
		this.Operator = op;

		// 単位元を保存
		this.Identity = identity;

		// ノード数を　2^⌈log2(N)⌉　にする
		this.LeafNum = 1;
		while (this.LeafNum < arr.Length) this.LeafNum <<= 1;

		// 葉の初期化
		this.Node = new T[this.LeafNum * 2 - 1];
		for (int i = 0; i < this.Count; ++i) this.Node[i] = this.Identity;
		for (int i = 0; i < arr.Length; ++i) this.Node[this.LeafNum - 1 + i] = arr[i];

		// 親ノードの値を決めていく
		for (int i = this.LeafNum - 2; i >= 0; --i) {
			// 左右と比較
			this.Node[i] = this.Operator(this.Node[2 * i + 1], this.Node[2 * i + 2]);
		}
	} // end of constructor

	/// index番目の値をvalueにする
	public void Update(int index, T value) {
		// 葉の更新
		index += this.LeafNum - 1;
		this.Node[index] = value;

		// 親の更新
		while (index > 0) {
			index = (index - 1) / 2;
			// 左右と比較
			this.Node[index] = this.Operator(this.Node[2 * index + 1], this.Node[2 * index + 2]);
		}
	} // end of update

	/// [l, r) の区間◯◯値を求める(求まる値はOperatorで指定されてる)
	public T Query(int l, int r) {
		return this.Query(l, r, 0, 0, this.LeafNum);
	} // end of method

	/// [l, r) は求めたい半開区間
	/// k は現在のノード番号
	/// [a, b) はkに対応する半開区間
	private T Query(int l, int r, int k, int a, int b) {
		// 現在の対応ノード区間が求めたい区間に含まれないとき
		// → 単位元を返す
		if (r <= a || b <= l) return this.Identity;

		// 現在の対応ノード区間が求めたい区間に完全に含まれるとき
		// → 現在のノードの値を返す
		if (l <= a && b <= r) return this.Node[k];

		// 左半分と右半分で見る
		int m = (a + b) / 2;
		T leftValue = Query(l, r, k * 2 + 1, a, m);
		T rightValue = Query(l, r, k * 2 + 2, m, b);
		return this.Operator(leftValue, rightValue);
	} // end of method
} // end of class

public class Kyopuro {
	public static void Main() {
		preprocess();
		var kyopuro = new Kyopuro();
		kyopuro.Solve();
		finalprocess();
	} // end of func


	public void Solve() {
		var (n, q) = readintt2();
		var st = new SegmentTree<long>((long a, long b) => a + b, new long[n], 0);

		for (int _ = 0; _ < q; ++_) {
			var query = readints();
			if (query[0] == 1) {
				int pos = query[1] - 1;
				int value = query[2];
				st.Update(pos, value);
			} else {
				int l = query[1] - 1;
				int r = query[2] - 1;
				writeline(st.Query(l, r));
			}
		}
	}
} // end of class
