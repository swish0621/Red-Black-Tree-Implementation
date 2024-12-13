#include <fstream>
#include <iostream>
#include "../code/WorkTrack.h"


using namespace std;

int main() {
  string input;
  RBT rbt;
  cout << "     WELCOME TO WORKTRACK" << endl;
  cout << "=================================" << endl;
  cout << "ALL INPUTS MUST BE LOWERCASE" << endl;
  cout << "ALL SPACES MUST BE ENTERED AS \"_\" " << endl;
  cout << "=================================" << endl << endl;
  cout << "COMMANDS:" << endl;
  cout << "---------" << endl;
  cout << "   SEARCH" << endl;
  cout << "   NEW" << endl;
  cout << "   DELETE" << endl;
  cout << "   SAVE" << endl;
  cout << "   LOAD" << endl;
  cout << "   CLEAR" << endl;
  cout << "   MENU" << endl;
        cout << "   QUIT" << endl << endl;
  while(input != "quit"){
    cout << "INPUT:";
    cin >> input;
    if (input == "search"){
      string customer;
      cout << endl << endl << "INPUT CUSTOMER NAME:" << endl;
      cin >> customer;
      auto it = rbt.lookup.find(customer);
      if (it != rbt.lookup.end()){
        cout << endl << customer << " HAS " << rbt.lookup.count(customer) << " JOB(S) " << endl << endl;
        for (auto itr = rbt.lookup.begin() ; itr != rbt.lookup.end() ; itr++){
          if (itr -> first == customer){
            cout << itr -> second << endl;
          }
        }
        cout << endl << "CHOOSE JOB NUMBER: " << endl;
        int job;
        cin >> job;
        Node* out = rbt.search(rbt.getRoot(), job);
        if (out == nullptr){
          cout << "NOT VALID" << endl;
        }
        else {
          cout << "   JOB NUMBER: " << out -> jobNumber << endl;
          cout << "   DATE: " << out -> job -> date[0] << "/" << out -> job -> date[1] << "/" << out -> job -> date[2] << endl;
          cout << "   EMPLOYEE: " << out -> job -> employee << endl;
          cout << "   COST: " << out -> job -> cost << endl;
          cout << "   PAID: " << out -> job -> paid << endl;
          cout << "   TIME: " << out -> job -> time << endl << endl;
        }
      }
      else {
      cout << "NOT FOUND" << endl;
      }
    }

    else if(input == "new"){
      Node* node = rbt.newNode();
      string customer;
      string month;
      string day;
      string year;
      string employee;
      string cost;
      string paid;
      string time;
      cout << endl << "ENTER CUSTOMER: " << endl;
      cin >> customer;
      cout << "ENTER MONTH: " << endl;
      cin >> month;
      cout << "ENTER DAY: " << endl;
      cin >> day;
      cout << "ENTER YEAR: " << endl;
      cin >> year;
      cout << "ENTER EMPLOYEE: " << endl;
      cin >> employee;
      cout << "ENTER COST: " << endl;
      cin >> cost;
      cout << "ENTER PAYMENT STATUS (T/F): " << endl;
      cin >> paid;
      cout << "ENTER TIME ESTIMATE: " << endl;
      cin >> time;
      node = rbt.newJob(node, customer, month, day, year, employee, cost, paid, time);
      rbt.insert(rbt.getRoot(), node);
      cout << endl << "NEW JOB CREATED:" << endl << endl;
    }

    else if(input == "delete"){
      string customer;
      cout << endl << endl << "INPUT CUSTOMER NAME:" << endl;
      cin >> customer;
      auto it = rbt.lookup.find(customer);
      if (it != rbt.lookup.end()){
        cout << customer << " HAS " << rbt.lookup.count(customer) << " JOBS " <<
        endl << endl;
        for (auto itr = rbt.lookup.begin() ; itr != rbt.lookup.end() ; itr++){
          if (itr -> first == customer){
            cout << itr -> second << endl;
          }
        }
        cout << endl << "CHOOSE JOB NUMBER: " << endl;
        int job;
        cin >> job;
        rbt.remove(rbt.getRoot(), job);
        for (auto itr = rbt.lookup.begin() ; itr != rbt.lookup.end();){
          if (itr -> second == job){
            itr = rbt.lookup.erase(itr);
          }
          else {
            ++itr;
          }
        }
        cout << endl << "JOB REMOVED" << endl;
      }
      else {
        cout << endl << "NOT FOUND" << endl;
      }
    }

    else if(input == "save"){
      rbt.save();
      cout << endl << "DATA HAS BEEN SAVED" << endl;
    }

    else if(input == "load"){
      rbt = rbt.load(rbt);
      cout << endl << "SAVE DATA LOADED" << endl;
    }

    else if(input == "clear"){
      std::ofstream file("../data.txt", std::ios::trunc);
        if (file.is_open()){
        file.close();
    }
      cout << endl << "SAVE DATA HAS BEEN CLEARED" << endl;
    }

    else if(input == "menu"){
      cout << endl << endl << "     WELCOME TO WORKTRACK" << endl;
      cout << "=================================" << endl;
      cout << "ALL INPUTS MUST BE LOWERCASE" << endl;
      cout << "ALL SPACES MUST BE ENTERED AS \"_\" " << endl;
      cout << "=================================" << endl << endl;
      cout << "COMMANDS:" << endl;
      cout << "---------" << endl;
      cout << "   SEARCH" << endl;
      cout << "   NEW" << endl;
      cout << "   DELETE" << endl;
      cout << "   SAVE" << endl;
      cout << "   LOAD" << endl;
      cout << "   CLEAR" << endl;
      cout << "   MENU" << endl;
      cout << "   QUIT" << endl << endl;
    }

    else if (input == "quit"){
      break;
    }
    else {
      cout << endl << "INVALID INPUT" << endl;
    }
    input.clear();
  }
}
