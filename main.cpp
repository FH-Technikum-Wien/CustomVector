#pragma once

#include <vector>
#include <iostream>

#include "vector.h"

class MyClass
{
public:
	MyClass(int size) { this->size = size; }
	int size;
};

std::ostream& operator<<(std::ostream& os, const MyClass& myClass) {
	return os << "size: " << myClass.size;
}

// Prints all elements.
template<typename T>
void print(Vector<T> vector)
{
	for (std::size_t i = 0; i < vector.size(); i++) {
		std::cout << vector[i] << std::endl;
	}
}

void testConstruction();
void testPushBack();
void testErase();
void testEraseBySwap();
void testReserve();
void testResize();
void testAt();
void testAsArray();
void testBrackets();


int main()
{
	testConstruction();
	testPushBack();
	testErase();
	testEraseBySwap();
	testReserve();
	testResize();
	testAt();
	testAsArray();
	testBrackets();

	return 0;
}

void testConstruction() 
{
	Vector<int> intVector = Vector<int>();

	intVector = Vector<int>(15);
	intVector = Vector<int>(15, 20);

	Vector<MyClass> noDefault = Vector<MyClass>();
	Vector<MyClass> noDefault2 = Vector<MyClass>(15, MyClass(10));

	Vector<int> copyConstructor = Vector<int>(intVector);

	Vector<int> copyConstructor2 = copyConstructor;
}

void testPushBack() 
{
	Vector<int> intVector = Vector<int>();
	intVector.push_back(0);
	intVector.push_back(1);
	intVector.push_back(2);

	Vector<MyClass> noDefault = Vector<MyClass>();
	noDefault.push_back(MyClass(0));
	noDefault.push_back(MyClass(1));
	noDefault.push_back(MyClass(2));
}

void testErase() 
{
	Vector<int> intVector = Vector<int>();
	intVector.push_back(0);
	intVector.push_back(1);
	intVector.push_back(2);
	intVector.push_back(3);
	intVector.push_back(4);
	intVector.push_back(5);

	intVector.erase(1,5);
	intVector.erase(1);
	intVector.erase(0);

	Vector<MyClass> noDefault = Vector<MyClass>();
	noDefault.push_back(MyClass(0));
	noDefault.push_back(MyClass(1));
	noDefault.push_back(MyClass(2));

	noDefault.erase(1, 3);
	noDefault.erase(0);
}

void testEraseBySwap() 
{
	Vector<int> intVector = Vector<int>();
	intVector.push_back(0);
	intVector.push_back(1);
	intVector.push_back(2);

	intVector.erase_by_swap(2);
	intVector.erase_by_swap(0);
	intVector.erase_by_swap(0);

	Vector<MyClass> noDefault = Vector<MyClass>();
	noDefault.push_back(MyClass(0));
	noDefault.erase_by_swap(0);
}

void testReserve() 
{
	Vector<int> intVector = Vector<int>();
	intVector.reserve(15);
	intVector.reserve(1);
	intVector.reserve(30);

	Vector<MyClass> noDefault = Vector<MyClass>();
	noDefault.reserve(15);
	noDefault.reserve(1);
	noDefault.reserve(30);
}

void testResize() 
{
	Vector<int> intVector = Vector<int>();
	intVector.resize(15);
	intVector.resize(1);
	intVector.resize(30);

	intVector.resize(15, 255);
	intVector.resize(40, 1000);
}

void testAt() 
{
	Vector<int> intVector = Vector<int>();
	intVector.push_back(0);
	intVector.push_back(1);
	intVector.push_back(2);

	int& number = intVector.at(1);
	number = 20;

	Vector<MyClass> noDefault = Vector<MyClass>();
	noDefault.push_back(MyClass(0));
	noDefault.push_back(MyClass(1));
	noDefault.push_back(MyClass(2));

	MyClass& myClass = noDefault.at(2);
	myClass.size = 20;
}

void testAsArray() 
{
	Vector<int> intVector = Vector<int>();
	intVector.push_back(0);
	intVector.push_back(1);
	intVector.push_back(2);

	int* asArray = intVector.as_array();

	Vector<MyClass> noDefault = Vector<MyClass>();
	noDefault.push_back(MyClass(0));
	noDefault.push_back(MyClass(1));
	noDefault.push_back(MyClass(2));

	MyClass* noDefaultAsArray = noDefault.as_array();
}

void testBrackets() 
{
	Vector<int> intVector = Vector<int>();
	intVector.push_back(0);
	intVector.push_back(1);
	intVector.push_back(2);

	int number = intVector[2];

	Vector<MyClass> noDefault = Vector<MyClass>();
	noDefault.push_back(MyClass(0));
	noDefault.push_back(MyClass(1));
	noDefault.push_back(MyClass(2));

	MyClass myClass = noDefault[1];
}