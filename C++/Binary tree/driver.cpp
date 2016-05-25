#include <iostream>
#include "binaryTree.h"
using namespace std;

int main()
{
	// create root node
	struct BinaryTree *root = NewNode(1);

	// add very first left and right leaves
	root -> left = NewNode(2);
	root -> right = NewNode(3);

	// add leaves for the left node
	root -> left -> left = NewNode(4);
	root -> left -> right = NewNode(5);

	// add leaves for the right node
	root -> right -> left = NewNode(6);
	root -> right -> right = NewNode(7);

	root -> left -> left -> left = NewNode(8);
	root -> left -> left -> right = NewNode(9);

	root -> left -> right -> left = NewNode(10);
	root -> left -> right -> right = NewNode(11);

	root -> right -> left -> left = NewNode(12);
	root -> right -> left -> right = NewNode(13);

	root -> right -> right -> left = NewNode(14);
	root -> right -> right -> right = NewNode(15);

	/*------------------------
			   [1]
		     /     \
		 [2]         [3]
	    /   \		/   \
      [4]   [5]   [6]   [7]
      | |   | |   | |   | |
      8-9  10-11 12-13 14-15 
	---------------------------*/

    cout << "InOrder traversal: ";
	InOrder(root);
	cout << endl << endl;
	cout << "PreOrder traversal: ";
	PreOrder(root);
	cout << endl << endl;
	cout << "PostOrder traversal: ";
	PostOrder(root);
	cout << endl << endl;
	cout << "LevelOrder traversal: ";
	cout << endl;
	LevelOrderTraversal(root);		

	return 0;
}