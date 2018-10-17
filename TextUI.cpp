#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "Election.h"
#include "ElectoralMap.h"
#include "TextUI.h"

TextUI::TextUI() {
  //main_menu_.push_back("What kind of election should we have (direct or representative, 0 to stop)?");
}

void TextUI::RouteChoice(ElectoralMap &map) {
  string choice;
  while(choice != "0"){
    cout << "What kind of election should we have (direct or representative, 0 to stop)? ";
    cin >> choice;

    if(choice == "direct"){
      Election e;
      e.AddCandidate();
      cout << map;
      e.printCandidates();

      while(choice != "0"){
        int can_id;
        cout << "Which candidate is campaigning (id) (0 to stop) ? ";
        cin >> can_id;

        Candidate * l = e.candidates_[can_id - 1];
        cout << map;

        while(choice != "0"){
          int dist_id;
          cout << "Where is this candidate campaigning (id) (0 to stop) ? ";
          cin >> dist_id;

          District * d = map.district_map[dist_id];
          e.campaign(l,d);
          cout << map;
        }
      }

      e.printCandidates();


    }

    else if(choice == "representative")
    {
      RepresentativeElection e;
      e.AddCandidate();
      e.printCandidates();
      cout << map;
    }
  }

/*
  for(int i = 0; i < e.candidates_.size(); i++){
    cout << e.candidates_[i]->Stringify() << endl;
  }
*/
}
