#include <iostream>
#include <fstream>

using namespace std;

int main(){
  //declare variables
  int red;
  int blue;
  int green;
  int choice;
  string fileName;
  fstream reader;
  string lineColor;
  
do
{

  cout<<"Enter the file name to check colors"<<endl;
  getline(cin, fileName);
  reader.open(fileName); 
  if (reader.is_open()){
    
    while(!reader.eof()){
      for (int lineNum = 0; lineNum <= fileName.length(); lineNum++){
        if (fileName == "color"){
          getline(reader,lineColor);
          cout<<lineColor<<endl;
          lineNum++;
        }
      }
    }
  }

  cout<<"Analyze another file? (y/n)"<<endl;
  cin>>choice;
  reader.close();
}while(choice == 'y');

  return 0;
}
