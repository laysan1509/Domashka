#include "pch.h"
#include "Node.h"
#include <iostream>
using namespace std;

Node::Node(int value)
{
	this->value = value;
	this->left = nullptr;
	this->right = nullptr;
}

int Node::getValue() {
	return this->value;
}
Node *Node::getLeft() {
	return this->left;
}
Node *Node::getRight() {
	return this->right;
}
void Node::setLeft(Node *left) {
	this->left = left;
}

void Node::setRight(Node *right) {
	this->right = right;
}






