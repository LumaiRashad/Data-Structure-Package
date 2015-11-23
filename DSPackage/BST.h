#pragma once
#include <iostream>
using namespace std;

template <class T>
class Node
{
public:
	T value
	Node *right;
	Node *left;
	Node();
	Node(T val);
}

template <class T>
Node<T>::Node()
{
	value=0;
	right=left=NULL;
}

template <class T>
Node<T>::Node(T val)
{
	value=val;
	right=left=NULL;
}


template <class T>
class BST
	int elements;
	Node <T> *root;
{
	BST();
	void Insert( T value);
	bool Find (T value);
}

template <class T>
BST<T>::BST()
{
	elements=0;
	root=NULL;
}

template<class T>
void BST<T>::Insert(T value)
{
   Node<T> *temp= new Node<T>(value);

   if(size==0)
    {
      root= new Node<T>(value);
      elements++;
      return;
    }
  else
    {
	Node<T> *ptr=root;
    Node<T> *parent=root;
     while(ptr!=NULL)
      {
          if(ptr->value > temp->value )
            {
               parent=ptr;
               ptr=ptr->left;
		    }
		   else if(ptr->value < temp->value)
            {
              parent=ptr;
              ptr=ptr->right;
            }
           else
				return;
      }

      if (parent->value > temp->value)
		  parent->left=temp;

	  else if(parent->value < temp->value)
		  parent->right=temp;
   }
   elements++;
}


template <class T>
bool BST<T>::Find(T value)
{
	Node<T>* ptr=root;
	while(ptr!=NULL)
	{
		if(ptr->value > value)
		{
			ptr=ptr->left;
		}
		else if (ptr->value < value)
		{
			ptr=ptr->right;
		}
		else
			return true;
	}
	return false;
}