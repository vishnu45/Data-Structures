import java.util.*;

/** -------------------------------------------------------
 *	Graph data structure class implementation 
-------------------------------------------------------- */
public class Graph {

	private int V;						// number of vertices
	private int E;						// number of edges
	private LinkedList<Integer>[] adj;	// adjacency list

	/** 
	 *	Constructor which creates a graph with V edges
	 *	[1] Number of edges are initialized
	 *	[2] Adjacency list is initialized
	 */
	public Graph(int V) {
		this.V = V;
		this.E = 0;
		adj = new LinkedList[V];
		for (int i = 0; i < V; i++) {
			adj[i] = new LinkedList<Integer>();
		}
	}

	/**
	 *	Creates an edge to the graph by adding either of the
	 *	vertices to each others' adjacency list
	 */
	public void addEdge(int u, int v) {
	 	adj[u].add(v);
	 	adj[v].add(u);
	 	E++;
	 }

	/**
	 *	Returns an interger iterable (list for the vertex)
	 */
	public Iterable<Integer> adj(int v) {
		return adj[v];
	}

	public int V() { return V; }	// return number of vertices
	public int E() { return E; }	// return number of edges

	// ----------------------- MAIN -----------------------
	public static void main(String[] args) {

		Graph G1 = new Graph(4);
		G1.addEdge(0, 2);
		G1.addEdge(1, 2);
		G1.addEdge(1, 3);
		G1.addEdge(2, 3);

		// print all the edges to each vertex
		for(int i = 0; i < 4; i++) {
			System.out.print(i + ":");
			for (int w : G1.adj(i)) {
				System.out.print(" <- " + w);
			}
			System.out.println();
		}

		
	}
}