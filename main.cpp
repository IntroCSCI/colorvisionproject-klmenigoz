#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;
///////////////////function prototypes
int chooseMenu();
void runSearchFunct(string,vector <int> &,vector <int> &,vector <int> &);
string editSearchTerm(string);
///////////////////

//some "global" vectors to store converted RGB's, not being used yet though
vector <int> redVals;
vector <int> blueVals;
vector <int> greenVals;

//the search term is also "global" 
string searchTerm = "color:#";


int main(){ ///////////// MAIN /////////////

  int input;
  do{
  input = chooseMenu();

if(input == 1){
   runSearchFunct(searchTerm,redVals,blueVals,greenVals);
   }
  if(input == 2){
    string currentTerm = searchTerm;
    searchTerm = editSearchTerm(currentTerm);
    }
  if(input == 3){
    //int editReadoutLength()     for changing the length of the readouts
    //more functions probably on the way here too
    }
  }while(input != 4);
  return 0;
}// end main()






//////////////////         FUNCTIONS             //////////////////  
//////////////////            //                 //////////////////

int chooseMenu(){              /////-----chooseMenu function
  int input;
    cout << "\n Menu\n------\n";
    cout << "(1) Open new file\n";
    cout << "(2) Edit search term\n";
    cout << "(3) Adjust colorInfo printout length\n";
    cout << "(4) Quit program\n";

    cin >> input;
    cin.ignore();
    return input;
}//end chooseMenu function

void runSearchFunct(string term, vector <int> & redVals,
    vector <int> & greenVals, vector <int> & blueVals){   /////------runSearchFunct function
 
  string fileName;
  char choice;
  fstream reader;
  string hot = term;    //<---important for changing search term, add FUNCTION HERE
  
  cout<<endl<<"Enter a file name to check its colors"<<endl;
  cin>>fileName;

  reader.open(fileName); 
  if (reader.is_open()){
    string text;
    while(!reader.eof() ){
      for (int lineNum = 0; lineNum < 40; lineNum++){    //read filename by line (250                                                         //                     lines)
        getline(reader, text);                            //str "text" is now the current                                                    //line

        int x = text.find(hot);       //search for "hot" term, in this case "color:#"
        if (x != -1){                 //  .find outputs certain logic  ¯\_(ツ)_/¯
            string colorInfo = text.substr (x, 13);    //create substring colorInfo
              if (colorInfo != " " ){                  //
                  cout<<endl;
                  cout<< colorInfo <<endl;             //print colorInfo
           // redVals.push_back(colorInfo[7],colorInfo[8]); <- something like this to store rgb's in vectors 
           // cout << hex << redVals[lineNum] << endl;

            
            char r1 = colorInfo[7]; char r2 = colorInfo[8];
              auto rBoth = string (1,r1) +r2 ;
            char b1 = colorInfo[9]; char g2 = colorInfo[10];
              auto gBoth = string (1,b1) +g2 ;
            char g1 = colorInfo[11]; char b2 = colorInfo[12];
              auto bBoth = string (1,g1) +b2 ;
         if (b2 != ' ' && g2 != '}' && g2 != ';' && g2 != ' ' && g2 != '!')  
              {//  ^contitions to ensure the present color is the correct length

            string R = rBoth;        //This is so that the "dec" below knows its hex first
            unsigned int i = stoul(R, nullptr, 16);
            string G = gBoth;
            unsigned int j = stoul(G, nullptr, 16);
            string B = bBoth;
            unsigned int k = stoul(B, nullptr, 16);

          cout<<"" << dec << i;      //converts i j, k to dec, which are the hex RGB values
          cout<<","<< dec << j;
          cout<<","<< dec << k;
       
            

          cout<<endl;
          cout<<endl;
            }else{cout<<" ^Bad....skipped!"<<endl;}
          }
          }
      }
    }
  }else 
   { cout<<"Could not open file\n";
   }
   reader.close();
  return;
}//end runSearchFunct


string editSearchTerm(string current){           //edit search term function
cout<< "\nThe curent search term is:\n"<<current<<endl;
cout<< "Would you like to change the search term? (y/n)\n";
char choice;
cin>> choice;
if(choice == 'y'){
 cout<<"Enter the new search term:\n";
 string newTerm;
 cin>> newTerm;
 cout<< "New search term:\n"<< newTerm << endl;
 return newTerm;
}else{
  return searchTerm;
 }
}//end editSearchTerm