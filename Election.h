//Shania Roy 
#ifndef _ELECTION_H_
#define _ELECTION_H_

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
#include "ElectoralMap.h"
using namespace std;

enum class Party { None, Republican, Democratic};
string PartyStringify(Party p); 

class Election{
public:
	void campaign();
	int vote(); 
private:




};


class Candidate{ //do 
	public: 
	String Stringify();  
	String getName(){return name };
	Party getAffil(){return affil}; 
	int getId(){return id};


	private: 
	string name; 
	Party affil; 
	int id; 

}; 


class RepresentativeElection : public Election{ //inherits election 
public:  
private: 

	
};
