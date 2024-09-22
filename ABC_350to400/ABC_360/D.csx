#pragma warning disable

using System;
using System.IO;
using System.Linq;
using System.Diagnostics;
using System.Collections;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using static System.Console;
using static System.Math;
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

	/// <summary>任意の要素数・初期値の3次元Listを作って初期化する</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
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
			for (int j = 0; j < list[i].Count; ++i) {
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
	public static int readint() {
		return int.Parse(ReadLine());
	} // end of func

	/// <summary>数字を1つlong型で読み込み</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static long readlong() {
		return long.Parse(ReadLine());
	} // end of func

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
	public static void WriteLine16<T>(T num) {
		WriteLine(string.Format("{0:0.################}", num));
	} // end of func

	/// <summary>整数を二進数で表示</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void WriteLine2bit(int num) {
		WriteLine(Convert.ToString(num, 2));
	} // end of func

	/// <summary>整数を二進数で表示</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void WriteLine2bit(long num) {
		WriteLine(Convert.ToString(num, 2));
	} // end of func

	/// <summary>整数を2進数表現した文字列に</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string IntToString2bit(int num) {
		return Convert.ToString(num, 2);
	} // end of func

	/// <summary>整数を2進数表現した文字列に</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string LongToString2bit(long num) {
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
		get {
			V v;
			return TryGetValue(i, out v) ? v : base[i] = default(V);
		}
		set { base[i] = value; }
	}
} // end of class

