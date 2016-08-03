#include "LinkedList.h"
#include <iostream>
using namespace std;

// function to remove duplicates in list
void RemoveDuplicates(LinkedList *inputList)
{
	struct node* temp1 = new node;
	temp1 = inputList -> GetHead();
	struct node* temp2 = new node;
	struct node* prev = new node;

	while (temp1)
	{
		temp2 = temp1 -> next;
		prev = temp1;

		while (temp2)
		{				
			// if a duplicate of temp1 is found
			if (temp1 -> data == temp2 -> data)
			{
				prev -> next = temp2 -> next;
				temp2 = temp2 -> next;
				// here advance the temp2 node but not the prev node
				continue;
			}

			// advance temp2 to next node in the list
			prev = temp2;
			temp2 = temp2 -> next;
		}
		temp1 = temp1 -> next;
	}

	return;
}

int main()
{
	// Creating linkedlist with duplicate enteries
	LinkedList inputList;

	// display list
	inputList.Append(1);
	inputList.Append(1);
	inputList.Append(2);
	inputList.Append(2);
	inputList.Append(3);
	inputList.Append(2);
	inputList.Append(5);
	inputList.Append(1);
	inputList.Append(6);
	inputList.Append(1);

	inputList.PrintList();

	// remove duplicates from list
	RemoveDuplicates(&inputList);

	// display list
	inputList.PrintList();

	return 0;
}