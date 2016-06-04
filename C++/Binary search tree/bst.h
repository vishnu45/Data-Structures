/* *******************************************************************
 Binary search tree implementation  
******************************************************************** */

#include <iostream>
using namespace std;

#ifndef BST_H
#define BST_H

//--------------------------------------------------------------------
// Structure: Binary search tree
//--------------------------------------------------------------------
struct bst
{
	int data;
	struct bst *left;
	struct bst *right;
};

//--------------------------------------------------------------------
// Function: To create a new binary search tree node
//--------------------------------------------------------------------
struct bst* CreateNode(int value)
{	
	struct bst *newNode = new bst;
	newNode -> data = value;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}

//--------------------------------------------------------------------
// Function: To return the height of a node in the binary search tree,
//	which is the length of the path from that node to the deepest node.
//--------------------------------------------------------------------
int GetHeight(struct bst *tObject)
{
	int i = 0, left, right;

	if (tObject == NULL)
		return 0;
	else
	{	
		// get the height of the left branch
		left = GetHeight(tObject -> left);
		// get the height of the right branch
		right = GetHeight(tObject -> right);
		// height is the greatest height among the left and right trees
		if (left > right)
			return left + 1;
		else
			return right + 1;
	}
}

//--------------------------------------------------------------------
// Function: To insert a value into the binary search tree
//--------------------------------------------------------------------
struct bst* Insert(struct bst *tObject, int value)
{
	struct bst *newNode = CreateNode(value);
	struct bst *tempNode = new bst;

	// if the bst is empty, create the bst with the value
	if (tObject == NULL)
		return CreateNode(value);
	// insert value into left branch if lesser than parent
	else if (value < tObject -> data)
		tObject -> left = Insert(tObject -> left, value);
	// insert value into right branch if greater than parent
	else 
		tObject -> right = Insert(tObject -> right, value);
	return tObject;
}

//--------------------------------------------------------------------
// Function: To print all the nodes at any particular level in the 
//	binary search tree.
//--------------------------------------------------------------------
void PrintAtGivenLevel(struct bst *tObject, int level)
{
	struct bst *temp = tObject;
	int i = level;
	if (temp == NULL)
		return;
	else
	{
		// if the particular level node is reached, print the data at the node
		if (i == 1)
		{
			cout << temp -> data << " ";
			return;
		}
		// else if the particular level has not reached
		// traverse to left child of the node
		PrintAtGivenLevel(temp -> left, i-1);
		// traverse to right child of the node
		PrintAtGivenLevel(temp -> right, i-1);
		return;
	}		
}

//--------------------------------------------------------------------
// Function: To print all the nodes in a binary search tree level wise  
//	starting at the root node. (left to right)
//--------------------------------------------------------------------
void LevelOrderTraversal(struct bst *tObject)
{
	int h = GetHeight(tObject), i = 1;
	while (i <= h)
	{
		PrintAtGivenLevel(tObject, i);
		cout << endl;
		i++;
	}
	return;
}

//--------------------------------------------------------------------
// Function: To search a key value in the binary serach tree
//--------------------------------------------------------------------  
struct bst* Search(struct bst *tObject, int value)
{
	struct bst *temp = new bst;
	temp = tObject;
	if (temp == NULL)
		return NULL;
	while (temp != NULL)
	{
		// when the node is reached
		if (value == temp -> data)
			return temp;
		// if the value > node.data move to the right branch
		else if (value >= temp -> data)
			temp = temp -> right;
		// if the value < node.data move to the left branch
		else
			temp = temp -> left;
	}
	return NULL;
}

//--------------------------------------------------------------------
// Function: To find the smallest value in the binary search tree
//--------------------------------------------------------------------  
struct bst* Min(struct bst *tObject)
{
	if (tObject == NULL)
		return NULL;
	// move to left most leaf in the tree to get the smallest value
	while (tObject -> left != NULL)	
		tObject = tObject -> left;
	return tObject;
}

//--------------------------------------------------------------------
// Function: To find the largest value in the binary search tree
//--------------------------------------------------------------------  
struct bst* Max(struct bst *tObject)
{
	if (tObject == NULL)
		return NULL;
	// move to right most leaf in the tree to get the largest value
	while (tObject -> right != NULL)	
		tObject = tObject -> right;
	return tObject;
}


//--------------------------------------------------------------------
// Function: To delete a value in the binary serach tree
//--------------------------------------------------------------------  
struct bst* deleteVal(struct bst *tObject, int value)
{
	if (tObject == NULL)
		return NULL;

	// if the value is greater than current node move to right branch
	if (value > tObject -> data)
		tObject -> right = deleteVal(tObject -> right, value);
	// if the value is greater than current node move to left branch
	else if (value < tObject -> data)
		tObject -> left = deleteVal(tObject -> left, value);
	// once the value is reached
	else
	{
		// if the left node is NULL, move right node to root
		if (tObject -> left == NULL)
		{
			tObject = tObject -> right;
			return tObject;
		}
		// if the right node is NULL, move left node to root
		else if (tObject -> right == NULL)
		{
			tObject = tObject -> left;
			return tObject;
		}
		// if both right and left nodes are not NULL, find the smallest
		// element from the right tree and use this to replace the deleted node
		struct bst *temp = Min(tObject -> right);
		tObject -> data = temp -> data;
		tObject -> right = deleteVal(tObject -> right, temp -> data);
	}
	return tObject;
}

#endif