/// Dictionayに初期値を与える(RubyのHash.new(0)みたいに)
class SortedMap<K, V> : SortedDictionary<K, V> {
	new public V this[K i] {
		get {
			V v;
			return TryGetValue(i, out v) ? v : base[i] = default(V);
		}
		set { base[i] = value; }
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
	public Edge(int from, int to, long cost) {
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

class Kyopuro {
	public static void Main() {
		preprocess();
		var kyopuro = new Kyopuro();
		kyopuro.Solve();
		finalprocess();
	} // end of func

	public void Solve() {
		var (n, t) = readintlongt2();
		string s = read();
		var xrr = readlongs();

		var data = new List<(long, char)>();
		for (int i = 0; i < n; ++i) {
			data.Add((xrr[i], s[i]));
		}
		data.Sort((a, b) => a.Item1.CompareTo(b.Item1));

		var rights = new List<long>();
		var leftavl = new AVLTree<long>();
		var dict = new Dictionary<long, long>();
		long leftcount = 0;
		for (int i = 0; i < n; ++i) {
			if (data[i].Item2 == '0') {
				leftavl.Insert(data[i].Item1);
				dict[data[i].Item1] = leftcount;
				leftcount += 1;
			} else {
				rights.Add(data[i].Item1);
			}
		}

		long ans = 0;
		long l, r, li, ri;
		bool lbret, ltmret;
		foreach (long x in rights) {
			l = leftavl.UpperBound(x, out lbret); // x以上の最小値
			if (lbret == false) continue;
			r = leftavl.FindLessThanMax(x + t + t + 1l, out ltmret);
			if (ltmret == false) continue;
			if (r < x) continue; // 次の0がx+2tよりも大きければx未満のrがひっかかる

			li = dict[l];
			ri = dict[r];
			// writeline($"x:{x} l:{l} r:{r} li:{li} ri:{ri}");
			ans += (ri - li + 1);
		}

		writeline(ans);


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

		/// <summary>自身をrootとする部分木のノード数の合計(rootのこの値は木全体のノード数)<br />
		/// childNodeNum-count → このkeyより大きいkeyのノード数の合計</summary>
		public int childNodeNum;

		public Node(T key) {
			this.key = key;
			this.height = 1;
			this.count = 1;
			this.childNodeNum = 1;
		} // end of constructor

		public override string ToString() => $"key:{this.key} height:{this.height} count:{this.count} childNodeNum:{this.childNodeNum}";
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


	// ---------------------------------------------------------------------
	//                           ↓↓↓ 木構造の構築 ↓↓↓
	// ---------------------------------------------------------------------


	// -------------------------------- 挿入 --------------------------------

	/// <summary>ノード挿入(公開用、外部からはこれを呼ぶ)、numで挿入する個数を指定</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void Insert(T key, int num = 1) => root = this.Insert(root, key, num);

	/// <summary>ノード挿入処理、回転した結果を今の注目ノードに置き換える</summary>
	private Node Insert(Node node, T key, int num, Node parent = null) {
		if (node == null) {
			var newNode = new Node(key) { parent = parent };
			newNode.count = num;
			newNode.childNodeNum = num;
			// 再帰的に親ノードのchildNodeNumを更新(1個増やす)
			var tmp = newNode.parent;
			while (tmp != null) {
				tmp.childNodeNum += num;
				tmp = tmp.parent;
			}

			return newNode;
		}

		int compare = this.comparer.Compare(key, node.key);
		// 注目ノードより小さいので左の子に挿入
		if (compare < 0) { node.left = this.Insert(node.left, key, num, node); }

		// 注目ノードより大きいので右の子に挿入
		else if (compare > 0) { node.right = this.Insert(node.right, key, num, node); }

		// 注目ノードと同じ(すでにkeyが含まれている)ので個数をカウント
		else {
			node.count += num;
			node.childNodeNum += num;

			// 親をたどってchildNodeNumを更新
			this.UpdateChildNodeNums(node.parent);
		}

		// 左右の子の深い方+1が現在のノードの高さ
		node.height = 1 + Max(this.GetHeight(node.left), this.GetHeight(node.right));

		// 高さを揃える
		return this.Balance(node);
	} // end of method

	// -------------------------------- 削除 --------------------------------

	/// <summary>ノード削除(公開用、外部からはこれを呼ぶ)、numで消す個数を指定</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void Remove(T key, int num = 1) => root = this.Remove(root, key, num);


	/// <summary>ノード削除処理、削除した結果を今の注目ノードに置き換える</summary>
	private Node Remove(Node node, T key, int num) {
		if (node == null) return null;

		int compare = this.comparer.Compare(key, node.key);
		// 注目ノードより小さいので削除は左に流す
		if (compare < 0) {
			node.left = this.Remove(node.left, key, num);
		}
		// 注目ノードより大きいので削除は右に流す
		else if (compare > 0) {
			node.right = this.Remove(node.right, key, num);
		}
		// 注目ノードが削除対象
		else {

			// 値が重複しているので個数を減らして終わり
			if (node.count - num >= 1) {
				node.count -= num;
				this.UpdateChildNodeNums(node);
				return node;
			}
			// 値が1つなのでノードを削除する
			// 片方または両方の子がない場合は、子で置き換える(子ノードが高々1子なので)
			if (node.left == null || node.right == null) {
				// 自分の親から根までの要素数を減らす
				var tmp1 = node.parent;
				while (tmp1 != null) {
					tmp1.childNodeNum -= node.count;
					tmp1 = tmp1.parent;
				}

				// 両方なければ自身を削除、片方あればそれで置き換える
				var tmp = node.left != null ? node.left : node.right;
				if (tmp != null) tmp.parent = node.parent;
				return tmp;
			}
			// 両方の子がある場合は、右部分木から最小値のノードを探して置き換える
			else {
				var minRight = this.FindMin(node.right);
				node.key = minRight.key;
				node.count = minRight.count;
				node.right = this.Remove(node.right, minRight.key, minRight.count);
				node.childNodeNum = node.count + (node.left?.childNodeNum ?? 0) + (node.right?.childNodeNum ?? 0);

				this.UpdateChildNodeNums(node.parent);
			}


		}

		// 高さを揃える
		node.height = 1 + Max(this.GetHeight(node.left), this.GetHeight(node.right));
		return this.Balance(node);
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
		x.childNodeNum = x.count + (x.left?.childNodeNum ?? 0) + (x.right?.childNodeNum ?? 0);
		y.childNodeNum = y.count + (y.left?.childNodeNum ?? 0) + (y.right?.childNodeNum ?? 0);

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
		y.childNodeNum = y.count + (y.left?.childNodeNum ?? 0) + (y.right?.childNodeNum ?? 0);
		x.childNodeNum = x.count + (x.left?.childNodeNum ?? 0) + (x.right?.childNodeNum ?? 0);

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

	/// <summary>parentを起点にrootまで(root含む)までのノード全てのchildNodeNumsを更新</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private void UpdateChildNodeNums(Node node) {
		while (node != null) {
			node.childNodeNum = node.count + (node.left?.childNodeNum ?? 0) + (node.right?.childNodeNum ?? 0);
			node = node.parent;
		}
	} // end of method


	// ---------------------------------------------------------------------
	//                          ↓↓↓  木構造の探索 ↓↓↓
	// ---------------------------------------------------------------------


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

	// -------------------------------- CountGreaterThanOrEqual --------------------------------

	/// <summary>ある値X以上のノード数を返す</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public int CountGreaterThanOrEqual(T key) {
		return CountGreaterThanOrEqual(this.root, key);
	} // end of method

	/// <summary>ある値X以上のノード数を返す</summary>
	private int CountGreaterThanOrEqual(Node node, T key) {
		if (node == null) return 0;
		int compare = this.comparer.Compare(key, node.key);

		// 現在のノードと一致するなら、現在のノード + 右部分木のすべてのノード
		if (compare == 0) { return node.count + (node.right?.childNodeNum ?? 0); }

		// keyが現在のノードより小さい場合
		// 現在のノード、右部分木はすべて条件を満たす
		// 左部分木は不明なため再帰的に検索
		else if (compare < 0) {
			int rightTreeNum = node.right?.childNodeNum ?? 0;
			return node.count + rightTreeNum + this.CountGreaterThanOrEqual(node.left, key);
		}

		// keyが現在のノードより大きい場合
		// 右部分木のみを調べる
		else { return this.CountGreaterThanOrEqual(node.right, key); }
	} // end of method

	// -------------------------------- CountGreaterThan --------------------------------

	/// <summary>ある値Xを超えるのノード数を返す</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public int CountGreaterThan(T key) {
		return CountGreaterThan(this.root, key);
	} // end of method

	/// <summary>ある値Xを超えるのノード数を返す</summary>
	private int CountGreaterThan(Node node, T key) {
		if (node == null) return 0;
		int compare = this.comparer.Compare(key, node.key);

		// keyが現在のノードより小さい場合
		// 現在のノード、右部分木はすべて条件を満たす
		// 左部分木は不明なため再帰的に検索
		if (compare < 0) {
			int rightTreeNum = node.right?.childNodeNum ?? 0;
			return node.count + rightTreeNum + this.CountGreaterThan(node.left, key);
		}

		// keyが現在のノードより大きい場合
		// 右部分木のみを調べる
		else { return this.CountGreaterThan(node.right, key); }
	} // end of method

	// -------------------------------- CountLessThanOrEqual --------------------------------

	/// <summary>ある値X以下のノード数を返す</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public int CountLessThanOrEqual(T key) {
		return CountLessThanOrEqual(this.root, key);
	} // end of method

	/// <summary>ある値X以下のノード数を返す</summary>
	private int CountLessThanOrEqual(Node node, T key) {
		if (node == null) return 0;
		int compare = this.comparer.Compare(key, node.key);

		// 現在のノードと一致するなら、現在のノード + 左部分木のすべてのノード
		if (compare == 0) { return node.count + (node.left?.childNodeNum ?? 0); }

		// keyが現在のノードより大きい場合
		// 現在のノード、左部分木はすべて条件を満たす
		// 右部分木は不明なため再帰的に検索
		else if (compare > 0) {
			int leftTreeNum = node.left?.childNodeNum ?? 0;
			return node.count + leftTreeNum + this.CountLessThanOrEqual(node.right, key);
		}

		// keyが現在のノードより小さい場合
		// 左部分木のみを調べる
		else { return this.CountLessThanOrEqual(node.left, key); }
	} // end of method

	// -------------------------------- CountLessThan --------------------------------

	/// <summary>ある値X以上のノード数を返す</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public int CountLessThan(T key) {
		return CountLessThan(this.root, key);
	} // end of method

