#pragma once
#include <iostream>
#include <list>
#include <string>
#include "Observer.h"
#include "Observable.h"
using namespace std;

class Client : public Observable { //Observable class
private:
	int id;
public:
	Client(int id) {
		this->id = id;
	}
	void notifyObserver(int action_num) {
		list<Observer*>::iterator it;
		for (it = observers.begin(); it != observers.end(); it++) {
			(*it)->notify(action_num);
		}
	}
	void print() {
		cout << "client ID is " << id << endl;
	}
};

