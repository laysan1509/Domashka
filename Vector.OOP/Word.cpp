#include "pch.h"
#include "Word.h"
#include <iostream>
#include <cstdlib>
using namespace std;
Word::Word()
{
	word = NULL;
	size = 0;
}

Word::~Word()
{
}

Word::Word(int size)
{
	word = (char*)malloc(size * sizeof(char));
	this->size = size;
}

void Word::push(char symbol)
{
	size++;
	word = (char*)realloc(word, size * sizeof(char));
	word[size - 1] = symbol;
}
int Word::getSize()
{
	return size;
}
char Word::getSymbol(int i) {
	return word[i];
}
void Word::setSymbol(char symbol, int i) {
	word[i] = symbol;
}
void Word::print() {
	for (int i = 0; i < this->getSize(); i++) {
		cout << this->getSymbol(i);
	}
	cout << " ";
}
bool Word::isCapital(int j) {
	if (this->getSymbol(j) >= 'A'&& this->getSymbol(j) <= 'Z')
		return true;
	else return false;
}
bool Word::isLetter(int j) {
	if (this->isCapital(j) || (this->getSymbol(j) >= 'a'&& this->getSymbol(j) <= 'z'))
		return true;
	else return false;
}
void Word::change(int j) {
	char symbol = (char)(this->getSymbol(j) + 32);
	this->setSymbol(symbol, j);
}

