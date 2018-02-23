#include "City.h"

	City::City(std::string cityName, int xCoor, int yCoor){
		name=cityName;
		x=xCoor;
		y=yCoor;
		visited=false;
		distanceFromStart=-1;
		optimalPrevious=nullptr;
	}

	bool City::operator<(City &c){
		std::string name2=c.getName();
		return name2<name;
	}

	void City::refresh(){
		visited=false;
		distanceFromStart=-1;
		optimalPrevious=nullptr;
	}
