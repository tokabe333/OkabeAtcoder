#pragma warning disable

using System;
using System.Linq;
using System.Collections.Generic;
using System.IO;
using static System.Console;
using static System.Math;

/// 最大公約数を計算 int
public int Gcd(int a, int b) {
	if (a == 1 || b == 1) return 1;
	if (a <= 0 || b <= 0) return 0;

	while (a >= 1 && b >= 1) {
		if (a < b) {
			int c = a;
			a = b;
			b = c;
		}
		a %= b;
	}

	return Max(a, b);
} // end of method

/// 最大公約数を計算 long
public long Gcd(long a, long b) {
	if (a == 1 || b == 1) return 1;
	if (a <= 0 || b <= 0) return 0;

	while (a >= 1 && b >= 1) {
		if (a < b) {
			long c = a;
			a = b;
			b = c;
		}
		a %= b;
	}

	return Max(a, b);
} // end of method

/// 最小公倍数を計算(longにしてるのでintから漏れることはなさそう)
public int Lcm(int a, int b) {
	long ab = a * b;
	ab /= Gcd(a, b);
	return (int)ab;
} // end of method

/// 最小公倍数を計算(128bitにしてるのでlongから漏れることはなさそう)
public long Lcm(long a, long b) {
	Int128 ab = a * b;
	ab /= Gcd(a, b);
	return (long)ab;
} // end of method
