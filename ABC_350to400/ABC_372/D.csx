#pragma warning disable

using System;
using System.IO;
using System.Linq;
using System.Text;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using static System.Console;
using static System.Math;
using static System.ComponentModel.TypeDescriptor;
using static Util;

class Util {
	public const long m107 = 1000000007;
	public const long m998 = 998244353;
	public const int a10_9 = 1000000000;
	public const long a10_18 = 1000000000000000000;
	public const int iinf = 1 << 30;
	public const long linf = (1l << 61) - (1l << 31);

	/// <summary>1行読みこみ</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string read() => ReadLine();

	/// <summary>1行読みこみ</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string readln() => ReadLine();

	/// <summary>1行読みこみ</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string readline() => ReadLine();

	/// <summary>改行なし出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void write() => Write("");

	/// <summary>改行なし出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void write<T>(T value) => Write(value);

	/// <summary>改行あり出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeln() => WriteLine("");

	/// <summary>改行あり出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeln<T>(T value) => WriteLine(value);

	/// <summary>改行あり出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeline() => WriteLine("");

	/// <summary>改行あり出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeline<T>(T value) => WriteLine(value);

	/// <summary>Yes出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeyes() => WriteLine("Yes");

	/// <summary>No出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeno() => WriteLine("No");

	/// <summary>改行なし出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void print() => Write("");

	/// <summary>改行なし出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void print<T>(T value) => Write(value);

	/// <summary>改行あり出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void println() => WriteLine("");

	/// <summary>改行あり出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void println<T>(T value) => WriteLine(value);

	/// <summary>改行あり出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printline() => WriteLine("");

	/// <summary>改行あり出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printline<T>(T value) => WriteLine(value);

	/// <summary>Yes出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printyes() => WriteLine("Yes");

	/// <summary>No出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printno() => WriteLine("No");

