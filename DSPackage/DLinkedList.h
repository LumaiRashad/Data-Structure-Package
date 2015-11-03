#pragma once
#include <iostream>
#include<string>
#include<assert.h>
using namespace std;

template<class T>
class Node{
public:
	T value;
	Node<T>* next;
	Node<T>* prev;
	Node();
	Node(T n);
};

template<class T>
Node<T>::Node()
{
	value=0;
	next=prev=NULL;
}

template<class T>
Node<T>::Node(T n)
{
	value=n;
	next=prev=NULL:
}

template<class T>
class DLinkedList
{
public:
	Node<T>*head;
	Node<T>*tail;
	int elements;

	DLinkedList();
	void AppendFront (T value);
	void AppendBack (T value);
	bool Empty();
	void DisplayForward();
	void DisplayBackward();
	void Clear();
};

template<class T>
DLinkedList<T>::DLinkedList()
{
	head=tail=NULL;
	elements=0;
}

template <class T>
bool DLinkedList<T>::Empty()
{
	return (elements==0);
}

template <class T>
void DLinkedList<T>::AppendFront( T value)
{
	Node <T> *temp = new Node <T> (value);
		if (Empty())
			head=tail=temp;
		else
		{
			head->prev=temp;
			head= temp;
		}
		elements++;
}

template <class T>
void DLinkedList<T>::AppendBack( T value)
{
	Node <T> *temp = new Node <T> (value);
		if (Empty())
			head=tail=temp;
		else
		{
			tail->next=temp;
			tail= temp;
		}
		elements++;
}

template <class T>
	void DLinkedList<T>:: DisplayForward()
	{
	    if(Empty())
            cout<<"The Doubly Linked List is damn empty. Fill it !!"<<endl;
        else
        {
		Node<T> *tmp=head;

		while(tmp!=NULL)
		{
			cout<<tmp->value<<endl;
			tmp=tmp->next;
		}
		cout<<"The size is: "<<elements<<endl;
        }

	}

	template <class T>
	void DLinkedList<T>:: DisplayBackward()
	{
	    if(Empty())
            cout<<"The Doubly Linked List is damn empty. Fill it !!"<<endl;
        else
        {
		Node<T> *tmp=tail;

		while(tmp!=NULL)
		{
			cout<<tmp->value<<endl;
			tmp=tmp->prev;
		}
		cout<<"The size is: "<<elements<<endl;
        }

	}

	template<class T>
	void DLinkedList<T>::Clear()
	{
		if (elements==0)
		{return;}

		Node<T> *tmp;
			while(!Empty())
		{
			tmp=head;
			head=head->next;
			delete tmp;

		}
		tail=NULL;
		elements=0;

	}
