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

	/// <summary>自由な型で2変数を入力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void readt2<T1, T2>(out T1 a, out T2 b) {
		string[] s = ReadLine().Split(' ');
		a = (T1)GetConverter(typeof(T1)).ConvertFromString(s[0]);
		b = (T2)GetConverter(typeof(T2)).ConvertFromString(s[1]);
	} // end of func

	/// <summary>自由な型で3変数を入力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void readt3<T1, T2, T3>(out T1 a, out T2 b, out T3 c) {
		string[] s = ReadLine().Split(' ');
		a = (T1)GetConverter(typeof(T1)).ConvertFromString(s[0]);
		b = (T2)GetConverter(typeof(T2)).ConvertFromString(s[1]);
		c = (T3)GetConverter(typeof(T3)).ConvertFromString(s[2]);
	} // end of func

	/// <summary>自由な型で4変数を入力</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void readt4<T1, T2, T3, T4>(out T1 a, out T2 b, out T3 c, out T4 d) {
		string[] s = ReadLine().Split(' ');
		a = (T1)GetConverter(typeof(T1)).ConvertFromString(s[0]);
		b = (T2)GetConverter(typeof(T2)).ConvertFromString(s[1]);
		c = (T3)GetConverter(typeof(T3)).ConvertFromString(s[2]);
		d = (T4)GetConverter(typeof(T4)).ConvertFromString(s[3]);
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

	// -------------------------------- 挿入 --------------------------------

	/// <summary>ノード挿入(公開用、外部からはこれを呼ぶ)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void Insert(T key) => root = this.Insert(root, key);

	/// <summary>ノード挿入処理、回転した結果を今の注目ノードに置き換える</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public Node Insert(Node node, T key) {
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
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
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
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public bool Contains(Node node, T key) {
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
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
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
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
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
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
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
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private void PrintTree(Node node, String indent, bool last) {
		if (node == null) return;
		Console.WriteLine($"{indent}+- {node.key} (Count: {node.count})");
		indent += last ? "   " : "|  ";

		this.PrintTree(node.left, indent, false);
		this.PrintTree(node.right, indent, true);
	} // end of method


	/// <summary>通りがけ順、中間順、inorder tree walk で表示 (左・中・右)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public void PrintTreeInOrder() => this.PrintTreeInOrder(this.root);

	/// <summary>通りがけ順、中間順、inorder tree walk で表示 (左・中・右)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private void PrintTreeInOrder(Node node) {
		if (node == null) return;

		// 左、中、右
		this.PrintTreeInOrder(node.left);
		for (int i = 0; i < node.count; ++i) Console.Write(node.key + " ");
		this.PrintTreeInOrder(node.right);
	} // end of method

	/// <summary>行きがけ順、先行順、preorder tree walk で表示 (中・左・右)</summary>
	public void PrintTreePreOrder() => this.PrintTreePreOrder(this.root);

	/// <summary>行きがけ順、先行順、preorder tree walk で表示 (中・左・右)</summary>
	private void PrintTreePreOrder(Node node) {
		if (node == null) return;

		// 中、左、右		
		for (int i = 0; i < node.count; ++i) Console.Write(node.key + " ");
		this.PrintTreeInOrder(node.left);
		this.PrintTreeInOrder(node.right);
	} // end of method

	// -------------------------------- 内部処理用 (Util) --------------------------------

	/// <summary>ノードの高さを取得</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private int GetHeight(Node node) => node != null ? node.height : 0;

	/// <summary>バランスファクタ(左右の高さの差)を取得、nullなら0</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private int GetBalance(Node node) => node != null ? GetHeight(node.left) - GetHeight(node.right) : 0;

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

		x.height = Max(GetHeight(x.left), GetHeight(x.right)) + 1;
		y.height = Max(GetHeight(y.left), GetHeight(y.right)) + 1;

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

		y.height = Max(GetHeight(y.left), GetHeight(y.right)) + 1;
		x.height = Max(GetHeight(x.left), GetHeight(x.right)) + 1;

		return x;
	} // end of method

	/// <summary>木のバランスを取る</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	private Node Balance(Node node) {
		// 左右差を取得
		int balance = GetBalance(node);

		// 左の子の方が大きい (1, 0, -1)ならば偏りがないので 1超過
		if (balance > 1) {
			// 左の子の右の子が大きい場合 < この形
			// L-R回転になるので先にL回転
			if (GetBalance(node.left) < 0) node.left = RotateLeft(node.left);
			return RotateRight(node);
		}

		// 右の子の方が大きい (1, 0, -1)ならば偏りがないので -1未満
		if (balance < -1) {
			// 右の子の左の子が大きい場合 > この形
			// R-L回転になるので先にR回転
			if (GetBalance(node.right) > 0) node.right = RotateRight(node.right);
			return RotateLeft(node);
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
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
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




class Kyopuro {
	public static void Main() {
		preprocess();
		var kyopuro = new Kyopuro();
		kyopuro.Solve();
		finalprocess();
	} // end of func


	public void Solve() {
		int n = readint();



	} // end of method
} // end of class
