public class DNode {
	public int item;
	public DNode next;
	public DNode previous;

	// DNode constructor
	public DNode(int item, DNode next, DNode previous) {
		this.item = item;
		this.next = next;
		this.previous = previous;
	}
}