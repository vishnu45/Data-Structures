/** -------------------------------------------------------
 *	Breadth first search class implementation
-------------------------------------------------------- */

import java.util.*;
public class BreadthFirstPaths {

	// to mark if the vertex was visited
	private boolean[] marked;
	// stores the vertex which led to this vertex
	private int[] edgeTo;
	// starting vertex to perform DFS
	private int S;

	/**
	 *	DFS constructor initializes marked[] and calls dfs()
	 */
	public BreadthFirstPaths(Graph G, int S) {
		this.marked = new boolean[G.V()];
		this.edgeTo = new int[G.V()];
		this.S = S;
		bfs(G, S);
	}


	/**
	 *	Performs depth first search starting at vertex v
	 */
	public void bfs(Graph G, int v) {
		// mark source vertex as visited
		marked[v] = true;
		PriorityQueue<Integer> pq = new PriorityQueue<Integer>();
		pq.add(v);

		// go through all vertices until pq is empty
		while (!pq.isEmpty()) {
			// remove vertex stored in front of queue
			int top = pq.poll();
			// go through all vertices connected to v
			for (int w : G.adj(top)) {
				if (!marked[w]) {
					// visit the node and mark them as visited
					edgeTo[w] = top;
					marked[w] = true;
					// add to the queue
					pq.add(w);
				}
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
		
		Stack<Integer> path = new Stack<Integer>();
		// using edgeTo iterate back to the starting position
		for (int i = v; i != edgeTo[i]; i = edgeTo[i]) {
			path.push(i);
		}
		path.push(this.S);
		return path;
	}




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
		BreadthFirstPaths D = new BreadthFirstPaths(G1, 0);		

		// print out all the paths
		for (int v = 0; v < G1.V(); v++) {
			if (!D.hasPathTo(v)) {
				break;
			}
			System.out.print(v + ": ");			
			for (int w: D.pathTo(v)) {				
				System.out.print(w + " <- ");
			}
			System.out.println();
		}

	}

}