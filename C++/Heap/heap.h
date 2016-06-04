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
	
	void InsertKey(int key);	//
	
	void MinHeapify(int index);	//		
	
	void DisplayHeap();			//
	
	int Left(int i);			//

	int Right(int i);			//

	int Parent(int i);			//

	int GetMin();				//

	int ExtractMin();			//

	void DeleteKey(int key);	//
	
};

MinHeap::MinHeap(int capacity) 
{
	this -> array = new int[capacity];
	this -> capacity = capacity;
	this -> size = 0;
}

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

	// heapify heap after key insertion
	int i = size-1;
	while (i > 0)
	{
		if (array[i] < array[Parent(i)])
			swap(&array[i], &array[Parent(i)]);
		i--;
	}
	return;
}

int MinHeap::GetMin() { return array[0]; }

int MinHeap::ExtractMin()
{
	if (size == 0)
		return INT_MAX;
	if (size == 1)
	{
		size--;
		return array[0];
	}
	int min = array[0];
	array[0] = array[size-1];
	size--;
	MinHeapify(0);
	return min;	
}

void MinHeap::MinHeapify(int index)
{
	int l = Left(index);
	int r = Right(index);
	int swap_i = index;	

	if (l < size && array[l] < array[index])
		swap_i = l;
	if (r < size && array[r] < array[swap_i])
		swap_i = r;	
	if (swap_i != index)
	{
		swap(&array[index], &array[swap_i]);
		MinHeapify(swap_i);
	}
	return;
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

void MinHeap::DeleteKey(int key)
{
	int index, i;
	if (size ==0)
		cout << "Heap is empty" << endl;	
	for (i=0; i<size; i++)
	{
		if (array[i] == key)
			break;
	}	
	if (i >= size)
	{
		cout << "Requested key not in the heap" << endl;
		return;
	}
	if (size == 1 && i == 0)
	{
		size--;
		return;
	}
	array[i] = array[size-1];
	size--;
	MinHeapify(i);
	return;
}

int MinHeap::Left(int i) { return (2*i + 1); }

int MinHeap::Right(int i) { return (2*i + 2); }

int MinHeap::Parent(int i) { return (i - 1) / 2; }

#endif