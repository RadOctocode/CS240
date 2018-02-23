#ifndef SORTER
#define SORTER
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <cstdlib>     
#include <vector>
#include <time.h>
template <class T>
class Sorter{
	private:
		T container;

	public:
		Sorter(); //constructor
		void clear();
		unsigned int size();
		void insert(int i);
		void shuffle();
		typename T::iterator operator[](int i);
		void bubbleSort();
		void selectionSort();
		void insertionSort();
	};

	template <class T>
	Sorter<T>::Sorter(){}//constructor


	template <class T>
	void Sorter<T>::clear(){
		if(!(container.empty())){
			container.clear();
		}
	}//clear


	template <class T>
	void Sorter<T>::shuffle(){
		if((!(container.empty()))||container.size()!=1){
			

			int* mysize=new int(container.size());
			std::vector<int> tempVec;
			for(int i=0;i<*mysize;++i){
				tempVec.push_back(container.back());
				container.pop_back();
			}

			std::random_shuffle(tempVec.begin(),tempVec.end());

			for(int i=0;i<*mysize;++i){
				container.push_back(tempVec.back());
				tempVec.pop_back();
			}

			delete mysize;
		}//end of empty
	}//shuffle


	template <class T>
	void Sorter<T>::insert(int i){
		container.push_back(i);
	}//insert


	template <class T>
	unsigned int Sorter<T>::size(){
		return container.size();
	}//size


	template <class T>
	typename T::iterator Sorter<T>::operator[](int i){
		typename T::iterator returnVal=container.begin();
		for (int j=0;j<i ;j++){
			if(j<container.size()){
				returnVal++;
			}
		}
		return returnVal;
	}//end of overloaded operator

	template <class T>
	void Sorter<T>::bubbleSort(){
		typename T::iterator i;
		clock_t t=clock();
		while(!std::is_sorted(container.begin(),container.end())){
			for(i = container.begin();i != std::next(container.begin(),container.size()-1);i++){
				typename T::iterator j=std::next(i,1);
				if(*i>*j){
					std::iter_swap(i,j);
				}
			}
		}
		t=clock()-t;
		std::cout<<(((float)t)/CLOCKS_PER_SEC)<<" seconds for "<<container.size()<<" items using bubble sort"<<std::endl;
	}//bubbleSort

	template <class T>
	void Sorter<T>::selectionSort(){
		typename T::iterator i;
		typename T::iterator j;
		clock_t t=clock();
		while(!std::is_sorted(container.begin(),container.end())){
			for(i = container.begin();i != container.end();i++){
				typename T::iterator currentMin=i;

				for(j=std::next(i,1);j != container.end();j++){
					if(*j<*currentMin){
						currentMin=j;
					}
				}
				std::iter_swap(i,currentMin);
			}
		}
		t=clock()-t;
		std::cout<<(((float)t)/CLOCKS_PER_SEC)<<" seconds for "<<container.size()<<" items using selection sort"<<std::endl;
	}//selectionSort

	template <class T>
	void Sorter<T>::insertionSort(){
		typename T::iterator i;
		typename T::iterator j;
		clock_t t=clock();
		while(!std::is_sorted(container.begin(),container.end())){
			for(i = container.begin();i != container.end();i++){
				j=i;
				while(j!=container.begin()){
					j--;
					if(*j>*i){
						std::iter_swap(i,j);
					}

				}
			}
		}
		t=clock()-t;
		std::cout<<(((float)t)/CLOCKS_PER_SEC)<<" seconds for "<<container.size()<<" items using insertion sort"<<std::endl;
		
	}//insertionSort


#endif