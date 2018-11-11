#pragma once
class Word
{
private:
	char *word;
	int size;
public:
	Word();
	~Word();
	Word(int size);
	void push(char symbol);
	int getSize();
	char getSymbol(int i);
	void setSymbol(char symbol, int i);
	void print();
	bool isCapital(int j);
	bool isLetter(int j);
	void change(int j);
	bool operator==(Word word);
};

