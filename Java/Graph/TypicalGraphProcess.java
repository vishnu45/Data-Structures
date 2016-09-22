/** -------------------------------------------------------
 *	A typical graph processing example
-------------------------------------------------------- */
public class TypicalGraphProcess {

	// Returns the degree of a vertex
	public static int degree(Graph G, int v) {
		int degree = 0;
		for (int w : G.adj(v)) {
			degree++;
		}
		return degree;
	}

	// ----------------------- MAIN -----------------------
	public static void main(String[] args) {

		Graph G1 = new Graph(4);
		G1.addEdge(0, 2);
		G1.addEdge(1, 2);
		G1.addEdge(1, 3);
		G1.addEdge(2, 3);
		System.out.println("Degree of vertices");
		for (int i = 0; i < G1.V(); i++) {
			System.out.println(i + ":" + degree(G1, i));
		}

	}
}