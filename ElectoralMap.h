#ifndef _ELECTORALMAP_H_
#define _ELECTORALMAP_H_

#include <map>
#include <sstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <iterator>
using namespace std;

class District{

public: 
District(); 
int get_id(); 
int get_area();
std::string ToString() const;
friend std::ostream& operator<<(std::ostream& os, const District &d); //function with access to private variables; 
//<<(d) function name parameter 


private: 
	static int class_id; //to be accessed from static methods; without an instance (how many)
	int instance_id; //actual id for each district 
	int area;


};

//should assign unique ids to 4 different Districts and store them in a map with id(static field)mapping to District. 
//override the operator<< for both the ElectoralMap and the District.
//District should start with a random area between 5 and 29 square miles.
class ElectoralMap{ //implements singleton design pattern 

public: 
static ElectoralMap& GetInstance(){ 

	 static ElectoralMap instance; 
	 return instance;  
}
friend std::ostream& operator<<(std::ostream& os, const ElectoralMap &e); 

District* get_district(int id);

private: 
ElectoralMap();  //private because its a singleton class 
std::map <int, District*> district_map;
}; 



#endif //ELECTORALMAP_H