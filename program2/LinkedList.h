#ifndef LINKEDLIST
#define LINKEDLIST
#include "Node.h"
#include <iostream>

template <class T>
class LinkedList{
	
	public:
		Node<T>* head;
		LinkedList(); //constructor
		LinkedList(const LinkedList<T> &myList);
		~LinkedList();//destructor
		bool insert(T myNode);
		void printWholeList();
		bool empty();
		T& read();
		bool remove(T &data);
		int iterator;
		Node<T>* iteratorNode;
	};



	template <class T>
	LinkedList<T>::LinkedList(){
		head=nullptr;
		Node<T>* iteratorNode=head;
		iterator=0;
	}//constructor





	template <class T>
	LinkedList<T>::LinkedList(const LinkedList<T> &myList){ 
			Node<T>* currentNode=myList.head;//get head and keep track of current node
			Node<T>* myNextPointer=currentNode->nextPointer;//get heads next pointer
		
			//* newHead=new T(currentNode->currentData);//create a new copy of the ant
			head=new Node<T>(currentNode->currentData);//set head
			Node<T>* currentCopyNode=head;//keep track of where in the new list we are

			while(myNextPointer!=nullptr){//while not the end of the list
				//T currentNodeData=myNextPointer->currentData;
				//T* newT=new T(currentNodeData);
				Node<T>* nextNodeCopy=new Node<T>(myNextPointer->currentData);
				currentCopyNode->nextPointer=nextNodeCopy;

				currentNode=myNextPointer;//cycle
				myNextPointer=currentNode->nextPointer;//cycle
			}

	}//copy constructor




	template <class T>
	LinkedList<T>::~LinkedList(){
		if(head!=nullptr){
			Node<T>* myNextPointer=nullptr;
			Node<T>* currentNode=head;
			while(currentNode!=nullptr){
				myNextPointer=currentNode->nextPointer;
				delete currentNode;
				currentNode=myNextPointer;
			}
		}
	}//deconstructor*/


	template <class T>
	bool LinkedList<T>::insert(T myNode){
		Node<T>* newNode=new Node<T>(myNode);
		if(head==nullptr){
			head=newNode;
			iteratorNode=head;
		}

		else{
			Node<T>* currentNode=head;
			Node<T>* myNextPointer=head->nextPointer;
			while(myNextPointer!=nullptr){
				currentNode=myNextPointer;
				myNextPointer=currentNode->nextPointer;


			}
			currentNode->nextPointer=newNode;

		}

		return true;
		
	}//end of insert



	template <class T>
	bool LinkedList<T>::remove(T &data){

		Node<T>* myNextPointer=head->nextPointer;
		Node<T>* currentNode=head;
		if((head->currentData==data)&&(head->nextPointer!=nullptr)){
			delete currentNode;
			head=myNextPointer;
			return true;
		}//special case delete only head**

		else if(head->currentData==data&&head->nextPointer==nullptr){
			delete currentNode;
			head=nullptr;
			return true;
		}

		else{
		while(myNextPointer!=nullptr){
			if((myNextPointer->currentData)==data){
				Node<T>* tempPointer=myNextPointer->nextPointer;
				delete myNextPointer;
				currentNode->nextPointer=tempPointer;
				return true;
			}
			else if((currentNode!=nullptr)&&(myNextPointer!=nullptr)){
				currentNode=currentNode->nextPointer;
				myNextPointer=currentNode->nextPointer;
			}

		}//end of while
		}
		return false;	
	}//end of remove


	template <class T>
	T& LinkedList<T>::read(){
			if(iteratorNode->nextPointer!=nullptr&&iterator>0){

				iteratorNode=iteratorNode->nextPointer;

			}
			++iterator;
			return iteratorNode->currentData;
	}//read


	template <class T>
	bool LinkedList<T>::empty(){
		bool returnVal=false;
		if(head==nullptr){returnVal=true;}
		return returnVal;	
	}//read*/


	template <class T>
	void LinkedList<T>::printWholeList(){
		Node<T>* myNextPointer=nullptr;
		Node<T>* currentNode=head;
		while(currentNode!=nullptr){
			myNextPointer=currentNode->nextPointer;
			std::cout<<"Object "<<(currentNode->currentData)<<std::endl;
			currentNode=myNextPointer;
		}
	}//printWholeList

	//i3














#endif