
#include <iostream>
#include <fstream>
#include "pch.h"
#include "Text.h"
using namespace std;

Text::Text()
{
	words = NULL;
	lenght = 0;
}

Text::~Text()
{
}

Text::Text(int lenght)
{
	words = (Word*)malloc(lenght * sizeof(Word));
	this->lenght = lenght;
}

void Text::push(Word word)
{
	lenght++;
	words = (Word*)realloc(words, lenght * sizeof(Word));
	words[lenght - 1] = word;
}

Word Text::getWord(int i)
{
	return words[i];
}

void Text::parser(ifstream &f) {
	char symbol;
	f >> symbol;
	while (!f.eof()) {
		Word word;
		for (int i = 0; symbol != '_'; i++) {
			word.push(symbol);
			f >> symbol;
		}
		this->push(word);
		f >> symbol;
	}
}
void Text::print() {
	for (int i = 0; i < this->getLenght(); i++) {
		this->getWord(i).print();
	}
	cout << endl << endl;
}

int Text::getLenght()
{
	return lenght;
}
void Text::delete_word(int i) {
	for (int j = i; j < lenght - 1; j++)
		words[j] = words[j + 1];
	lenght--;
	words = (Word*)realloc(words, lenght * sizeof(Word));
}
void Text::normalite()
{
	for (int i = 0; i < this->getLenght(); i++) {
		int size = this->getWord(i).getSize();
		Word word(size);
		word = this->getWord(i);

		for (int j = 0; j < this->getWord(i).getSize(); j++) {
			if (!word.isLetter(j)) {
				this->delete_word(i);
				i--;
				break;
			}
			else {
				if (word.isCapital(j)) {
					word.change(j);
				}
			}
		}
	}
}

