#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "analyzer.h"

using namespace std;


int chooseMenu();


int main(){ ///////////// MAIN /////////////

  analyzer probe;   //object for probing 

  int input;
  do{
   input = chooseMenu();


  if(input == 1){
    probe.runSearchFunct();
   }

  if(input == 2){
    probe.editSearchTerm();
   }

  if(input == 3){
    probe.editReadoutLength();
   }

  if(input == 4){
    probe.editLinesToSearch();
  }

  if(input == 5){
    probe.readStoredHexOrDec();
   }
  }while(input != 6);
  return 0;
}// end main()





int chooseMenu(){///-----chooseMenu function
  int input;
    cout << "\n\u001b[96;1m Menu\u001b[0m\n------\n";
    cout << "\u001b[94;1m(1)\u001b[0m Open a new file for analyzing\n";
    cout << "\u001b[94;1m(2)\u001b[0m Edit the search term\n";
    cout << "\u001b[94;1m(3)\u001b[0m Adjust the colorInfo readout length\n";
    cout << "\u001b[94;1m(4)\u001b[0m Adjust the number of lines to search\n";
    cout << "\u001b[94;1m(5)\u001b[0m Read from stored colors (open file first)\n\n";
    cout << "\u001b[36;1m(6)\u001b[0m Quit program\n";

    std::cin >> input;
    std::cin.ignore();
    if(!(input >=0 && input <= 10 )){
     chooseMenu(); 
    }
    return input;
}//end chooseMenu function

