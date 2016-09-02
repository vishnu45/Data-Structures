/** -------------------------------------------------------
 * 	To reverse two nodes in a singly linked list
 ------------------------------------------------------- */

public class SwapSList extends SList {

	/** Constructor for creating SwapSList */
	public SwapSList(int value) {
		super(value);
	}

	/** Swaps tow nodes in the list */
	public void Swap(int index1, int index2) {
		// check if list is empty
		if (size == 0) {
			System.out.println("List is empty");
			return;
		}

		// check for index out of bounds
		if ( index1 < 0 || index2 < 0 || 
			index1 >= size || index2 >= size) {
			System.out.println("Index out of bounds");
			return;
		}

		// if both indices are same
		if (index1 == index2) {
			return;
		}
		int start, stop, i = 0;
		Node startNode, startNodePrev, stopNode, stopNodePrev;
		startNode = sentinel.next;
		startNodePrev = sentinel;
		if (index1 > index2) {
			start = index2;
			stop = index1;
		}
		else {
			start = index1;
			stop = index2;
		}
		Node p = sentinel.next;
		while (i < stop-1) {
			if (i == start-1) {				
				startNodePrev = p;
				startNode = p.next;				
			}
			p = p.next;
			i++;
		}
		stopNodePrev = p;
		stopNode = p.next;		
		
		// swap startNode and stopNode
		Node p1 = startNode.next;
		Node p2 = startNode;		
		startNode.next = stopNode.next;
		startNodePrev.next = stopNode;
		stopNode.next = p1;
		stopNodePrev.next = p2;		
		return;
	}

	// --------------------	MAIN --------------------------
	public static void main(String[] args) {
		SwapSList S1 = new SwapSList(1);
		S1.InsertBack(2);
		S1.InsertBack(3);
		S1.InsertBack(4);
		S1.InsertBack(5);
		S1.InsertBack(6);
		S1.Print();

		// in between swap
		System.out.println("Swap-index:1-4");
		S1.Swap(1, 4);
		S1.Print();
		// in between reversed swap
		System.out.println("Swap-index:4-1");
		S1.Swap(4, 1);
		S1.Print();

		// tail swap
		System.out.println("Swap-index:1-5");
		S1.Swap(1, 5);
		S1.Print();
		// head swap
		System.out.println("Swap-index:0-4");
		S1.Swap(0, 4);
		S1.Print();
		System.out.println("Swap-index:0-5");
		S1.Swap(0, 5);
		S1.Print();

		// index out of bounds swap
		System.out.println("Swap-index:0-44");
		S1.Swap(0, 44);
	}
}