	/// <summary>任意の要素数・初期値の配列を作って初期化する</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static T[] makearr<T>(int num, T value) {
		var arr = new T[num];
		for (int i = 0; i < num; ++i) arr[i] = value;
		return arr;
	} // end of func

	/// <summary>任意の要素数・初期値の２次元配列を作って初期化する</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
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

	/// <summary>任意の要素数・初期値の3次元配列を作って初期化する</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
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

	/// <summary>任意の要素数・初期値のListを作って初期化する</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static List<T> makelist<T>(int num, T value) {
		return new List<T>(makearr(num, value));
	} // end of func

	/// <summary>任意の要素数・初期値の2次元Listを作って初期化する</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static List<List<T>> makelist2<T>(int height, int width, T value) {
		var arr = new List<List<T>>();
		for (int i = 0; i < height; ++i) {
			arr.Add(makelist(width, value));
		}
		return arr;
	} // end of func

	/// 任意の要素数・初期値の3次元Listを作って初期化する
	[MethodImpl(256)]
	public static List<List<List<T>>> makelist3<T>(int height, int width, int depth, T value) {
		var arr = new List<List<List<T>>>();
		for (int i = 0; i < height; ++i) {
			arr.Add(new List<List<T>>());
			for (int j = 0; j < width; ++j) {
				arr[i].Add(makelist(depth, value));
			}
		}
		return arr;
	} // end of func

	/// <summary>1次元配列のディープコピーを行う</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static T[] copyarr<T>(T[] arr) {
		T[] brr = new T[arr.Length];
		Array.Copy(arr, brr, arr.Length);
		return brr;
	} // end of func 

	/// <summary>2次元配列のディープコピーを行う</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static T[][] copyarr2<T>(T[][] arr) {
		T[][] brr = new T[arr.Length][];
		for (int i = 0; i < arr.Length; ++i) {
			brr[i] = new T[arr[i].Length];
			Array.Copy(arr[i], brr[i], arr[i].Length);
		}
		return brr;
	} // end of func

	/// <summary>3次元配列のディープコピーを行う</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
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

	/// <summary>1次元Listのディープコピーを行う</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static List<T> copylist<T>(List<T> list) {
		return new List<T>(list);
	} // end of func

	/// <summary>2次元Listのディープコピーを行う</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static List<List<T>> copylist2<T>(List<List<T>> list) {
		List<List<T>> list2 = new List<List<T>>();
		for (int i = 0; i < list.Count; ++i) {
			list2.Add(new List<T>(list[i]));
		}
		return list2;
	} // end of func

	/// <summary>3次元Listのディープコピーを行う</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static List<List<List<T>>> copylist3<T>(List<List<List<T>>> list) {
		List<List<List<T>>> list2 = new List<List<List<T>>>();
		for (int i = 0; i < list.Count; ++i) {
			List<List<T>> tmplist = new List<List<T>>();
			for (int j = 0; j < list[i].Count; ++j) {
				tmplist.Add(new List<T>(list[i][j]));
			}
			list2.Add(tmplist);
		}
		return list2;
	} // end of func

	/// <summary>1次元Listを出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printlist<T>(List<T> list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// <summary>1次元配列を出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printlist<T>(T[] list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// <summary>2次元リストを出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printlist2<T>(List<List<T>> list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func

	/// <summary>2次元配列を出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printlist2<T>(T[][] list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func	

	/// <summary>1次元Listを出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printarr<T>(List<T> list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// <summary>1次元配列を出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printarr<T>(T[] list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// <summary>2次元リストを出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printarr2<T>(List<List<T>> list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func

	/// <summary>2次元配列を出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printarr2<T>(T[][] list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func

	/// <summary>ジェネリックを出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printiter<T>(IEnumerable<T> generic) {
		foreach (var it in generic) {
			Write(it + " ");
		}
		WriteLine();
	} // end of func

	/// <summary>ジェネリックを出力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printlineiter<T>(IEnumerable<T> generic) {
		foreach (var it in generic) {
			WriteLine(it + " ");
		}
	} // end of func

	/// <summary>数字を1つint型で読み込み</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static int readint() => int.Parse(ReadLine());

	/// <summary>数字を1つlong型で読み込み</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static long readlong() => long.Parse(ReadLine());

	/// <summary>数字を1つfloat型で読み込み</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static float readfloat() => float.Parse(ReadLine());

	/// <summary>数字を1つfloat型で読み込み</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static double readdouble() => double.Parse(ReadLine());

	/// <summary>入力を空白区切りのstringで返す(変則的な入力に対応)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string[] readsplit() {
		return ReadLine().Split(' ');
	} // end of func

	/// <summary>数字をスペース区切りでint型で入力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static int[] readints() {
		return ReadLine().Split(' ').Select(_ => int.Parse(_)).ToArray();
	} // end of func

	/// <summary>数字をスペース区切りでlong型で入力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static long[] readlongs() {
		return ReadLine().Split(' ').Select(_ => long.Parse(_)).ToArray();
	} // end of func

	/// <summary>数字をスペース区切りでfloat型で入力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static float[] readfloats() {
		return ReadLine().Split(' ').Select(_ => float.Parse(_)).ToArray();
	} // end of func

	/// <summary>数字をスペース区切りでdouble型で入力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static double[] readdoubles() {
		return ReadLine().Split(' ').Select(_ => double.Parse(_)).ToArray();
	} // end of func

	/// <summary>文字列をスペース区切りで入力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string[] readstrings() {
		return ReadLine().Split(' ');
	} // end of func

	/// <summary>読み込んだint2つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (int, int) readintt2() {
		var arr = readints();
		return (arr[0], arr[1]);
	} // end of func

	/// <summary>読み込んだint3つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (int, int, int) readintt3() {
		var arr = readints();
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// <summary>読み込んだint4つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (int, int, int, int) readintt4() {
		var arr = readints();
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// <summary>読み込んだlong2つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (long, long) readlongt2() {
		var arr = readlongs();
		return (arr[0], arr[1]);
	} // end of func

	/// <summary>読み込んだ数long3つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (long, long, long) readlongt3() {
		var arr = readlongs();
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// <summary>読み込んだ数long4つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (long, long, long, long) readlongt4() {
		var arr = readlongs();
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// <summary>読み込んだfloat2つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (float, float) readfloatt2() {
		var arr = readfloats();
		return (arr[0], arr[1]);
	} // end of func

	/// <summary>読み込んだfloat3つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (float, float, float) readfloatt3() {
		var arr = readfloats();
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// <summary>読み込んだfloat4つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (float, float, float, float) readfloatt4() {
		var arr = readfloats();
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// <summary>読み込んだdouble2つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (double, double) readdoublet2() {
		var arr = readdoubles();
		return (arr[0], arr[1]);
	} // end of func

	/// <summary>読み込んだdouble3つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (double, double, double) readdoublet3() {
		var arr = readdoubles();
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// <summary>読み込んだdouble4つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (double, double, double, double) readdoublet4() {
		var arr = readdoubles();
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// <summary>読み込んだstring2つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (string, string) readstringt2() {
		var arr = ReadLine().Split(' ');
		return (arr[0], arr[1]);
	} // end of func

	/// <summary>読み込んだstring3つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (string, string, string) readstringt3() {
		var arr = ReadLine().Split(' ');
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// <summary>読み込んだstring3つをタプルで返す(分解代入用)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (string, string, string, string) readstringt4() {
		var arr = ReadLine().Split(' ');
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func


	/// 自由な型で2変数を入力
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void readt2<T1, T2>(out T1 a, out T2 b) {
		string[] s = readsplit();
		a = (T1)GetConverter(typeof(T1)).ConvertFromString(s[0]);
		b = (T2)GetConverter(typeof(T2)).ConvertFromString(s[1]);
	} // end of func

	/// 自由な型で3変数を入力
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void readt3<T1, T2, T3>(out T1 a, out T2 b, out T3 c) {
		string[] s = readsplit();
		a = (T1)GetConverter(typeof(T1)).ConvertFromString(s[0]);
		b = (T2)GetConverter(typeof(T2)).ConvertFromString(s[1]);
		c = (T3)GetConverter(typeof(T3)).ConvertFromString(s[2]);
	} // end of func

	/// 自由な型で4変数を入力
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void readt4<T1, T2, T3, T4>(out T1 a, out T2 b, out T3 c, out T4 d) {
		string[] s = readsplit();
		a = (T1)GetConverter(typeof(T1)).ConvertFromString(s[0]);
		b = (T2)GetConverter(typeof(T2)).ConvertFromString(s[1]);
		c = (T3)GetConverter(typeof(T3)).ConvertFromString(s[2]);
		d = (T4)GetConverter(typeof(T4)).ConvertFromString(s[3]);
	} // end of func

	/// <summary>先頭に要素数(int)と次にでかい数字1つ</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (int, long) readintlongt2() {
		var arr = ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
		return ((int)arr[0], arr[1]);
	} // end of func

	/// <summary>先頭に要素数(int)と次にでかい数字2つ</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (int, long, long) readintlongt3() {
		var arr = ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
		return ((int)arr[0], arr[1], arr[2]);
	} // end of func

	/// <summary>先頭に要素数(int)と次にでかい数字2つ</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (int, long, long, long) readintlongt4() {
		var arr = ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
		return ((int)arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// <summary>小数点以下を16桁で表示(精度が厳しい問題に対応)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeline16<T>(T num) {
		WriteLine(string.Format("{0:0.################}", num));
	} // end of func

	/// <summary>整数を二進数で表示</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeline2bit(int num) {
		WriteLine(Convert.ToString(num, 2));
	} // end of func

	/// <summary>整数を二進数で表示</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeline2bit(long num) {
		WriteLine(Convert.ToString(num, 2));
	} // end of func

	/// <summary>整数を2進数表現した文字列に</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string i2s2bit(int num) {
		return Convert.ToString(num, 2);
	} // end of func

	/// <summary>整数を2進数表現した文字列に</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string l2s2bit(long num) {
		return Convert.ToString(num, 2);
	} // end of func

	/// <summary>出力のflush削除</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void preprocess() {
		var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
		System.Console.SetOut(sw);
	} // end of func

	/// <summary>出力をflush</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void finalprocess() {
		System.Console.Out.Flush();
	} // end of func
} // end of class

