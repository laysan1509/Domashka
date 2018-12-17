#pragma once
#include "IStack.h"
#include "LinkedList.h"

class StackListImpl : public IStack {
private:
	IList *list;
public:
	StackListImpl(IList *list);
	void push(int value) override;
	int pop() override;
	bool contains(int value) override;
	void print() override;
};
