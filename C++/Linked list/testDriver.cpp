#include <iostream>
#include "LinkedList.h"
using namespace std;

int main()
{
	LinkedList list1;
	
	list1.Push(2);
	list1.PrintList();
	list1.Push(1);
	list1.PrintList();

	list1.Append(3);
	list1.PrintList();
	list1.Append(5);
	list1.PrintList();
	list1.Append(6);
	list1.PrintList();
	
	list1.Insert(3,4);
	list1.PrintList();

	// list1.Remove(2);
	// list1.PrintList();

	list1.Swap(3,5);
	list1.PrintList();

	return 0;
}