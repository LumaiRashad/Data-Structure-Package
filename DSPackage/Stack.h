#pragma once
#include <iostream>
#include <string>
using namespace std;

template<class T>
class Node{
public:
	T value;
	Node<T>* next;

	Node();
	Node(T n);
};

template<class T>
Node<T>::Node()
{value=0;
next=NULL;}

template<class T>
Node<T>::Node(T n)
{value=n;
next=NULL;}


template<class T>
class Stack{
public:
	Node<T>* head;
	int elements;

	Stack();
	int Size();
	bool Empty();
	void Clear();
	void push(T val);
	T pop();
	T top();
};

template <class T>
Stack<T>::Stack()
{
	elements=0;
	head=NULL;
}

template <class T>
bool Stack<T>::Empty()
{
	return (elements==0);
}

template <class T>
int Stack <T>::Size()
{
	return elements;
}

template <class T>
void Stack<T>::push(T val)
{
	Node<T>*temp=new Node <T> (val);
		if(Empty())
			head=temp;
		else
		{
			head->next=temp;
			head= temp;
		}
		elements ++;
}

template<class T>
T Stack<T>::pop()
{
	Node <T> *del=head;
	head=head->next;
	T val=del->value;
	delete del;
	elements--;
	return val;
}

template<class T>
void Stack<T>:: Clear()
{
	while(head!=NULL)
		pop();
}

template <class T>
T Stack<T>::top()
{
	return head->value;
}

