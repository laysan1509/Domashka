// ConsoleApplication75.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "IList.h"
#include "LinkedList.h"
#include "IStack.h"
#include "StackListImpl.h"
#include "ArrayList.h"
#include "IQueue.h"
#include "QueueListImpl.h"

int main() {
	IList *list = new LinkedList();
	IStack *stack = new StackListImpl(list);
	IQueue *queue = new QueueListImpl(list);
	cout << "LIST:" << endl;
	list->add(5);
	list->add(6);
	list->add(4);
	list->addToBegin(0);
	list->print();
	list->remove(0);
	list->remove(2);
	list->print();
	cout << "get: " << list->get(1) << endl;
	int count;
	cout << "enter count for searching" << endl;
	cin >> count;
	if (list->contains(count))
		cout << "this list contains " << count << endl;
	else cout << "this list doesn`t contain " << count << endl;

	ArrayList *array = new ArrayList;
	cout << "ARRAY:" << endl;
	array->add(3);
	array->add(6);
	array->add(4);
	array->addToBegin(0);
	array->print();
	array->remove(0);
	array->remove(2);
	array->print();
	cout << "enter count for searching" << endl;
	cin >> count;
	if (array->contains(count))
		cout << "this array contains " << count << endl;
	else cout << "this array doesn`t contain " << count << endl;

	cout << "STACK:" << endl;
	stack->push(4);
	stack->push(0);
	stack->push(3);
	stack->print();
	stack->pop();
	stack->print();
	cout << "enter count for searching" << endl;
	cin >> count;
	if (stack->contains(count))
		cout << "this stack contains " << count << endl;
	else cout << "this stack doesn`t contain " << count << endl;

	cout << "QUEUE:" << endl;
	queue->push(2);
	queue->push(0);
	queue->push(7);
	queue->print();
	queue->pop();
	queue->print();
	cout << "enter count for searching" << endl;
	cin >> count;
	if (stack->contains(count))
		cout << "this stack contains " << count << endl;
	else cout << "this stack doesn`t contain " << count << endl;

	system("pause");
	return 0;
}