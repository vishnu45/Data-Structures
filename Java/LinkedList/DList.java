public class DList {

	private DNode sentinel;
	private int size;

	/** Creates new DList of size 0 */
	public DList() {
		sentinel = new DNode(-1, null, null);
		size = 0;		
	}

	/** Creates new DList of size 1 */
	public DList(int value) {
		sentinel = new DNode(-1, null, null);
		sentinel.next = new DNode(value, null, null);
		sentinel.next.next = sentinel.next;
		sentinel.next.previous = sentinel.next;
		size = 1;
	}

	/** Check if the list is empty */
	public boolean IsEmpty() {

		return (size == 0);
	}

	/** Returns the element at the specified index of the list */
	public DNode Get(int index) {
		// check if list is empty
		if (size == 0) {
			System.out.println("List is empty");
			return null;
		}

		// check if index out of bounds
		if (index < 0 || index >= size) {
			System.out.println("Index out of bounds");
			return null;
		}

		int i = 0;
		DNode p = sentinel.next;
		while (i < index) {
			p = p.next;
			i++;
		}
		return p;
	}

	/** Returns the first element in the list */
	public DNode GetFront() {
		return sentinel;
	}

	/** Returns the element to the end of the list */
	public DNode GetBack() {
		return sentinel;
	}

	/** Returns the size of the list */
	public int Size() {

		return size;
	}

	/** Inserts an element at the front of the list */
	public void InsertFront(int value) {
		// check if list is empty
		if (size == 0) {
			sentinel.next = new DNode(value, null, null);
			sentinel.next.next = sentinel.next;
			sentinel.next.previous = sentinel.next;
			size++;
			return;
		}

		// create the new node
		DNode newNode = new DNode(value, sentinel.next, sentinel.next.previous);
		sentinel.next.previous.next = newNode;
		sentinel.next.previous = newNode;		
		sentinel.next = newNode;
		size++;
		return;
	}

	/** Inserts an element at the end of the list */
	public void InsertBack(int value) {
		// check if list is empty
		if (size == 0) {
			sentinel.next = new DNode(value, null, null);
			sentinel.next.next = sentinel.next;
			sentinel.next.previous = sentinel.next;
			size++;
			return;
		}
		DNode newNode = new DNode(value, sentinel.next, sentinel.next.previous);
		sentinel.next.previous.next = newNode;
		sentinel.next.previous = newNode;
		size++;
		return;
	}

	/** Inserts an element at the specified index in the list */
	public void InsertAt(int value, int index) {

	}

	/** Deletes an item at the given index in the list */
	public void DeleteAt(int index) {

	}

	/** Prints the DList */
	public void Print() {
		// check if list is empty
		if (size == 0) {
			System.out.println("List is empty");
			return;
		}
		DNode p = sentinel.next;
		while (! (p.next.equals(sentinel.next)) ) {
			System.out.print(p.item + " -> ");
			p = p.next;
		}
		System.out.println(p.item + " -> NULL");
		return;
	}


	// --------------------	MAIN --------------------------
	public static void main(String[] args) {
		System.out.println(
				"---------------------"
			+ 	" Starting program execution "
			+ 	"---------------------");

		// Constructor testing ----------------------------
		// Size() testing ---------------------------------
		// IsEmpty() testing ------------------------------
		DList D1 = new DList();
		DList D2 = new DList(5);
		System.out.println("Size of D1: " + D1.Size());
		System.out.println("Size of D2: " + D2.Size());
		if (D1.IsEmpty()) {
			System.out.println("D1 is empty");
		}
		else {
			System.out.println("D1 is not empty");
		}
		if (D2.IsEmpty()) {
			System.out.println("D2 is empty");
		}
		else {
			System.out.println("D2 is not empty");
		}

		System.out.println();
		// InsertFront() testing --------------------------
		// Print() testing
		D1.InsertFront(15);
		D1.InsertFront(13);
		D2.InsertFront(4);
		D1.Print();
		D2.Print();

		System.out.println();
		// InsertBack() testing ---------------------------
		DList D3 = new DList();
		DList D4 = new DList(25);
		D3.InsertBack(2);
		D4.InsertBack(27);
		D4.InsertBack(28);
		D2.InsertBack(6);
		System.out.println("Size of D2: " + D2.Size());
		System.out.println("Size of D3: " + D3.Size());
		System.out.println("Size of D4: " + D4.Size());
		D2.Print();
		D3.Print();
		D4.Print();

		System.out.println();
		// Get() testing ----------------------------------
		System.out.println("Item at index 0: " + D4.Get(0).item);
		System.out.println("Item at index 1: " + D4.Get(1).item);
		System.out.println("Item at index 2: " + D4.Get(2).item);
		System.out.println("Item at index 3: " + D4.Get(3));

	}
}