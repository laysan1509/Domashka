#include "pch.h"
#include "ArrayList.h"
#include <iostream>
using namespace std;
ArrayList::ArrayList()
{
	this->maxSize = DEFAULT_SIZE;
	this->array = new int[this->maxSize];
	this->currentSize = 0;
}

bool ArrayList::isEmpty() {
	return this->currentSize == 0;
}

void ArrayList::add(int value) {
	this->currentSize++;
	array[currentSize - 1] = value;
}

void ArrayList::addToBegin(int value) {
	this->currentSize++;
	for (int i = this->size() - 1; i > 0; i--) {
		array[i] = this->get(i - 1);
	}
	array[0] = value;
}

int ArrayList::size() {
	return this->currentSize;
}

int ArrayList::get(int index) {
	return this->array[index];
}

void ArrayList::remove(int index) {
	if (index < 0 || index>this->size()) {
		cout << " please, enter correct index" << endl;
	}
	else {
		for (int i = index; i < this->size() - 1; i++) {
			array[i] = this->get(i + 1);
		}
		this->currentSize--;

	}
}

void ArrayList::print()
{
	for (int i = 0; i < this->size(); i++) {
		cout << this->get(i) << " ";
	}
	cout << endl;
}
bool ArrayList::contains(int value) {
	// TODO: реализовать
	for (int i = 0; i < this->size(); i++) {
		if (value == this->get(i)) {
			return true;
			break;
		}
	}
	return false;
}
