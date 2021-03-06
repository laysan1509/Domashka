// ConsoleApplication73.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include "Observer.h"
#include "Observable.h"
#include "Client.h"
#include "Bank2.h"
#include "Bank1.h"
using namespace std;

int main() {
	Client client(1);
	Bank2 bank2;
	Bank1 bank1;
	client.addObserver(bank1);
	client.addObserver(bank2);
	int action_num;
	cout << "Enter 1 if you wish to receive money" << endl << "Enter 2 if you want to invest money" << endl;
	cin >> action_num;
	client.notifyObserver(action_num);
	return 0;
}

