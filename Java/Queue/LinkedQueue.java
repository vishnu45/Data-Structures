/* --------------------------------------------------------
	Queue implementation using linked nodes
-------------------------------------------------------- */
public class LinkedQueue {

	// Linked Node
	private class Node {
		private int item;
		private Node next;
		public Node(int item, Node next) {
			this.item = item;
			this.next = next;
		}
	}

	private int length;		// length of the queue
	private Node front;		// element at the front of queue
	private Node rear;		// element at the read of queue

	// Create an empty queue
	public LinkedQueue() {
		this.length = 0;
		this.front = null;
		this.rear = null;
	}

	// Enqueue item in the queue
	public void enqueue(int x) {
		// check if queue is empty
		if (length==0) {
			front = new Node(x, null);
			rear = front;
			length++;
			return;
		}
		// if queue is not empty
		Node newNode = new Node(x, null);
		rear.next = newNode;
		rear = newNode;
		length++;
	}

	// Dequeue item from top of queue and returns it
	public int dequeue() {
		// check if queue is empty
		if (length == 0) {
			System.out.println("Empty Queue");
			return 0;
		}
		// if queue is not empty
		int retVal = front.item;
		front = front.next;
		length--;
		return retVal;
	}

	// Returns item from the top of the queue
	public int first() {
		// check if queue is empty
		if (length == 0) {
			System.out.println("Empty Queue");
			return 0;
		}
		// if queue is not empty
		return front.item;
	}

	// Returns size of the queue
	public int size() {
		return length;
	}

	// Check whether queue is empty
	public boolean isEmpty() {
		return length == 0;
	}

	// returns a string representation of the queue
	public String toString() {
		String qStr = "";
		Node temp = front;
		while (temp != null) {
			qStr += temp.item + " -> ";
			temp = temp.next;
		}
		qStr += "END";
		return qStr;
	}

	// ----------------------- MAIN -----------------------
	public static void main(String[] args) {
		LinkedQueue Q = new LinkedQueue();
		System.out.println(Q.isEmpty());
		System.out.println(Q.size());
		System.out.println(Q.first());
		System.out.println(Q.dequeue());
		Q.enqueue(1); Q.enqueue(2); Q.enqueue(3); 
		Q.enqueue(4); Q.enqueue(5);
		System.out.println(Q.toString());
		System.out.println(Q.first());
		System.out.println(Q.dequeue());
		System.out.println(Q.dequeue());
		System.out.println(Q.toString());
	}

} 