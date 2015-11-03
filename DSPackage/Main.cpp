#include "LinkedList.h"
#include "Stack.h"
#include "Queue.h"
#include "DLinkedList.h"
#include <iostream>
#include <string>
using namespace std;

int main ()
{
	Stack <int> obj;
	obj.push(1);
	obj.push(4);
	obj.push(5);
	obj.push(2);
	obj.push(1);
	obj.Display();
	obj.Clear();
	obj.Display();

	return 0;
}
