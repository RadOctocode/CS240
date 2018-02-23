#ifndef QUEUE
#define QUEUE
#include <iostream>
#include "LinkedList.h"

template <class T>
class Queue{
	private:
		LinkedList<T>* myList;
	public:
		Queue(); //constructor
		~Queue(); //destructor
		bool enqueue(T data);//Adds a data object onto the queue and returns a boolean if successful
		T dequeue();//removes a data object from queue and returns it
		T peek();//returns a copy (not a reference) of the data object but does not remove it from the list
		bool empty();//returns a boolean, true if the queue is empty, false if it contains 1 or more elements
		void clear();//deletes all items from the queue0
		
};
	
	template <class T>
	Queue<T>::Queue(){
		myList=new LinkedList<T>();
	}

	template <class T>
	Queue<T>::~Queue(){
		delete myList;
	}

	template <class T>
	bool Queue<T>::enqueue(T myData){
		myList->insert(myData);
		return true;
	}

	template <class T>
	T Queue<T>::dequeue(){
		T headData= T(myList->head->currentData);
		myList->remove(headData);
		return headData;
	}

	template <class T>
	T Queue<T>::peek(){
		T headData= T(myList->head->currentData);
		return headData;
	}

	template <class T>
	bool Queue<T>::empty(){
		bool returnVal=true;
		Node<T>* head= myList->head;
		if(head!=nullptr){
			returnVal=false;
		}
		return returnVal;
	}

	template <class T>
	void Queue<T>::clear(){
		while(!(this->empty())){
			this->dequeue();

		}
	}

#endif