/// Dictionayに初期値を与える(RubyのHash.new(0)みたいに)
class HashMap<K, V> : Dictionary<K, V> {
	new public V this[K i] {
		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		get { V v; return TryGetValue(i, out v) ? v : base[i] = default(V); }

		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		set => base[i] = value;
	}
} // end of class

/// Dictionayに初期値を与える(RubyのHash.new(0)みたいに)
class SortedMap<K, V> : SortedDictionary<K, V> {
	new public V this[K i] {
		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		get { V v; return TryGetValue(i, out v) ? v : base[i] = default(V); }

		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		set => base[i] = value;
	}
} // end of class

/// 座標に便利(値型だけど16byteまではstructが速い)
struct YX {
	public int y;
	public int x;
	public YX(int y, int x) {
		this.y = y;
		this.x = x;
	}

	// デバッグ出力
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public override string ToString() => $"y:{y} x:{x}";
} // end of class

/// グラフをするときに(値型だけど16byteまではstructが速い)
struct Edge : IComparable<Edge> {
	public int from;
	public int to;
	public long cost;
	public Edge(int from, int to, long cost = 0) {
		this.from = from;
		this.to = to;
		this.cost = cost;
	}

	/// コスト順にソートできるように
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public int CompareTo(Edge opp) => this.cost.CompareTo(opp.cost);

