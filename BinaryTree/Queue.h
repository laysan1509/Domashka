#pragma once
#include "Node.h"
#include "Node_q.h"
class Queue {
private:
	Node_q *tail;
	Node_q *head;
	int count;
public:
	Queue();
	bool isEmpty();
	void push(Node* value);
	void print();
	void printReverse();
	Node* pop();
};

