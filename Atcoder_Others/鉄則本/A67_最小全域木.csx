#pragma warning disable

using System;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using static System.Console;
using static System.Math;
using static Util;

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

	/// 3次元配列のディープコピーを行う
	public static T[][][] copyarr3<T>(T[][][] arr) {
		T[][][] brr = new T[arr.Length][][];
		for (int i = 0; i < arr.Length; ++i) {
			brr[i] = new T[arr[i].Length][];
			for (int j = 0; j < arr[i].Length; ++j) {
				brr[i][j] = new T[arr[i][j].Length];
				Array.Copy(arr[i][j], brr[i][j], arr[i][j].Length);
			}
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
			list2.Add(new List<T>(list[i]));
		}
		return list2;
	} // end of func

	/// 3次元Listのディープコピーを行う
	public static List<List<List<T>>> copylist3<T>(List<List<List<T>>> list) {
		List<List<List<T>>> list2 = new List<List<List<T>>>();
		for (int i = 0; i < list.Count; ++i) {
			List<List<T>> tmplist = new List<List<T>>();
			for (int j = 0; j < list[i].Count; ++i) {
				tmplist.Add(new List<T>(list[i][j]));
			}
			list2.Add(tmplist);
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

	/// 入力を空白区切りのstringで返す(変則的な入力に対応)
	public static string[] readsplit() {
		return ReadLine().Split(' ');
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

	/// 整数を二進数で表示
	public static void WriteLine2bit(int num) {
		WriteLine(Convert.ToString(num, 2));
	} // end of func

	/// 整数を二進数で表示
	public static void WriteLine2bit(long num) {
		WriteLine(Convert.ToString(num, 2));
	} // end of func

	/// 整数を2進数表現した文字列に
	public static string IntToString2bit(int num) {
		return Convert.ToString(num, 2);
	} // end of func

	/// 整数を2進数表現した文字列に
	public static string LongToString2bit(long num) {
		return Convert.ToString(num, 2);
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

/// 座標に便利
class YX {
	public int y;
	public int x;
	public YX(int y, int x) {
		this.y = y;
		this.x = x;
	}
} // end of class


class MyPriorityQueue<T> {
	/// 内部で持つヒープ配列
	public List<T> heap = new List<T>();

	/// 現在の要素数
	public int Count { get { return heap.Count; } }

	/// 比較用関数 (第1引数の方が優先度が高いときにtrue)
	private Func<T, T, bool> Compare;

	public MyPriorityQueue(Func<T, T, bool> compare) {
		this.Compare = compare;
	}  // end of constructor

	/// 新規の値を追加する
	public void Enqueue(T num) {
		// 追加する要素のノード番号　
		int node = this.heap.Count;
		this.heap.Add(num);

		// 可能な限り親と交換
		while (node > 0) {
			// 親ノード
			int p = (node - 1) / 2;

			// 交換条件を満たさなくなったら終わり
			if (this.Compare(num, heap[p]) == false) break;

			// 親ノードの値を子に降ろす
			heap[node] = heap[p];
			node = p;
		} // end of while

		// 新規の値を下ろす場所を見つけたので終わり
		heap[node] = num;
	} // end of method

	/// 一番優先度の高い値を返す
	public T Peek() => this.heap[0];

	/// 一番優先度の高い値を返して削除する
	public T Dequeue() {
		// return用の優先度が一番高い値
		T ret = this.heap[0];

		// 先頭を削除
		this.Pop();

		return ret;
	} // end of method

	/// 一番優先度の高い値を削除する
	public void Pop() {
		// 根に持ってくる値
		T last = heap[this.heap.Count - 1];

		// 最後尾を削除 O(1)
		this.heap.RemoveAt(this.heap.Count - 1);

		// 要素がなくなったら終了
		if (this.heap.Count == 0) return;

		// 先頭を置き換えて降ろしていく
		int node = 0;
		while (node * 2 + 1 < this.heap.Count) {
			int a = node * 2 + 1;
			int b = node * 2 + 2;

			// 右の子が存在して、なおかつ優先度が高いならば
			if (b < this.heap.Count && this.Compare(this.heap[b], this.heap[a])) a = b;

			// 交換条件を満たさなくなったら終わり
			if (this.Compare(last, this.heap[a])) break;

			// 優先度の高い子を上げる
			this.heap[node] = this.heap[a];
			node = a;
		} // end of while

		// 先頭に持ってきた値の置き場所が決まったので更新
		this.heap[node] = last;
	} // end of method

} // end of class

/// union by rankと経路圧縮をする
/// O(a(N)) 
class UnionFind {
	/// 親のノード番号
	public int[] parents;

	/// 属する集合の要素数　
	public int[] sizes;

	/// ノード数NのUnionFindを作成
	public UnionFind(int n) {
		this.parents = new int[n];
		this.sizes = new int[n];
		for (int i = 0; i < n; ++i) {
			// 初期状態では親を持たない
			this.parents[i] = -1;
			// 集合サイズは1
			this.sizes[i] = 1;
		}
	} // end of constructor

	/// ノードiの親を返す
	public int Root(int node) {
		// 根を見つけたらノード番号を変えす
		if (this.parents[node] == -1) return node;

		// 根までの経路を全て根に直接つなぐ
		else {
			int parent = this.Root(this.parents[node]);
			this.parents[node] = parent;
			return parent;
		}
	} // end of method

	/// ノードuとvの属する集合を結合する
	public void Unite(int u, int v) {
		int ru = this.Root(u);
		int rv = this.Root(v);
		if (ru == rv) return;
		// 大きい集合の根に結合(union by rank)
		// 高さが高々log2になる
		if (ru > rv) {
			int tmp = ru;
			ru = rv;
			rv = tmp;
		}
		this.parents[ru] = rv;
		this.sizes[rv] = this.sizes[ru] + this.sizes[rv];
		this.sizes[ru] = this.sizes[rv];
	} // end of method

	/// ノードuとvが同じ集合に属しているか
	public bool Connected(int u, int v) {
		return this.Root(u) == this.Root(v);
	} // end of method
} // end of class


class Kyopuro {
	public static void Main() {
		preprocess();
		var kyopuro = new Kyopuro();
		kyopuro.Solve();
		finalprocess();
	} // end of func

	/// 最小全域木を返す
	/// (node, cost)の順番のグラフ(ダイクストラと逆にしちゃった…)
	List<List<(int, long)>> MinimumSpanningTree(int n, MyPriorityQueue<(int, int, long)> pq) {
		var mst = makelist2(n, 0, (0, 0l));
		var uf = new UnionFind(n);

		// 距離が小さい順にPriorityQueueにエッジが入っている
		// エッジの両辺のノードがつながっていないならつなげる(UnionFindで集合検索)
		while (pq.Count > 0) {
			var abc = pq.Dequeue();
			int a = abc.Item1;
			int b = abc.Item2;
			long c = abc.Item3;
			if (uf.Connected(a, b) == true) continue;
			uf.Unite(a, b);
			mst[a].Add((b, c));
			mst[b].Add((a, c));
		}

		return mst;
	}


	public void Solve() {

		var (n, m) = readintt2();
		var pq = new MyPriorityQueue<(int, int, long)>((a, b) => a.Item3 <= b.Item3);
		for (int i = 0; i < m; ++i) {
			var abc = readintt3();
			abc.Item1 -= 1;
			abc.Item2 -= 1;
			pq.Enqueue(abc);
		}

		var mst = MinimumSpanningTree(n, pq);
		long ans = 0;
		for (int i = 0; i < n; ++i) {
			foreach (var ac in mst[i]) {
				ans += ac.Item2;
			}
		}
		writeline(ans / 2);

	} // end of func
} // end of class