	/// デバッグ出力用
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public override string ToString() => $"cost:{cost} from:{from} to:{to}";
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

// 通常のセグメント木(範囲検索、1つ更新をlogN)
/// long版、中身の改造は便利
public class SegmentTree {
	/// 一番下の葉の数 (2のべき乗になってるはず)
	public int LeafNum { get; set; }

	/// ノード全体の要素数
	public int Count { get => this.Node.Length; }

	/// 実際に木を構築するノード
	public (long, int)[] Node { get; set; }

	/// 作用素 (TとTに対する演算結果Tを返す min, max, sumなど)
	private Func<(long, int), (long, int), (long, int)> Operator;

	/// モノイドの単位元 (オペレーターの演算に影響を及ぼさない)
	private (long, int) Identity = (0l, 0);

	/// 元配列を渡してセグメントツリーの作成
	/// 初期値はminやmaxなどで変わると思うので与える(デフォルト=0のはず)
	public SegmentTree(Func<(long, int), (long, int), (long, int)> op, long[] arr) {
		// 作用素を保存
		this.Operator = op;


		// ノード数を　2^⌈log2(N)⌉　にする
		this.LeafNum = 1;
		while (this.LeafNum < arr.Length) this.LeafNum <<= 1;

		// 葉の初期化
		this.Node = new (long, int)[this.LeafNum * 2 - 1];
		for (int i = 0; i < this.Count; ++i) this.Node[i] = this.Identity;
		for (int i = 0; i < arr.Length; ++i) this.Node[this.LeafNum - 1 + i] = (arr[i], i);

		// 親ノードの値を決めていく
		for (int i = this.LeafNum - 2; i >= 0; --i) {
			// 左右と比較
			this.Node[i] = this.Operator(this.Node[2 * i + 1], this.Node[2 * i + 2]);
		}
	} // end of constructor

	/// index番目の値をvalueにする
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void Update(int index, long value) {
		// 葉の更新
		index += this.LeafNum - 1;
		this.Node[index] = (value, index);

		// 親の更新
		while (index > 0) {
			index = (index - 1) / 2;
			// 左右と比較
			this.Node[index] = this.Operator(this.Node[2 * index + 1], this.Node[2 * index + 2]);
		}
	} // end of update

	/// [l, r) の区間◯◯値を求める(求まる値はOperatorで指定されてる)
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public (long, int) Query(int l, int r) {
		return this.Query(l, r, 0, 0, this.LeafNum);
	} // end of method

	/// [l, r) は求めたい半開区間
	/// k は現在のノード番号
	/// [a, b) はkに対応する半開区間
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private (long, int) Query(int l, int r, int k, int a, int b) {
		// 現在の対応ノード区間が求めたい区間に含まれないとき
		// → 単位元を返す
		if (r <= a || b <= l) return this.Identity;

		// 現在の対応ノード区間が求めたい区間に完全に含まれるとき
		// → 現在のノードの値を返す
		if (l <= a && b <= r) return this.Node[k];

		// 左半分と右半分で見る
		int m = (a + b) / 2;
		(long, int) leftValue = Query(l, r, k * 2 + 1, a, m);
		(long, int) rightValue = Query(l, r, k * 2 + 2, m, b);
		return this.Operator(leftValue, rightValue);
	} // end of method
} // end of class


/// <summary>AVL木</summary>
public class AVLTree<T> : IEnumerable<T> where T : IComparable<T> {
	/// <summary>AVL木を構成するノード1個分</summary>
	public class Node {
		/// <summary>要素の値</summary>
		public T key;

		public Node left;
		public Node right;
		public Node parent;

		/// <summary>自身をrootとした時の木の高さ</summary>
		public int height;

		/// <summary>同一のkeyの個数</summary>
		public int count;

		/// <summary>自身も含む子要素の数の合計(rootのこの値は木全体のノード数)<br />
		/// childNodeNum-count → このkeyより大きいkeyのノード数の合計</summary>
		public int childNodeNum;

