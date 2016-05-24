#include <iostream>

#ifndef BINARYTREE_H
#define BINARYTREE_H

using namespace std;

struct binaryTree
{
	int data;
	struct binaryTree *left;
	struct binaryTree *right;
};

struct binaryTree* newNode(int value)
{
	struct binaryTree *tObject = new binaryTree;
	tObject -> data = value;
	tObject -> left = NULL;
	tObject -> right = NULL;
	return tObject;
}

#endif