#pragma once
#include "Observer.h"
#include <iostream>
using namespace std;

class Bank1 : public Observer {
public:
	virtual void notify(int action_num) {
		cout << "BANK #1" << endl;
		int sum;
		if (action_num == 1) { //снять деньги
			cout << "Enter the sum you wish to receive:  ";
			cin >> sum;
			cout << "Procent for your receiving is 5%" << endl;
			sum = sum - sum * 0.05;
			cout << "Received sum: " << sum << endl;
		}
		if (action_num == 2) {//рассчитать процент по вкладу
			cout << "Enter the sum you want to invest:  ";
			cin >> sum;
			int procent;
			if (sum <= 10000)
				procent = 3;
			if (sum > 10000 && sum <= 100000)
				procent = 5;
			if (sum > 100000)
				procent = 7;
			cout << endl << "The percentage of your investment will be: " << procent << "%" << endl;
		}
	}
};

