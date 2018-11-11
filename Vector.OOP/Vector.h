#pragma once
#include <iostream>
#include "Dictionary.h"
#include "Text.h"
#include "Word.h"

using namespace std;
class Vector
{
private:
	int *vector;
	int size;
public:
	Vector();
	Vector(int size);
	int getSize();
	int getElement(int i);
	void counting(Dictionary dictionary, Text text);
	void print();
	~Vector();
};

