#pragma once

#include <vector>
#include "vector.h"

class MyClass
{
public:
	MyClass(int size) { this->size = size; }
	int size = 0;
};



int main()
{
	std::vector<int> test = std::vector<int>();
	Vector<int> test2 = Vector<int>();

	test.push_back(0);
	test.push_back(1);
	test.push_back(2);

	test.erase(test.begin() + 1);

	test2.push_back(0);
	test2.push_back(1);
	test2.push_back(2);
	test2.push_back(3);
	test2.push_back(4);
	test2.push_back(5);
	test2.push_back(6);
	test2.push_back(7);
	test2.push_back(8);
	test2.push_back(9);

	test2.erase(1);

	int number = test2[0];
	int number1 = test2[1];
	int number2 = test2[2];

	test2.erase(3, 5);

	int number3 = test2[3];
	int number4 = test2[4];
	int number5 = test2[5];

	test2.resize(22);

	int number20 = test2[20];
	int number21 = test2[21];

	test2.resize(31, 5);

	int number29 = test2[29];
	int number30 = test2[30];

	test2.erase_by_swap(0);


	Vector<MyClass> noDefaultConstructor = Vector<MyClass>();
	noDefaultConstructor.push_back(MyClass(15));

	return 0;
}