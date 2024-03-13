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

void WriteLine16<T>(T num) {
	WriteLine(string.Format("{0:0.################ }", num));
}

void Main() {
	double a = 1 / 7.0 * 334;
	double b = 1 / 7.0;
	WriteLine16(a);
	WriteLine16(b);
}

Main();

