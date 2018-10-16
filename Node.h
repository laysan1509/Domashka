#pragma once
class Node
{
private:
	int value;
	Node *left;
	Node *right;
public:
	Node(int value);
	Node* getLeft();
	Node* getRight();
	int getValue();
	void setLeft(Node *left);
	void setRight(Node *right);

};