		public Node(T key) {
			this.key = key;
			this.height = 1;
			this.count = 1;
			this.childNodeNum = 1;
		} // end of constructor
	} // end of class

	/// <symmary>木の根、ここから全ノードを辿っていく</summary>
	public Node root;

	/// <summary>比較関数、デフォルトでは小さい順</summary>
	private readonly IComparer<T> comparer;

	public AVLTree(IComparer<T> comparer = null) => this.comparer = comparer ?? Comparer<T>.Default;

	public AVLTree(T[] array, IComparer<T> comparer = null) {
		this.comparer = comparer ?? Comparer<T>.Default;
		for (int i = 0; i < array.Length; ++i) this.Insert(array[i]);
	} // end of constructor

	public AVLTree(List<T> list, IComparer<T> comparer = null) {
		this.comparer = comparer ?? Comparer<T>.Default;
		foreach (T value in list) this.Insert(value);
	} // end of constructor

	// -------------------------------- 挿入 --------------------------------

	/// <summary>ノード挿入(公開用、外部からはこれを呼ぶ)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void Insert(T key) => root = this.Insert(root, key);

	/// <summary>ノード挿入処理、回転した結果を今の注目ノードに置き換える</summary>
	private Node Insert(Node node, T key, Node parent = null) {
		if (node == null) return new Node(key) { parent = parent };

		int compare = this.comparer.Compare(key, node.key);
		// 注目ノードより小さいので左の子に挿入
		if (compare < 0) { node.left = this.Insert(node.left, key, node); }

		// 注目ノードより大きいので右の子に挿入
		else if (compare > 0) { node.right = this.Insert(node.right, key, node); }

		// 注目ノードと同じ(すでにkeyが含まれている)ので個数をカウント
		else {
			node.count += 1;
			node.childNodeNum += 1;

			// 親をたどってchildNodeNumを更新
			Node p = node.parent;
			while (p != null) {
				p.childNodeNum += 1;
				p = p.parent;
			}
		}

		// 左右の子の深い方+1が現在のノードの高さ
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

		int compare = this.comparer.Compare(key, node.key);
		// 注目ノードより小さいので削除は左に流す
		if (compare < 0) {
			node.left = this.Remove(node.left, key);
		}
		// 注目ノードより大きいので削除は右に流す
		else if (compare > 0) {
			node.right = this.Remove(node.right, key);
		}
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
				if (tmp != null) tmp.parent = node.parent;
				// 両方なければ自身を削除、片方あればそれで置き換える
				return tmp;
			}
			// 両方の子がある場合は、右部分木から最小値のノードを探して置き換える
			else {
				var minRight = this.FindMin(node.right);
				node.key = minRight.key;
				node.count = minRight.count;
				node.right = this.Remove(node.right, minRight.key);
				// if (node.right != null) node.right = node;
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

		int compare = this.comparer.Compare(key, node.key);
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
		int compare = this.comparer.Compare(node.key, key);
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

	/// <summary>LowerBoundで検索してIteratorを返す</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public AVLIterator LowerBoundIterator(T key) {
		Node result = null;
		bool found = this.LowerBoundIterator(this.root, key, ref result);
		if (found) return new AVLIterator(result);
		else throw new InvalidOperationException($"{key}以上の値が存在しません");
	} // end of method

	/// <summary>LowerBoundで検索してIteratorを返す</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public AVLIterator LowerBoundIterator(T key, out bool found) {
		Node result = null;
		found = this.LowerBoundIterator(this.root, key, ref result);
		return new AVLIterator(result);
	} // end of method

	/// <summary>LowerBoundでイテレータを返す実装(値の代わりにNodeを返している)</summary>
	private bool LowerBoundIterator(Node node, T key, ref Node result) {
		if (node == null) return false;
		int compare = this.comparer.Compare(node.key, key);
		if (0 <= compare) {
			result = node;
			bool foundInLeft = this.LowerBoundIterator(node.left, key, ref result);
			return true;
		} else {
			return this.LowerBoundIterator(node.right, key, ref result);
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

		int compare = this.comparer.Compare(node.key, key);
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

	/// <summary>key超過の最小値を探してIteratorを返す(存在しなければエラー)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public AVLIterator UpperBoundIterator(T key) {
		Node result = null;
		bool found = this.UpperBoundIterator(this.root, key, ref result);
		if (found) return new AVLIterator(result);
		else throw new InvalidOperationException($"{key}超過の値が存在しません");
	} // end of method

	/// <summary>key超過の最小値を探してIteratorを返す(存在しなければdefault)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public AVLIterator UpperBoundIterator(T key, out bool found) {
		Node result = null;
		found = this.UpperBoundIterator(this.root, key, ref result);
		return new AVLIterator(result);
	} // end of method

