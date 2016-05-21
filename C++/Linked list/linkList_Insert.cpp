/* *******************************************************************
 Inserting elements in a singly linked list
 Time complexity	: O(n), to insert at the end in worst case
 Space complexity	: O(1), for the temporary variable
******************************************************************** */

#include <iostream>
using namespace std;

//--------------------------------------------------------------------
// Structure: Linked list struct
//--------------------------------------------------------------------
struct LinkedList
{
	int data;
	struct LinkedList *next;
};

//--------------------------------------------------------------------
// Function: To print all elements in the linked list whose head node 
// is provided
//--------------------------------------------------------------------
void dispList(struct LinkedList *node)
{
	while(node!=NULL)
	{
		cout << node -> data << "->";
		node = node -> next;
	}
	cout << endl;	
}

//--------------------------------------------------------------------
// Function: To insert element in front of the given Linked list
//--------------------------------------------------------------------
void insert_front(struct LinkedList **head, int value)
{
	struct LinkedList *new_node = new LinkedList;

	cout << "Value to insert: " << value << endl;
	new_node -> data = value;
	new_node -> next = *head;
	*head = new_node;	
}

//--------------------------------------------------------------------
// Function: To insert element at the end of the given LinkedList
//--------------------------------------------------------------------
void insert_end(struct LinkedList **head, int value)
{
	struct LinkedList *new_node = new LinkedList;
	struct LinkedList *node = new LinkedList;
	
	cout << "Value to insert: " << value << endl;
	node = *head;

	new_node -> data = value;
	new_node -> next = NULL;
	while(node -> next != NULL)
	{
		node = node -> next;
	}
	node -> next = new_node;	
}

//--------------------------------------------------------------------
// Function: To insert element in between LinkedList
//--------------------------------------------------------------------
void insert_btw(struct LinkedList **head, int value)
{
	struct LinkedList *new_node = new LinkedList;
	struct LinkedList *node = new LinkedList;
	
	cout << "Value to insert: " << value << endl;
	node = *head;
	new_node -> data = value;
	while (true)
	{
		// if value lesser than starting element
		if( node -> data >= value)
		{
			new_node -> next = node;
			*head = new_node;
			break;
		}

		// if value greater than last element
		if( node -> next == NULL)
		{
			new_node -> next = NULL;
			node -> next = new_node;
			break;
		}

		if (((node -> data) < value) && 
			(((node -> next) -> data) >= value))
		{
			new_node -> next = node -> next;
			node -> next = new_node;
			break;
		}
		node = node -> next;
	}
}

int main()
{
	// Declare and initialize a linked list
	struct LinkedList *head = new LinkedList;
	struct LinkedList *second = new LinkedList;
	struct LinkedList *fourth = new LinkedList;

	head -> data = 2;
	head -> next = second;
	second -> data = 4;
	second -> next = fourth;
	fourth -> data = 6;
	fourth -> next = NULL;

	// Display original list
	dispList(head);

	// Insert at the beginning of Linked list
	insert_front(&head, 1);
	dispList(head);

	// Insert at the end of the Linked list
	insert_end(&head, 7);
	dispList(head);

	// Insert somewhere in between
	insert_btw(&head, 3);
	dispList(head);
	insert_btw(&head, 0);
	dispList(head);
	insert_btw(&head, 8);
	dispList(head);
	insert_btw(&head, 8);
	dispList(head);

	return 0;
}