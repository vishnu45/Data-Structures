#include <iostream>
using namespace std;

// Structure: Linked list struct
struct LinkList
{
	int data;
	struct LinkList *next;
};

// Function: To print all elements in the linked list whose head node is provided
void printList(struct LinkList *node)
{
	while(node != NULL)
	{
		cout<<node->data<<" -> ";
		node = node->next;
	}
}

int main()
{
	// declare the 3 nodes
	struct LinkList *head = new LinkList;
	struct LinkList *second = new LinkList;
	struct LinkList *third = new LinkList;;

	// initialize node values and link them
	head->data = 1;
	head->next = second;
	second->data = 2;
	second->next = third;
	third->data = 3;
	third->next = NULL;

	// print all values in linked list
	printList(head);

	return 0;
}