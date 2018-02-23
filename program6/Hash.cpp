#include "Hash.h"

	Hash::Hash(unsigned int size){
		std::pair<std::string,std::string> emptyPair("",""); 
		std::vector<std::pair<std::string,std::string>> myVector(size,emptyPair);
		passwordVector=myVector;
		currentSize=0;
	}//end of constructor

	int Hash::hasher(std::string key){

   		int i, sum;
   		for (sum=0, i=0; i < key.length(); i++){
   			sum += key[i];
   		}

   		return sum % (passwordVector.capacity());
	}//end of hasher


	bool Hash::insert(std::string key, std::string value){
		bool retVal=true;
		if(currentSize==passwordVector.capacity()){
			retVal=false;
		}// this if statement is fine

		else{
			int index=hasher(key);
			std::pair<std::string,std::string> currentPair(key,value); 
			std::pair<std::string,std::string> currentSpot=passwordVector[index];	
			while(!(std::get<0>(currentSpot)=="")){
				++index;
				if(index<passwordVector.size()){
				currentSpot=passwordVector[index];
				}

				else{
					index=0;
					currentSpot=passwordVector[index];
				}
			}
			
				passwordVector[index]=currentPair;
		
				++currentSize;
			
		}
		return retVal;
	}//end of insert


	void Hash::printHash(){
		for(int i=0; i<passwordVector.capacity();i++){
		
			std::pair<std::string,std::string> currentTuple=passwordVector[i];
			std::cout<<"Index "<< i<<"  Key "<< std::get<0>(currentTuple)<<"  Value "<<std::get<1>(currentTuple)<<'\n';
			
		}//end of for
	}//end of printhash

	std::string Hash::find(std::string key){
		int index=hasher(key);
		std::string retVal="";

		for(int i=index; i<passwordVector.size(); i++ ){
			std::pair<std::string,std::string> currentPair=passwordVector[i];

			if(key== std::get<0>(currentPair)){
				retVal=std::get<1>(currentPair);
				return retVal;
			}

		}

		for(int i=0; i<passwordVector.size();i++){
			std::pair<std::string,std::string> currentPair=passwordVector[i];

			if(key== std::get<0>(currentPair)){
				retVal=std::get<1>(currentPair);
				return retVal;
			}
		}

		return retVal;


	}

	bool Hash::empty(){
		bool retVal=false;
		if (currentSize==0){
			retVal=true;
		}
		return retVal;
	}


	bool Hash::remove(std::string key){
		bool retVal=false;
		int index=hasher(key);

		std::pair<std::string,std::string> emptyPair("",""); 

		for(int i=index; i<passwordVector.size(); i++ ){

			if(key==std::get<0>(passwordVector[i])){
				passwordVector[i]=emptyPair;
				retVal=true;
				--currentSize;

				return retVal;
			}

		}

		for(int i=0; i<passwordVector.size();i++){
			std::pair<std::string,std::string> currentPair=passwordVector[i];

			if(key== std::get<0>(currentPair)){
				passwordVector[i]=emptyPair;
				retVal=true;
				--currentSize;

				return retVal;
			}
		}
		return retVal;
	}
