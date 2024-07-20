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

	/// <summary>1?s??????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string read() => ReadLine();

	/// <summary>1?s??????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string readln() => ReadLine();

	/// <summary>1?s??????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string readline() => ReadLine();

	/// <summary>???s????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void write() => Write("");

	/// <summary>???s????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void write<T>(T value) => Write(value);

	/// <summary>???s????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeln() => WriteLine("");

	/// <summary>???s????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeln<T>(T value) => WriteLine(value);

	/// <summary>???s????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeline() => WriteLine("");

	/// <summary>???s????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeline<T>(T value) => WriteLine(value);

	/// <summary>???s????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void print() => Write("");

	/// <summary>???s????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void print<T>(T value) => Write(value);

	/// <summary>???s????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void println() => WriteLine("");

	/// <summary>???s????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void println<T>(T value) => WriteLine(value);

	/// <summary>???s????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printline() => WriteLine("");

	/// <summary>???s????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printline<T>(T value) => WriteLine(value);

	/// <summary>?C???v?f???E?????l??z?????????????????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static T[] makearr<T>(int num, T value) {
		var arr = new T[num];
		for (int i = 0; i < num; ++i) arr[i] = value;
		return arr;
	} // end of func

	/// <summary>?C???v?f???E?????l??Q?????z?????????????????</summary>
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

	/// <summary>?C???v?f???E?????l??3?????z?????????????????</summary>
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

	/// <summary>?C???v?f???E?????l??List????????????????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static List<T> makelist<T>(int num, T value) {
		return new List<T>(makearr(num, value));
	} // end of func

	/// <summary>?C???v?f???E?????l??2????List????????????????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static List<List<T>> makelist2<T>(int height, int width, T value) {
		var arr = new List<List<T>>();
		for (int i = 0; i < height; ++i) {
			arr.Add(makelist(width, value));
		}
		return arr;
	} // end of func

	/// ?C???v?f???E?????l??3????List????????????????
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

	/// <summary>1?????z???f?B?[?v?R?s?[???s??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static T[] copyarr<T>(T[] arr) {
		T[] brr = new T[arr.Length];
		Array.Copy(arr, brr, arr.Length);
		return brr;
	} // end of func 

	/// <summary>2?????z???f?B?[?v?R?s?[???s??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static T[][] copyarr2<T>(T[][] arr) {
		T[][] brr = new T[arr.Length][];
		for (int i = 0; i < arr.Length; ++i) {
			brr[i] = new T[arr[i].Length];
			Array.Copy(arr[i], brr[i], arr[i].Length);
		}
		return brr;
	} // end of func

	/// <summary>3?????z???f?B?[?v?R?s?[???s??</summary>
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

	/// <summary>1????List??f?B?[?v?R?s?[???s??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static List<T> copylist<T>(List<T> list) {
		return new List<T>(list);
	} // end of func

	/// <summary>2????List??f?B?[?v?R?s?[???s??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static List<List<T>> copylist2<T>(List<List<T>> list) {
		List<List<T>> list2 = new List<List<T>>();
		for (int i = 0; i < list.Count; ++i) {
			list2.Add(new List<T>(list[i]));
		}
		return list2;
	} // end of func

	/// <summary>3????List??f?B?[?v?R?s?[???s??</summary>
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

	/// <summary>1????List???o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printlist<T>(List<T> list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// <summary>1?????z????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printlist<T>(T[] list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// <summary>2???????X?g???o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printlist2<T>(List<List<T>> list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func

	/// <summary>2?????z????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printlist2<T>(T[][] list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func	

	/// <summary>1????List???o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printarr<T>(List<T> list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// <summary>1?????z????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printarr<T>(T[] list) {
		WriteLine(string.Join(" ", list));
	} // end of func

	/// <summary>2???????X?g???o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printarr2<T>(List<List<T>> list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func

	/// <summary>2?????z????o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printarr2<T>(T[][] list) {
		foreach (var l in list) {
			WriteLine(string.Join(" ", l));
		}
	} // end of func

	/// <summary>?W?F?l???b?N???o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printiter<T>(IEnumerable<T> generic) {
		foreach (var it in generic) {
			Write(it + " ");
		}
		WriteLine();
	} // end of func

	/// <summary>?W?F?l???b?N???o??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void printlineiter<T>(IEnumerable<T> generic) {
		foreach (var it in generic) {
			WriteLine(it + " ");
		}
	} // end of func

	/// <summary>??????1??int?^???????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static int readint() {
		return int.Parse(ReadLine());
	} // end of func

	/// <summary>??????1??long?^???????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static long readlong() {
		return long.Parse(ReadLine());
	} // end of func

	/// <summary>???????????string????(????I????????)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string[] readsplit() {
		return ReadLine().Split(' ');
	} // end of func

	/// <summary>???????X?y?[?X?????int?^?????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static int[] readints() {
		return ReadLine().Split(' ').Select(_ => int.Parse(_)).ToArray();
	} // end of func

	/// <summary>???????X?y?[?X?????long?^?????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static long[] readlongs() {
		return ReadLine().Split(' ').Select(_ => long.Parse(_)).ToArray();
	} // end of func

	/// <summary>???????X?y?[?X?????float?^?????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static float[] readfloats() {
		return ReadLine().Split(' ').Select(_ => float.Parse(_)).ToArray();
	} // end of func

	/// <summary>???????X?y?[?X?????double?^?????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static double[] readdoubles() {
		return ReadLine().Split(' ').Select(_ => double.Parse(_)).ToArray();
	} // end of func

	/// <summary>????????X?y?[?X????????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string[] readstrings() {
		return ReadLine().Split(' ');
	} // end of func

	/// <summary>??????int2????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (int, int) readintt2() {
		var arr = readints();
		return (arr[0], arr[1]);
	} // end of func

	/// <summary>??????int3????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (int, int, int) readintt3() {
		var arr = readints();
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// <summary>??????int4????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (int, int, int, int) readintt4() {
		var arr = readints();
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// <summary>??????long2????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (long, long) readlongt2() {
		var arr = readlongs();
		return (arr[0], arr[1]);
	} // end of func

	/// <summary>???????long3????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (long, long, long) readlongt3() {
		var arr = readlongs();
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// <summary>???????long4????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (long, long, long, long) readlongt4() {
		var arr = readlongs();
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// <summary>??????float2????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (float, float) readfloatt2() {
		var arr = readfloats();
		return (arr[0], arr[1]);
	} // end of func

	/// <summary>??????float3????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (float, float, float) readfloatt3() {
		var arr = readfloats();
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// <summary>??????float4????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (float, float, float, float) readfloatt4() {
		var arr = readfloats();
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// <summary>??????double2????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (double, double) readdoublet2() {
		var arr = readdoubles();
		return (arr[0], arr[1]);
	} // end of func

	/// <summary>??????double3????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (double, double, double) readdoublet3() {
		var arr = readdoubles();
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// <summary>??????double4????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (double, double, double, double) readdoublet4() {
		var arr = readdoubles();
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// <summary>??????string2????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (string, string) readstringt2() {
		var arr = ReadLine().Split(' ');
		return (arr[0], arr[1]);
	} // end of func

	/// <summary>??????string3????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (string, string, string) readstringt3() {
		var arr = ReadLine().Split(' ');
		return (arr[0], arr[1], arr[2]);
	} // end of func

	/// <summary>??????string3????^?v??????(???????p)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (string, string, string, string) readstringt4() {
		var arr = ReadLine().Split(' ');
		return (arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// <summary>????v?f??(int)?????????????1??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (int, long) readintlongt2() {
		var arr = ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
		return ((int)arr[0], arr[1]);
	} // end of func

	/// <summary>????v?f??(int)?????????????2??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (int, long, long) readintlongt3() {
		var arr = ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
		return ((int)arr[0], arr[1], arr[2]);
	} // end of func

	/// <summary>????v?f??(int)?????????????2??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static (int, long, long, long) readintlongt4() {
		var arr = ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();
		return ((int)arr[0], arr[1], arr[2], arr[3]);
	} // end of func

	/// <summary>?????_?????16????\??(???x??????????????)</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeline16<T>(T num) {
		WriteLine(string.Format("{0:0.################}", num));
	} // end of func

	/// <summary>???????i????\??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeline2bit(int num) {
		WriteLine(Convert.ToString(num, 2));
	} // end of func

	/// <summary>???????i????\??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void writeline2bit(long num) {
		WriteLine(Convert.ToString(num, 2));
	} // end of func

	/// <summary>??????2?i???\?????????????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string i2s2bit(int num) {
		return Convert.ToString(num, 2);
	} // end of func

	/// <summary>??????2?i???\?????????????</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static string l2s2bit(long num) {
		return Convert.ToString(num, 2);
	} // end of func

	/// <summary>?o???flush??</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void preprocess() {
		var sw = new StreamWriter(Console.OpenStandardOutput()) { AutoFlush = false };
		System.Console.SetOut(sw);
	} // end of func

	/// <summary>?o???flush</summary>
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static void finalprocess() {
		System.Console.Out.Flush();
	} // end of func
} // end of class

