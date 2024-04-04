using System.Collections.Generic;
using System.Linq;

// public static class IListExt {
// 	public static void Deconstruct<T>
// 	(
// 		this IList<T> self,
// 		out T first,
// 		out IList<T> rest
// 	) {
// 		first = self.Count > 0 ? self[0] : default;
// 		rest = self.Skip(1).ToArray();
// 	}

// 	public static void Deconstruct<T>
// 	(
// 		this IList<T> self,
// 		out T first,
// 		out T second,
// 		out IList<T> rest
// 	) {
// 		first = self.Count > 0 ? self[0] : default;
// 		second = self.Count > 1 ? self[1] : default;
// 		rest = self.Skip(2).ToArray();
// 	}

// 	public static void Deconstruct<T>
// 	(
// 		this IList<T> self,
// 		out T first,
// 		out T second,
// 		out T third,
// 		out IList<T> rest
// 	) {
// 		first = self.Count > 0 ? self[0] : default;
// 		second = self.Count > 1 ? self[1] : default;
// 		third = self.Count > 2 ? self[2] : default;
// 		rest = self.Skip(3).ToArray();
// 	}

// 	public static void Deconstruct<T>
// 	(
// 		this IList<T> self,
// 		out T first,
// 		out T second,
// 		out T third,
// 		out T four,
// 		out IList<T> rest
// 	) {
// 		first = self.Count > 0 ? self[0] : default;
// 		second = self.Count > 1 ? self[1] : default;
// 		third = self.Count > 2 ? self[2] : default;
// 		four = self.Count > 3 ? self[3] : default;
// 		rest = self.Skip(4).ToArray();
// 	}
// }

public class Hoge {
	public static void Main() {
		var (a, b, rest) = new[] { 1, 2, 3, 4, 5 };

		Console.WriteLine(a);
		Console.WriteLine(b);
		Console.WriteLine(string.Join(", ", rest));
	}
}