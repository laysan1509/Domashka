#include "pch.h"
#include "LinkedList.h"

LinkedList::LinkedList() {
	// this - указатель на экземпл€р, дл€ которого был
	// произведен вызов функции/конструктора
	(*this).top = nullptr;
	this->end = nullptr;
	this->count = 0;
}

bool LinkedList::isEmpty() {
	return this->top == nullptr;
}

void LinkedList::add(int value) {
	Node *newNode = new Node(value);
	if (this->end != nullptr) {
		this->end->next = newNode;
	}
	else {
		this->top = newNode;
	}
	this->end = newNode;
	this->count++;
}

void LinkedList::addToBegin(int value) {
	Node *newNode = new Node(value);
	this->count++;
	if (this->isEmpty()) {
		this->top = newNode;
		this->end = newNode;
	}
	else {
		newNode->next = this->top;
		this->top = newNode;
	}

}

int LinkedList::size() {
	return this->count;
}

int LinkedList::get(int index) {
	// TODO: реализовать
	Node *current = this->top;
	if (this->isEmpty())
		return 0;
	else {
		for (int kol = 0; kol < this->size(); kol++) {
			if (kol == index) {
				return current->data;
				break;
			}
			current = current->next;
		}
	}
	return -1;
}


void LinkedList::remove(int index) {
	if (index < 0 || index>this->size()) {
		cout << " please, enter correct index" << endl;
	}
	else {
		Node *current = this->top;
		Node *saving = NULL;
		if (this->isEmpty()) {
			cout << "list is empty (like you)" << endl;
		}
		else {
			if (index == 0 && this->size() == 1) {
				this->top = nullptr;
				this->end = nullptr;
				delete current;
			}
			else if (index == 0) {
				this->top = current->next;
				delete current;
			}
			else {
				for (int i = 0; current->next != nullptr; i++) {
					if (index == i + 1) {
						if (index == this->size() - 1) {
							saving = current->next;
							this->end = saving;
							delete saving;
						}
						else {
							saving = current->next;
							current->next = current->next->next;
							delete saving;
						}
						break;
					}
					current = current->next;
				}
			}
		}
		this->count--;
	}
}
void LinkedList::print() {
	Node *current = this->top;
	for (int i = 0; i < this->size(); i++) {
		cout << current->data << " ";
		current = current->next;
	}
	cout << endl;
}
bool LinkedList::contains(int value) {
	// TODO: реализовать
	for (int i = 0; i < this->size(); i++) {
		if (value == this->get(i)) {
			return true;
			break;
		}
	}
	return false;
}
