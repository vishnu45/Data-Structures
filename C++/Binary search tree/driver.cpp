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

	return 0;
}