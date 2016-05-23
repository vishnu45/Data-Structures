/* *******************************************************************
 Array implementation of interger queue  
******************************************************************** */

#ifndef ARRAYQUEUE_H
#define ARRAYQUEUE_H

#include <iostream>
using namespace std;

//--------------------------------------------------------------------
// Structure: Array queue
//--------------------------------------------------------------------
struct queue
{
	int front, rear, size;
	int capacity;
	int *array;
};

//--------------------------------------------------------------------
// Function: To create a new queue for given capacity
//--------------------------------------------------------------------
struct queue* createQueue(int capacity)
{
	struct queue *qObject = new queue;
	qObject -> front = 0;
	qObject -> rear = -1;
	qObject -> size = 0;
	qObject -> capacity = capacity;
	qObject -> array = new int[capacity];

	return qObject;
}

//--------------------------------------------------------------------
// Function: To check whether queue is full
//--------------------------------------------------------------------
bool isFull(struct queue *qObject)
{
	if ( qObject -> size == ( qObject -> capacity) )
		return true;
	else
		return false;
}

//--------------------------------------------------------------------
// Function: To check whether queue is empty
//--------------------------------------------------------------------
bool isEmpty(struct queue *qObject)
{
	if ( qObject -> size == 0 )
		return true;
	else
		return false;
}

//--------------------------------------------------------------------
// Function: To enqueue an element in the queue
//--------------------------------------------------------------------
void enqueue(struct queue **qObject, int value)
{
	// check if queue is full
	if (isFull(*qObject))
	{
		cout << "Queue is full. Can't add any more values." << endl;
		return;
	}
	// update rear position and size, then add value to array
	((*qObject) -> rear ) = 
		(((*qObject) -> rear ) + 1) % ((*qObject) -> capacity);
	((*qObject) -> size )++;
	(*qObject) -> array[(*qObject) -> rear] = value;
	cout << "Enqueued element " << value << endl;
	return;
}

//--------------------------------------------------------------------
// Function: To dequeue an element from the queue
//--------------------------------------------------------------------
void dequeue(struct queue **qObject)
{
	// check if queue is empty
	if (isEmpty(*qObject))
	{
		cout << "Queue is empty. No values in queue to dequeue." << endl;
		return;
	}
	cout << "Dequeued " << (*qObject) -> array[(*qObject) -> front] << " from queue." << endl;
	((*qObject) -> front) = 
		(((*qObject) -> front ) + 1) % ((*qObject) -> capacity);
	((*qObject) -> size )--;
	return;
}

//--------------------------------------------------------------------
// Function: To get the element in the front of the queue
//--------------------------------------------------------------------
int front(struct queue *qObject)
{
	return qObject -> array[qObject -> front];
}

//--------------------------------------------------------------------
// Function: To get the element in the rear of the queue
//--------------------------------------------------------------------
int rear(struct queue *qObject)
{
	return qObject -> array[qObject -> rear];
}

#endif