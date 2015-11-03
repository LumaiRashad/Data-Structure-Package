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

	Node();
    Node(T x);

};

template <class T>
class LinkedList
{
public:
	Node<T> *head;
	Node<T> *tail;
	int element;
	LinkedList();
	void Append (T value);
	bool Empty();
	void Display();
	void Clear();
	void InsertAt (int index, T value);
	T DeleteAt (int index);
	void Get(int x);
};

template<class T>
Node <T>::Node()
	{
		next=NULL;
	}

template <class T>
	Node <T>::Node(T x)
	{
		value=x;
		next=NULL;
	}

template<class T>
	LinkedList<T>::LinkedList()
	{
		head=tail=NULL;
		element=0;
	}

	template <class T>
	void LinkedList<T>:: Append (T value)
	{
		Node <T> *temp = new Node <T> (value);
		if (Empty())
			head=tail=temp;
		else
		{
			tail->next=temp;
			tail= temp;
		}

		element++;
	}

	template<class T>
	bool LinkedList<T>:: Empty()
	{
		return (element==0);
	}

	template <class T>
	void LinkedList<T>:: Display()
	{
	    if(Empty())
            cout<<"The Linked List is damn empty. Fill it !!"<<endl;
        else
        {
		Node<T> *tmp=head;

		while(tmp!=NULL)
		{
			cout<<tmp->value<<endl;
			tmp=tmp->next;
		}
		cout<<"The size is: "<<element<<endl;
        }

	}

	template <class T>
	void LinkedList<T>:: Clear()
	{
		if (element==0)
		{
			return;
		}
		Node<T> *tmp;
		while(!Empty())
		{
			tmp=head;
			head=head->next;
			delete tmp;

		}
		tail=NULL;
		element=0;
	}

	template <class T>
	void LinkedList <T>:: InsertAt (int index, T value)
	{
		assert(index>=0 && index < element);
		Node <T> *insert= new Node <T>(value);
		if(index==0)
		{
			if(Empty())
				Append(value);
			else
			{
				insert->next=head;
				head=insert;
			}
		}
		else
		{
			Node <T> *temp=head;
			for(int i=0; i<index-1; i++)
				temp=temp->next;
			insert->next=temp->next;
			temp->next=insert;
		}
		element++;

	}

	template <class T>
	T LinkedList <T>::DeleteAt(int index)
	{
		assert((index>=0) && (index<element));
		Node <T> *del;
		T val;
		if(index==0)
		{
			del=head;
			val=del->value;
			head=head->next;
		}
		else
		{
			Node <T>* temp=head;
			for(int i=0; i<index-1; i++)
				temp=temp->next;
			del=temp->next;
			temp->next=del->next;
			val=del->value;
		}
		delete del;

		return val;

	}


	template <class T>
	void LinkedList <T> ::Get (int x)//index
	{
		Node <T> *temp;
		temp=head;
		for(int i=0; i<x; i++)
			temp=temp->next;
		cout<<"The value is: "<<temp->value<<endl;
	}

