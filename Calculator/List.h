#pragma once
#include <iostream>
using namespace std;

template <class T>
class List
{
	friend class Calculator;
private:
	T* items;
	int itemCount;
	int size;

public:
	List();
	~List();
	void addItem(T itm);
	T getItem(int index);
	int removeAt(int index);
	void print();
};