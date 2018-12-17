#pragma once
class IQueue {
public:
	virtual void push(int value) = 0;
	virtual int pop() = 0;
	virtual bool contains(int value) = 0;
	virtual void print() = 0;
};
