public class ArrayList {
	public int[] items;
	public int size;
	public int RFACTOR = 2;

	/** Creates an empty list */
	public ArrayList() {
		items = new int[5];
		size = 0;
	}

	/** Resize the new array so that it is of the given capacity */
	private void Resize(int capacity) {
		int[] newItems = new int[capacity];
		System.arraycopy(items, 0, newItems, 0, size);
		items = newItems;
	}

	/** Inserts x at the back of the list */
	public void InsertBack(int x) {
		// check if list is full
		if (size == items.length) {
			Resize(size*RFACTOR);
		}
		items[size] = x;
		size++;
	}

	/** Inserts x at the specified index in the list */
	public void InsertAt(int x, int index) {
		// check if index out of bounds
		if (index < 0 || index > size) {
			System.out.println("Index out of bounds");
			return;
		}
		// check if list array full
		if (size+1 == items.length) {
			Resize(size*RFACTOR);			
		}
		int[] a = new int[items.length];
		System.arraycopy(items, 0, a, 0, index);
		a[index] = x;
		System.arraycopy(items, index, a, index+1, size-index);
		items = a;
		size++;		
	} 

	/** Returns the item from the back of the list */
	public int GetBack() {
		// check if list is empty
		if (size == 0) {
			System.out.println("List is empty");
			return -1;
		}
		return items[size-1];
	}

	/** Gets the ith item in the list */
	public int Get(int i) {
		// check if list is empty
		if (size == 0) {
			System.out.println("List is empty");
			return -1;
		}
		// check if index out of bounds
		if (i < 0 || i >= size) {
			System.out.println("Index is out of bounds");
			return -1;
		}
		return items[i];
	}

	/** Deletes item from back of the list and returns
	 *	deleted item */
	public void DeleteBack() {
		// check if list is empty
		if (size == 0) {
			System.out.println("List is empty");
			return;
		}
		size--;
		if (size < items.length/2) {			
			Resize((items.length)/RFACTOR);
		}
	}

	/** To print the list */
	public void Print() {
		if (size == 0) {
			System.out.println("List is empty");
			return;
		}
		for (int i = 0; i < size; i++) {
			System.out.print(items[i] + " ");
		}
		System.out.println();
	}

	// --------------------	MAIN --------------------------
	public static void main(String[] args) {
		ArrayList A1 = new ArrayList();
		
		// InsertBack() testing ---------------------------
		// Resize() testing -------------------------------
		// GetBack() testing ------------------------------
		System.out.println("Back: " + A1.GetBack());
		A1.InsertBack(1);
		A1.InsertBack(2);
		A1.Print();				
		A1.InsertBack(3);
		A1.InsertBack(4);
		A1.InsertBack(6);
		A1.InsertBack(7);
		A1.Print();
		System.out.println("Back: " + A1.GetBack());

		// Get() ------------------------------------------
		System.out.println("Item[0]: " + A1.Get(0));
		System.out.println("Item[4]: " + A1.Get(4));
		System.out.println("Item[5]: " + A1.Get(5));

		// InsertAt() testing -----------------------------
		A1.InsertAt(5, 4);
		A1.Print();
		A1.InsertAt(0, 0);
		A1.Print();
		A1.InsertAt(8, 8);
		A1.Print();

		// DeleteBack() testing ---------------------------
		A1.DeleteBack();		
		A1.DeleteBack();
		A1.DeleteBack();
		A1.Print();
		A1.DeleteBack();		
		A1.DeleteBack();		
		A1.DeleteBack();
		A1.DeleteBack();
		A1.DeleteBack();
		A1.Print();
		A1.DeleteBack();
		A1.DeleteBack();		
	}

}