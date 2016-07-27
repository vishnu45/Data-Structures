#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node
{
	int data;
	struct node *next;
};

class LinkedList
{
private:
	struct node *head;
	int listLength;

public:
	LinkedList();
	void Push(int value);
	void Append(int value);
	void Insert(int position, int value);
	void Remove(int position);
	void PrintList();
	// void Exists(int value);

	// Extra utilities

	struct node* next(int value);
	struct node* prev(int value);
	
	void Swap(int value1, int value2);
	// check if node present 

};

#endif