	/// <summary>UpperBoundでイテレータを返す実装(値の代わりにNodeを返している)</summary>
	private bool UpperBoundIterator(Node node, T key, ref Node result) {
		if (node == null) return false;
		int compare = this.comparer.Compare(node.key, key);
		if (0 < compare) {
			result = node;
			bool foundInLeft = this.UpperBoundIterator(node.left, key, ref result);
			return true;
		} else {
			return this.UpperBoundIterator(node.right, key, ref result);
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

		int compare = this.comparer.Compare(node.key, key);
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

	/// <summary>key未満の最大要素を探してIteratorを返す(存在しなければエラー)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public AVLIterator FindLessThanMaxIterator(T key) {
		Node result = null;
		bool found = this.FindLessThanMaxIterator(this.root, key, ref result);
		if (found) return new AVLIterator(result);
		else throw new InvalidOperationException($"{key}より小さい要素が存在しません");
	} // end of method

	/// <summary>key未満の最大要素を探してIteratorを返す(存在しなければdefault)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public AVLIterator FindLessThanMaxIterator(T key, out bool found) {
		Node result = null;
		found = this.FindLessThanMaxIterator(this.root, key, ref result);
		return new AVLIterator(result);
	} // end of method

	/// <summary>FindLessThanMaxイテレータを返す実装(値の代わりにNodeを返している)</summary>
	private bool FindLessThanMaxIterator(Node node, T key, ref Node result) {
		if (node == null) return false;
		int compare = this.comparer.Compare(node.key, key);
		if (0 <= compare) return this.FindLessThanMaxIterator(node.left, key, ref result);
		else {
			result = node;
			bool foundInRight = this.FindLessThanMaxIterator(node.right, key, ref result);
			return true;
		}
	} // end of method

	// -------------------------------- 最小値最大値 --------------------------------

	/// <summary>最初の値を返す(基本は最小値)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public T MinValue() => this.FirstValue();

