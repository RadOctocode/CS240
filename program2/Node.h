#ifndef NODE
#define NODE
#include <iostream>

template <class T>
class Node{
	public:
		Node(T myData); //constructor
		T currentData;
		Node* nextPointer;

		
};
	
	template <class T>
	Node<T>::Node(T myData){
		currentData=myData;
		nextPointer=nullptr;
	}

#endif