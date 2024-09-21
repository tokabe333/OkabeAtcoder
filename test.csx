using System;
using System.Collections.Generic;
using System.Linq;

public class SortedMultiset<T> where T : IComparable<T> {
	private const int BUCKET_RATIO = 50;
	private const int REBUILD_RATIO = 170;
	private List<List<T>> buckets;
	private int size;

	public SortedMultiset(IEnumerable<T> items = null) {
		var a = items?.ToList() ?? new List<T>();
		size = a.Count;
		if (size > 0 && !a.SequenceEqual(a.OrderBy(x => x))) {
			a.Sort();
		}
		Build(a);
	}

	private void Build(List<T> a = null) {
		if (a == null) a = this.ToList();
		int bucketSize = (int)Math.Ceiling(Math.Sqrt(a.Count / (double)BUCKET_RATIO));
		buckets = new List<List<T>>(bucketSize);

		for (int i = 0; i < bucketSize; i++) {
			buckets.Add(a.Skip(a.Count * i / bucketSize).Take(a.Count * (i + 1) / bucketSize - a.Count * i / bucketSize).ToList());
		}
	}

	public IEnumerator<T> GetEnumerator() {
		foreach (var bucket in buckets) {
			foreach (var item in bucket) {
				yield return item;
			}
		}
	}

	public void Add(T x) {
		if (size == 0) {
			buckets = new List<List<T>> { new List<T> { x } };
			size = 1;
			return;
		}

		var (bucket, index) = Position(x);
		bucket.Insert(index, x);
		size++;

		if (bucket.Count > buckets.Count * REBUILD_RATIO) {
			Build();
		}
	}

	public bool Discard(T x) {
		if (size == 0) return false;

		var (bucket, index) = Position(x);
		if (index == bucket.Count || !bucket[index].Equals(x)) return false;

		bucket.RemoveAt(index);
		size--;

		if (bucket.Count == 0) {
			Build();
		}

		return true;
	}

	public int Count => size;

	public T LT(T x) {
		for (int i = buckets.Count - 1; i >= 0; i--) {
			var bucket = buckets[i];
			if (bucket[0].CompareTo(x) < 0) {
				return bucket[BinarySearch(bucket, x) - 1];
			}
		}
		return default;
	}

	public T LE(T x) {
		for (int i = buckets.Count - 1; i >= 0; i--) {
			var bucket = buckets[i];
			if (bucket[0].CompareTo(x) <= 0) {
				return bucket[BinarySearch(bucket, x) - 1];
			}
		}
		return default;
	}

	public T GT(T x) {
		foreach (var bucket in buckets) {
			if (bucket.Last().CompareTo(x) > 0) {
				return bucket[BinarySearch(bucket, x)];
			}
		}
		return default;
	}

	public T GE(T x) {
		foreach (var bucket in buckets) {
			if (bucket.Last().CompareTo(x) >= 0) {
				return bucket[BinarySearch(bucket, x)];
			}
		}
		return default;
	}

	public int Index(T x) {
		int count = 0;
		foreach (var bucket in buckets) {
			if (bucket.Last().CompareTo(x) >= 0) {
				return count + BinarySearch(bucket, x);
			}
			count += bucket.Count;
		}
		return count;
	}

	public int IndexRight(T x) {
		int count = 0;
		foreach (var bucket in buckets) {
			if (bucket.Last().CompareTo(x) > 0) {
				return count + BinarySearch(bucket, x);
			}
			count += bucket.Count;
		}
		return count;
	}

	private (List<T>, int) Position(T x) {
		foreach (var bucket in buckets) {
			if (bucket.Last().CompareTo(x) >= 0) {
				return (bucket, BinarySearch(bucket, x));
			}
		}
		throw new InvalidOperationException("The set is empty.");
	}

	private int BinarySearch(List<T> bucket, T x) {
		return bucket.BinarySearch(x) >= 0 ? bucket.BinarySearch(x) : ~bucket.BinarySearch(x);
	}
}

// 使用例
public static class Program {
	public static void Main() {
		var A = new List<int> { 3, -1, 4, -1, 5, -9, 2, -6, 5, -3, 5, -8 };

		var s = new SortedMultiset<int>(A);
		Console.WriteLine(string.Join(", ", s)); // 内部状態を表示
		s.Add(0);
		s.Discard(-1);

		Console.WriteLine(s.Count); // 値の個数を表示
		Console.WriteLine(s.LT(2)); // 指定値より小さい最大要素を表示
		Console.WriteLine(s.LE(2)); // 指定値以下の最大要素を表示
		Console.WriteLine(s.GT(2)); // 指定値より大きい最小要素を表示
		Console.WriteLine(s.GE(2)); // 指定値以上の最小要素を表示

		Console.WriteLine(s.IndexRight(2)); // 指定値以下の要素の個数を表示
		Console.WriteLine(s.Index(2)); // 指定値未満の要素の個数を表示
	}
}
