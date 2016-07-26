#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList()
{
	cout << "Initializing linked list ..." << endl;
	head = NULL;
	listLength = 0;
}

void LinkedList::Push(int value)
{
	cout << "Inserting value at the front ..." << endl;

	// create the new node
	struct node *newNode = new node;
	newNode -> data = value;

	// check if list is empty
	if (!head)
	{
		head = newNode;
		newNode -> next = NULL;
	}
	else
	{
		struct node *temp = new node;
		temp = head;
		newNode -> next = temp;
		head = newNode;
	}
	listLength++;
	return;
}

