using System;
using System.Linq;
using System.Collections.Generic;
using static System.Console;
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

Mainn.Main();
static class Util {

	public static double PI = 3.141592653589793;
	public static long m107 = 1000000007;
	public static long m998 = 998244353;

	/// �����_�ȉ���16���ŕ\��(���x�����������ɑΉ�)
	public static void WriteLine16<T>(T num) {
		WriteLine(string.Format("{0:0.################ }", num));
	} // end of func

	/// 1����List���o��
	public static void printvec<T>(List<T> list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// 1�����z����o��
	public static void printvec<T>(T[] list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// 2�������X�g���o��
	public static void printvvec<T>(List<List<T>> list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func

	/// 2�����z����o��
	public static void printvvec<T>(T[][] list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func

	/// ������1��int�^�œǂݍ���
	public static int readint() {
		return int.Parse(ReadLine());
	} // end of func

	/// ������1��long�^�œǂݍ���
	public static long readlong() {
		return long.Parse(ReadLine());
	}

	/// �������X�y�[�X��؂��int�^�œ���
	public static int[] readints() {
		return ReadLine().Split(" ").Select(_ => int.Parse(_)).ToArray();
	} // end of func

	/// �������X�y�[�X��؂��long�^�œ���
	public static long[] readlongs() {
		return ReadLine().Split(" ").Select(_ => long.Parse(_)).ToArray();
	} // end of func

	/// ��������X�y�[�X��؂�œ���
	public static string[] readstrings() {
		return ReadLine().Split(" ").ToArray();
	} // end of func

	/// �o�͂�flush�폜
	public static void preprocess() {
		var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
		System.Console.SetOut(sw);
	} // end of func

	/// �o�͂�flush
	public static void finalprocess() {
		System.Console.Out.Flush();
	} // end of func

} // end of class
static class Mainn {
	public static void Main() {

		preprocess();
		var a = readints();
		printvec(a);
		finalprocess();
	}
}