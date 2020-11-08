#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int chooseMenu();
void runSearchFunct(string);
string editSearchTerm(string);


string searchTerm = "color:#";
     
int main(){ ////////////////////////////////// MAIN //////////////////////////////////////

  int input;
  do{
  input = chooseMenu();

if(input == 1){
   runSearchFunct(searchTerm);
   }
  if(input == 2){
    string currentTerm = searchTerm;
    searchTerm = editSearchTerm(currentTerm);
    }
  if(input == 3){
    //int editReadoutLength()
    }
  }while(input != 4);
  return 0;
}






//////////////////         FUNCTIONS             //////////////////  
//////////////////            //                 //////////////////

int chooseMenu(){                  /////-----chooseMenu function
  int input;
    cout << "\n Menu\n------\n";
    cout << "(1) Open new file\n";
    cout << "(2) Edit search term\n";
    cout << "(3) Adjust colorInfo printout length\n";
    cout << "(4) Quit program\n";

    cin >> input;
    cin.ignore();
    return input;
}

void runSearchFunct(string term){            /////------runSearchFunct function
 
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
      for (int lineNum = 0; lineNum < 250; lineNum++){    //read filename by line (250                                                         //                     lines)
        getline(reader, text);                            //str "text" is now the current                                                    //line

        int x = text.find(hot);       //search for "hot" term, in this case "color:#"
        if (x != -1){                 //  .find outputs certain logic  ¯\_(ツ)_/¯
            string colorInfo = text.substr (x, 13);    //create substring colorInfo
              if (colorInfo != " " ){                  //

                  cout<< colorInfo <<endl;             //print colorInfo


          }
          }
      }
    }
  }else 
   { cout<<"Could not open file\n";
   }
   reader.close();
  return;
}


string editSearchTerm(string current){
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

}