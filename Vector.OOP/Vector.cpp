#include "pch.h"
#include "Vector.h"
#include <iostream>
#include "Dictionary.h"
#include "Text.h"
#include "Word.h"

using namespace std;

Vector::Vector()
{
	vector = NULL;
	size = 0;
}
Vector::Vector(int size)
{
	vector = (int*)malloc(size * sizeof(int));
	this->size = size;
}
int Vector::getSize()
{
	return size;
}
int Vector::getElement(int i)
{
	return vector[i];
}
void Vector::counting(Dictionary dictionary, Text text) {
	for (int i = 0; i < dictionary.getLenght(); i++) {
		size++;
		vector = (int*)realloc(vector, size * sizeof(int));
		vector[size - 1] = 0;
		for (int j = 0; j < text.getLenght(); j++) {
			if (dictionary.getWord(i) == text.getWord(j)) {
				vector[size - 1] = this->getElement(i) + 1;
			}
		}
	}
}

void Vector::print() {
	for (int i = 0; i < this->getSize(); i++) {
		cout << this->getElement(i) << ", ";
	}
	cout << endl;
}

Vector::~Vector()
{
}
