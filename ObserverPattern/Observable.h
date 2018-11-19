#pragma once
#include <iostream>
#include <list>
#include "Observer.h"
using namespace std;
class Observable {
public:
	list<Observer*> observers;
	void addObserver(Observer& observer) {
		observers.push_back(&observer);
	}
	virtual void notifyObserver(int action_num) = 0;
};

