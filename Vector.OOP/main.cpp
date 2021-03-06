// ConsoleApplication69.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include "Text.h"
#include "Word.h"
#include "Dictionary.h"
#include "Vector.h"
using namespace std;

int main()
{
	ifstream f("C:\\Users\\Ляйсан\\Desktop\\input1.txt");
	ifstream f2("C:\\Users\\Ляйсан\\Desktop\\input.txt");
	Text text;
	text.parser(f);
	cout << "Text from file #1:" << endl;
	text.print();
	Text text1;
	text1.parser(f2);
	cout << "Text2 from file #2:" << endl;
	text1.print();

	text.normalite();
	cout << "Text after parser:" << endl;
	text.print();

	text1.normalite();
	cout << "Text2 after parser:" << endl;
	text1.print();

	Dictionary dictionary;
	dictionary.create(text);
	cout << "Dictionary from file#1:" << endl;
	dictionary.print();
	dictionary.create(text1);
	cout << "Dictionary from file#1 + file#2:" << endl;
	dictionary.print();

	cout << "Sorting dictionary:" << endl;
	dictionary.sort();
	dictionary.print();

	Vector vector;
	cout << "Vector for Text1:" << endl;
	vector.counting(dictionary, text);
	vector.print();

	Vector vector1;
	cout << "Vector for Text2:" << endl;
	vector1.counting(dictionary, text1);
	vector1.print();

	return 0;
}


