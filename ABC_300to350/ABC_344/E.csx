using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
using static Util;
using System.IO;

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

	/// 小数点以下を16桁で表示(精度が厳しい問題に対応)
	public static void WriteLine16<T>(T num) {
		WriteLine(string.Format("{0:0.################ }", num));
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
	public static void printllist<T>(List<List<T>> list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func

	/// 2次元配列を出力
	public static void printllist<T>(T[][] list) {
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
	}

	/// 数字をスペース区切りでint型で入力
	public static int[] readints() {
		return ReadLine().Split(' ').Select(_ => int.Parse(_)).ToArray();
	} // end of func

	/// 数字をスペース区切りでlong型で入力
	public static long[] readlongs() {
		return ReadLine().Split(' ').Select(_ => long.Parse(_)).ToArray();
	} // end of func

	/// 文字列をスペース区切りで入力
	public static string[] readstrings() {
		return ReadLine().Split(' ').ToArray();
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


/// main program
public class Kyopuro {
	public static void Main() {
		preprocess();

		int n = readint();
		var arr = new List<int>(readints());
		arr.Insert(0, 0);
		arr.Add(-1);

		var next = new Dictionary<int, int>();
		var prev = new Dictionary<int, int>();
		for (int i = 0; i < arr.Count - 1; ++i) {
			prev[arr[i + 1]] = arr[i];
			next[arr[i]] = arr[i + 1];
		}

		int q = readint();
		for (int qq = 0; qq < q; ++qq) {
			var line = readints();
			if (line[0] == 1) {
				int x = line[1];
				int y = line[2];
				int tugi = next[x];
				next[x] = y;
				prev[y] = x;
				next[y] = tugi;
				prev[tugi] = y;
			} else {
				int x = line[1];
				prev[next[x]] = prev[x];
				next[prev[x]] = next[x];
				prev.Remove(x);
				next.Remove(x);
			}
		}

		int hoge = next[0];
		while (hoge != -1) {
			Write(hoge + " ");
			hoge = next[hoge];
		}
		WriteLine();

		finalprocess();
	} // end of func
} // end of class

Kyopuro.Main();