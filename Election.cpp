#include "Election.h"
#include <math.h>

Election::Election(){

}

void Election::AddCandidate(){
  string canName;
  int canId = 1;
  string choice;

  cout<< "Would you like to add a Republican candidate? y or n ";
  cin>> choice;

  while(choice == "y")
  {
    cout<< "What is the name of your candidate? ";
    cin>> canName;

    //Candidate r(canId, canName, Party::Republican);

    Candidate * c1 = new Candidate(canId, canName, Party::Republican);
    candidates_.push_back(c1);
    canId++;

    cout<< "Would you like to add a Republican candidate? y or n ";
    cin>> choice;

  }

  cout<< "Would you like to add a Democratic candidate? y or n ";
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

Candidate::Candidate(){

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


Party Election::vote(ElectoralMap &s){
  Party majority;

  for(auto const& x : s.district_map)
  {
    District temp = *(x.second);
    int n_voters = temp.party_array[0];
    int r_voters = temp.party_array[1];
    int d_voters = temp.party_array[2];


    if(d_voters == 0 && r_voters > d_voters){
      r_voters = r_voters + n_voters;

      temp.party_array[1] = r_voters;
      majority = Party::Republican;
    }
    else if(r_voters == 0 && d_voters > r_voters){
      d_voters = d_voters + n_voters;

      temp.party_array[2] = d_voters;
      majority = Party::Democratic;
    }
    else if(r_voters > d_voters){
      int n_majority_voters = round(n_voters * 0.7);
      int n_minority_voters = round(n_voters * 0.3);

      int r_majority_voters = round(r_voters * 0.9);
      int r_other_voters = round(r_voters * 0.1);

      int d_majority_voters = round(d_voters * 0.9);
      int d_other_voters = round(d_voters * 0.1);

      r_majority_voters = r_majority_voters + n_majority_voters + d_other_voters;
      d_majority_voters = d_majority_voters + n_minority_voters + r_other_voters;

      cout << r_majority_voters << endl;
      cout << d_majority_voters << endl;

      temp.party_array[1] = r_majority_voters;
      temp.party_array[2] = d_majority_voters;
      if(r_majority_voters > d_majority_voters){
        majority = Party::Republican;
      }
      else{
        majority = Party::Democratic;
      }
    }
    else if (d_voters > r_voters){
      majority = Party::Democratic;

      int n_majority_voters = round(n_voters * 0.7);
      int n_minority_voters = round(n_voters * 0.3);

      int d_majority_voters = round(d_voters * 0.9);
      int d_other_voters = round(d_voters * 0.1);

      int r_majority_voters = round(r_voters * 0.9);
      int r_other_voters = round(r_voters * 0.1);

      d_majority_voters = d_majority_voters + n_majority_voters + r_other_voters;
      r_majority_voters = r_majority_voters + n_minority_voters + d_other_voters;

      cout << r_majority_voters << endl;
      cout << d_majority_voters << endl;

      temp.party_array[2] = d_majority_voters;
      temp.party_array[1] = r_majority_voters;

      if(d_majority_voters > r_majority_voters){
        majority = Party::Democratic;
      }
      else{
        majority = Party::Republican;
      }
     }
  }
  return majority;
}

void Election::ElectionWinner(Party majority){

  std::vector<Candidate*> R;
  std::vector<Candidate*> D;
  Candidate *winner;
  for(int i=0; i<candidates_.size(); i++) //every candidate in
  {
    Party ofCand = candidates_[i]->getAffil();

    if(ofCand == Party::Republican )
    {
      R.push_back(candidates_[i]);
    }
    else if(ofCand == Party::Democratic)
    {
      D.push_back(candidates_[i]);
    }

  }
  
  if(majority == Party::Republican)
  {
    srand(time(NULL));
    int random = rand() % (R.size()-1) + 0;

    winner = R[random];

  }
  else if(majority == Party::Democratic)
  {
    srand(time(NULL));
    int random = rand() % (D.size()-1) + 0;

    winner = D[random];

  }

  cout<<"winner is " << winner->getName();
}

RepresentativeElection::RepresentativeElection(){

}
