//Shania Roy
#include "Election.h"

Election::Election(){

}

void Election::AddCandidate(){
  string canName;
  int canId = 1;
  string choice;

  cout<< "would you like to add a Republican candidate? y or n ";
  cin>> choice;

  while(choice == "y")
  {
    cout<< "What is the name of your candidate? ";
    cin>> canName;

    //Candidate r(canId, canName, Party::Republican);

    Candidate * c1 = new Candidate(canId, canName, Party::Republican);
    candidates_.push_back(c1);
    canId++;

    cout<< "would you like to add a Republican candidate? y or n ";
    cin>> choice;

  }

  cout<< "would you like to add a Democratic candidate? y or n ";
  cin>> choice;

  while(choice == "y")
  {
    cout<< "What is the name of your candidate? ";
    cin>> canName;

    ///Candidate r(canId, canName, Party::Democratic);

    Candidate * c1 = new Candidate(canId, canName, Party::Democratic);
    candidates_.push_back(c1);
    canId++;

    cout<< "would you like to add a Democratic candidate? y or n ";
    cin>> choice;
  }
}

void Election::printCandidates(){
  for(int i = 0; i < candidates_.size(); i++){
    cout << candidates_[i]->Stringify() << endl;
  }
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
*/


void Election::campaign(Candidate * c, District *d)
{
  Party can = c->getAffil();
  if(can == Party::Republican){
    double p_success = ((d->party_array[1] + 1) * 2)/(d->party_array[2]) * ((d->party_array[1] + 1) * 2)/(d->get_area());
    double p_extra = p_success * 0.1;

    cout << "Chances to convert: " << p_success << endl;
    cout << "Chances to convert from another party: " << p_extra << endl;

    if(p_success > 1.00 && p_extra < 1.00){
      d->party_array[1] = d->party_array[1] + 1;
      d->party_array[0] = d->party_array[0] - 1;
      cout << "Congrats! You've converted someone from none to Republican" << endl;
    }
    else if(p_success > 1.00 && p_extra > 1.00){
      d->party_array[1] = d->party_array[1] + 2;
      d->party_array[0] = d->party_array[0] - 1;
      d->party_array[2] = d->party_array[2] - 1;
      cout << "Congrats! You've converted someone from none to Republican and someone from Democrat to Republican" << endl;;
    }
    else if(p_success > 1.00 && p_extra > 1.00 && d->party_array[0] == 0){
      d->party_array[1] = d->party_array[1] + 1;
      d->party_array[2] = d->party_array[2] - 1;
      cout << "Congrats! You've converted someone from Democrat to Republican";
    }
    else if(p_success < 1.00 || d->party_array[1] == 0){
      cout << "No one was converted" << endl;
    }
  }
  else if(can == Party::Democratic){
    double p_success = ((d->party_array[2] + 1) * 2)/(d->party_array[1]) * ((d->party_array[2] + 1) * 2)/(d->get_area());
    double p_extra = p_success * 0.1;

    cout << "Chances to convert: " << p_success << endl;
    cout << "Chances to convert from another party: " << p_extra << endl;

    if(p_success > 1.00 && p_extra < 1.00){
      d->party_array[2] = d->party_array[2] + 1;
      d->party_array[0] = d->party_array[0] - 1;
      cout << "Congrats! You've converted someone from none to Democrat" << endl;
    }
    else if(p_success > 1.00 && p_extra > 1.00){
      d->party_array[2] = d->party_array[2] + 2;
      d->party_array[0] = d->party_array[0] - 1;
      d->party_array[1] = d->party_array[1] - 1;
      cout << "Congrats! You've converted someone from none to Democrat and someone from Republican to Democrat" << endl;;
    }
    else if(p_success > 1.00 && p_extra > 1.00 && d->party_array[0] == 0){
      d->party_array[2] = d->party_array[2] + 1;
      d->party_array[1] = d->party_array[1] - 1;
      cout << "Congrats! You've converted someone from Republican to Democrat";
    }
    else if(p_success < 1.00 || d->party_array[2] == 0){
      cout << "No one was converted" << endl;
    }
  }
}
/*
Candidate Election::vote(ElectoralMap &s){
  for(auto const& x : s.district_map)
  {
    District *temp = *(x.second)
    int n_voters = temp->party_array[0];
    int r_voters = temp->party_array[1];
    int d_voters = temp->party_array[2];

    Party majority;
    if(r_voters > d_voters){
      majority = Party::Republican;
      r_voters = r_voters*.9;
      n_voters = n_voters *.7;
      temp->party_array[1] = temp->party_array[1]+n_voters;
    }
    else{
      majority = Party::Democrat;
      n_voters = n_voters *.7;
      temp->party_array[1] = temp->party_array[1]+n_voters;
    }


  }
}
*/

RepresentativeElection::RepresentativeElection(){

}
