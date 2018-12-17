#include "pch.h"
#include "StackListImpl.h"

void StackListImpl::push(int value) {
	this->list->addToBegin(value);
}

int StackListImpl::pop() {
	int result = this->list->get(0);
	this->list->remove(0);
	return result;
}

bool StackListImpl::contains(int value)
{
	return this->list->contains(value);
}

void StackListImpl::print()
{
	this->list->print();
}

StackListImpl::StackListImpl(IList *list) {
	this->list = list;
}