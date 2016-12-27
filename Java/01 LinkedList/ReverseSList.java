/** -------------------------------------------------------
 *	To reverse nodes in a singly linked list
 ------------------------------------------------------- */

 public class ReverseSList extends SList {

 	/** Constructor to initialize ReverseSList with single value */
 	public ReverseSList(int value) {
 		super(value); 		
 	} 

 	/** To reverse nodes in the list */
 	public void Reverse() {
 		// check if list is empty
 		if (size == 0) {
 			System.out.println("List is empty");
 			return;
 		}

 		// check if list has only one item
 		if (size == 0) {
 			return;
 		}

 		Node currNode = sentinel.next;
 		Node nextNode = currNode.next;
 		Node p;
 		currNode.next = null;
 		while (nextNode != null) {
 			p = nextNode.next;
 			nextNode.next = currNode;
 			currNode = nextNode;
 			nextNode = p; 			
 		}
 		sentinel.next = currNode; 
 		return;
 	}

 	// --------------------	MAIN --------------------------
 	public static void main(String[] args) {
 		// Create the SList
 		ReverseSList S1 = new ReverseSList(1);
 		S1.InsertBack(2);
 		S1.InsertBack(3);
 		S1.InsertBack(4);
 		S1.InsertBack(5);
 		S1.Print(); 		

 		// Testing Reverse()
 		S1.Reverse();
 		S1.Print();
 		S1.DeleteAt(0);
 		S1.Reverse();
 		S1.Print();
 	}
 	
 }