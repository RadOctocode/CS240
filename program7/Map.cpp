#include "Map.h"

	Map::Map(std::string filename){
		std::ifstream myfile (filename);
  		if (myfile.is_open()){
        std::string myName;
        int myX;
        int myY;
    		while (myfile>>myName>>myX>>myY){
          std::pair<std::string,City*> currentPair(myName, new City(myName,myX,myY)); 

          cities.push_back(currentPair);
    		}
        std::sort(cities.begin(),cities.end());

    		myfile.close();
  		}


      else{
        std::cout << "Unable to open file";
      } 

      for(int i=0;i<cities.size();i++){
          City* currentCity=cities[i].second;
          City* north=nullptr;
          City* south=nullptr;
          City* east=nullptr;
          City* west=nullptr;
        for(int j=0;j<cities.size();j++){

  
            if((cities[j].second->getXCoor()==currentCity->getXCoor())&&(cities[j].second->getYCoor()<currentCity->getYCoor())){
              if((south==nullptr)||(south->getYCoor()<cities[j].second->getYCoor())){
                south=cities[j].second;
              }//check if south is empty
            }//if the city is to the south

            else if((cities[j].second->getXCoor()==currentCity->getXCoor())&&(cities[j].second->getYCoor()>currentCity->getYCoor())){
              if((north==nullptr)||(north->getYCoor()>cities[j].second->getYCoor())){
                north=cities[j].second;
              }//check if south is empty
            }//if our city is to the north

            else if((cities[j].second->getYCoor()==currentCity->getYCoor())&&(cities[j].second->getXCoor()>currentCity->getXCoor())){
              if((west==nullptr)||(west->getXCoor()>cities[j].second->getXCoor())){
                west=cities[j].second;
              }//check if south is empty
            }//if the city is to the west

            else if((cities[j].second->getYCoor()==currentCity->getYCoor()) && (cities[j].second->getXCoor()<currentCity->getXCoor())){
              if((east==nullptr)||(east->getXCoor()<cities[j].second->getXCoor())){
                east=cities[j].second;
              }//check if south is empty
            }//if our city is to the east

          
        }//end of for checking for current city 
          if(north!=nullptr) {currentCity->my_push_back(north);}
          if(south!=nullptr) {currentCity->my_push_back(south);}
          if(east!=nullptr) {currentCity->my_push_back(east);}
          if(west!=nullptr) {currentCity->my_push_back(west);}


      }//for all citys 

	}//end of constructor




  Map::~Map(){
    for(int i=0; i<cities.size();i++){
      delete cities[i].second;
    }
  }//end of destructor




  City* Map::findHelper(int min, int max, std::string myCityName){
    int guess=(min+max)/2;
    if(max<min){
      return NULL;
    }

    if(cities[guess].first==myCityName){
      return cities[guess].second;
    }


    if(myCityName>cities[guess].first){
      return findHelper(guess+1,max,myCityName);
    }

    if(myCityName<cities[guess].first){
      return findHelper(min,guess-1,myCityName);
    }
  }//end of findhelper

  City* Map::findByName(std::string cityName){
    return findHelper(0,cities.size()-1,cityName);
  }//end of find



  int Map::getDistance(City* start, City* end){
    int retVal=0;
    int distance=0;
    if(start->getXCoor()==end->getXCoor()){
      distance=(start->getYCoor())-(end->getYCoor());
    }

    else{
      distance=(start->getXCoor())-(end->getXCoor());
    }
     retVal=abs(distance);
    return retVal;
  }//get distance



  City* Map::findSmallest(){
    City* retVal=nullptr;
    int currentSmallest=0;
    for(int i=0;i<cities.size();i++){
      if(((cities[i].second->distanceFromStart<currentSmallest)||(currentSmallest==0))&&((cities[i].second->visited!=true)&&(cities[i].second->distanceFromStart!=-1))){
        retVal=cities[i].second;
        currentSmallest=cities[i].second->distanceFromStart;
      }
    }
 
    return retVal;

  }//find lowesr dist



std::vector<City*> Map::shortestPath(City* start, City* dest){

    std::vector<City*> retVal;
  
    for(int i=0; i<cities.size();i++){
      City* currentFor=cities[i].second;
      currentFor->refresh();
    }//clean map
      start->distanceFromStart=0;
    start->optimalPrevious=start;


    City* currentCity=start;
    while(((currentCity!=dest)&&(dest->visited!=true))&&(currentCity!=nullptr)){
          std::list<City*> currentList=currentCity->getAdjacent();
          if(currentList.size()!=0){
          for(std::list<City*>::const_iterator iterator = currentList.begin(), end = currentList.end(); iterator != end; ++iterator){

            City* adjCity=*iterator;
            int difference=getDistance(currentCity,adjCity);
            int additionDistance=currentCity->distanceFromStart;

            if(((difference+additionDistance)<(adjCity->distanceFromStart))||(adjCity->distanceFromStart<0)){
              adjCity->optimalPrevious=currentCity;
              adjCity->distanceFromStart=difference+additionDistance;
            }

          }

        currentCity->visited=true;
        currentCity=findSmallest();
        if(currentCity==nullptr){return retVal;}
      }
    }//fill in the map


  currentCity=dest;
    
    while((currentCity!=start)&&(currentCity->optimalPrevious!=nullptr)){
      retVal.push_back(currentCity);
      currentCity=currentCity->optimalPrevious;
    }
      retVal.push_back(start);
    
    std::reverse(retVal.begin(),retVal.end());   

    return retVal;
}//end of function
  
unsigned int Map::pathDistance(City * start, City * dest){
  int retVal=0;
  std::vector<City*> returnedVector=shortestPath(start,dest);
  if(returnedVector.size()==0){
    retVal=-1;
  }

  else{
    retVal=returnedVector[(returnedVector.size()-1)]->distanceFromStart;
  }

  return retVal;

}//path







