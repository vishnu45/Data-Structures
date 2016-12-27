/* --------------------------------------------------------
	HashMap implementation using separate chaining
	----------------------------------------------
					Time Complexity
	----------------------------------------------
		Average case	|		Worst case
	----------------------------------------------
		Search 	: O(1)	|	Search 	: O(n)
		Insert 	: O(1)	|	Insert 	: O(n)
		Delete	: O(1)	|	Delete 	: O(n)
	----------------------------------------------
			Space complexity : O(n)
-------------------------------------------------------- */
import java.util.ArrayList;
public class HashMap<K, V> {

	// list of linked hash nodes
	private ArrayList<HashNode<K, V>> bucketArray;

	// initial hash map capacity
	private int numBuckets;

	// current number of buckets occupied
	private int size;

	// Hashmap initialization
	public HashMap() {
		bucketArray = new ArrayList<HashNode<K, V>>();
		numBuckets = 10;
		size = 0;

		for (int i = 0; i < numBuckets; i++) {
			bucketArray.add(null);
		}
	}

	public int size() {
		return size;
	}

	public boolean isEmpty() {
		return size() == 0;
	}

	// returns the hashmap index to which the key maps to
	private int getBucketIndex(K key) {
		int hashCode = key.hashCode();
		int index = hashCode % numBuckets;
		return index;
	}

	// adds a key value pair to the map
	public void add(K key, V value) {
		
		// calculate hashtable index
		int bucketIndex = getBucketIndex(key);

		// get the particular index's list's head
		HashNode<K, V> head = bucketArray.get(bucketIndex);
		
		// check if key already present in map
		while (head != null) {
			// if key found, change value to new value
			if (head.key.equals(key)) {
				head.value = value;
				return;
			}
			head = head.next;
		}

		// if key not found, insert into map new pair
		size++;
		// have head point to 
		head = bucketArray.get(bucketIndex);
		// create the new node
		HashNode<K, V> newNode = new HashNode<K, V>(key, value);
		// inset newNode in front
		newNode.next = head;
		bucketArray.set(bucketIndex, newNode);

		// check if hashmap has to be resized
		if ((1.0*size)/numBuckets >= 0.7) {
			// create a temp map
			ArrayList<HashNode<K, V>> temp = bucketArray;
			bucketArray = new ArrayList<HashNode<K, V>>();

			// double the capacity
			numBuckets = numBuckets * 2;

			// initialize the new map
			for (int i = 0; i < numBuckets; i++) {
				bucketArray.add(null);
			}

			// add all the K,V pairs from the old map to new
			for (HashNode<K, V> headNode : temp) {
				while (headNode != null) {
					add(headNode.key, headNode.value);
					headNode = headNode.next;
				}
			}
		}
	}

	// returns the value for a key
	public V get(K key) {
		// find hash key index for given key
		int bucketIndex = getBucketIndex(key);
		HashNode<K, V> head = bucketArray.get(bucketIndex);

		// check if key is present in the list
		while (head != null) {
			if (head.key.equals(key)) {
				return head.value;
			}
			head = head.next;
		}

		// if key was not found
		return null;
	}

	// removes given key and returns the removed value
	public V remove(K key) {
		// find hash key index for given key
		int bucketIndex = getBucketIndex(key);
		HashNode<K, V> head = bucketArray.get(bucketIndex);

		// search for key in list
		// keep track of prev node
		HashNode<K, V> prev = null;
		while (head != null) {
			if (head.key.equals(key)) {
				break;
			}
			prev = head;
			head = head.next;
		}

		// if key not present
		if (head == null) {
			return null;
		}

		// if key present at the beginning
		if (prev == null) {
			bucketArray.set(bucketIndex, head.next);
		}
		// if key present later
		else {
			prev.next = head.next;
		}
		size--;

		return head.value;
	}

	// ----------------------- MAIN -----------------------
	public static void main(String[] args) {
		HashMap<String, Integer> map = new HashMap<>();
        map.add("this",1 );
        map.add("coder",2 );
        map.add("this",4 );
        map.add("hi",5 );
        System.out.println(map.size());
        System.out.println(map.remove("this"));
        System.out.println(map.remove("this"));
        System.out.println(map.size());
        System.out.println(map.isEmpty());
	}
}