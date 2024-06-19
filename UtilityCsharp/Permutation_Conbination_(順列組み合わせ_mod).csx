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


class Kyopuro {
	public static void Main() {
		var kyopuro = new Kyopuro();
		kyopuro.Solve();
	} // end of func

	/// a^nを繰り返し二乗法
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public long KurikaeshiPow(long a, long n, long mod = long.MaxValue) {
		if (n == 0) return 1;
		if (n == 1) return a % mod;

		long ret = 1;
		while (n > 0) {
			// a^(2^k) をかけていく k = nを二進数表現したときに1が立っているbit
			if ((n & 1) == 1) ret = (ret * a) % mod;
			n >>= 1;
			a = (a * a) % mod;
		}

		return ret;
	} // end of method

	/// (nume / deno) % mod を計算
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	long ModDiv(long nume, long deno, long mod = 998244353l) {
		return (nume * KurikaeshiPow(deno, mod - 2, mod)) % mod;
	} // end of method

	/// nCkを計算する
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	long nCk(long n, long k, long mod = 998244353l) {
		long nume = 1, deno = 1;
		for (long i = k; i <= n; ++i) nume = (nume * i) % mod;
		for (long i = 2; i <= k; ++i) deno = (deno * i) % mod;
		return ModDiv(nume, deno, mod);
	} // end of method

	/// nPkを計算する
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	long nPk(long n, long k, long mod = 998244353l) {
		long npk = 1;
		for (long i = k; i <= n; ++i) npk = (npk * i) % mod;
		return npk;
	} // end of method


	public void Solve() {

		long n = 5;
		long k = 3;

		long nck = nCk(n, k);
		Console.WriteLine(nck);
		Console.WriteLine(nPk(n, k));
		Console.WriteLine(ModDiv(11, 7));

	} // end of method
} // end of class
