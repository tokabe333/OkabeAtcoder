using System;
using System.Collections.Generic;
using System.Diagnostics;


class Program {
	static void Main() {
		long linf = (1l << 61) - (1l << 31);
		long ii = -linf;
		Console.WriteLine(linf);
		Console.WriteLine(ii);

	}
}
