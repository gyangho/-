#include "List.h"
#include "String.h"
template <class T>
List<T>::List()
{
	itemCount = 0;
	size = 5;
	items = new T[size];
}

template <class T>
List<T>::~List()
{
	delete[] items;
}

template <class T>
void List<T>::addItem(T itm)
{
	if (itemCount < size)
	{
		items[itemCount] = itm;
		itemCount++;
	}
	else
	{
		T* newItems = new T[size * 2];
		for (int i = 0; i < itemCount; i++)
			newItems[i] = items[i];
		newItems[itemCount] = itm;
		itemCount++;
		delete[] items;
		items = newItems;
		size = size * 2;
	}
}
template <class T>
T List<T>::getItem(int index)
{
	if (index < itemCount)
		return items[index];
	else
		return -99999;
}


template <class T>
int List<T>::removeAt(int index)
{
	if (index >= itemCount)
		return -99999;
	T result = items[index];
	T* tmp = new T[size];
	itemCount--;
	for (int i = 0; i < itemCount; i++)
	{
		if (i >= index)
			tmp[i] = items[i + 1];
		else
			tmp[i] = items[i];
	}
	delete[] items;
	items = tmp;
	return result;
}

template <class T>
void List<T>::print()
{
	/*
	int i = 0;
	while (1)
	{
		cout << items[i].buffer << " ";
		i++;
		if (i == itemCount)
		{
			cout << "\n";
			break;
		}
	}
	*/
	int i = 0;
	while (1)
	{
		items[i].Print();
		i++;
		if (i == itemCount)
		{
			cout << "\n";
			break;
		}
	}
}
