/* --------------------------------------------------------
	Queue implementation using dynamic array concept
-------------------------------------------------------- */
public class DynamicArrayQueue {

	private int[] qArray;	// array Queue
	private int capacity;	// maximum capacity of the array
	private int length;		// size of the queue
	private static int MAX_CAP = 4;

	// create an empty queue
	public DynamicArrayQueue() {
		this.capacity = MAX_CAP;
		this.qArray = new int[MAX_CAP];
		this.length++;
	}

	// enqueue item in the queue
	public void enqueue(int x) {
		// check if array is maxed out
		if (length == capacity) {
			expand();
		}
		qArray[length] = x;
		length++;
	}

	// expands the array when max capacity is reached
	public void expand() {
		// create a new array of double the size
		capacity *= 2;
		int[] tempArray = new int[capacity];
		System.arraycopy(qArray, 0, tempArray, 0, length);
		qArray = tempArray;
	}

	// dequeue item from top of queue and returns it
	public int dequeue() {
		int retVal = qArray[length-1];
		length--;
		// check if array is too small for current capacity
		if (length < capacity/2) {
			collpase();
		}
		return retVal;
	}

	// collapses the arry to half capcity
	public void collpase() {
		// create a new array of half the length
		capacity /= 2;
		int[] tempArray = new int[capacity];
		System.arraycopy(qArray, 0, tempArray, 0, length);
		qArray = tempArray;	
	}

	// returns item from the top of the queue
	public int first() {
		return qArray[0];		
	}

	// returns size of the queue
	public int size() {
		return length;
	}

	// check whether queue is empty
	public boolean isEmpty() {
		return length == 0;
	}

	// returns a string representation of the queue
	public String toString() {
		String qStr = "";
		for (int i = 0; i < length; i++) {
			qStr += qArray[i] + " -> ";
		}
		qStr += "END";
		return qStr;
	}

	// ----------------------- MAIN -----------------------
	public static void main(String[] args) {
		DynamicArrayQueue DQ = new DynamicArrayQueue();
		DQ.enqueue(1); DQ.enqueue(2); DQ.enqueue(3); 
		DQ.enqueue(4); DQ.enqueue(5); DQ.enqueue(6);
		DQ.enqueue(7); DQ.enqueue(8); DQ.enqueue(9);
		System.out.println(DQ.toString());
		System.out.println(DQ.first());
		DQ.dequeue(); DQ.dequeue(); DQ.dequeue();
		DQ.dequeue(); DQ.dequeue(); DQ.dequeue();
		System.out.println(DQ.dequeue());		
		System.out.println(DQ.toString());
	}

} 