	/// <summary>ある値X以上のノード数を返す</summary>
	private int CountLessThan(Node node, T key) {
		if (node == null) return 0;
		int compare = this.comparer.Compare(key, node.key);

		// keyが現在のノードより大きい場合
		// 現在のノード、左部分木はすべて条件を満たす
		// 右部分木は不明なため再帰的に検索
		if (compare > 0) {
			int leftTreeNum = node.left?.childNodeNum ?? 0;
			return node.count + leftTreeNum + this.CountLessThan(node.right, key);
		}

		// keyが現在のノードより小さい場合
		// 左部分木のみを調べる
		else { return this.CountLessThan(node.left, key); }
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


	// ---------------------------------------------------------------------
	//                            ↓↓↓ 表示 ↓↓↓
	// ---------------------------------------------------------------------


	/// <summary>中身表示用(公開用、外部からはこれを呼ぶ)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void PrintTree() => this.PrintTree(this.root, "", true);

	/// <summary>整形して中身を表示する</summary>
	private void PrintTree(Node node, String indent, bool last) {
		if (node == null) return;
		string parentKey = node.parent != null ? node.parent.key.ToString() : "null";
		// Console.WriteLine($"{indent}+- {node.key} (Count: {node.count})");
		Console.WriteLine($"{indent}+- {node.key} (Count: {node.count}, ChildNodeNums:{node.childNodeNum} Parent: {parentKey})");
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


	// ---------------------------------------------------------------------
	//                    ↓↓↓ foreach, iterator サポート ↓↓↓
	// ---------------------------------------------------------------------


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

