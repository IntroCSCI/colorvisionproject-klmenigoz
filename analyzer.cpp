#include "analyzer.h"
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>


using std::cout;
using std::cin;
using std::endl;
using std::string;


//////////////////         FUNCTIONS             //////////////////  
//////////////////            //                 //////////////////




void analyzer::runSearchFunct(){   /////------runSearchFunct 
  //                        ////          ...function

  string fileName;
  char choice;
  std::fstream reader;
  string hot = searchTerm;    //<---important for changing search term, add FUNCTION HERE
  
  cout<<endl<<"Enter a file name to check its colors:\nFor example, try entering w3schools.html\n"<<endl;
  std::cin>>fileName;

  reader.open(fileName); 
  if (reader.is_open()){
    string text;


      for (int lineNum = 1; lineNum < linesToSearch; lineNum++){    //read filename by line  
        getline(reader, text);                            //str "text" is now the current line    

        int x = text.find(hot);       //search for "hot" term, in this case "color:#"
        if (x != -1){                 //  .find outputs certain logic  ¯\_(ツ)_/¯
            string colorInfo = text.substr (x, readoutLength); //create substring colorInfo, default readout len 
              if (colorInfo != " " ){                  //
                  cout<<endl;
                  cout<<"Line "<<lineNum<<", found..."<<endl;
                  cout<< "\u001b[93;1m" << colorInfo << "\u001b[0m" <<endl; //print colorInfo

            
            char r1 = colorInfo[7]; char r2 = colorInfo[8];
              auto rBoth = string (1,r1) +r2 ;
            char b1 = colorInfo[9]; char g2 = colorInfo[10];
              auto gBoth = string (1,b1) +g2 ;
            char g1 = colorInfo[11]; char b2 = colorInfo[12];
              auto bBoth = string (1,g1) +b2 ;
         if (b2 != ' ' && g2 != '}' && g2 != ';' && g2 != ' ' && g2 != '!')  
              {//  ^conditions to ensure the current color is a workable length

            string R = rBoth;        //This is so that the "dec" below knows its hex first
            unsigned int i = stoul(R, nullptr, 16);
            string G = gBoth;
            unsigned int j = stoul(G, nullptr, 16);
            string B = bBoth;
            unsigned int k = stoul(B, nullptr, 16);

          cout<<"" << std::dec << i; //prints i j and k, which are the hex values, as decimal ones
          cout<<","<< std::dec << j;     
          cout<<","<< std::dec << k;
          
          
          redVals.push_back(i);  //here we store the HEX values
          greenVals.push_back(j);
          blueVals.push_back(k);
            

          cout<<endl;
          cout<<endl;
            }else{cout<<"\u001b[91;1m ^Bad....skipped!\u001b[0m\n"<<endl;}
          }
          }
      }

  }else 
   { cout<<"Could not open file\n";
   }
   reader.close();
  return;
}//end runSearchFunct



void analyzer::editSearchTerm(){  //edit search term function
cout<< "\nThe curent search term is: \u001b[93;1m"<<searchTerm<<endl;
cout<< "\u001b[0mWould you like to change the search term? (y/n)\n";
char choice;
cin>> choice;
if(choice == 'y' || choice == 'Y'){
 cout<<"Enter the new search term:\n";
 string newTerm;
 cin>> newTerm;
 cout<< "New search term:\n\u001b[93;1m"<< newTerm <<"\u001b[0m\n";
 searchTerm = newTerm;
  }
  return;
}//end editSearchTerm



void analyzer::editReadoutLength(){         //edit readout function def
    cout<< "\nThe curent readout length is: \u001b[93;1m"<<readoutLength<<endl;
    cout<<"\u001b[0mChange readout length? (y/n)\n";
    char input;
    cin>>input;
    if(input == 'Y' || input == 'y' ){
      cout<<"\nDefault: 13\nCurrent: "<<readoutLength<<"\nNew: ";
      int newLength;
      cin>>newLength;
      readoutLength = newLength;
      cout <<"New readout length: \u001b[93;1m"<<readoutLength<<"\u001b[93;1m\n";
      
    }
    return;
}



void analyzer::editLinesToSearch(){   //lines to search function def
cout<< "\nThe curent line target is: \u001b[93;1m"<<linesToSearch<<endl;
cout<<"\u001b[0mChange the number of lines to search? (y/n)\n";
    char input;
    cin>>input;
    if(input == 'Y' || input == 'y' ){
      cout<<"\nDefault: 300\nCurrent: "<<linesToSearch<<"\nNew: ";
      int newLines;
      cin>>newLines;
      linesToSearch = newLines;
      cout <<"New line target:\u001b[93;1m "<<linesToSearch<<"\u001b[0m\n";
  }
  return;
}



void analyzer::readStoredHexOrDec(){  //readStoredHexOrDec Function
      cout<< "Read Hex or Dec? (h/d)\n";
      char choice;
      cin>>choice;
      if(choice == 'H' || choice == 'h'){
        cout<<"\u001b[95;1mReading from stored hexadecimal values: \n\n\u001b[0m";
        for (int i=0; i<redVals.size(); i++ ){
        cout<<"0x\u001b[97;1m" << std::hex << redVals[i];//prints R G and B as hex 
        cout<<""   << std::hex << blueVals[i];     
        cout<<""   << std::hex << greenVals[i]<<"\u001b[0m";
        cout<<endl;
      
        }
      }

      else if(choice == 'D' || choice == 'd'){
        cout<< "\u001b[95;1mReading from stored decimal values: \n\n\u001b[0m";
        for (int i=0; i<redVals.size(); i++ ){
        cout<<"" << std::dec << redVals[i];//prints R G and B,  but as decimal values
        cout<<","<< std::dec << blueVals[i];     
        cout<<","<< std::dec << greenVals[i];
        cout<<endl;
      
        }
      }
      return;
    }//end readStoredHexOrDec function


