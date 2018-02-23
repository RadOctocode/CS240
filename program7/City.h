#ifndef CITY
#define CITY
#include <iostream>
#include <cstring>
#include <list>
//#include <utility>        // std::tuple, std::get, std::tie, std::ignore
class City{
	private:
		std::string name;
		int x;
		int y;
		std::list<City*> adjacencyList;
	
		
	public:
		City(std::string cityName, int xCoor, int yCoor);
		//public vars
		bool visited;
		int distanceFromStart;
		City* optimalPrevious;
		//public vars
		std::string getName() const {return name;};
		//Returns the city name
		int getXCoor() const {return x;};
		//Returns the x coordinate
		int getYCoor() const {return y;};
		//Returns the y coordinate
		std::list<City*> getAdjacent(){return adjacencyList;};
		//Returns a copy of the adjacency list
		void my_push_back(City* myCity){adjacencyList.push_back(myCity);};
		//add to adjaceny list
		bool operator<(City &c);
		//Compares cities by name using the string operator< method;
		void refresh();
		//refresh the old disktras

		
};
#endif