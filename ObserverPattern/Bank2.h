#pragma once
#include "Observer.h"
#include <iostream>
using namespace std;

class Bank2 : public Observer {
public:
	virtual void notify(int action_num) {
		cout << "BANK #2" << endl;
		int sum;
		if (action_num == 1) { //снять деньги
			cout << "Sorry, you can`t recieve money from this bank" << endl;
		}
		if (action_num == 2) {//рассчитать процент по вкладу
			cout << "Enter the sum you want to invest:  ";
			cin >> sum;
			int procent;
			if (sum <= 10000)
				cout << "Sorry, sum must be >10000" << endl;
			else {
				if (sum > 10000 && sum <= 100000)
					procent = 4;
				if (sum > 100000)
					procent = 8;
				cout << endl << "The percentage of your investment will be: " << procent << "%" << endl;
			}
		}
	}
};

