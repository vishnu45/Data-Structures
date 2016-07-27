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
};

#endif