#include <iostream>
#include "LinkedList.h"
using namespace std;

// constructor function for linked list initialization
LinkedList::LinkedList()
{
	cout << "Initializing linked list ..." << endl;
	head = NULL;
	listLength = 0;
}

// function to display the elements of a linked list
void LinkedList::PrintList()
{
	if (!head)
	{
		cout << "Empty linked list!" << endl;
		return;
	}
	struct node *temp = new node;
	temp = head;
	while (temp)
	{
		cout << temp -> data << " -> ";
		temp = temp -> next;
	}
	cout << endl;
	return;
}

// function to push elements to the front of a linked list
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

// function to append value to end of linked list
void LinkedList::Append(int value)
{
	cout << "Inserting value at the end ..." << endl;

	// create the new node
	struct node *newNode = new node;
	newNode -> data = value;
	newNode -> next = NULL;

	// check if the list is empty
	if (!head)
		head = newNode;
	else
	{
		struct node *temp = new node;
		temp = head;

		// find last node
		while (temp -> next)
			temp = temp -> next;
		temp -> next = newNode; 
	}

	listLength++;
	return;
}

// function to insert value at a particular position of linked list
void LinkedList::Insert(int position, int value)
{
	cout << "Inserting value at position " 
		 << position << " ... " << endl;

	// check if given position is out of bounds		
	if (position > listLength)
	{
		cout << "Invalid position!" << endl;
		return;
	}

	// create new node
	struct node *newNode = new node;
	newNode -> data = value;

	// check if node has to inserted at the beginning
	if (position == 0)
	{
		struct node *temp = new node;
		temp = head;
		newNode -> next = temp;
		head = newNode;
		listLength++;
		return;
	}

	int i = 1;
	struct node *temp = new node;
	temp = head;

	// get to the node after which the node has to be inserted
	while (i < position)
	{
		temp = temp -> next;
		i++;
	}

	// insert the node
	newNode -> next = temp -> next; 
	temp -> next = newNode;
	listLength++;
	return;
}

// function to remove a node from a particular position in the linked list
void LinkedList::Remove(int position)
{		
	// check if position is out of bounds
	if (position >= listLength)
	{
		cout << "Invalid position!" << endl;
		return;
	}
	cout << "Deleting value at position " 
		 << position << " ..." << endl;

	struct node *temp = new node;
	// if the head is to be removed
	if (position == 0)
	{
		temp = head;
		head = head -> next;
		delete temp;
		listLength--;
		return;
	}

	struct node *temp2 = new node;
	int i = 1;
	temp = head;
	while (i < position)
	{
		temp = temp -> next;
		i++;
	}
	temp2 = temp -> next;
	temp -> next = (temp -> next) -> next;
	delete temp2;
	listLength--;

	return;
}

// function to check if value exists in linked list
bool LinkedList::Exists(int value)
{
	cout << "Checking if value: " << value 
		 << " present in the linked list ..." << endl;
	struct node *temp = new node;

	if (head -> data == value)
		return true;

	temp = head;
	while (temp -> data != value)
	{
		if (!temp -> next)
			return false;
		temp = temp -> next;
	}
	return true;
}

// function to swap two nodes in the linked list
void LinkedList::Swap(int value1, int value2)
{
	cout << "Swapping values " << value1 
		 << " and " << value2 << " ..." << endl;

	struct node *node1 = new node;
	struct node *node1_p = new node;
	struct node *node2 = new node;
	struct node *node2_p = new node;
	struct node *temp = new node;

	// find node1 and previous node to node1
	if (head -> data == value1)
	{
		node1 = head;
		node1_p = NULL;
	}
	else
	{
		node1 = head;
		while (node1 -> data != value1)
		{
			node1_p = node1;
			node1 = node1 -> next;
		}
	}

	// find node2 and previous node to node2
	if (head -> data == value2)	
	{
		node2 = head;
		node2_p = NULL;
	}
	else
	{
		node2 = head;
		while (node2 -> data != value2)
		{
			node2_p = node2;
			node2 = node2 -> next;
		}
	}

	if (node1_p != NULL)
		node1_p -> next = node2;
	else
		head = node2;

	if (node2_p != NULL)
		node2_p -> next = node1;
	else
		head = node1;

	temp = node1 -> next;
	node1 -> next = node2 -> next;
	node2 -> next = temp;

	return;

}