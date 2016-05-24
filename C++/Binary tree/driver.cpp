#include <iostream>
#include "binaryTree.h"
using namespace std;

int main()
{
	// create root node
	struct binaryTree *root = newNode(1);

	// add very first left and right leaves
	root -> left = newNode(2);
	root -> right = newNode(3);

	// add leaves for the left node
	root -> left -> left = newNode(4);
	root -> left -> right = newNode(5);

	/*------------------
			[1]
		   /   \
		 [2]   [3]
		/   \
	  [4]   [5]
	-------------------*/
	  
	return 0;
}