/* *******************************************************************
 Stack implementation using integer array  
******************************************************************** */

#ifndef STACK_H
#define STACK_H

#include <iostream>
using namespace std;

//--------------------------------------------------------------------
// Structure: Stack struct
//--------------------------------------------------------------------
struct Stack
{
	int top;
	int capacity;
	char *array;
};

//--------------------------------------------------------------------
// Function: To create a new stack for given capacity
//--------------------------------------------------------------------
struct Stack *createStack(int capacity)
{
	struct Stack *stObject = new Stack;
	stObject -> top = -1;
	stObject -> capacity = capacity;
	char *sArray = new char [capacity];
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
void push(struct Stack *sObject, char value)
{
	if(isFull(sObject))
	{
		//cout << "Stack is full. Can't push any more elements." << endl;
		return;
	}
	sObject -> top ++;
	sObject -> array[sObject -> top] = value;
	// cout << "Pushed value: " << value << " onto stack." << endl;
}

//--------------------------------------------------------------------
// Function: To pop elements off of stack
//--------------------------------------------------------------------
void pop(struct Stack *sObject)
{
	if(isEmpty(sObject))
	{
		// cout << "Stack is empty. No element present to pop." << endl;
		return;
	}
	// cout << "Popped value:" << sObject -> array[sObject -> top] <<" from stack." << endl;
	sObject -> top--;
	
}

//--------------------------------------------------------------------
// Function: To retrieve top element in stack
//--------------------------------------------------------------------
char topElement(struct Stack *sObject)
{	
	return sObject -> array [sObject -> top];
}

#endif