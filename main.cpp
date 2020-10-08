#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int main(){
  

  int red;      //r g and b are not 
  int blue;     //    yet being used
  int green;
  char choice;
  fstream reader;
  string hot = "color:";    //<---important for changing search term
do
{
  string fileName;
  
  cout<<endl<<"Enter the file name to check colors"<<endl;
  cin>>fileName;

  reader.open(fileName); 
  if (reader.is_open()){
    string text;
    while(!reader.eof() ){
      for (int lineNum = 0; lineNum < 250; lineNum++){    //read filename line by line
        getline(reader, text);                            //str "text" is now the current                                                    //line

        int x = text.find(hot);       //search for "hot" term, in this case "color:"
        if (x != -1){                 //  .find outputs certain logic  ¯\_(ツ)_/¯
            string colorInfo = text.substr (x, 41);    //create substring colorInfo
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