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