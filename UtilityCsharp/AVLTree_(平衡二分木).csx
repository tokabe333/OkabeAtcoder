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

/// <summary>AVL木</summary>
public class AVLTree<T> where T : IComparable<T> {
	/// <summary>AVL木を構成するノード1個分</summary>
	public class Node {
		public T key { get; set; }
		public Node left { get; set; }
		public Node right { get; set; }
		public int height { get; set; }
		public int count { get; set; }

		public Node(T key) {
			this.key = key;
			this.height = 1;
			this.count = 1;
		} // end of constructor
	} // end of class

	public Node root;

	/// <summary>ノード挿入(公開用、外部からはこれを呼ぶ)</summary>
	public void Insert(T key) => root = this.Insert(root, key);

	/// <summary>ノード挿入処理、回転した結果を今の注目ノードに置き換える</summary>
	public Node Insert(Node node, T key) {
		if (node == null) return new Node(key);

		int compare = key.CompareTo(node.key);
		// 注目ノードより小さいので左の子に挿入
		if (compare < 0) node.left = this.Insert(node.left, key);

		// 注目ノードより大きいので右の子に挿入
		else if (compare > 0) node.right = this.Insert(node.right, key);

		// 注目ノードと同じ(すでにkeyが含まれている)ので個数をカウント
		else node.count += 1;

		// 左右の個の深い方+1が現在のノードの高さ
		node.height = 1 + Max(this.GetHeight(node.left), this.GetHeight(node.right));

		// 高さを揃える
		return this.Balance(node);
	} // end of method

	/// <summary>ノード削除(公開用、外部からはこれを呼ぶ)</summary>
	public void Remove(T key) => root = this.Remove(root, key);


	/// <summary>ノード削除処理、削除した結果を今の注目ノードに置き換える</summary>
	private Node Remove(Node node, T key) {
		if (node == null) return null;

		int compare = key.CompareTo(node.key);
		// 注目ノードより小さいので削除は左に流す
		if (compare < 0) node.left = this.Remove(node.left, key);

		// 注目ノードより大きいので削除は右に流す
		else if (compare > 0) node.right = this.Remove(node.right, key);

		// 注目ノードが削除対象
		else {
			// 値が重複しているので個数を減らして終わり
			if (node.count > 1) {
				node.count -= 1;
				return node;
			}

			// 値が1つなのでノードを削除する

			// 片方または両方の子がない場合は、子で置き換える(子ノードが高々1子なので)
			if (node.left == null || node.right == null) {
				var tmp = node.left != null ? node.left : node.right;
				// 両方なければ自身を削除、片方あればそれで置き換える
				return tmp;
			}

			// 両方の子がある場合は、右部分木から最小値のノードを探して置き換える
			else {
				var minRight = this.FindMin(node.right);
				node.key = minRight.key;
				node.count = minRight.count;
				node.right = this.Remove(node.right, minRight.key);
			}
		}

		// 高さを揃える
		node.height = 1 + Max(this.GetHeight(node.left), this.GetHeight(node.right));
		return this.Balance(node);
	} // end of method


	/// <summary>中身表示用(公開用、外部からはこれを呼ぶ)</summary>
	public bool Contains(T key) => this.Contains(this.root, key);

	/// <summary>再帰的に検索対象を探す</summary>
	public bool Contains(Node node, T key) {
		if (node == null) return false;

		int compare = key.CompareTo(node.key);
		if (compare == 0) return true;
		else if (compare < 0) return this.Contains(node.left, key);
		else return this.Contains(node.right, key);
	} // end of method


	/// <summary>中身表示用(公開用、外部からはこれを呼ぶ)</summary>
	public void PrintTree() => this.PrintTree(this.root, "", true);

	/// <summary>整形して中身を表示する</summary>
	private void PrintTree(Node node, String indent, bool last) {
		if (node == null) return;
		Console.WriteLine($"{indent}+- {node.key} (Count: {node.count})");
		indent += last ? "   " : "|  ";

		this.PrintTree(node.left, indent, false);
		this.PrintTree(node.right, indent, true);
	} // end of method

	// -------------------------------- 内部処理用 (Util)--------------------------------

	/// <summary>ノードの高さを取得</summary>
	private int GetHeight(Node node) => node != null ? node.height : 0;

	/// <summary>バランスファクタ(左右の高さの差)を取得、nullなら0</summary>
	private int GetBalance(Node node) => node != null ? GetHeight(node.left) - GetHeight(node.right) : 0;

	/// <summary>指定されたノード以下の部分木から最小値のノードを返す
	private Node FindMin(Node node) {
		while (node.left != null) node = node.left;
		return node;
	} // end of method

	/// <summary>右回転</summary>
	private Node RotateRight(Node y) {
		// < この形が     (上がy, 左がx, 下がt2)
		// > この形になる (上がx, 右がy, 下がt2)
		Node x = y.left;
		Node t2 = x.right;

		x.right = y;
		y.left = t2;

		y.height = Max(GetHeight(y.left), GetHeight(y.right)) + 1;
		x.height = Max(GetHeight(x.left), GetHeight(x.right)) + 1;

		return x;
	} // end of method

	/// <summary>木のバランスを取る</summary>
	private Node Balance(Node node) {
		// 左右差を取得
		int balance = GetBalance(node);

		// 左の子の方が大きい (1, 0, -1)ならば偏りがないので 1超過
		if (balance > 1) {
			// 左の子の右の子が大きい場合 < この形
			// L-R回転になるので先にL回転
			if (GetBalance(node.left) < 0) node.left = RotateLeft(node.left);
			return RotateRight(node);
		}

		// 右の子の方が大きい (1, 0, -1)ならば偏りがないので -1未満
		if (balance < -1) {
			// 右の子の左の子が大きい場合 > この形
			// R-L回転になるので先にR回転
			if (GetBalance(node.right) > 0) node.right = RotateRight(node.right);
			return RotateLeft(node);
		}

		return node;
	} // end of method

	/// <summary>左回転</summary>
	private Node RotateLeft(Node x) {
		// > この形が     (上がx, 右がy, 下がt2)
		// < この形になる (上がy, 左がx, 下がt2)
		Node y = x.right;
		Node t2 = y.left;

		y.left = x;
		x.right = t2;

		x.height = Max(GetHeight(x.left), GetHeight(x.right)) + 1;
		y.height = Max(GetHeight(y.left), GetHeight(y.right)) + 1;

		return y;
	} // end of method
} // end of class

class Kyopuro {
	public static void Main() {
		var kyopuro = new Kyopuro();
		kyopuro.Solve();
	} // end of func

	public void Solve() {

		AVLTree<int> tree = new AVLTree<int>();

		tree.Insert(10);
		tree.Insert(20);
		tree.Insert(10); // 重複
		tree.Insert(30);
		tree.Insert(20); // 重複
		tree.Insert(40);
		tree.Insert(50);
		tree.Insert(25);

		tree.PrintTree();

		Console.WriteLine("Search 30: " + tree.Contains(30));
		Console.WriteLine("Search 60: " + tree.Contains(60));
		Console.WriteLine("Search 20: " + tree.Contains(20));
		Console.WriteLine("Search 10: " + tree.Contains(10));
	} // end of method
} // end of class
