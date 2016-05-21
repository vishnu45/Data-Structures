/* *******************************************************************
 Basic stack implementation using integer array 
******************************************************************** */

#include <iostream>
using namespace std;

//--------------------------------------------------------------------
// Structure: Stack struct
//--------------------------------------------------------------------
struct Stack
{
	int top;
	int capacity;
	int *array;
};

//--------------------------------------------------------------------
// Function: To create a new stack for given capacity
//--------------------------------------------------------------------
struct Stack *createStack(int capacity)
{
	struct Stack *stObject = new Stack;
	stObject -> top = -1;
	stObject -> capacity = capacity;
	int *sArray = new int [capacity];
	stObject -> array = sArray;
	return stObject;
}

//--------------------------------------------------------------------
// Function: To check if a stack is empty
//--------------------------------------------------------------------
bool isEmpty(struct Stack *sObject)
{
	return ( sObject -> top == -1 );
}

//--------------------------------------------------------------------
// Function: To check if a stack is full
//--------------------------------------------------------------------
bool isFull(struct Stack *sObject)
{
	return ( sObject -> top == (sObject -> capacity-1) );
}

//--------------------------------------------------------------------
// Function: To push elements onto stack
//--------------------------------------------------------------------
void push(struct Stack *sObject, int value)
{
	if(isFull(sObject))
	{
		cout << "Stack is full. Can't push any more elements." << endl;
		return;
	}
	sObject -> top ++;
	sObject -> array[sObject -> top] = value;
	cout << "Pushed value: " << value << " onto stack." << endl;
}

//--------------------------------------------------------------------
// Function: To pop elements off of stack
//--------------------------------------------------------------------
void pop(struct Stack *sObject)
{
	if(isEmpty(sObject))
	{
		cout << "Stack is empty. No element present to pop." << endl;
		return;
	}
	cout << "Popped value:" << sObject -> array[sObject -> top] <<" from stack." << endl;
	sObject -> top--;
	
}

//--------------------------------------------------------------------
// Function: To retrieve top element in stack
//--------------------------------------------------------------------
int topElement(struct Stack *sObject)
{	
	return sObject -> array [sObject -> top];
}

int main()
{
	// Create a stack
	struct Stack *sObject = new Stack;
	sObject = createStack(5);

	// push elements into stack
	isEmpty(sObject) 	? cout << "Stack is empty" << endl 
						: cout << "Stack is not empty" << endl;
	pop(sObject);
	push(sObject, 1);
	isEmpty(sObject) 	? cout << "Stack is empty" << endl 
						: cout << "Stack is not empty" << endl;
	push(sObject, 2);
	push(sObject, 3);
	push(sObject, 4);
	cout << "Top element: " << topElement(sObject) << endl;
	isFull(sObject) 	? cout << "Stack is full" << endl 
						: cout << "Stack is not full" << endl;
	cout << "Top element on stack: " << topElement(sObject) << endl;
	push(sObject, 5);
	isFull(sObject) 	? cout << "Stack is full" << endl 
						: cout << "Stack is not full" << endl;
	push(sObject, 6);

	// pop elements from the stack
	pop(sObject);
	pop(sObject);
	cout << "Top element on stack: " << topElement(sObject) << endl;	

	return 0;
}