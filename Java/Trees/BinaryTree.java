/* --------------------------------------------------------
	Binary Tree implementation
-------------------------------------------------------- */
import java.util.Stack;
public class BinaryTree {

	public BinaryNode root;	

	// empty binary tree constructor
	public BinaryTree() {
		root = null;		
	}

	// binary tree constructor with data
	public BinaryTree(String item) {
		root = new BinaryNode(item, null, null);
	}

	// preorder traversal: root -> left child -> right child
	public void preOrder(BinaryNode root) {
		// if the current node is null (parent has no children)
		if (root == null) {
			return;
		}
		System.out.print(root.data + " ");
		preOrder(root.left);
		preOrder(root.right);
	}

	// preorder iterative: root -> left -> right
	public void preOrderIterative() {
		BinaryNode temp = root;
		Stack<BinaryNode> NodeStack = new Stack<BinaryNode>(); 

		// continue until stack is empty
		while (true) {
			// until null left is reached
			while (temp!=null) {
				System.out.print(temp.data + " ");
				// push the node onto stack for latter right printing
				NodeStack.push(temp);
				// traverse to left child
				temp = temp.left;
			}
			// when stack is empty (no more nodes in stack)
			if (NodeStack.empty()) {
				break;
			}
			// assign right node to temp (current node and left complete)
			temp = (NodeStack.pop()).right;
		}
	}

	// postorder traversal: 

	// inorder traversal

	// level order traversal

	// ------------------------ MAIN ------------------------
	public static void main(String[] args) {
		BinaryTree tree = new BinaryTree();
		tree.root = new BinaryNode("C", null, null);
		tree.root.left = new BinaryNode("F", null, null);
		tree.root.right = new BinaryNode("H", null, null);
		tree.root.left.left = new BinaryNode("G", null, null);
		tree.root.left.right = new BinaryNode("A", null, null);
		tree.root.left.right.left = new BinaryNode("D", null, null);
		tree.root.left.right.right = new BinaryNode("E", null, null);
		tree.root.right = new BinaryNode("H", null, null);
		tree.root.right.left = new BinaryNode("B", null, null);
		tree.root.right.left.left = new BinaryNode("I", null, null);
		tree.root.right.left.right = new BinaryNode("J", null, null);
		tree.root.right.left.right.left = new BinaryNode("K", null, null);
		System.out.println("Preorder traversal (recursive):");
		tree.preOrder(tree.root);
		System.out.println();
		System.out.println("Preorder traversal (iterative):");
		tree.preOrderIterative();
	}
}
