#pragma once
#include "IQueue.h"
#include "IList.h"

class QueueListImpl : public IQueue {
private:
	IList *list;
public:
	QueueListImpl(IList *list);
	void push(int value) override;
	int pop() override;
	bool contains(int value) override;
	void print() override;
};

