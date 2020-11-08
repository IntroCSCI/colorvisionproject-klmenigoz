#include <iostream>
#include <fstream>
#include <string>

using namespace std;

char chooseMenu();
void runSearchFunct();

int main(){ ////////////////////////////////// MAIN //////////////////////////////////////
  
  int red;      //r g and b are not 
  int blue;     //    yet being used
  int green;
  char choice;
  fstream reader;
  string hot = "color:#";    //<---important for changing search term, add FUNCTION HERE



  char input;
  input = chooseMenu();

do{

if(input == 'o' || input == 'O'){
   runSearchFunct();
  }

}while( input != 'q' && input != 'Q' );

do
{
  string fileName;
  
  cout<<endl<<"Enter a file name to check its colors"<<endl;
  cin>>fileName;

  reader.open(fileName); 
  if (reader.is_open()){
    string text;
    while(!reader.eof() ){
      for (int lineNum = 0; lineNum < 250; lineNum++){    //read filename by line (250                                                         //                     lines)
        getline(reader, text);                            //str "text" is now the current                                                    //line

        int x = text.find(hot);       //search for "hot" term, in this case "color:"
        if (x != -1){                 //  .find outputs certain logic  ¯\_(ツ)_/¯
            string colorInfo = text.substr (x, 13);    //create substring colorInfo
              if (colorInfo != " " ){                  //
                 
                  cout<< colorInfo <<endl;
          }
          }
      }
    }
  }else 
   { cout<<"Could not open file\n";
   }
   reader.close();
  cout<<"Analyze another file? (y/n)"<<endl;
  
  cin>>choice;
  
}while(choice != 'n');

  return 0;
}


char chooseMenu(){                  //chooseMenu function
  char input;
    cout << "Menu\n----\n";
    cout << "(O)pen new file\n";
    cout << "(E)dit search term\n";

    cout << "(Q)uit program\n";

    cin >> input;
    cin.ignore();
    return input;
}


void runSearchFunct(){              //search function



}