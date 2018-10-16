#include "pch.h"
#include "BinaryTree.h"
#include <iostream>
using namespace std;


BinaryTree::BinaryTree()
{
	this->root = nullptr;
}

Node *BinaryTree::insert(Node *&root, int value)
{
	if (root == nullptr) {
		Node *newNode = new Node(value);
		root = newNode;
	}
	else if (root->getValue() >= value) {
		Node *temp = root->getLeft();
		root->setLeft(insert(temp, value));
	}
	else {
		Node *temp = root->getRight();
		root->setRight(insert(temp, value));
	}
	return root;
}

void BinaryTree::create(int element) {
	int value;
	for (int i = 0; i < element; i++) {
		cout << "enter value" << endl;
		cin >> value;
		this->insert(root, value);
	}
}

bool BinaryTree::find(Node *root, int element) {
	if (root == NULL)
		return false;
	if (root->getValue() == element)
		return true;
	else if (root->getValue() >= element) {
		Node *temp = root->getLeft();
		this->find(temp, element);
	}
	else {
		Node *temp = root->getRight();
		this->find(temp, element);
	}
}

bool BinaryTree::find_node(int element) {
	return this->find(root, element);
}
void BinaryTree::print(Node *root, int level) {
	if (root != nullptr)
	{
		this->print(root->getRight(), level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "   ";
		}
		cout << root->getValue() << endl;
		this->print(root->getLeft(), level + 1);
	}
}
void BinaryTree::print_tree() {
	this->print(root, 0);
}
//обход в ширину. вывод в строку
void BinaryTree::width(Queue *queue) {
	queue->push(root);
	Node *temp;
	while (!queue->isEmpty()) {
		temp = queue->pop();
		cout << temp->getValue() << " ";
		if (temp->getLeft() != nullptr) {
			Node *temp_1 = temp->getLeft();
			queue->push(temp->getLeft());
		}
		if (temp->getRight() != nullptr) {
			queue->push(temp->getRight());
		}
	}
}
//чтоб всё по красоте было
/void BinaryTree::width_print(Queue *queue) {
	queue->push(root);
	Node *temp;
	int level = 0;
	while (!queue->isEmpty()) {
		temp = queue->pop();
		cout << temp->getValue() << "-" << level << endl;
		if (temp->getLeft() != nullptr) {
			Node *temp_1 = temp->getLeft();
			queue->push(temp->getLeft());
		}
		if (temp->getRight() != nullptr) {
			queue->push(temp->getRight());
		}
	}
}
void BinaryTree::count_of_nodes(Node *root, int level) {
	if (root != nullptr)
	{
		this->count_of_nodes(root->getRight(), level + 1);
		for (int i = 0; i < level; i++)
		{
			cout << "level is "<<i<<", value is "
		}
		cout << root->getValue() << endl;
		this->count_of_nodes(root->getLeft(), level + 1);
	}
}
void BinaryTree::count_of_level() {
	this->count_of_nodes(root, 0);
}