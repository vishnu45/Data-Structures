/* *******************************************************************
 Basic stack implementation using linked list 
******************************************************************** */

#include <iostream>
using namespace std;

//--------------------------------------------------------------------
// Structure: Stack struct
//--------------------------------------------------------------------
struct Stack
{
	int data;
	struct Stack *next;
};

//--------------------------------------------------------------------
// Function: To create a new stack node
//--------------------------------------------------------------------
struct Stack* newNode(int value)
{
	struct Stack *node = new Stack;
	node -> data = value;
	node -> next = NULL;
	return node;
}

//--------------------------------------------------------------------
// Function: To check if a stack is empty
//--------------------------------------------------------------------
bool isEmpty(struct Stack *sObject)
{
	return sObject == NULL;
}

//--------------------------------------------------------------------
// Function: To push elements onto stack
//--------------------------------------------------------------------
void push(struct Stack **sObject, int value)
{
	struct Stack *node = new Stack;
	node = newNode(value);
	node -> next = *sObject;
	*sObject = node;
	cout << "Pushed value: " << value << " to stack." << endl;
}

//--------------------------------------------------------------------
// Function: To pop elements off of stack
//--------------------------------------------------------------------
void pop(struct Stack **sObject)
{
	if(isEmpty(*sObject))
	{
		cout << "Stack is empty. No elements to pop." << endl;
		return;
	}
	struct Stack *temp = new Stack;
	temp = *sObject;
	*sObject = (*sObject) -> next;
	cout << "Popped value: " << temp -> data << " from the stack." << endl;
	delete temp;	
}

//--------------------------------------------------------------------
// Function: To retrieve top element in stack
//--------------------------------------------------------------------
void topElement(struct Stack *sObject)
{
	cout << "Top element: " << sObject -> data << endl;
}

int main()
{
	// Initialize stack
	struct Stack *sObject =  new Stack;
	sObject = NULL;

	// push and pop elements
	pop(&sObject);
	push(&sObject, 1);
	push(&sObject, 2);
	push(&sObject, 3);
	pop(&sObject);

	// retrive top element on stack
	topElement(sObject);

	return 0;
}