/* *******************************************************************
 Binary tree implementation  
******************************************************************** */

#include <iostream>

#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std;

//--------------------------------------------------------------------
// Structure: Binary tree
//--------------------------------------------------------------------
struct BinaryTree
{
	int data;
	struct BinaryTree *left;
	struct BinaryTree *right;
};

//--------------------------------------------------------------------
// Function: To create a new binary tree node using the given value
//--------------------------------------------------------------------
struct BinaryTree* NewNode(int value)
{
	struct BinaryTree *tObject = new BinaryTree;
	tObject -> data = value;
	tObject -> left = NULL;
	tObject -> right = NULL;
	return tObject;
}

//--------------------------------------------------------------------
// Function: To display the contents of the binary tree InOrder
// 	- First left child node is displayed
//	- Second root node is displayed
//	- Third right child node is displayed
//--------------------------------------------------------------------
void InOrder(struct BinaryTree *root)
{
	if(root == NULL)
		return;	
	InOrder(root -> left);
	cout << root -> data << " ";
	InOrder(root -> right);	
	return;
}

//--------------------------------------------------------------------
// Function: To display the contents of the binary tree PreOrder
// 	- First root node is displayed
//	- Second left child node is displayed
//	- Third right child node is displayed
//--------------------------------------------------------------------
void PreOrder(struct BinaryTree *root)
{
	if(root == NULL)
		return;	
	cout << root -> data << " ";
	PreOrder(root -> left);		
	PreOrder(root -> right);	
	return;
}

//--------------------------------------------------------------------
// Function: To display the contents of the binary tree PostOrder
// 	- First left child node is displayed
//	- Second right child node is displayed
//	- Third root node is displayed
//--------------------------------------------------------------------
void PostOrder(struct BinaryTree *root)
{
	if(root == NULL)
		return;	
	PostOrder(root -> left);
	PostOrder(root -> right);
	cout << root -> data << " ";
	return;
}

//--------------------------------------------------------------------
// Function: To return the height of a node in the binary tree, which 
//	is the length of the path from that node to the deepest node.
//--------------------------------------------------------------------
int GetHeight(struct BinaryTree *root)
{
	// if tree is NULL
	if(root == NULL)
		return 0;
	else
	{
		// traverse through the left child
		int left_height = GetHeight(root -> left);
		// traverse through the right child
		int right_height = GetHeight(root -> right);
		// height is the greatest height among the left and right trees
		if (left_height > right_height)
			return left_height + 1;
		else
			return right_height + 1;
	}
}

//--------------------------------------------------------------------
// Function: To print all the nodes at any particular level in the 
//	binary tree.
//--------------------------------------------------------------------
void PrintAtGivenLevel(struct BinaryTree *root, int level)
{
	// if empty tree return
	if(root == NULL)
		return;
	else
	{
		// if the particular level node is reached, print the data at the node
		if (level == 1)
			cout << root -> data << " ";
		// else if the particular level has not reached
		else if (level > 1)
		{
			// traverse to left child of the node
			PrintAtGivenLevel(root -> left, level - 1);
			// traverse to right child of the node
			PrintAtGivenLevel(root -> right, level - 1);
		}
		return;
	}
}

//--------------------------------------------------------------------
// Function: To print all the nodes in a binary tree level wise  
//	starting at the root node. (left to right)
//--------------------------------------------------------------------
void LevelOrderTraversal(struct BinaryTree *root)
{
	int i = 1;
	// until all the levels are rtaversed through
	while(i <= GetHeight(root))
	{
		// print all the nodes (data) at the particular level
		PrintAtGivenLevel(root, i);
		cout << endl;
		i++;
	}
	return;
}

#endif