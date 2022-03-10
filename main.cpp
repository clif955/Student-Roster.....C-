//
//  main.cpp
//  Task 1
//
//  Created by clifton davis on 2/2/22.
//

#include "main.hpp"
#include <iostream>
#include "degree.h"
#include "roster.h"

using namespace std;

//main to call all functions
int main(){
    cout<<"Class Roster Task 1"<<" "<<"Scripting and Programming using C++"<<" "<<"cda1132 Clifton Davis"<<endl;
    cout<<endl;
    //student data table
    string studentData[5] =
  {"A1,John,Smith,John1989@gmail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Clifton,Davis,cda1132@wgu.edu,45,15,30,45,SOFTWARE"
};
    Roster classRoster;
    for(int i =0; i<5; ++i){
    classRoster.ParseStudentId( studentData[i] );
    };
    classRoster.printAll();
    classRoster.printInvalidEmails();
    for(int i=0; i<5; ++i){
    classRoster.printAverageDaysInCourse(studentData[i].substr(0,2));
    };
    //print degree program
    classRoster.printByDegreeProgram(SOFTWARE);
    //remove student
    classRoster.remove("A3");
    classRoster.printAll();
    classRoster.remove("A3");
    
    
    
    
    return 0;
}
