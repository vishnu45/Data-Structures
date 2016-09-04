public class ArrayList {
	public int[] items;
	public int size;
	public int RFACTOR = 2;

	/** Creates an empty list */
	public ArrayList() {
		items = new int[8];
		size = 0;
	}

	/** Resize the new array so that it is of the given capacity */
	private void Resize(int capacity) {

	}

	/** Inserts x at the back of the list */
	public void InsertBack(int x) {
		// check if list is full
		if (size == items.length) {
			Resize(size * RFACTOR);
		}
		items[size] = x;
		size++;
	}

	/** Returns the item from the back of the list */
	public int GetBack() {

		return 0;
	}

	/** Gets the ith item in the list */
	public int Get(int i) {

		return 0;
	}

	/** Deletes item from back of the list and returns
	 *	deleted item */
	public int DeleteBack() {

		return 0;
	}

	/** To print the list */
	public void Print() {
		if (size == 0) {
			System.out.println("List is empty");
			return;
		}
		for (int i = 0; i < size; i++) {
			System.out.println(items[i] + " ");
		}
	}

	// --------------------	MAIN --------------------------
	public static void main(String[] args) {

	}

}