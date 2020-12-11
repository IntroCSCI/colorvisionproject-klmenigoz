//HEADER file (interface) for analyzer class
#ifndef ANALYZER_H //Pre-processor directives
#define ANALYZER_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using std::string;
using std::vector;

class analyzer{
  
  private:

  string searchTerm;
  int linesToSearch;
  vector <int> redVals;
  vector <int> blueVals;
  vector <int> greenVals;
  int readoutLength;

  public:

  //constructor prototype for analyzer
  //analyzer();

  // overloaded constructor proto for initializer list
  analyzer():readoutLength{13},searchTerm{"color:#"},linesToSearch{300}{
  }


  //other function prototypes 

  //int chooseMenu();      is in main()

  void runSearchFunct(); //2

  void editSearchTerm(); //3

  void editLinesToSearch(); //4

  void editReadoutLength(); //5

  void readStoredHexOrDec(); //6

};

#endif