using System;
using System.Collections.Generic;
using System.Diagnostics;

class Program {
	static void Main(string[] args) {
		const int N = 1000000; // 追加する要素の数

		// SortedSet インスタンスを生成
		SortedSet<int> sortedSet = new SortedSet<int>();

		// ランダムな整数を生成して SortedSet に追加
		Random rand = new Random();
		for (int i = 0; i < N; i++) {
			sortedSet.Add(rand.Next());
		}

		// ベンチマーク: 要素のランダムなアクセス
		Stopwatch stopwatch = new Stopwatch();
		stopwatch.Start();

		for (int i = 0; i < N; i++) {
			// int randomIndex = rand.Next(0, sortedSet.Count);
			// int first = sortedSet.First();
			int end = sortedSet.Reverse().First();
		}

		stopwatch.Stop();
		Console.WriteLine($"SortedSet ベンチマーク: {stopwatch.ElapsedMilliseconds} ミリ秒");
	}


}
