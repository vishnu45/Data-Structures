/* *******************************************************************
 Creating and traversing a single linked list
 Time complexity	: O(n), for scanning the list of size n
 Space complexity	: O(1), for temporary variable node
******************************************************************** */

#include <iostream>
using namespace std;

//--------------------------------------------------------------------
// Structure: Linked list struct
//--------------------------------------------------------------------
struct LinkList
{
	int data;
	struct LinkList *next;
};

//--------------------------------------------------------------------
// Function: To print all elements in the linked list whose head node 
// is provided
//--------------------------------------------------------------------
void printList(struct LinkList *node)
{
	while(node != NULL)
	{
		cout<<node->data<<" -> ";
		node = node->next;
	}
	cout << endl;
}

//--------------------------------------------------------------------
// Function: To find length of the linked list 
//--------------------------------------------------------------------
int list_length(struct LinkList *node)
{
	int count = 1;
	while(node -> next != NULL)
	{
		count++;
		node = node -> next;
	}
	return count;
}

int main()
{
	// declare the 3 nodes
	struct LinkList *head = new LinkList;
	struct LinkList *second = new LinkList;
	struct LinkList *third = new LinkList;;
	struct LinkList *fourth = new LinkList;;

	// initialize node values and link them
	head -> data = 1;
	head -> next = second;
	second -> data = 2;
	second -> next = third;
	third -> data = 3;
	third -> next = fourth;
	fourth -> data = 4;
	fourth -> next = NULL;

	// print all values in linked list
	printList(head);

	// find linked list length
	cout << "Length of List = " << list_length(head) << endl;

	return 0;
}