/// Dictionay??????l??^????(Ruby??Hash.new(0)???????)
class HashMap<K, V> : Dictionary<K, V> {
	new public V this[K i] {
		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		get { V v; return TryGetValue(i, out v) ? v : base[i] = default(V); }

		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		set => base[i] = value;
	}
} // end of class

/// Dictionay??????l??^????(Ruby??Hash.new(0)???????)
class SortedMap<K, V> : SortedDictionary<K, V> {
	new public V this[K i] {
		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		get { V v; return TryGetValue(i, out v) ? v : base[i] = default(V); }

		[MethodImpl(MethodImplOptions.AggressiveInlining)]
		set => base[i] = value;
	}
} // end of class

/// ???W????(?l?^??????16byte????struct??????)
struct YX {
	public int y;
	public int x;
	public YX(int y, int x) {
		this.y = y;
		this.x = x;
	}

	// ?f?o?b?O?o??
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public override string ToString() => $"y:{y} x:{x}";
} // end of class

/// ?O???t??????????(?l?^??????16byte????struct??????)
struct Edge : IComparable<Edge> {
	public int from;
	public int to;
	public long cost;
	public Edge(int from, int to, long cost = 0) {
		this.from = from;
		this.to = to;
		this.cost = cost;
	}

	/// ?R?X?g????\?[?g????????
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public int CompareTo(Edge opp) => this.cost.CompareTo(opp.cost);

	/// ?f?o?b?O?o??p
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
		var num = new List<Int128>(new Int128[] { 10, 9 });
		for (int i = 1; i < 20; ++i) {
			num.Add((Int128)Math.Pow(10, i) * 9);
			num.Add((Int128)Math.Pow(10, i) * 9);
		}
		printlist(num);

		var prefix = new Int128[num.Count];
		prefix[0] = num[0];
		for (int i = 1; i < prefix.Length; ++i) prefix[i] = num[i] + prefix[i - 1];
		printlist(prefix);

		Int128 n = Int128.Parse(read());


	} // end of method
} // end of class
