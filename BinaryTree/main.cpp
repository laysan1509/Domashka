// ConsoleApplication66.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "BinaryTree.h"
#include "Queue.h"
using namespace std;

int main()
{
	cout << "recurs" << endl;
	BinaryTree tree_1;
	tree_1.create(6);
	tree_1.print_tree();
	/*if (tree_1.find_node(10))
		cout << "yes" << endl;
	else cout << "no" << endl;*/
	Queue *queue= new Queue();
	tree_1.width(queue);
	tree_1.count_of_level();
	return 0;
}
