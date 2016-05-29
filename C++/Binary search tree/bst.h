#include <iostream>
using namespace std;

#ifndef BST_H
#define BST_H

struct bst
{
	int data;
	struct bst *left;
	struct bst *right;
};

struct bst* CreateNode(int value)
{	
	struct bst *newNode = new bst;
	newNode -> data = value;
	newNode -> left = NULL;
	newNode -> right = NULL;
	return newNode;
}

int GetHeight(struct bst *tObject)
{
	int i = 0, left, right;

	if (tObject == NULL)
		return 0;
	else
	{
		left = GetHeight(tObject -> left);
		right = GetHeight(tObject -> right);
		if (left > right)
			return left + 1;
		else
			return right + 1;
	}
}

// insert node
struct bst* Insert(struct bst *tObject, int value)
{
	struct bst *newNode = CreateNode(value);
	struct bst *tempNode = new bst;

	if (tObject == NULL)
		return CreateNode(value);
	else if (value < tObject -> data)
		tObject -> left = Insert(tObject -> left, value);
	else 
		tObject -> right = Insert(tObject -> right, value);
	return tObject;
}

// print at level
void PrintAtGivenLevel(struct bst *tObject, int level)
{
	struct bst *temp = tObject;
	int i = level;
	if (temp == NULL)
		return;
	else
	{
		if (i == 1)
		{
			cout << temp -> data << " ";
			return;
		}
		PrintAtGivenLevel(temp -> left, i-1);
		PrintAtGivenLevel(temp -> right, i-1);
		return;
	}		
}

// level order traversal
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

// search node
struct bst* Search(struct bst *tObject, int value)
{
	struct bst *temp = new bst;
	temp = tObject;
	if (temp == NULL)
		return NULL;
	while (temp != NULL)
	{
		if (value == temp -> data)
			return temp;
		else if (value >= temp -> data)
			temp = temp -> right;
		else
			temp = temp -> left;
	}
	return NULL;
}

// delete node

#endif