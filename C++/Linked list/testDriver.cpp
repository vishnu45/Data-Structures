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

	list1.Remove(1);
	list1.PrintList();
	list1.Insert(1,2);
	list1.PrintList();

	list1.Swap(3,4);
	list1.PrintList();

	if (list1.Exists(0))
		cout << "Yes";
	else
		cout << "No";

	return 0;
}