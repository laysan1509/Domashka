// ConsoleApplication66.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "BinaryTree.h"
#include "Queue.h"
using namespace std;

int main()
{
	int count_of_nodes, node_for_search;
	cout << "Enter count of nodes: ";
	cin >> count_of_nodes;
	BinaryTree tree;
	tree.create(count_of_nodes);
	cout << " Our tree: " << endl;
	tree.print_tree();
	cout << "Enter node`s value to search for: ";
	cin >> node_for_search;
	if (tree.find_node(node_for_search))
		cout << "The search is successful!" << endl;
	else cout << "Sorry, bro, try another value:( " << endl;
	Queue *queue = new Queue();
	cout << "Tree width output:   " << endl;
	tree.wide(queue);

	return 0;
}
