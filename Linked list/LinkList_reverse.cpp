/* *******************************************************************
 Reversing a singly linked list
 Time complexity	: 
 Space complecity	:
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
void printList(struct LinkedList *node)
{
	while(node != NULL)
	{
		cout<<node->data<<" -> ";
		node = node->next;
	}
	cout << endl;
}

//--------------------------------------------------------------------
// Function: To insert element at the end of the given LinkedList
//--------------------------------------------------------------------
void push(struct LinkedList **head, int value)
{
	struct LinkedList *node = new LinkedList;
	struct LinkedList *new_node = new LinkedList;

	new_node -> data = value;
	new_node -> next = NULL;
	node = *head;
	while(node -> next != NULL)
		node = node -> next;
	node -> next = new_node;
}

//--------------------------------------------------------------------
//	Function: To reverse given LinkedList
//--------------------------------------------------------------------
void reverse(struct LinkedList **head)
{
	struct LinkedList *prev_node = new LinkedList;
	prev_node = NULL;
	struct LinkedList *curr_node = new LinkedList;
	curr_node = *head;
	struct LinkedList *next_node = new LinkedList;

	while(curr_node != NULL)
	{
		next_node = curr_node -> next;
		curr_node -> next = prev_node;
		prev_node = curr_node;
		curr_node = next_node;
	}
	*head = prev_node;
}

int main()
{
	struct LinkedList *head = new LinkedList;
	
	// push elements to the linked list
	head -> data = 0;
	head -> next = NULL;
	push(&head, 1);
	push(&head, 2);
	push(&head, 3);
	push(&head, 4);

	// display original linked list
	printList(head);

	// reverse and display reversed linked list
	reverse(&head);
	printList(head);

	return 0;
}