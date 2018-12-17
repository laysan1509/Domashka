#pragma once
#include <iostream>
#include "IList.h"

using namespace std;
// ���� �������� ������
struct Node
{
	// ������ ����
	int data;
	// ��������� �� ��������� �������
	Node* next;

	Node(int data) {
		this->data = data;
		this->next = nullptr;
	}
};

class LinkedList : public IList {
protected:
	// ��������� �� ������ ������
	Node *top;
	// ��������� �� ����� ������
	Node *end;
	// ���������� ���������
	int count;
public:
	// ����������� - �������������� ��������� ������
	LinkedList();
	bool isEmpty() override;
	void add(int value) override;
	void addToBegin(int value) override;
	int size() override;
	int get(int index) override;
	void remove(int index) override;
	void print() override;
	bool contains(int value) override;
};

