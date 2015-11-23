#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class PQueueNode
{
public:
	T value;
	PQueueNode *next;

	PQueueNode ();
	PQueueNode(T n);
};

template<class T>
PQueueNode<T>::PQueueNode()
{
	value=0;
	next=NULL;
}

template<class T>
PQueueNode<T>::PQueueNode(T n)
{
	value=n;
	next=NULL;
}


template <class T>
class Queue
{
	int elements;
	PQueueNode<T> *head;
	PQueueNode<T> *tail;

public:
	Queue();
	void Clear();
	bool Empty();
	void push( T value);
	T pop();
	T front();
	T back();
	void Print ();

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
	PQueueNode<T>* insert=new PQueueNode<T>(value);
	if(Empty())
	{
		head=tail=insert;
		elements++;
	}

	else if(insert->value = tail->value)
	{
		elements++;
		return;
	}

	else if(insert->value > tail-value)
	{
		tail->next=insert;
		tail=insert;
		elements ++;
		return;
	}

	else if((head->value > insert->value) && (insert->value < tail-value))
	{
		insert->next=head;
		head=insert;
		elements++;
		return;
	}

	else
	{
		PQueueNode<T>* temp=head;
		while(temp!=NULL)
		{
			if(temp->next->value > insert->value)
			{
				temp=temp->next;
				insert->next=temp->next;
				temp->next=insert;
				elements++;
				return;
			}
			else
				temp=temp->next;
		}
	}
}

template<class T>
T Queue<T>:: pop()
{
	PQueueNode<T> *del=head;
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

template <class T>
void Queue<T> ::Print()
{
	DQueueNode <T>* tmp=head;
	while(tmp!=NULL)
	{
		cout<<tmp->value<<" ";
		tmp=tmp->next;
	}
}