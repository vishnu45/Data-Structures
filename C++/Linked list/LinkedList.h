#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct node
{
	int data;
	struct node *next;
};

class LinkedList
{
public:
	LinkedList();
	void Push();
	void Append();
	void Insert();
	void Remove();
	void PrintList();
};

#endif