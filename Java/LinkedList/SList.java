public class SList {

	private Node sentinel;
	private int size;

	/** Creates new SList of size 0 */
	public SList() {
		sentinel = new Node(-1, null);
		size = 0;
		return;
	}

	/** Creates new SList of size 1 */
	public SList(int x) {
		sentinel = new Node(-1, null);
		sentinel.next = new Node(x, null);
		size = 1;
		return;
	}

	/** Check if list is empty */
	public boolean IsEmpty() {

		return size == 0;
	}

	/** Returns the element at the specified index of the list */
	public int Get(int index) {
		// check if list is empty
		if (size == 0) {
			System.out.println("List is empty");
			return -1;
		}

		// check if index out of bounds
		if (index < 0 || index >= size ) {
			System.out.println("Index out of bounds");
			return -1;
		}

		// traverse to the node at the specified index and return value
		Node p = sentinel.next;
		int i = 0;
		while (i < index) {
			p = p.next;
		}
		return p.item;
	}

	/** Returns the first element in the list */
	public Node GetFront() {
		// check if list is empty
		if (size == 0) {
			System.out.println("List is empty");
			return null;
		}

		// return the element at the front
		return sentinel.next;
	}

	/** Returns the last element in the list */
	public Node GetBack() {
		// check if list is empty
		if (size == 0) {
			System.out.println("List is empty");
			return null;
		}
		Node p = sentinel.next;
		while (p.next != null) {
			p = p.next;
		}
		return p;
	}

	/** Inserts an element at the front of the list */
	public void InsertFront(int value) {
		// check if list is empty
		if (size == 0) {
			sentinel.next = new Node(value, null);
			size++;
			return;
		}
		Node newNode = new Node(value, sentinel.next);
		sentinel.next = newNode;
		size++;
		return;
	}

	/** Inserts an element to the end of the list */
	public void InsertBack(int value) {

	}

	/** Retunrs the size of the list */
	public int Size() {

		return size;
	}

	/** Inserts an element at the specified  index */
	public void InsertAt(int x, int value) {

	}

	/** Deletes an item at the given index */
	public void DeleteAt(int index) {

	}

	/** Prints the list */
	public void Print() {
		// check if size is 0
		if (size == 0) {
			System.out.println("List is empty");
			return;
		}
		Node p = sentinel.next;
		while (p != null) {
			System.out.print(p.item + " -> ");
			p = p.next;
		}
		System.out.println("NULL");
		return;
	}

}