#include "IList.h"
const int DEFAULT_SIZE = 10;
class ArrayList : public IList {
protected:
	int *array;
	int maxSize;
	int currentSize;
public:
	ArrayList();
	bool isEmpty() override;
	void add(int value) override;
	void addToBegin(int value) override;
	int size() override;
	int get(int index) override;
	void remove(int index) override;
	void print() override;
	bool contains(int value);
};
