#include <iostream>
#include "BSTree.h"
#include <vector> 
	BSTree::BSTree(){
		head=nullptr;
	}//constructor


	BSTree::~BSTree(){
		delete head;
	}//destructor


	bool BSTree::empty(){
		bool returnValue=false;
		if(head==nullptr){
			returnValue=true;
		}
		return returnValue;
	}//empty

	bool BSTree::preOrder(Node* startNode, Node* referenceNode){
		if(referenceNode==nullptr){
			return true;
		}
			Node* rightNode=referenceNode->getRight();
			Node* leftNode=referenceNode->getLeft();
			if(rightNode!=nullptr){
				Node* newRight=new Node(rightNode->getData());
				startNode->setRight(newRight);

			}
			if(leftNode!=nullptr){
				Node* newLeft=new Node(leftNode->getData());
				startNode->setLeft(newLeft);
			}
		
		preOrder(startNode->getLeft(), referenceNode->getLeft());
		preOrder(startNode->getRight(), referenceNode->getRight());

	}//post order*/


	BSTree::BSTree(const BSTree &oldTree){
		Node* oldTreeHead= oldTree.getHead();
		if(oldTreeHead){
			head=new Node(oldTreeHead->getData());
		}
		preOrder(head, oldTreeHead);
	}

	bool BSTree::insert(int val){
		Node* myNode=new Node(val);
		Node* currentNode=head;
		Node* parentNode=nullptr;
		bool returnValue=true;
		bool leftOrRight=false;

		if(currentNode==head&&head==nullptr){
			head=myNode;		
		}

		else{
			 while(currentNode!=nullptr){
				if((currentNode->getData())>(myNode->getData())){
					parentNode=currentNode;
					leftOrRight=false;
					currentNode=currentNode->getLeft();
				}
				else if((currentNode->getData())<(myNode->getData())){
					parentNode=currentNode;
					leftOrRight=true;
					currentNode=currentNode->getRight();
				}
				else if((currentNode->getData())==(myNode->getData())){
					returnValue=false;
					delete myNode;
					return returnValue;
					break;
				}
			}//cycle
				myNode->setParent(parentNode);
				if(!leftOrRight){
					parentNode->setLeft(myNode);
				}
				else{
					parentNode->setRight(myNode);
				}

		}//end of else

		return returnValue;
	}//end of insert


	bool BSTree::find(int val){
		Node* currentNode=head;
		bool nodeFound=false;

		while(currentNode!=nullptr){
			if((currentNode->getData())>val){
				currentNode=currentNode->getLeft();
			}
			else if((currentNode->getData())<val){
				currentNode=currentNode->getRight();
			}
			else if(currentNode->getData()==val){
				nodeFound=true;
				return nodeFound;
				break;
			}

		}
		return nodeFound;
	}//end of find


	void BSTree::removeHelper(Node* deleteNode, bool direction){
		Node* parentNode=deleteNode->getParent();

		if(parentNode!=nullptr){
			if(deleteNode->getLeft()==nullptr&&deleteNode->getRight()==nullptr){
				if(direction){
					parentNode->setRight(nullptr);
				}
				else if(!direction){
					parentNode->setLeft(nullptr);
				}
				if(deleteNode->getParent()==nullptr){
					head=nullptr;	
				}
				delete deleteNode;
			}//leaf case

			else if(deleteNode->getLeft()==nullptr||deleteNode->getRight()==nullptr){
				Node* child;
				if(deleteNode==parentNode->getLeft()){

					if(deleteNode->getLeft()!=nullptr){
						child=deleteNode->getLeft();
						child->setParent(parentNode);
						if(parentNode==nullptr){
							head=child;
						}
						else{
							parentNode->setLeft(child);

						}
					}
					else{
						child=deleteNode->getRight();
						parentNode->setLeft(child);
						child->setParent(parentNode);
						if(deleteNode->getParent()==nullptr){
							head=child;
						}
					}

				}//end left

				//right
				else{
				
					if(deleteNode->getLeft()!=nullptr){
						child=deleteNode->getLeft();
						parentNode->setRight(child);
						child->setParent(parentNode);
						if(deleteNode->getParent()==nullptr){
							head=child;
						}
					}
					else{
						child=deleteNode->getRight();
						child->setParent(parentNode);
						if(deleteNode->getParent()==nullptr){
							head=child;
						}
					}
				}//right
		
				deleteNode->setParent(nullptr);
				deleteNode->setRight(nullptr);
				deleteNode->setLeft(nullptr);

				delete deleteNode;

			}//one branch
			else if(deleteNode->getLeft()!=nullptr&&deleteNode->getRight()!=nullptr){
				Node* promotionNode=deleteNode->getRight();
				Node* iteratorNode=deleteNode->getRight()->getLeft();
				while(iteratorNode!=nullptr){
					if(promotionNode->getLeft()!=nullptr){
						promotionNode=promotionNode->getLeft();
					
					}
					iteratorNode=iteratorNode->getLeft();
				}
				deleteNode->setData(promotionNode->getData());
				Node* promoParent=promotionNode->getParent();
				if(promotionNode->getRight()!=nullptr){
					if(promotionNode==promoParent->getRight()){
						promoParent->setRight(promotionNode->getRight());
						(promotionNode->getRight())->setParent(promoParent);
					}//if on thkje right
					else{
						promoParent->setLeft(promotionNode->getRight());
						(promotionNode->getRight())->setParent(promoParent);
					}//if on the left

				}
				else{
					promotionNode->getParent()->setLeft(nullptr);
				}
				promotionNode->setRight(nullptr);
				delete promotionNode;
					
			}//2 branches
			}//is this the head node?

			else{
				if(deleteNode->getLeft()==nullptr&&deleteNode->getRight()==nullptr){
					head=nullptr;
					delete deleteNode;
				}//

				else if(deleteNode->getLeft()==nullptr||deleteNode->getRight()==nullptr){
					if(deleteNode->getLeft()!=nullptr){
						Node* myChild=deleteNode->getLeft();
						myChild->setParent(nullptr);
						head=myChild;
						

					}//if left 
					else{
						Node* myChild=deleteNode->getRight();
						myChild->setParent(nullptr);
						head=myChild;
					}
						deleteNode->setParent(nullptr);
						deleteNode->setRight(nullptr);
						deleteNode->setLeft(nullptr);
						delete deleteNode;

				}//end left

				else if(deleteNode->getLeft()!=nullptr&&deleteNode->getRight()!=nullptr){
					Node* promotionNode=deleteNode->getRight();
					Node* iteratorNode=deleteNode->getRight()->getLeft();
					while(iteratorNode!=nullptr){
						if(promotionNode->getLeft()!=nullptr){
							promotionNode=promotionNode->getLeft();
						
						}
						iteratorNode=iteratorNode->getLeft();
					}
					deleteNode->setData(promotionNode->getData());
					Node* promoParent=promotionNode->getParent();
					if(promotionNode->getRight()!=nullptr){
						if(promotionNode==promoParent->getRight()){
							promoParent->setRight(promotionNode->getRight());
							(promotionNode->getRight())->setParent(promoParent);
						}//if on thkje right
						else{
							promoParent->setLeft(promotionNode->getRight());
							(promotionNode->getRight())->setParent(promoParent);
						}//if on the left

					}
					else{
						promotionNode->getParent()->setLeft(nullptr);
					}
					promotionNode->setRight(nullptr);
					delete promotionNode;
						
				}//2 branches

			}

	}//end of remove helper


	bool BSTree::remove(int val){

		Node* currentNode=head;
		bool leftOrRight=false;
		bool nodeDel=false;
		
		while(currentNode!=nullptr){
			if((currentNode->getData())>val){
				currentNode=currentNode->getLeft();
				leftOrRight=false;
			}
			else if((currentNode->getData())<val){
				currentNode=currentNode->getRight();
				leftOrRight=true;
			}
			else if(currentNode->getData()==val){

				removeHelper(currentNode, leftOrRight);
				nodeDel=true;
				return nodeDel;
				break;
			}

		}
		
		return nodeDel=false;
	}//end of remove


	bool BSTree::inOrder(Node* startNode, std::vector<int> &tempList){
		if(startNode==nullptr){return true;}
		inOrder(startNode->getLeft(),tempList);
		tempList.push_back(startNode->getData());
		inOrder(startNode->getRight(),tempList);
		
	}//end of in order


	void BSTree::sortedArray(std::vector<int> &list){
		Node* currentNode=head;
		inOrder(currentNode,list);
		std::cout<<std::endl;
	}//end of sorted array


//print out binary tree
//add numbers to a queue
//have each parent read in its children and add it to the queue left first then right
//print each element as a "node"
