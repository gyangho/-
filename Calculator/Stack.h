#pragma once
template <class T>
class Stack
{
	friend class Calculator;
private:
	T* stack;
	int top;
	int capacity;
public:
	Stack(int stackCapcity = 10);
	bool IsEmpty() const;
	T& Top() const;
	void Push(const T& item);
	void Pop();
	void Print();
};
