#include <iostream>
using namespace std;

#ifndef HEAP_H
#define HEAP_H

void swap(int *a, int *b)
{
	int temp = *a;
	*a = *b;
	*b = temp;
	return;
}

class MinHeap
{
	int *array;
	int capacity;
	int size;

public:	
	MinHeap(int capacity);	
	void InsertKey(int key);	
	void MinHeapify();
	void DisplayHeap();
	
	// int left(int i);

	// int right(int i);

	int Parent(int i);

	
};

MinHeap::MinHeap(int capacity)
{
	this -> array = new int[capacity];
	this -> capacity = capacity;
	this -> size = 0;
};

void MinHeap::InsertKey(int key)
{
	// check if heap is full
	if (size == capacity)
	{
		cout << "Heap is full. Can't add any more keys." << endl;
		return;
	}

	// insert key at the end of the heap
	array[size++] = key;

	// heapify heap
	MinHeapify();
	return;
}

void MinHeap::MinHeapify()
{
	int i = size-1;
	while (i > 0)
	{
		if (array[i] > array[Parent(i)])
			swap(&array[i], &array[Parent(i)]);
		i--;
	}
}

void MinHeap::DisplayHeap()
{
	if (size == 0)
		cout << "Heap is empty!" << endl;
	int i = 0;
	while (i < size)
		cout << array[i++] << " ";
	cout << endl;
	return;
}

int MinHeap::Parent(int i)
{
	return (i - 1) / 2 ;
}

#endif