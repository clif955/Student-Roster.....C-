#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;


Student::Student(){
 //getters and setters for student
}
void Student::SetID(string studentID){
    ID = studentID;
};
string Student::GetID(){
    return ID;
};
void Student::SetFname(string firstName){
    first = firstName;
};
string Student::GetFname(){
    return first;
};
void Student::SetLname(string lastName){
    last = lastName;
};
string Student::GetLname(){
    return last;
};
void Student::SetEmail(string emailAddress){
    email = emailAddress;
};
string Student::GetEmail(){
    return email;
};
void Student::SetAge(int age){
    Age = age;
};
int Student::GetAge(){
    return Age;
};
void Student::SetDays(int daysInCourse[]){
    for (int i = 0; i<3; ++i){
      this->daysInCourse[i] = daysInCourse[i];
    }
     
};
int* Student::GetDays(){
    return daysInCourse;
};
void Student::SetDegree(DegreeProgram degreeProgram){
   
    degree = degreeProgram;
   };
DegreeProgram Student::getDegree(){
    return degree;
};
void Student::Print(){
    string program;
    if(degree == SECURITY){
        program = "SECURITY";
    }
    if(degree == NETWORK){
        program = "NETWORK";
    }
    if(degree == SOFTWARE){
        program = "SOFTWARE";
    }
    cout<<"\t"<<ID<<"\tFirst Name:"<<first<<"\tLast Name:"<<last<<"\tEmail:"<<email<<"\tAge:"<<Age<<"\tdays in Course:{"<<daysInCourse[0]<<","<<daysInCourse[1]<<","<<daysInCourse[2]<<"}\tDegree Program:"<<program<<endl;
    
}
