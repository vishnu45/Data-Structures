/* --------------------------------------------------------
	Binary Tree Node implementation
-------------------------------------------------------- */
public class BinaryNode {
	String data;
	BinaryNode left;
	BinaryNode right;

	// Binary tree node constructor
	public BinaryNode(String data, BinaryNode l, BinaryNode r) {
		this.data = data;
		this.left = l;
		this.right = r;
	}
}