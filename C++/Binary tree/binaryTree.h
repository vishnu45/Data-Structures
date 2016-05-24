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

#endif