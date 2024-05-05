using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Runtime.CompilerServices;

class Program {
	[MethodImpl(MethodImplOptions.AggressiveInlining)]
	public static T[] copyarr<T>(T[] arr) {
		T[] brr = new T[arr.Length];
		Array.Copy(arr, brr, arr.Length);
		return brr;
	} // end of func 

	static void Main(string[] args) {
		const int N = 1000000; // 追加する要素の数

		// SortedSet インスタンスを生成
		SortedSet<int> sortedSet = new SortedSet<int>();

		// ランダムな整数を生成して SortedSet に追加
		Random rand = new Random();
		for (int i = 0; i < N; i++) {
			sortedSet.Add(rand.Next());
		}

		var arr = new int[10000];
		for (int i = 0; i < arr.Length; ++i) arr[i] = rand.Next(100000);

		// ベンチマーク: 要素のランダムなアクセス
		Stopwatch stopwatch = new Stopwatch();
		stopwatch.Start();

		// for (int i = 0; i < N; i++) {
		// 	// int randomIndex = rand.Next(0, sortedSet.Count);
		// 	// int first = sortedSet.First();
		// 	int end = sortedSet.Reverse().First();
		// }
		for (int i = 0; i < 1000000; ++i) {
			// var brr = new List<int>(arr).ToArray();
			var brr = copyarr(arr);
		}

		stopwatch.Stop();
		Console.WriteLine($"SortedSet ベンチマーク: {stopwatch.ElapsedMilliseconds} ミリ秒");
	}


}
