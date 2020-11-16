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
void readStoredHexOrDec(vector <int> &,vector <int> &,vector <int> &);
///////////////////


//search term needed to be out here for both the change term function
// ...and search function to be initialized with this information, not a 
// ... const GLOBAL_VARIABLE because we have a function for CHANGING it
string searchTerm = "color:#";


int main(){ ///////////// MAIN /////////////
  vector <int> redVals;
  vector <int> blueVals;
  vector <int> greenVals;

  int input;
  do{
  input = chooseMenu();

if(input == 1){
   runSearchFunct(searchTerm, redVals, blueVals, greenVals);
   }
  if(input == 2){
    string currentTerm = searchTerm;
    searchTerm = editSearchTerm(currentTerm);
    
    }
  if(input == 3){
    //int editReadoutLength() -> for changing the length of the hex/colorname readouts
    //more functions probably on the way, also to be called here
    }
  if(input == 4){
    readStoredHexOrDec(redVals, greenVals, blueVals);
  }
  }while(input != 5);
  return 0;
}// end main()






//////////////////         FUNCTIONS             //////////////////  
//////////////////            //                 //////////////////

int chooseMenu(){              /////-----chooseMenu function
  int input;
    cout << "\n Menu\n------\n";
    cout << "(1) Open a new file\n";
    cout << "(2) Edit search term\n";
    cout << "(3) Adjust colorInfo readout length\n";
    cout << "(4) Read some stored hex or decimal colors (run once first)\n";
    cout << "(5) Quit program\n";

    cin >> input;
    cin.ignore();
    return input;
}//end chooseMenu function

void runSearchFunct(string term, vector <int> & redVals,
    vector <int> & greenVals, vector <int> & blueVals){   /////------runSearchFunct 
  //                                                      ////          ...function
 
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
      for (int lineNum = 0; lineNum < 40; lineNum++){    //read filename by line (250 lines  
        getline(reader, text);                            //str "text" is now the current line    

        int x = text.find(hot);       //search for "hot" term, in this case "color:#"
        if (x != -1){                 //  .find outputs certain logic  ¯\_(ツ)_/¯
            string colorInfo = text.substr (x, 13);    //create substring colorInfo
              if (colorInfo != " " ){                  //
                  cout<<endl;
                  cout<<"Line "<<lineNum<<", found..."<<endl;
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
              {//  ^conditions to ensure the current color is a workable length

            string R = rBoth;        //This is so that the "dec" below knows its hex first
            unsigned int i = stoul(R, nullptr, 16);
            string G = gBoth;
            unsigned int j = stoul(G, nullptr, 16);
            string B = bBoth;
            unsigned int k = stoul(B, nullptr, 16);

          cout<<"" << dec << i;     //prints i j and k, which are the hex values, as decimal ones
          cout<<","<< dec << j;     
          cout<<","<< dec << k;
          
          redVals.push_back(i);     //here we store the HEX values
          greenVals.push_back(j);
          blueVals.push_back(k);
            

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


void readStoredHexOrDec(vector <int> & redVals,     //readStoredHexOrDec Function
    vector <int> & greenVals, vector <int> & blueVals){
      cout<< "Read Hex or Dec? (H/D)\n";
      char choice;
      cin>>choice;
      if(choice == 'H' || choice == 'h'){
        for (int i=0; i<redVals.size(); i++ ){
        cout<<"0x" << hex << redVals[i];     //prints R G and B as the hex values
        cout<<""   << hex << blueVals[i];     
        cout<<""   << hex << greenVals[i];
        cout<<endl;
        cout<<endl;
        }
      }

      else if(choice == 'D' || choice == 'd'){
        for (int i=0; i<redVals.size(); i++ ){
        cout<<"" << dec << redVals[i];     //prints R G and B,  but as decimal values
        cout<<","<< dec << blueVals[i];     
        cout<<","<< dec << greenVals[i];
        cout<<endl;
        cout<<endl;
        }
      }

    }//end readStoredHexOrDec function
