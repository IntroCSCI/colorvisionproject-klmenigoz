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
  vector <int> redVals;   //
  vector <int> blueVals;  //the color values from file
  vector <int> greenVals; //...are stored here
  int readoutLength;

  public:

  //constructor prototype for analyzer (not being used currently)
  //analyzer();   

  // overloaded constructor prototype for initializer list
  analyzer():readoutLength{13},searchTerm{"color:#"},linesToSearch{300}{
  }


  //other function prototypes 

  //int chooseMenu(); is located in main.cpp

  void runSearchFunct(); //1

  void editSearchTerm(); //2

  void editLinesToSearch(); //3

  void editReadoutLength(); //4

  void readStoredHexOrDec(); //5

};

#endif