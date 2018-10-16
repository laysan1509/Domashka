#pragma once
#include "Node.h"
#include "Queue.h"
class BinaryTree
{
private:
	Node *root;
public:
	BinaryTree();
	Node *insert(Node *&root, int value);
	void create(int element);
	void print_tree();
	void wide(Queue * queue);
	bool find(Node *root, int element);
	bool find_node(int element);
	void print(Node *root, int level);
};

