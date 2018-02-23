#ifndef BSTREE
#define BSTREE
#include <iostream>
#include <vector>
class BSTree{
	private:
		class Node{
			private:
				int currentData;
				Node* parent;
				Node* left;
				Node* right;

			public:
				Node(int val){
					currentData=val;
					parent=nullptr;
					left=nullptr;
					right=nullptr;
				};
				~Node(){
					delete left;
					delete right;
					//parent=nullptr;
				}
				void setLeft(Node* myPointer){
					left=myPointer;
				};
				void setRight(Node* myPointer){
					right=myPointer;
				};
				void setParent(Node* myPointer){
					parent=myPointer;
				};
				void setData(int val){
					currentData=val;
				}
				Node* getLeft(){
					return left;
				};
				Node* getRight(){
					return right;
				};
				Node* getParent(){
					return parent;
				};
				int getData(){
					return currentData;
				};
		};

		Node* head;

	public:
		BSTree();
		Node* getHead() const {return head;};
		bool preOrder(Node* startNode, Node* referenceNode);
		BSTree(const BSTree &old_tree);
		~BSTree();
		bool empty();
		bool insert(int val);
		bool find(int val);
		void removeHelper(Node* deleteNode, bool direction);
		bool remove(int val);
		void sortedArray(std::vector<int> &list);
		bool inOrder(Node* startNode, std::vector<int> &tempList);		
		//Node* getHead()const{return head;};
		//remove has 3 cases 
		//del leaf
		//del branch with one child- short circut
		//del branch with 2 childeren
		//promote changes a value of the node
		//make sure to update the parent pointer
};
#endif