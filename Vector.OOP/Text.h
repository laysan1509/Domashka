#pragma once
#include "Word.h"
#include <iostream>
#include <cstdlib>
#include <fstream>
using namespace std;
class Text
{
private:
	Word *words;
	int lenght;

public:
	Text();
	~Text();
	Text(int size);
	void push(Word word);
	Word getWord(int i);
	void parser(ifstream & f);
	void print();
	int getLenght();
	void normalite();
	void delete_word(int i);
};

