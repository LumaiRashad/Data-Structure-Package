#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class QueueNode
{
public:
	T value;
	QueueNode<T> *next;

	QueueNode ();
	QueueNode(T n);
};

template<class T>
QueueNode<T>::QueueNode()
{
	value=0;
	next=NULL;
}

template<class T>
QueueNode<T>::QueueNode(T n)
{
	value=n;
	next=NULL;
}


template <class T>
class Queue
{
public:
	int elements;
	QueueNode<T> *head;
	QueueNode<T> *tail;

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
	QueueNode<T>* temp=new QueueNode<T>(value);
	tail->next=temp;
	tail=temp;
	elements++;
}

template<class T>
T Queue<T>:: pop()
{
	QueueNode<T> *del=head;
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
