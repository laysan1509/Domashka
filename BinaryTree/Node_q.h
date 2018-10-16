#pragma once
#include "Node.h"
class Node_q {
private:
	Node* node;
	Node_q *next;
	Node_q *previous;
public:
	Node_q(Node* value);
	Node* getNode();
	void setNext(Node_q *next);
	Node_q *getNext();
	void setPrevious(Node_q *previous);
	Node_q *getPrevious();
};

