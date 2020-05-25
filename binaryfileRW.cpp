//----------------------------------------------
//Task: Modify some students data from the file "students.dat", and
//change student "Jack" to "Mike",
//and change "Jane 40" to "Grace 70"
//and output the students data to the standard output device.
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
    fstream iofile("students.dat", ios::in|ios::out|ios::binary);
    // open the file "student.dat" by defining an fstream
    //object 'iofile' to connect to the file "student.dat"

    if(!iofile){
        cout<<"error";
        return 0;
    }


    iofile.seekp(2*sizeof(s), ios::beg);
    //move the file writing handle(pointer) to
    //the beginning of the third student "Jane" in the file
    strcpy(s.szName, "Jelly");
    //cannot assign to array, instead, copy to it using strcpy
    s.nScore = 70;
    iofile.write( (char *) & s, sizeof(s));


    //if only change name Jack to Mike, iofile.write( "Mike", strlen("Mike")+1);
    // strlen("Mike") returns the length of the C string "Mike"
    iofile.seekp(sizeof(s), ios::beg);
    iofile.write( "Mike", strlen("Mike")+1);

    //change one student data
    strcpy(s.szName, "Kelly");
    s.nScore = 65;
    iofile.seekp(5*sizeof(s), ios::beg);
    iofile.write( (char *) & s, sizeof(s));


    //change one student data, only change name and score not changed
    strcpy(s.szName, "kally");
    iofile.seekp(4*sizeof(s), ios::beg);
    iofile.write( (char *) & s, sizeof(s.szName));


    iofile.seekg(0, ios::beg);
    //set file reading pointer from the beginning of the file "students.dat"
    while(iofile.read((char *) & s, sizeof(s)))
    //the first parameter is the reference to the fstream object "s"
    //and read the object "s" in the form of string, with the size of the object
        cout<<s.szName<<" "<<s.nScore<<endl;

    iofile.close();

    return 0;
}

//-----------------------------------
// Test the binaryfileRW.cpp
//---------------------------
/*
(base) mikki7s-MacBook-Pro:CPP mikki7$ g++ binaryfileRW.cpp -std=c++11 -o binaryfrw
(base) mikki7s-MacBook-Pro:CPP mikki7$ ./binaryfrw
Tom 60
Mike 80
Jelly 70
Grace 70
kally 55
Kelly 65
*/
