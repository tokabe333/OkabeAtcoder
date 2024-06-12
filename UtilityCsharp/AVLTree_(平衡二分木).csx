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

public class AVLTree<T> where T : IComparable<T> {
	public class Node {
		public T key { get; set; }
		public Node left { get; set; }
		public Node right { get; set; }
		public int height { get; set; }

		public Node(T key) {
			this.key = key;
			this.height = 1;
		} // end of constructor
	} // end of class
}

class Kyopuro {
	public static void Main() {
		var kyopuro = new Kyopuro();
		kyopuro.Solve();
	} // end of func

	public void Solve() {


	} // end of method
} // end of class
