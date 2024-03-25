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


public class Kyopuro {
	public static void Main() {
		preprocess();
		var kyopuro = new Kyopuro();
		kyopuro.Solve();
		finalprocess();
	} // end of func


	/// ノードをつなぐ距離と行き先
	public class Edge {
		public long cost;
		public int node;
		public Edge(long c = 0, int n = 0) { this.cost = c; this.node = n; }
	} // end of class

	/// long型を比較する関数 (昇順)
	public class ComparerAsc : IComparer<long> {
		public int Compare(long x, long y) {
			if (x < y) return -1;
			if (x > y) return 1;
			return 0;
		}
	} // end of class

	public List<long> Dijkstra(List<List<Edge>> graph, int start) {
		// 変数用意
		int n = graph.Count;

		// 最大値
		long inf = System.Int64.MaxValue;

		// <node, cost> cost降順
		var pq = new PriorityQueue<int, long>(new ComparerAsc());

		// 確定した距離を保持
		var distance = new List<long>(makearr<long>(n, inf));
		distance[start] = 0;
		pq.Enqueue(start, 0);
		while (pq.Count > 0) {
			int node;
			long cost;
			pq.TryDequeue(out node, out cost);

			// すでに確定した距離以上なら更新余地は無い
			if (distance[node] < cost) continue;

			// 各種距離を追加
			foreach (var next in graph[node]) {
				// 更新余地がない場合は次
				if (distance[next.node] < cost + next.cost) continue;
				distance[next.node] = cost + next.cost;
				pq.Enqueue(next.node, cost + next.cost);
			}
		} // end of while

		return distance;
	} // end of method



	public void Solve() {
		var (n, m, tt) = readintt3();
		long t = tt;
		var graph1 = makelist2(n, 0, new Edge());
		var graph2 = makelist2(n, 0, new Edge());
		var arr = readlongs();
		for (int i = 0; i < m; ++i) {
			var (a, b, c) = readintt3();
			--a; --b;
			graph1[a].Add(new Edge(c, b));
			graph2[b].Add(new Edge(c, a));
		}


		var dist1 = Dijkstra(graph1, 0);
		var dist2 = Dijkstra(graph2, 0);
		long ans = 0;
		for (int i = 0; i < n; ++i) {
			long time = t - dist1[i] - dist2[i];
			long money = time * arr[i];
			ans = Max(ans, money);
		}

		// printlist(dist1);
		// printlist(dist2);
		writeline(ans);

	}
} // end of class
