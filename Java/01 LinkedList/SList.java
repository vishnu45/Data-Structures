/* --------------------------------------------------------
					Singly-Linked List
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
--------------------------------------------------------*/
public class SList {

	public Node sentinel;
	public int size;

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
			i++;
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
		// if list is empty
		if (size == 0) {
			sentinel.next = new Node(value, null);
			size++;
			return;
		}
		Node newNode = new Node(value, null);
		Node p = sentinel.next;
		while (p.next != null) {
			p = p.next;
		}
		p.next = newNode;
		size++;
		return;
	}

	/** Retunrs the size of the list */
	public int Size() {

		return size;
	}

	/** Inserts an element at the specified  index */
	public void InsertAt(int value, int index) {
		if (index < 0 || index > size) {
			System.out.println("Index out of bounds");
			return;
		}
		Node p = sentinel;
		int i = 0;
		while (i < index) {
			p = p.next;
			i++;
		}
		Node newNode = new Node(value, p.next);
		p.next = newNode;
		size++;
		return;
	}

	/** Deletes an item at the given index */
	public void DeleteAt(int index) {
		// check if size is zero
		if (size == 0) {
			System.out.println("List is empty");
			return;
		}
		// check if index is out of bounds
		if (index < 0 || index >= size) {
			System.out.println("Index out of bounds");
			return;
		}
		Node p = sentinel;
		int i = 0;
		while (i < index) {
			p = p.next;
			i++;
		}
		p.next = p.next.next;
		size--;
		return;
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