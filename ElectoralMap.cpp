#include <sstream>
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <vector>
#include <string>
#include <math.h>
#include <map>
#include <iterator>
#include "ElectoralMap.h"
#include <random>
#include <time.h>
using namespace std;

int District::class_id = 1; 


District::District() //add a map to an integer 
{
	//class_id=1; //can only set static variables like this; increments everytime that this is run 
	instance_id = class_id;
	class_id = class_id+1; //increments everytime an instance of district is made 
	area = (rand()% 25)+5; //random number between 5 and 29  

}
int District::get_id()
{
	return instance_id;
}
int District::get_area()
{
	return area; 
}



std::string District::ToString() const {
  std::stringstream stream;
  stream<<"District Id:"<<instance_id<<" Area:"<< area;
  std::string s = stream.str();
  return  s;
}
std::ostream& operator<<(std::ostream& os, const District &f)
{
	//os << sprintf("District Id: %s District area: %s", to_string(f.instance_id), to_string(f.area));
	os<<f.ToString(); 
	//string temp = string("District Area: ") + string(f.get_area()) + string("District ID:") + string(f.get_id()); 
	//	os<< temp;  
		return os; 

}

/*std::string District::ToString() const {
  std::stringstream stream;
  stream << std::fixed << std::setprecision(2) << district_map;
  std::string s = stream.str();
  return "District Map: " + s;
}
std::ostream& operator<<(std::ostream& os, const ElectoralMap &e)
{
	os<<e.ToString(); 
	return os; 

}*/


//double check friend functions 

ElectoralMap::ElectoralMap()
{
	for(int i=0; i<4; i++)
	{
		District* temp = new District();  //sets district fields; changes class id; sets area 
		district_map.insert(std::pair<int,District*>(temp->get_id(),temp)); 
	}
	
} 
District* ElectoralMap::get_district(int id)
{

	return district_map[id]; 
}
std::ostream& operator<<(std::ostream& os, const ElectoralMap &e)
{
 
	for(auto const& x : e.district_map)
	{
		os<<x.first << ":" << *(x.second) << endl; 
	}
	return os; 
}

