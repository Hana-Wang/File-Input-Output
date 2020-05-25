//----------------------------------------------
//Task: Input scores and names of students from keyboard, and
//store these data in a binary file with the name "students.dat".
//-----------------------------------------------

#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

class CStudent{
    public:
        char szName[20];
        int  nScore;
};
int main()
{
  CStudent s;
  ofstream Outfile("students.dat", ios::out|ios::binary);
  // open a file "student.dat" by defining an ofstream object Outfile to connect
  //to the file "student.dat"

  while(cin>>s.szName>>s.nScore){
      if(strcmp(s.szName, "exit")==0)
          break;  // if input "exit", then exit the while loop
      Outfile.write((char *) & s, sizeof(s));
      //write a student data in the form of string
  }

  Outfile.close(); //close the file "students.dat"

  return 0;
}


//-----------------------------------
// Test the binaryfilewrite.cpp
//---------------------------
/*
(base) mikki7s-MacBook-Pro:CPP mikki7$ g++ binaryfilewrite.cpp -std=c++11 -o binaryfw
(base) mikki7s-MacBook-Pro:CPP mikki7$ ls
binaryfilewrite.cpp	binaryfw
(base) mikki7s-MacBook-Pro:CPP mikki7$ ./binaryfw
Tom 60
Jack 80
Jane 40
exit

exit 0
*/
