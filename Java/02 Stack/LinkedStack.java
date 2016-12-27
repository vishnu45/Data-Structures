/* --------------------------------------------------------
	Stack implementation using linked nodes
	----------------------------------------------
					Time Complexity
	----------------------------------------------
		Average case	|	Worst case
	----------------------------------------------
		Access	: O(n)	|	Access	: O(n)
		Search 	: O(n)	|	Search 	: O(n)
		Insert 	: O(1)	|	Insert 	: O(1)
		Delete	: O(1)	|	Delete 	: O(1)
	----------------------------------------------
			Space complexity : O(n)
-------------------------------------------------------- */
public class LinkedStack {

	private Node top;
	private int length;

	// constructor to create an empty stack
	public LinkedStack() {
		this.top = null;
		this.length = 0;
	}

	// inserts item to the top of the stack
	public void push(int x) {
		Node temp = new Node(x, top);
		top = temp;
		length++;
	}

	// checks whether the stack is empty
	public boolean isEmpty() {
		return length == 0;
	}

	// removes item from the top of the stack and returns it
	public int pop() {
		if (this.isEmpty()) {
			System.out.println("Empty stack");
			return -1;
		}
		Node temp = top.next;
		int value = top.item;
		top = temp;
		length--;
		return value;
	}

	// returns item at the top of the stack
	public int peek() {
		if (isEmpty()) {
			System.out.println("Empty Stack");
			return -1;
		}
		return top.item;
	}

	// returns size of the stack
	public int size() {
		return length;
	}

	// returns the string representation of the stack
	public String toString() {
		if (isEmpty()) {
			return "Empty Stack";
		}
		String S = "";
		Node temp = top;
		while (temp != null) {
			S = S + Integer.toString(temp.item) + "\n";
			temp = temp.next;
		}
		return S;
	}

	// ----------------------- MAIN -----------------------
	public static void main(String[] args) {
		LinkedStack L = new LinkedStack();
		L.push(1); L.push(2); L.push(3); L.push(4); L.push(5);
		System.out.println(L.toString());
		System.out.println(L.pop());
		System.out.println();
		System.out.println(L.toString());
		L.push(6);
		System.out.println(L.peek());
	}
}