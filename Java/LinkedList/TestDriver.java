/** Class to test the SList class */
import org.junit.Test;
import static org.junit.Assert.*;

public class TestDriver {

	/** Test to check when a null list is declared */
	@Test
	public static void testListDeclaration() {
		SList S1 = new SList();
		
		// check whether S1 size if zero
		try {
			assertEquals(0, S1.Size());
		} catch(AssertionError e) {
			System.out.println("FAIL - Test #01: Size is not 0");
			return;
		}

		// check whether front is sentinel node with null next		
		try {			
			assertEquals(null, S1.GetFront());
		} catch(AssertionError e) {
			System.out.println("FAIL - Test #01: sentinel next is not null");
			return;
		}
		System.out.println("PASS - Test#01: List declaration");
		return;
	}

	/** Test to check when a list with a single value is created */
	@Test
	public static void testListInstantiation() {
		SList S1 = new SList(5);

		// check whether the first element is as expected
		try {
			assertEquals(5, S1.Get(0));			
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#02: Incorrect item in list."
				+" List instantiation failed");
			return;
		}

		// check whether size is 1
		try {
			assertEquals(1, S1.Size());
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#02: Incorrect size");
			return;
		}

		System.out.println("PASS - Test#02: List instantiation");
	}

	@Test
	/** Test to check the GetFront() function */
	public static void testGetFront() {
		SList S1 = new SList();
		SList S2 = new SList(7);

		// check whether empty list's front is null
		try {
			assertEquals(null, S1.GetFront());
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#03: Empty list size"
				+ " is not null");
			return;
		}

		// check whether correct front element is returned
		try {
			assertEquals(7, S2.GetFront().item);
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#03: Incorrect element returned"
				+ " is not null");
			return;
		}
		System.out.println("PASS - Test#03: GetFront function");
	}

	@Test
	/** To check the IsEmpty function */
	public static void testIsEmpty() {
		SList S1 = new SList();
		SList S2 = new SList(8);

		// check whether empty list is empty
		try {
			assertEquals(true, S1.IsEmpty());
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#04: IsEmpty() incorrect"
			+ " for empty list");
			return;
		}

		// check whether non-empty list is not empty
		try {
			assertEquals(false, S2.IsEmpty());
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#04: IsEmpty() incorrect"
			+ " for non-empty list");
			return;			
		}
		System.out.println("PASS - Test#04: IsEmpty function");	
	}

	/** Test to check the GetBack() function */
	@Test
	public static void testGetBack() {
		SList S1 = new SList();
		SList S2 = new SList(1);

		// check for empty list
		try {
			assertEquals(null, S1.GetBack());
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#05: Last element of empty"
			+ " list incorrect");
			return;
		}

		// check for list with size 1
		try {
			assertEquals(1, S2.GetBack().item);
		} catch(AssertionError e) {
			System.out.println("FAIL - Test#05: Last element of list"
				+ " with size 1 incorrect");
			return;
		}

		// check for list with more than 1 item

		System.out.println("PASS - Test#05: GetBack() function");
	}

	/** Test to check the InsertFront() function */
	@Test
	public static void testInsertFront() {
		// check for empty list
		SList S1 = new SList();
		S1.InsertFront(2);		
		try {
			assertEquals(2, S1.Get(0));			
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#06: Insertion at front into"
			+ " empty list incorrect");
			return;
		}

		// check for non-empty list
		S1.InsertFront(1);
		try {
			assertEquals(1, S1.Get(0));
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#06: Insertion at front of"
			+ " non-empty list incorrect");
			return;
		}
		System.out.println("PASS - Test#06: List insertion at front");
	}

	/** Test to check the InsertBack() function */
	@Test
	public static void testInsertBack() {
		// check for empty list
		SList S1 = new SList();
		S1.InsertBack(1);
		try {
			assertEquals(1, S1.Get(0));			
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#07: Insertion at back of"
			+ " empty list incorrect");
			return;
		}

		// check for non empty list
		S1.InsertBack(2);
		try {
			assertEquals(2, S1.Get(1));
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#07: Insertion at back of"
			+ " non-empty list incorrect");
			return;
		}
		System.out.println("PASS - Test#07: List insertion at back");
	}

	/** Test to check the InsertAt() function */
	@Test
	public static void testInsertAt() {
		// check for empty list
		SList S1 = new SList();
		S1.InsertAt(5, 0);
		try {
			assertEquals(5, S1.Get(0));
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#08: Incorrect insertion"
				+ " of item at index for empty list");
			return;
		}

		// check for non-empty list
		S1.InsertAt(6, 1);
		try {
			assertEquals(6, S1.Get(1));
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#08: Incorrect insertion"
				+ " of item at index for non-empty list");
			return;
		}

		// check for out of bounds
		S1.InsertAt(7, 4);
		try {
			assertEquals(2, S1.Size());
		} catch (AssertionError e) {
			System.out.println("FAIL - Test#08: Incorrect insertion"
				+ " of item for out of bound index");
			return;
		}
		System.out.println("PASS - Test#08: Insert at index");
	}

	/** Test to check the Size() function */

	/** Demo function */
	public static void demo() {
		SList S1 = new SList(3);
		S1.InsertFront(2);
		S1.InsertFront(1);
		S1.Print();
		S1.InsertBack(5);
		S1.InsertBack(6);
		S1.Print();
		S1.InsertAt(0, 0);
		S1.InsertAt(4, 4);
		S1.InsertAt(7, 7);
		S1.InsertAt(7, 10);
		S1.Print();
	}

	public static void main(String[] args) {
		testListDeclaration();
		testListInstantiation();
		testGetFront();
		testIsEmpty();
		testGetBack();
		testInsertFront();
		testInsertBack();
		testInsertAt();

		// demo();
	}
}