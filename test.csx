using System;
using System.Collections.Generic;

public class Edge {
	public int Source, Destination, Weight;
	public Edge(int source, int destination, int weight) {
		Source = source;
		Destination = destination;
		Weight = weight;
	}
}

public class Graph {
	public int VerticesCount, EdgesCount;
	public List<Edge> Edges;

	public Graph(int verticesCount, int edgesCount) {
		VerticesCount = verticesCount;
		EdgesCount = edgesCount;
		Edges = new List<Edge>();
	}

	public void AddEdge(int source, int destination, int weight) {
		Edges.Add(new Edge(source, destination, weight));
	}

	public void BellmanFord(int source) {
		int[] distances = new int[VerticesCount];
		for (int i = 0; i < VerticesCount; i++)
			distances[i] = int.MaxValue;
		distances[source] = 0;

		for (int i = 1; i < VerticesCount; i++) {
			foreach (Edge edge in Edges) {
				int u = edge.Source;
				int v = edge.Destination;
				int weight = edge.Weight;
				if (distances[u] != int.MaxValue && distances[u] + weight < distances[v])
					distances[v] = distances[u] + weight;
			}
		}

		// 負の閉路が存在するかチェック
		foreach (Edge edge in Edges) {
			int u = edge.Source;
			int v = edge.Destination;
			int weight = edge.Weight;
			if (distances[u] != int.MaxValue && distances[u] + weight < distances[v]) {
				Console.WriteLine("グラフには負の閉路が存在します。");
				return;
			}
		}

		PrintSolution(distances);
	}

	private void PrintSolution(int[] distances) {
		Console.WriteLine("頂点までの最短距離:");
		for (int i = 0; i < VerticesCount; i++)
			Console.WriteLine($"{i}\t {distances[i]}");
	}
}

class Program {
	static void Main(string[] args) {
		int vertices = 5;  // 頂点の数
		int edges = 8;     // 辺の数
		Graph graph = new Graph(vertices, edges);

		graph.AddEdge(0, 1, -1);
		graph.AddEdge(0, 2, 4);
		graph.AddEdge(1, 2, 3);
		graph.AddEdge(1, 3, 2);
		graph.AddEdge(1, 4, 2);
		graph.AddEdge(3, 2, 5);
		graph.AddEdge(3, 1, 1);
		graph.AddEdge(4, 3, -3);

		graph.BellmanFord(0);

	}
}
