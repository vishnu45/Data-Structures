/* *******************************************************************
 Infix to postfix conversion using stack
******************************************************************** */

#include <iostream>
// include stack header file
#include "stack.h"
using namespace std;

//--------------------------------------------------------------------
// Function: To check operator precedence
//--------------------------------------------------------------------
bool checkHighPriority(char ch, struct Stack *sObject)
{
	switch(ch)
	{
		case '^':
			return true;
		case '/':	
		case '*':
			if (topElement(sObject) == '^')
				return false;
			else
				return true;
			break;
		case '-':			
		case '+':
			if (topElement(sObject) == '/' || 
				topElement(sObject) == '*' ||
				topElement(sObject) == '^')
				return false;
			else
				return true;
			break;
	}
} 

//--------------------------------------------------------------------
// Function: To convert and print the infix to postfix expression
//--------------------------------------------------------------------
void infixToPostfix(string exp)
{
	// Create a stack
	struct Stack *sObject = new Stack;
	sObject = createStack(exp.length());
	char ch;

	for (int i=0; i < exp.length(); i++ )
	{
		ch = exp.at(i);
		// check if character is a variable, if yes print variable
		if( ((int)(ch) >= 97) && ((int)(ch) <= 122) )
		{
			cout << exp.at(i) << " ";
			continue;
		}
		// check if character is any of the arithemetic operators (+, -, *, /, ^)
		else if ( ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^')				  
		{
			// if stack is empty push operator to stack
			if ( isEmpty(sObject) )
				push(sObject, ch);
			// if stack not empty
			else
			{
				// until precendence of current character less than that in stack
				while(!checkHighPriority(ch, sObject))
				{
					if ( isEmpty(sObject) )
						break;
					// print the operator in stack and pop it
					cout << topElement(sObject) << " ";
					pop(sObject);
				}
				push(sObject, ch);
			}
		}

		// check if opening brackets
		else if ( ch == '(' )
		{
			push(sObject, ch);
		}

		// check if closing brackets
		else if ( ch == ')' )
		{
			// until beginning bracket found print out all operators in stack
			while ( topElement(sObject) != '(' )
			{
				cout << topElement(sObject) << " "; 
				pop(sObject);
			}
			pop(sObject);
		}

		// any other character
		else 
			continue;
	}

	// if stack is not empty print out all the remaining operators in stack
	while(!isEmpty(sObject))
	{
		cout << topElement(sObject) << " ";
		pop(sObject);
	}
	cout << endl;	
}

int main()
{	
	infixToPostfix("a+b-c*d/e");
	infixToPostfix("a/b*c-d+e");
	infixToPostfix("(a+b)*(c+d)");
	infixToPostfix("a+b*(c^d-e)^(f+g*h)-i");
	
	return 0;
}