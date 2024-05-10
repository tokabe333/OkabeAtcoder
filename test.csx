#pragma warning disable

using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Runtime.CompilerServices;
using static System.Console;
using static System.Math;
using System.Diagnostics;

class MillerRabin {


}

class Program {
	// 素数判定を行う関数
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public bool IsPrime(long n) {
		if (n <= 1) return false;
		if (n == 2) return true;
		if (n % 2 == 0) return false;

		long s = 0;
		long d = n - 1;

		while (d % 2 == 0) {
			s += 1;
			d >>= 1;
		}

		var arr = new long[] { 2, 325, 9375, 28178, 450775, 9780504, 1795265022 };
		foreach (var a in arr) {
			if (a % n == 0) return true;
			System.Int128 x = KurikaeshiPow(a, d, n);
			if (x == 1) continue;

			long t;
			for (t = 0; t < s; ++t) {
				if (x == n - 1) break;
				x = x * x % n;
			}
			if (t == s) return false;
		}


		return true;
	}

	/// a^nを繰り返し二乗法
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public long KurikaeshiPow(System.Int128 a, System.Int128 n, long m = long.MaxValue) {
		System.Int128 mod = m;
		if (n == 0) return 1;
		if (n == 1) return (long)(a % mod);

		System.Int128 ret = 1;
		while (n > 0) {
			// a^(2^k) をかけていく k = nを二進数表現したときに1が立っているbit
			if ((n & 1) == 1) ret = (ret * a) % mod;
			n >>= 1;
			a = (a * a) % mod;
		}

		return (long)ret;
	} // end of method

	static void Main() {
		int n = int.Parse(Console.ReadLine());
		var arr = Console.ReadLine().Split(' ').Select(x => long.Parse(x)).ToArray();

		var p = new Program();
		foreach (var a in arr) {
			WriteLine(p.IsPrime(a) ? "Yes" : "No");
		}
	}
}