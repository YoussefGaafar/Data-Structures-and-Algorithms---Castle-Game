#pragma once

#include "Generic_DS\Node.h"
template<typename T>
class LinkedListStack
{
private:
	Node<T>* Top;
	int Count;
public:
	LinkedListStack();
	LinkedListStack(const LinkedListStack<T>& S);
	bool isEmpty() const;
	bool push(const T& item);
	bool pop(T& item);
	bool peek(T& item);
	int GetCount() const;
	const T* toArray(int& count);
};

template<typename T>
LinkedListStack<T>::LinkedListStack()
{
	Top = nullptr;
	Count = 0;
}

template<typename T>
LinkedListStack<T>::LinkedListStack(const LinkedListStack<T>& S)
{
	if (!S.Top) return;
	Top = new Node<T>(S.Top->getItem());
	Node<T>* next = new Node<T>;
	Node<T>* temp = Top->getNext();
	Top->setNext(next);
	while (temp)
	{
		next->setItem(temp->getItem());
		temp = temp->getNext();
		next = next->getNext();
		next = new Node<T>;
	}
	next->setNext(nullptr);
	Count = S.Count;
}

template<typename T>
bool LinkedListStack<T>::isEmpty() const
{
	if (Top == nullptr)
		return true;
	return false;
}

template<typename T>
bool LinkedListStack<T>::push(const T& item)
{
	Node<T>* temp = new Node<T>(item);
	if (temp == nullptr)
		return false;

	if (isEmpty())
		Top = temp;
	else
	{
		temp->setNext(Top);
		Top = temp;
	}
	Count++;
	return true;
}

template<typename T>
bool LinkedListStack<T>::pop(T& item)
{
	if (isEmpty())
		return false;

	Node<T>* temp = Top;
	item = Top->getItem();
	Top = Top->getNext();
	delete temp;
	Count--;
	return true;
}

template<typename T>
bool LinkedListStack<T>::peek(T& item)
{
	if (isEmpty())
		return false;

	item = Top->getItem();
	return true;
}

template <typename T>
int LinkedListStack<T>::GetCount() const
{
	return Count;
}

template <typename T>
const T* LinkedListStack<T>::toArray(int& count)
{
	count = 0;

	if (!Top)
		return nullptr;
	//counting the no. of items in the Stack
	Node<T>* p = Top;
	while (p)
	{
		count++;
		p = p->getNext();
	}


	T* Arr = new T[count];
	p = Top;
	for (int i = 0; i < count; i++)
	{
		Arr[i] = p->getItem();
		p = p->getNext();
	}
	return Arr;
}