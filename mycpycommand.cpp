//----------------------------------------------
//Task: create a command line code to copy data from one
//file(source file) to another desitination file(destination file)
//sample command line code:
//mycopy src.dat dest.dat
//-----------------------------------------------

#include<iostream>
#include<fstream>
using namespace std;

class CStudent{
    public:
        char szName[20];
        int  nScore;
};

int main(int argc, char * argv[]){
//this is the way to write command line code; the parameters in the
//function "main" gives the number of arguments and arguments.
   CStudent s;

   if(argc != 3){
   // from the sample code: mycopy src.dat dest.dat, we need three arguments
      cout<<"File name missing!"<<endl;
      return 0;
   }

   ifstream inFile(argv[1], ios::binary|ios::in);
   //open a file "argv[1]" to read

   if(!inFile){
       cout<<"Source file open error."<<endl;
       return 0;
   }

   //ofstream outFile(argv[2], ios::binary|ios::out);
   fstream ioFile(argv[2], ios::binary|ios::out|ios::in);
   //open a file "argv[2]" to write

   if(!ioFile){
       cout<<"New(Destination) file open error."<<endl;
   }

   char c;
   while(inFile.get(c))
   // every time read a character from a file "argv[1]" to char typ variable c;
        ioFile.put(c);
       //write the character in the file "argv[2]"

   cout<<"Output the destination file with the name:"<<" "<<argv[2]<<endl;
   ioFile.seekg(0, ios::beg);
       //set file reading pointer from the beginning of the file "students.dat"
   while(ioFile.read((char *) & s, sizeof(s)))
   //the first parameter is the reference to the fstream object "s"
   //and read the object "s" in the form of string, with the size of the object
       cout<<s.szName<<" "<<s.nScore<<endl;


   ioFile.close();   //close the file to write
   inFile.close(); //close the file to read

   return 0;
}

//-----------------------------------
// Test the mycpycommand.cpp
//---------------------------
/*
(base) mikki7s-MacBook-Pro:CPP mikki7$ g++ mycpycommand.cpp -std=c++11 -o mycpy
(base) mikki7s-MacBook-Pro:CPP mikki7$ ./mycpy students.dat student1.dat
Output the destination file with the name: student1.dat
Tom 60
Mike 80
Jelly 70
Grace 70
kally 55
Kelly 65
*/
