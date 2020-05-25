//----------------------------------------------
//Task: Read the students data from the file "students.dat", and
//output these data to the screen.
//-----------------------------------------------

#include<iostream>
#include<fstream>
using namespace std;

class CStudent{
    public:
        char szName[20];
        int  nScore;
};

int main(){
    CStudent s;
    ifstream inFile("students.dat", ios::in|ios::binary);
    // open the file "student.dat" by defining an ifstream object inFile to connect
    //to the file "student.dat"
    if(!inFile){
        cout<<"error"<<endl;
        return 0;
    }

    while(inFile.read((char *) & s, sizeof(s))){
      //the first parameter is the reference to the ifstream object "s"
      //and read the object "s" in the form of string, with the size of the object
        int nReadedBytes = inFile.gcount();  //number of Bytes read from the file
        cout<<s.szName<<" "<<s.nScore<<endl;
        cout<<nReadedBytes<<endl;
    }

    inFile.close();
    return 0;
}

//-----------------------------------
// Test the binaryfileread.cpp
//---------------------------
/*
(base) mikki7s-MacBook-Pro:CPP mikki7$ g++ binaryfileread.cpp -std=c++11 -o binaryfr
(base) mikki7s-MacBook-Pro:CPP mikki7$ ls
binaryfileread.cpp	binaryfr		students.dat
binaryfilewrite.cpp	binaryfw
(base) mikki7s-MacBook-Pro:CPP mikki7$ ./binaryfr
Tom 60
24
Jack 80
24
Jane 40
24
*/
