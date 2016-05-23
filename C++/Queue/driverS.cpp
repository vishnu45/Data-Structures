/* *******************************************************************
 Driver program to check implementation of array queue "arrayQueue.h"
******************************************************************** */

#include <iostream>
#include "arrayQueue.h"
using namespace std;

int main()
{
	// declare and initialize queue
	struct queue *qObject = createQueue(5);
	
	// enqueue values to queue
	enqueue(&qObject, 1);
	cout << "Front element: " << front(qObject);
	cout << " Rear element: " << rear(qObject) << endl;
	enqueue(&qObject, 2);
	enqueue(&qObject, 3);
	enqueue(&qObject, 4);
	enqueue(&qObject, 5);
	cout << "Front element: " << front(qObject);
	cout << " Rear element: " << rear(qObject) << endl;

	enqueue(&qObject, 6);
	dequeue(&qObject);
	enqueue(&qObject, 6);
	cout << "Front element: " << front(qObject);
	cout << " Rear element: " << rear(qObject) << endl;

	// dequeue all elements from the queue
	dequeue(&qObject);
	dequeue(&qObject);
	dequeue(&qObject);
	dequeue(&qObject);
	cout << "Front element: " << front(qObject);
	cout << " Rear element: " << rear(qObject) << endl;
	dequeue(&qObject);
	isEmpty(qObject) 
		? cout << "Queue is empty" << endl
		: cout << "Queue is not empty" << endl;

	return 0;
}