using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;

using pii = (int, int);
using pll = (long, long);
using pdd = (double, double);
using pss = (string, string);
using pis = (int, string);
using psi = (string, int);
using pls = (long, string);
using psl = (string, long);
using pds = (double, string);
using psd = (string, double);
using pid = (int, double);
using pdi = (double, int);
using pld = (long, double);
using pdl = (double, long);
using vb = bool[];
using vvb = bool[][];
using vvvb = bool[][][];
using vi = int[];
using vvi = int[][];
using vvvi = int[][][];
using vl = long[];
using vvl = long[][];
using vvvl = long[][][];
using vd = double[];
using vvd = double[][];
using vvvd = double[][][];
using vs = string[];
using vvs = string[][];
using vvvs = string[][][];
using listb = System.Collections.Generic.List<bool>;
using llistb = System.Collections.Generic.List<System.Collections.Generic.List<bool>>;
using lllistb = System.Collections.Generic.List<System.Collections.Generic.List<System.Collections.Generic.List<bool>>>;
using listi = System.Collections.Generic.List<int>;
using llisti = System.Collections.Generic.List<System.Collections.Generic.List<int>>;
using lllisti = System.Collections.Generic.List<System.Collections.Generic.List<System.Collections.Generic.List<int>>>;
using listl = System.Collections.Generic.List<long>;
using llistl = System.Collections.Generic.List<System.Collections.Generic.List<long>>;
using lllistl = System.Collections.Generic.List<System.Collections.Generic.List<System.Collections.Generic.List<long>>>;
using listd = System.Collections.Generic.List<double>;
using llistd = System.Collections.Generic.List<System.Collections.Generic.List<double>>;
using lllistd = System.Collections.Generic.List<System.Collections.Generic.List<System.Collections.Generic.List<double>>>;
using lists = System.Collections.Generic.List<string>;
using llists = System.Collections.Generic.List<System.Collections.Generic.List<string>>;
using lllists = System.Collections.Generic.List<System.Collections.Generic.List<System.Collections.Generic.List<string>>>;
using mii = System.Collections.Generic.SortedDictionary<int, int>;
using mll = System.Collections.Generic.SortedDictionary<long, long>;
using mss = System.Collections.Generic.SortedDictionary<string, string>;
using mis = System.Collections.Generic.SortedDictionary<int, string>;
using msi = System.Collections.Generic.SortedDictionary<string, int>;
using mls = System.Collections.Generic.SortedDictionary<long, string>;
using msl = System.Collections.Generic.SortedDictionary<string, long>;
using umii = System.Collections.Generic.Dictionary<int, int>;
using umll = System.Collections.Generic.Dictionary<long, long>;
using umss = System.Collections.Generic.Dictionary<string, string>;
using umis = System.Collections.Generic.Dictionary<int, string>;
using umsi = System.Collections.Generic.Dictionary<string, int>;
using umls = System.Collections.Generic.Dictionary<long, string>;
using umsl = System.Collections.Generic.Dictionary<string, long>;
using seti = System.Collections.Generic.SortedSet<int>;
using setl = System.Collections.Generic.SortedSet<long>;
using sets = System.Collections.Generic.SortedSet<string>;
using useti = System.Collections.Generic.HashSet<int>;
using usetl = System.Collections.Generic.HashSet<long>;
using usets = System.Collections.Generic.HashSet<string>;

const double PI = 3.141592653589793;
const long m107 = 1000000007;
const long m998 = 998244353;

/// 小数点以下を16桁で表示(精度が厳しい問題に対応)
void WriteLine16<T>(T num) {
	WriteLine(string.Format("{0:0.################ }", num));
} // end of func

/// 1次元Listを出力
void printvec<T>(List<T> list) {
	WriteLine(string.Join(" ", list));
} // end of func

/// 1次元配列を出力
void printvec<T>(T[] list) {
	WriteLine(string.Join(" ", list));
} // end of func

/// 2次元リストを出力
void printvvec<T>(List<List<T>> list) {
	foreach (var l in list) {
		WriteLine(string.Join(" ", l));
	}
} // end of func

/// 2次元配列を出力
void printvvec<T>(T[][] list) {
	foreach (var l in list) {
		WriteLine(string.Join(" ", l));
	}
} // end of func

/// 数字を1つint型で読み込み
int readint() {
	return int.Parse(ReadLine());
} // end of func

/// 数字を1つlong型で読み込み
long readlong() {
	return long.Parse(ReadLine());
}

/// 数字をスペース区切りでint型で入力
int[] readints() {
	return ReadLine().Split(" ").Select(_ => int.Parse(_)).ToArray();
} // end of func

/// 数字をスペース区切りでlong型で入力
long[] readlongs() {
	return ReadLine().Split(" ").Select(_ => long.Parse(_)).ToArray();
} // end of func

/// 文字列をスペース区切りで入力
string[] readstrings() {
	return ReadLine().Split(" ").ToArray();
} // end of func

/// 出力のflush削除
void preprocess() {
	var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
	System.Console.SetOut(sw);
} // end of func

/// 出力をflush
void finalprocess() {
	System.Console.Out.Flush();
} // end of func

void main() {
	var a = readints();
	printvec(a);
} // end of func


preprocess();
main();
finalprocess();