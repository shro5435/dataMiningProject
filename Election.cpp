//Shania Roy
#include "Election.h"

Election::Election(){

}


std::string PartyStringify(Party p) //tested and working
{


    //generate the characters
    //character

    if (p == Party::None){

         return "None";
    }
    if (p == Party::Republican){

         return "Republican";
    }
    if (p == Party::Democratic){

         return "Democratic";
    }



}

Candidate::Candidate(int id_, string name_, Party affil_){
  id = id_;
  name = name_;
  affil = affil_;
}

string Candidate::Stringify(){
	name = getName();
	affil = getAffil();
	id = getId();
	string info = "-------------------\n" + to_string(id) + ": " + name + " [Party: " + PartyStringify(affil) + "]\n";
	return info;
}
/*
int Election::Vote(){

voter v;
District c;
int ctypeVotes=0;
int nonctypeVotes=0;
int nonctypeVotes;
Party districtWinner;
if(v.getAffil() != Party::None)
 {

	Party ctype = c.getAffil();
	if(ctype == Party::Democratic)
	{
		//randomize with 70% odds that this voter votes for Democratic
	}
	if(ctype == Party::Republican)
	{
		//randomize with 70% odds that this voter votes for Republican
	}
	//how to implement ctype and a "potential voter"

}


 if(v.vote() == ctype)
 {

 	ctypeVotes = ctypeVotes+1;
 }

if(v.vote() != ctype)
{
	nonctypeVotes = nonctypeVotes+1;
}
if(ctypeVotes > nonctypeVotes)
{

	 districtWinner = ctypeVotes;
}
else{

	districtWinner = nonctypeVotes;
}
return districtWinner;
}



void Election::campaign()
{



}
*/
