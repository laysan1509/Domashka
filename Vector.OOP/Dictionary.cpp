#include <iostream>
#include <cstdlib>
#include "pch.h"
#include "Dictionary.h"
#include "Text.h"
#include "Word.h"

using namespace std;

Dictionary::Dictionary() {
	dictionary = NULL;
	count = 0;
}

Dictionary::Dictionary(int count) {
	dictionary = (Word*)malloc(count * sizeof(Word));
	this->count = count;
}

void Dictionary::push(Word word) {
	count++;
	dictionary = (Word*)realloc(dictionary, count * sizeof(Word));
	dictionary[count - 1] = word;
}

Word Dictionary::getWord(int i)
{
	return dictionary[i];
}

bool Dictionary::isEmpty() {
	if (count == 0)
		return true;
	else return false;
}
int Dictionary::getLenght()
{
	return count;
}

bool Word::operator==(Word word) {
	bool check = true;
	if (this->getSize() >= word.getSize()) {
		for (int j = 0; j < this->getSize() && check; j++) {
			if (this->getSymbol(j) != word.getSymbol(j)) {
				check = false;
			}
		}
	}
	else {
		for (int j = 0; j < word.getSize() && check; j++) {
			if (this->getSymbol(j) != word.getSymbol(j)) {
				check = false;
			}
		}
	}
	return check;
}
bool Dictionary::search(Word word) {
	for (int i = 0; i < this->getLenght(); i++) {
		if (this->getWord(i) == word) {
			return true;
		}
	}
	return false;
}
void Dictionary::create(Text text) {
	for (int i = 0; i < text.getLenght(); i++) {
		if (this->isEmpty())
			push(text.getWord(i));
		if (!search(text.getWord(i)))
			push(text.getWord(i));
	}
}

void Dictionary::print() {
	for (int i = 0; i < this->getLenght(); i++) {
		this->getWord(i).print();
	}
	cout << endl << endl;
}

Dictionary::~Dictionary()
{
}
void Dictionary::setWord(Word word, int i) {
	dictionary[i] = word;
}
void Dictionary::sort() {
	for (int i = 0; i < (this->getLenght() - 1); i++)
	{
		for (int j = i + 1; j < this->getLenght(); j++)
		{
			for (int k = 0; this->getWord(i).getSymbol(k) != this->getWord(j).getSymbol(k); k++) {

				if (this->getWord(i).getSymbol(k) > this->getWord(j).getSymbol(k))
				{
					Word temp = this->getWord(i);
					this->setWord(this->getWord(j), i);
					this->setWord(temp, j);
				}
				break;
			}
		}
	}
}