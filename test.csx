using System;

public class AVLTree {
	public class Node {
		public int Value;
		public Node Left, Right;
		public int Height;
		public int Size;  // 部分木のサイズ

		public Node(int value) {
			Value = value;
			Height = 1;
			Size = 1;
		}
	}

	private Node root;

	public int Count => GetSize(root);

	private int GetSize(Node node) {
		return node?.Size ?? 0;
	}

	private int GetHeight(Node node) {
		return node?.Height ?? 0;
	}

	private Node RotateRight(Node y) {
		Node x = y.Left;
		Node T2 = x.Right;

		// 回転
		x.Right = y;
		y.Left = T2;

		// 高さの更新
		y.Height = Math.Max(GetHeight(y.Left), GetHeight(y.Right)) + 1;
		x.Height = Math.Max(GetHeight(x.Left), GetHeight(x.Right)) + 1;

		// サイズの更新
		y.Size = GetSize(y.Left) + GetSize(y.Right) + 1;
		x.Size = GetSize(x.Left) + GetSize(x.Right) + 1;

		return x;
	}

	private Node RotateLeft(Node x) {
		Node y = x.Right;
		Node T2 = y.Left;

		// 回転
		y.Left = x;
		x.Right = T2;

		// 高さの更新
		x.Height = Math.Max(GetHeight(x.Left), GetHeight(x.Right)) + 1;
		y.Height = Math.Max(GetHeight(y.Left), GetHeight(y.Right)) + 1;

		// サイズの更新
		x.Size = GetSize(x.Left) + GetSize(x.Right) + 1;
		y.Size = GetSize(y.Left) + GetSize(y.Right) + 1;

		return y;
	}

	private int GetBalance(Node node) {
		return node == null ? 0 : GetHeight(node.Left) - GetHeight(node.Right);
	}

	public void Insert(int value) {
		root = Insert(root, value);
	}

	private Node Insert(Node node, int value) {
		if (node == null)
			return new Node(value);

		if (value < node.Value)
			node.Left = Insert(node.Left, value);
		else if (value > node.Value)
			node.Right = Insert(node.Right, value);
		else
			return node;

		node.Height = Math.Max(GetHeight(node.Left), GetHeight(node.Right)) + 1;
		node.Size = GetSize(node.Left) + GetSize(node.Right) + 1;

		int balance = GetBalance(node);

		if (balance > 1 && value < node.Left.Value)
			return RotateRight(node);

		if (balance < -1 && value > node.Right.Value)
			return RotateLeft(node);

		if (balance > 1 && value > node.Left.Value) {
			node.Left = RotateLeft(node.Left);
			return RotateRight(node);
		}

		if (balance < -1 && value < node.Right.Value) {
			node.Right = RotateRight(node.Right);
			return RotateLeft(node);
		}

		return node;
	}

	public int CountGreaterThanOrEqual(int x) {
		return CountGreaterThanOrEqual(root, x);
	}

	private int CountGreaterThanOrEqual(Node node, int x) {
		if (node == null)
			return 0;

		if (x == node.Value) {
			// 現在のノードの値がxに一致する場合、右部分木の全ての要素とこのノード自身を含む
			return GetSize(node.Right) + 1;
		} else if (x < node.Value) {
			// xが現在のノードの値より小さい場合、右部分木全体とこのノード自身が条件を満たす
			return GetSize(node.Right) + 1 + CountGreaterThanOrEqual(node.Left, x);
		} else {
			// xが現在のノードの値より大きい場合、左部分木のみを調べる
			return CountGreaterThanOrEqual(node.Right, x);
		}
	}
}

class Program {
	static void Main() {
		AVLTree tree = new AVLTree();
		tree.Insert(10);
		tree.Insert(20);
		tree.Insert(5);
		tree.Insert(6);
		tree.Insert(15);

		Console.WriteLine("Count of elements >= 10: " + tree.CountGreaterThanOrEqual(10)); // 出力: 4
		Console.WriteLine("Count of elements >= 15: " + tree.CountGreaterThanOrEqual(15)); // 出力: 2
		Console.WriteLine("Count of elements >= 7: " + tree.CountGreaterThanOrEqual(7));   // 出力: 4
	}
}
