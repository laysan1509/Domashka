#include "pch.h"
#include "Node_q.h"

Node_q::Node_q(Node* node) {
	this->node = node;
	this->next = nullptr;
}

Node* Node_q::getNode() {
	return this->node;
}

void Node_q::setNext(Node_q *next) {
	this->next = next;
}

Node_q *Node_q::getNext() {
	return this->next;
}

void Node_q::setPrevious(Node_q *previous) {
	this->previous = previous;
}

Node_q *Node_q::getPrevious() {
	return this->previous;
}