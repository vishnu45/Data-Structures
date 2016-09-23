/** -------------------------------------------------------
 *	Depth first search class implementation
-------------------------------------------------------- */

import java.util.*;
public class DepthFirstPaths {

	// to mark if the vertex was visited
	private boolean[] marked;
	// stores the vertex which led to this vertex
	private int[] edgeTo;
	// starting vertex to perform DFS
	private int S;

	/**
	 *	DFS constructor initializes marked[] and calls dfs()
	 */
	public DepthFirstPaths(Graph G, int S) {
		this.marked = new boolean[G.V()];
		this.edgeTo = new int[G.V()];
		this.S = S;
		dfs(G, this.S);
	}

	/**
	 *	Performs depth first search starting at vertex v
	 */
	private void dfs(Graph G, int v) {
		// mark the current node as visited
		marked[v] = true;
		// go through all the nodes the current node is connected to
		for ( int w : G.adj(v)) {
			// if the node is already visited, ignore
			if (!marked[w]) {
				// go the unvisited node and record the edge from which it was reached
				edgeTo[w] = v;
				// call the dfs on this vertex
				dfs(G, w);	
			}			
		}
	}

	/**
	 *	returns true if the graph starting at source vertex
	 *	(given in constructor) has a path to the requested vertex
	 */
	public boolean hasPathTo(int v) {
		return marked[v];
	}

	/**
	 *	returns the path to the vertex v from the source s
	 */
	public Iterable<Integer> pathTo(int v) {
		// check if there is a path from S to the v
		if (!hasPathTo(v)) return null;

		// return back a stack of all edgeTo vertices
		Stack<Integer> path = new Stack<Integer>();
		int temp = v;
		while (temp != this.S) {			
			path.push(temp);
			temp = edgeTo[temp];
		}
		path.push(this.S);
		return path;
	}

	public boolean marked(int v) { return marked[v]; }
	public int edgeTo(int v) { return edgeTo[v]; }

	// --------------------- MAIN ------------------------
	public static void main(String[] args) {
		Graph G1 = new Graph(13);
		G1.addEdge(0, 5);
		G1.addEdge(4, 3);
		G1.addEdge(0, 1);
		G1.addEdge(9, 12);
		G1.addEdge(6, 4);
		G1.addEdge(5, 4);
		G1.addEdge(0, 2);
		G1.addEdge(11, 12);
		G1.addEdge(9, 10);
		G1.addEdge(0, 6);
		G1.addEdge(7, 8);
		G1.addEdge(9, 11);
		G1.addEdge(5, 3);
		DepthFirstPaths D = new DepthFirstPaths(G1, 0);
		D.dfs(G1, 0);

		// print out all the paths
		for (int v = 0; v < G1.V(); v++) {
			System.out.print(v + ":");			
			for (int w: D.pathTo(v)) {
				if (!w) {
					break;
				}
				System.out.print(w + " <- ");
			}
			System.out.println();
		}

	}

}