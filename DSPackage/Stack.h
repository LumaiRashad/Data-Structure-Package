#pragma once
#include <iostream>
#include <string>
using namespace std;

template <class T>
class StackNode
{
public:
	StackNode();
	StackNode(T val);
	StackNode<T> *next;
	T value;
};


template <class T>
class Stack
{
	StackNode<T> *head;
	int elements;
public:
	Stack();
	int Size();
	bool Empty();
	void Clear();
	void push(T val);
	T pop();
	void Display();
	T top();
};


template<class T>
StackNode<T>::StackNode()
{
	next=NULL;
	value=0;
}

template<class T>
StackNode<T>::StackNode(T val)
{
	next=NULL;
	value=val;
}



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
void Stack<T>::push(T val)
{
	StackNode<T> *temp= new StackNode <T> (val);

		if(Empty())
			head=temp;

		else
		{
			temp->next=head;
			head= temp;
		}
		elements++;
}

template<class T>
T Stack<T>::pop()
{
	T val;
	if (Empty())
		cout<<"You can't pop"<<endl;
	else
	{
	StackNode <T> *del=head;
	head=head->next;
    val=del->value;
	delete del;
	}
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
void Stack<T>::Display()
{
	if(Empty())
		cout<<endl<<"The Stack is empty!!"<<endl;
	else
    {
	StackNode<T> *temp = head;
	while(temp!=NULL)
	{
		cout<<temp->value<<"  ";
		temp=temp->next;
	}
    }
	cout<<endl<<"The size is: "<<elements<<endl;
}

template <class T>
T Stack<T>::top()
{
	return head->value;
}
