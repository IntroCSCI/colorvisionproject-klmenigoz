#include <iostream>
#include <fstream>
#include <string>

using namespace std;




int main(){
  //declare variables

  int red;
  int blue;
  int green;
  char choice;
  fstream reader;
  string hot = "color:";
do
{
  string fileName;
  
  cout<<endl<<"Enter the file name to check colors"<<endl;
  cin>>fileName;

  reader.open(fileName); 
  if (reader.is_open()){
    string text;
    while(!reader.eof() ){
      for (int lineNum = 0; lineNum < fileName.length(); lineNum++){
        getline(reader, text);
          


        int x = text.find(hot);
        if (x != -1){
        string colorInfo = text.substr (x, 18);
        if (colorInfo != " " ) 
          {
          
        
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