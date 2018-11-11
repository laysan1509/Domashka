#pragma once
#include "Word.h"
#include "Text.h"
#include <cstdlib>
#include <iostream>
using namespace std;
class Dictionary
{
private:
	Word *dictionary;
	int count;
public:
	Dictionary();
	Dictionary(int count);
	void push(Word word);
	Word getWord(int i);
	bool isEmpty();
	int getLenght();
	bool search(Word word);
	void create(Text text);
	void print();
	void sort();
	~Dictionary();
	void setWord(Word word, int i);
};

