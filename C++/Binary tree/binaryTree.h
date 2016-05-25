#include <iostream>

#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std;

// binary tree structure
struct BinaryTree
{
	int data;
	struct BinaryTree *left;
	struct BinaryTree *right;
};

// create a binary tree node
struct BinaryTree* NewNode(int value)
{
	struct BinaryTree *tObject = new BinaryTree;
	tObject -> data = value;
	tObject -> left = NULL;
	tObject -> right = NULL;
	return tObject;
}

// binary tree traversal: inorder
void InOrder(struct BinaryTree *root)
{
	if(root == NULL)
		return;	
	InOrder(root -> left);
	cout << root -> data << " ";
	InOrder(root -> right);	
	return;
}

// binary tree traversal: preorder
void PreOrder(struct BinaryTree *root)
{
	if(root == NULL)
		return;	
	cout << root -> data << " ";
	PreOrder(root -> left);		
	PreOrder(root -> right);	
	return;
}

// binary tree traversal: postorder
void PostOrder(struct BinaryTree *root)
{
	if(root == NULL)
		return;	
	PostOrder(root -> left);
	PostOrder(root -> right);
	cout << root -> data << " ";
	return;
}

// get height of a tree
int GetHeight(struct BinaryTree *root)
{
	if(root == NULL)
		return 0;
	else
	{
		int left_height = GetHeight(root -> left);
		int right_height = GetHeight(root -> right);
		if (left_height > right_height)
			return left_height + 1;
		else
			return right_height + 1;
	}
}

// level order traversal for a tree
void PrintAtGivenLevel(struct BinaryTree *root, int level)
{
	if(root == NULL)
		return;
	else
	{
		if (level == 1)
			cout << root -> data << " ";
		else if (level > 1)
		{
			PrintAtGivenLevel(root -> left, level - 1);
			PrintAtGivenLevel(root -> right, level - 1);
		}
		return;
	}
}

// level order traversal for a tree, level - Method 1
void LevelOrderTraversal(struct BinaryTree *root)
{
	int i = 1;
	while(i <= GetHeight(root))
	{
		PrintAtGivenLevel(root, i);
		cout << endl;
		i++;
	}
	return;
}

#endif