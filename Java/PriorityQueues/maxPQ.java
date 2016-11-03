/* --------------------------------------------------------
	Max Prioroty queue implementation using binary heaps
-------------------------------------------------------- */

public class maxPQ<Key extends Comparable<Key>> {

	private Key[] pq;			// binary heap tree
	private int size;				// size of heap pq[1..N]

	/** maxPQ constructor - create a priority queue of initial
	 *	capacity max */
	@SuppressWarnings("unchecked")
	public maxPQ(int capacity) {
		size = 0;
		pq = (Key[]) new Comparable[capacity + 1];
	}

	/**	create a priority queue from the keys in a[] */
	@SuppressWarnings("unchecked")
	public maxPQ(Key[] items) {
		size = items.length;
		pq = (Key[]) new Comparable[size + 1];
		for (int i = 0; i < size; i++) {
			pq[i+1] = items[i];
		}
		buildHeap();
	}

	/** heapifies the complete heap*/
	public void buildHeap() {
		// percolation need to be checked for parents alone
		// the leaf level nodes need not be checked
		// begin from the last parent level
		for (int i = size/2; i > 0; i--) {
			percolate(i);
		}
	}

	/** percolate down the item in order maintain heap property */
	public void percolate(int index) {

		// for storing left and right child
		// for storing index of child to be swapped		
		int childIndex;
		// temporaily store the root index value
		Key temp = pq[index];

		// check if left child (at minimum is present)
		for (; 	index*2 <= size;	// check if children present
		 		index = childIndex, // move down
		 		pq[index] = temp) 	// swap values (move down parent)
		{
			// storing index of left child
			childIndex = index*2;			

			// if right child exists and it is greater than left
			if (childIndex != size && 
				pq[childIndex + 1].compareTo(pq[childIndex]) > 0) {
				// child index to swap is right
				childIndex++;				
			}
			// if the above block does not get executed the
			// child remains as left child

			// else (either left child is greater || there is 
			// no right child)
			// in such a case check if child is greater than parent
			if (pq[childIndex].compareTo(pq[index]) > 0) {				
				pq[index] = pq[childIndex];				
			}			

			// else - if parent is greater than child
			else {
				break;
			}			
		}		
	}

	/** insert a key into the priority queue */
	@SuppressWarnings("unchecked")
	public void insert(Key value) {
		// check if size is at maxCapacity of pq
		if (size == pq.length - 1) {
			Key[] newPQ = (Key[]) new Comparable[pq.length*2 + 1];			
			for (int i = 1; i <= size; i++) {
				newPQ[i] = pq[i];				 
			}
			size++;
			newPQ[size] = value;
			pq = newPQ;
		}
		// if there is space in pq
		else {
			size++;
			pq[size] = value;
		}

		// make sure to heapify
		// percolate up
		int index = size;
		for ( ; 
			(index > 1) && // until root is checked
			(value.compareTo(pq[index/2]) > 0);	// value > parent
			index = index/2) // move to parent
		{
			pq[index] = pq[index/2];
		}
		// place new value at appropriate index
		pq[index] = value;
	}

	/** return the largest key */
	public Key findMax() {
		// check if heap is empty
		if (isEmpty()) {
			System.out.println("Empty heap");
			return null;
		}
		// return top most element in heap
		else {
			return pq[1];
		}
	}

	/** return and remove the largest key */
	public Key removeMax() {
		// check if heap is empty
		if (isEmpty()) {
			System.out.println("Empty heap");
			return null;
		}

		// retrive max item
		Key maxItem = findMax();
		// move last item to root and reduce size
		pq[1] = pq[size];
		size--;
		// heapify - percolate down
		percolate(1);
		return maxItem;
	}
	
	/** returns size of the pq */
	public int size() {
		return size;
	}

	/** returns whether pq is empty or not */
	public boolean isEmpty() {
		return size == 0;
	}

	/** prints the heap array */
	public void print() {
		for (int i = 1; i <= size; i++) {
			System.out.print(pq[i] + " ");
		}
	}
	
	// ------------------------ MAIN ------------------------
	public static void main(String[] args) {
		Integer[] A = new Integer[]{1, 2, 3, 4, 5, 6, 7};
		maxPQ<Integer> p = new maxPQ<Integer>(A);
		p.print();
		System.out.println();
		p.insert(8);
		p.print();
		System.out.println();
		p.insert(7);
		p.print();
		System.out.println();
		p.insert(9);
		p.print();
		System.out.println();
		System.out.println("Max: " + p.findMax());
		System.out.println("Max: " + p.removeMax());
		p.print();
		System.out.println();
	}
}