	/// <summary>最初の値を返す(基本は最小値)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public T FirstValue() {
		Node node = this.root;
		while (node.left != null) node = node.left;
		return node.key;
	} // end of method

	/// <summary>最初のノードのイテレータ返す</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public AVLIterator First() {
		Node node = this.root;
		while (node.left != null) node = node.left;
		return new AVLIterator(node);
	} // end of method


	/// <summary>最後の値を返す(基本は最大値)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public T MaxValue() => this.LastValue();

	/// <summary>最後の値を返す(基本は最大値)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public T LastValue() {
		Node node = this.root;
		while (node.right != null) node = node.right;
		return node.key;
	} // end of method

	/// <summary>最後のノードのイテレータを返す</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public AVLIterator Last() {
		Node node = this.root;
		while (node.right != null) node = node.right;
		return new AVLIterator(node);
	} // end of method

	// -------------------------------- 表示 --------------------------------

	/// <summary>中身表示用(公開用、外部からはこれを呼ぶ)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void PrintTree() => this.PrintTree(this.root, "", true);

	/// <summary>整形して中身を表示する</summary>
	private void PrintTree(Node node, String indent, bool last) {
		if (node == null) return;
		string parentKey = node.parent != null ? node.parent.key.ToString() : "null";
		// Console.WriteLine($"{indent}+- {node.key} (Count: {node.count})");
		Console.WriteLine($"{indent}+- {node.key} (Count: {node.count}, Parent: {parentKey})");
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
		Node xparent = x.parent;

		y.left = x;
		y.parent = xparent;
		if (x != null) x.parent = y;

		x.right = t2;
		if (t2 != null) t2.parent = x;

		// 高さ再調整
		x.height = Max(this.GetHeight(x.left), this.GetHeight(x.right)) + 1;
		y.height = Max(this.GetHeight(y.left), this.GetHeight(y.right)) + 1;

		// 子要素の数を更新
		x.childNodeNum = x.count + (x.left != null ? x.left.childNodeNum : 0) + (x.right != null ? x.right.childNodeNum : 0);
		y.childNodeNum = y.count + (y.left != null ? y.left.childNodeNum : 0) + (y.right != null ? y.right.childNodeNum : 0);

		return y;
	} // end of method

	/// <summary>右回転</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private Node RotateRight(Node y) {
		// < この形が     (上がy, 左がx, 下がt2)
		// > この形になる (上がx, 右がy, 下がt2)
		Node x = y.left;
		Node t2 = x.right;
		Node yparent = y.parent;

		x.right = y;
		x.parent = yparent;
		if (y != null) y.parent = x;

		y.left = t2;
		if (t2 != null) t2.parent = y;

		// 高さ再調整
		y.height = Max(this.GetHeight(y.left), this.GetHeight(y.right)) + 1;
		x.height = Max(this.GetHeight(x.left), this.GetHeight(x.right)) + 1;

		// 子要素の数を更新
		x.childNodeNum = x.count + (x.left != null ? x.left.childNodeNum : 0) + (x.right != null ? x.right.childNodeNum : 0);
		y.childNodeNum = y.count + (y.left != null ? y.left.childNodeNum : 0) + (y.right != null ? y.right.childNodeNum : 0);

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


	/// <summary>イテレータを実装するためのクラス</suumary>
	public class AVLIterator {
		/// <summary>現在のイテレータ</summary>
		public Node value { get; private set; }

		public AVLIterator(Node node) => this.value = node;

		/// <summary>次のイテレータを持つか</summary>
		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		public bool HasNext() => GetNextNode(this.value) != null;

		/// <summary>前のイテレータを持つか</summary>
		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		public bool HasPrev() => GetPrevNode(this.value) != null;

		/// <summary>次のイテレータを返す</summary>
		public AVLIterator Next() {
			this.value = GetNextNode(this.value);
			return this;
		} // end of method

		/// <summary>前のイテレータを返す</summary>
		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		public AVLIterator Prev() {
			this.value = GetPrevNode(this.value);
			return this;
		} // end of method

		/// <summary>次のイテレータを取得する</summary>
		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		private Node GetNextNode(Node node) {
			if (node == null) return null;
			if (node.right != null) {
				node = node.right;
				while (node.left != null) node = node.left;
				return node;
			}
			while (node.parent != null && node == node.parent.right) {
				node = node.parent;
			}
			return node.parent;
		} // end of method

		/// <summary>前のイテレータを取得する</summary>
		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		private Node GetPrevNode(Node node) {
			if (node == null) return null;
			if (node.left != null) {
				node = node.left;
				while (node.right != null) node = node.right;
				return node;
			}
			while (node.parent != null && node == node.parent.left) {
				node = node.parent;
			}
			return node.parent;
		} // end of method
	} // end of class
} // end of class


class Kyopuro {
	public static void Main() {
		preprocess();
		var kyopuro = new Kyopuro();
		kyopuro.Solve();
		finalprocess();
	} // end of func

	// モノイドを定義 区間最小、範囲更新
	struct op_max : ILazySegmentTreeOperator<long, long> {
		public long Identity { get => linf; }
		public long FIdentity { get => linf; }
		public long Operate(long a, long b) => Max(a, b);
		public long Mapping(long f, long x) => f;
		public long Composition(long f, long g) => f;
	}


	public void Solve() {
		int n = readint();
		var arr = readlongs();

		var stack = new Stack<(long, int)>();
		var leftarr = new int[n]; // 自分の左側、自分よりも大きくて一番近いやつの場所

		for (int i = 0; i < n; ++i) {

			while (true) {
				if (stack.Count == 0) {
					leftarr[i] = -1;
					stack.Push((arr[i], i));
					break;
				}

				// 左に小さいのがあるときは取り出す
				if (stack.Peek().Item1 <= arr[i]) {
					stack.Pop();
				}

				// 左に大きいのがあるときはそこを記憶して自分をいれて次の要素へ
				else {
					leftarr[i] = stack.Peek().Item2;
					stack.Push((arr[i], i));
					break;
				}
			}

		}

		printlist(leftarr);

		var avl = new AVLTree<int>(leftarr);
		avl.Insert(iinf);

		for (int i = 0; i < n - 1; ++i) {
			avl.Remove(leftarr[i]);

			// 自身以下の値の個数が答えになるはず
			var node = avl.UpperBoundIterator(leftarr[i]);
			node = node.Prev();


		}
	} // end of method
} // end of class
