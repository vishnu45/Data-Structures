/* --------------------------------------------------------
	Binary Tree implementation
-------------------------------------------------------- */
import java.util.Stack;
import java.util.Queue;
import java.util.LinkedList;
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

	// preorder recursive: root -> left child -> right child
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

	// inorder recursive: left -> root -> right
	public void inOrder(BinaryNode root) {
		if (root != null) {
			inOrder(root.left);
			System.out.print(root.data + " ");
			inOrder(root.right);			
		}
	}

	// inorder iterative: left -> root -> right
	public void inOrderIterative() {
		BinaryNode temp = root;
		Stack<BinaryNode> NodeStack = new Stack<BinaryNode>();

		// continue until stack is empty
		while (true) {
			// continue until 
			while (temp != null) {
				NodeStack.push(temp);
				// traverse to the left child
				temp = temp.left;
			}
			// exit when stack is empty
			if (NodeStack.empty()) {
				break;
			}
			// move to the parent node once the left child is null
			temp = NodeStack.pop();			
			System.out.print(temp.data + " ");
			// traverse to the right child
			temp = temp.right;
		}

	}

	// postorder recursive: left -> right -> root
	public void postOrder(BinaryNode root) {
		if (root != null) {
			postOrder(root.left);
			postOrder(root.right);
			System.out.print(root.data + " ");
		}
	}

	// postorder iterative: left -> right -> root
	// public void postOrderIterative() {
	// 	BinaryNode temp = root;
	// 	BinaryNode current = null;
	// 	Stack<BinaryNode> NodeStack = new Stack<BinaryNode>();

	// 	// continue until stack is empty
	// 	while (true) {
	// 		// traverse until left leaf is reached
	// 		while (temp != null) {
	// 			NodeStack.push(temp);
	// 			temp = temp.left;
	// 		}

	// 		// if right child exists
	// 		if (NodeStack.peek().right != null) {
	// 			temp = NodeStack.peek().right;
	// 			continue;
	// 		}

	// 		// if right child does not exist - print leftmost node
	// 		temp = NodeStack.pop();
	// 		System.out.println(temp.data + " ");
			
	// 		temp = NodeStack.peek().right;
	// 		// if right child present
	// 		if (temp != null) {
	// 			// temp = temp.left;
	// 			continue;
	// 		}

	// 		// if right child not present
	// 		else {
	// 			System.out.print(NodeStack.pop().data);
	// 			temp = NodeStack.peek().right;
	// 		}
	// 	}
	// }

	// level order traversal: print nodes at each level
	public void levelOrder() {
		BinaryNode temp;
		Queue<BinaryNode> NodeQueue = new LinkedList<BinaryNode>();
		NodeQueue.add(root);

		// until there are no nodes in queue
		while (NodeQueue.size() > 0) {
			temp = NodeQueue.remove();
			System.out.print(temp.data + " ");
			// add the left child to the queue (if exists)
			if (temp.left != null) {
				NodeQueue.add(temp.left);
			}
			// add the right child to the queue (if exists)
			if (temp.right != null) {
				NodeQueue.add(temp.right);
			}
		}
	}

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
		System.out.println();
		System.out.println("Inorder traversal (recursive):");
		tree.inOrder(tree.root);
		System.out.println();
		System.out.println("Inorder traversal (iterative):");
		tree.inOrderIterative();
		System.out.println();
		System.out.println("Postorder traversal (recursive):");
		tree.postOrder(tree.root);
		System.out.println();
		System.out.println("Level order traversal:");
		tree.levelOrder();
	}
}
