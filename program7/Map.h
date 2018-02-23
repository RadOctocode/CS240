#ifndef MAP
#define MAP
#include "City.h"
#include <iostream>
#include <fstream>
#include <cstring>
#include <vector>
#include <tuple>
#include <algorithm>
#include <stdlib.h> 
class Map{
	private:
		std::vector<std::pair<std::string,City*>> cities;

	public:
		Map(std::string filename);
		~Map();
		City* findByName(std::string cityName);
		int getDistance(City* start, City* end);
		City* findHelper(int min, int max, std::string cityName);
		City* findSmallest();
		std::vector<City*> shortestPath(City* start, City* dest);
		unsigned int pathDistance(City * start, City * dest); 



		
};
#endif