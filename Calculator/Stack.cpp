#include "Stack.h"
#include <iostream>

using namespace std;

template<class T>
Stack<T>::Stack(int stackCapacity) :capacity(stackCapacity)
{
	if (capacity < 1) throw "Stack capacity must be >0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
inline bool Stack<T>::IsEmpty() const { return top == -1; }

template <class T>
inline T& Stack<T>::Top() const
{
	if (IsEmpty())throw "Stack is empty";
	return stack[top];
}

template<class T>
void Stack<T>::Push(const T& x)
{
	if (top == capacity - 1)
	{
		T* newstack = new T[2 * capacity];
		for (int i = 0; i < capacity; i++)
			newstack[i] = stack[i];
		delete[] stack;
		stack = newstack;
		capacity *= 2;
	}
	stack[++top] = x;
}

template <class T>
void Stack<T>::Pop()
{
	if (IsEmpty()) throw "Stack is empty. Cannot delete";
	stack[top--].~T();
}

template <class T>
void Stack<T>::Print()
{
	int i = 0;
	cout << "capacity: " << capacity << endl;
	cout << "top: " << top << endl;
	for (i = 0; i < top + 1; i++)
		cout << stack[i] << " ";
	cout << "\n";
}
