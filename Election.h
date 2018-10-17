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

class Candidate{ //do
	public:
	Candidate(int id_, string name_, Party affil_);
	string Stringify();
	string getName(){return name; };
	Party getAffil(){return affil; };
	int getId(){return id; };


	private:
	string name;
	Party affil;
	int id;

};


class Election{
public:
	Election();
	void campaign(Candidate *c, District *d);
	//Candidate vote(ElectoralMap &s);
	void setPartyVal(Party,int);
	void AddCandidate();
	void printCandidates();

	vector<Candidate *> candidates_;

private:


};


class RepresentativeElection : public Election{ //inherits election
public:
	RepresentativeElection();
	vector<Candidate *> candidates_;
private:

};

#endif
