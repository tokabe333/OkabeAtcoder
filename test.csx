using System;
using System.Collections.Generic;
using System.Diagnostics;
using static System.Console;

class Program {
	static void Main() {

		long n = 998244352;
		long nn = n * n;
		Int128 nnn = (Int128)(n) * n;
		WriteLine(nn * 2);
		WriteLine(nnn * 2);
		WriteLine(long.MaxValue);

	}
}
