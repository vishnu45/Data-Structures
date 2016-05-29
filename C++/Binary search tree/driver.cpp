#include <iostream>
#include "bst.h"
using namespace std;

int main()
{
	struct bst *tObject = new bst;
	tObject = CreateNode(7);
	tObject = Insert(tObject, 4);
	tObject = Insert(tObject, 2);
	tObject = Insert(tObject, 5);
	tObject = Insert(tObject, 9);
	tObject = Insert(tObject, 10);
	tObject = Insert(tObject, 8);
	tObject = Insert(tObject, 11);

	LevelOrderTraversal(tObject);

	Search(tObject, 8)
		? cout << "Key found at: " << Search(tObject, 8) -> data << endl
		: cout << "Key not present in tree" << endl;

	cout << "Min value: " << Min(tObject) -> data << endl;
	cout << "Max value: " << Max(tObject) -> data << endl;

	struct bst *tObject1 = new bst;
	tObject = CreateNode(10);
	tObject = Insert(tObject, 7);
	tObject = Insert(tObject, 20);
	tObject = Insert(tObject, 5);
	tObject = Insert(tObject, 8);
	tObject = Insert(tObject, 15);
	tObject = Insert(tObject, 25);
	tObject = Insert(tObject, 12);
	tObject = Insert(tObject, 18);
	tObject = Insert(tObject, 22);
	tObject = Insert(tObject, 27);
	cout << endl;
	LevelOrderTraversal(tObject);
	cout << endl;
	tObject = deleteVal(tObject, 20);
	LevelOrderTraversal(tObject);

	return 0;
}