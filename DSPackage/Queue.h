#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class Node
{
public:
	T value;
	Node<T> *next;

	Node ();
	Node(T n);
};

template<class T>
Node<T>::Node()
{
	value=0;
	next=NULL;
}

template<class T>
Node<T>::Node(T n)
{
	value=n;
	next=NULL;
}


template <class T>
class Queue
{
public:
	int elements;
	Node<T> *head;
	Node<T> *tail;

	Queue();
	void Clear();
	bool Empty();
	void push( T value);
	T pop();
	T front();
	T back();

};

template< class T>
Queue<T>::Queue()
{
	elements=0;
	head=tail=NULL;
}

template <class T>
bool Queue<T>::Empty()
{
	return (elements==0);
}

template <class T>
void Queue<T>:: push(T value)
{
	Node<T>* temp=new Node<T>(value);
	tail->next=temp;
	tail=temp;
	elements++;
}

template<class T>
T Queue<T>:: pop()
{
	Node<T> *del=head;
	head=head->next;
	T val= head->value;
	delete del;
	elements--;
	return val;
}

template <class T>
T Queue<T>::front()
{
	return head->value;
}

template <class T>
T Queue<T>::back()
{
	return tail->value;
}

template <class T>
void Queue<T>::Clear()
{
	while(head!=NULL)
		pop();
}
