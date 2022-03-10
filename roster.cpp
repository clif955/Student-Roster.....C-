#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include "roster.h"
#include "student.h"
#include "degree.h"
using namespace std;
//Parsing data form the studentdata table
void Roster::ParseStudentId(string studentData){
    
    size_t lhs, rhs;
    lhs = 0;
    //finds the studentID
    rhs = studentData.find(","); //will find the comma
    string studentID = studentData.substr(0, rhs);
    //finds the First Name
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string firstName = studentData.substr(lhs,rhs - lhs);
    //finds the Last Name
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string lastName = studentData.substr(lhs,rhs - lhs);
    //finds the email Address
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string emailAddress = studentData.substr(lhs,rhs - lhs);
    //finds the Age
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int age = stoi(studentData.substr(lhs,rhs - lhs));
    //finds the average Days in First Course
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse1 = stoi(studentData.substr(lhs,rhs - lhs));
    //finds the average Days in Second Course
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse2 = stoi(studentData.substr(lhs,rhs - lhs));
    //finds the average Days in Third Course
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    int daysInCourse3 = stoi(studentData.substr(lhs,rhs - lhs));
    //finds the Degree Program
    lhs = rhs + 1;
    rhs = studentData.find(",", lhs);
    string degreeprogram = studentData.substr(lhs);
    DegreeProgram program;
    if(degreeprogram == "SECURITY"){
        program = SECURITY;
    }
    if(degreeprogram == "NETWORK"){
        program = NETWORK;
    }
    if(degreeprogram == "SOFTWARE"){
        program = SOFTWARE;
    }
    
    this->add(studentID,firstName,lastName,emailAddress,age,daysInCourse1,daysInCourse2,daysInCourse3, program);


};
//adds and sets values when called
void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram){
    int daysInCourse[]={daysInCourse1,daysInCourse2,daysInCourse3};
    Student *student = new Student();
    student->SetID(studentID);
    student->SetFname(firstName);
    student->SetLname(lastName);
    student->SetEmail(emailAddress);
    student->SetAge(age);
    student->SetDays(daysInCourse);
    //student->SetDays(daysInCourse2);
    //student->SetDays(daysInCourse3);
    student->SetDegree(degreeprogram);
    this->classRosterArray[++lastIndex]= student;
};
//check to see if a student exist
void Roster::remove(string studentID){
    bool student_Exist = false;
    
    for(int i = 0; i<=lastIndex; ++i) {
        if(classRosterArray[i] != nullptr && classRosterArray[i]->GetID() == studentID){
           student_Exist = true;
            if (i <= lastIndex - 1){
                Student* student = classRosterArray[i];
                classRosterArray[i] = classRosterArray[lastIndex];
                classRosterArray[lastIndex] = student;
                lastIndex--;
                
            }
            
        }
        
        };
    if (student_Exist == false){ cout<<"Error!"<<"This student does not exist!"<<endl;}
    
};
//print all student Information
void Roster::printAll(){
    int i;
    for(i = 0; i<=lastIndex; ++i) {
        classRosterArray[i]->Print();
        
    }
         
};
//print average days in course
void Roster::printAverageDaysInCourse(string studentID){
    int i;
    //int daysInCourse[]={daysInCourse[1],daysInCourse[2],daysInCourse[3]};
    
    for(i = 0; i<5; ++i) {

        if(classRosterArray[i]->GetID()== studentID){
            int averageDays = classRosterArray[i]->GetDays()[0];
            averageDays += classRosterArray[i]->GetDays()[1];
            averageDays += classRosterArray[i]->GetDays()[2];
            averageDays = averageDays/3;
            cout<<classRosterArray[i]->GetFname()<<" " <<"average Days in Course: "<<averageDays<<endl;
        }
        };
    
};
//check to see if all emails are in a valid format
bool is_email_valid(string email){

    bool checkf_at = (email.find("@") > 0 && email.find("@") < email.length())? true : false;
    
    bool checkf_period = (email.find(".") > 0 && email.find(".") < email.length())? true : false;

    bool checkf_space = (email.find(" ") > 0 && email.find(" ") < email.length())? true : false;
    
     return (checkf_at && checkf_period && !checkf_space? true : false) ;
};
//print invalid emails
void Roster::printInvalidEmails(){
    int i;
    string email;
    for(i = 0; i<5; ++i) {
         email = (classRosterArray[i]->GetEmail());
        bool isValidEmail = is_email_valid(email);
        if (!isValidEmail)
        {
            classRosterArray[i]->Print();
        }
};
};
//display the degree
void Roster::printByDegreeProgram(DegreeProgram degreeprogram){
 
    
    for (int i = 0; i<5; ++i) {
        if(classRosterArray[i]->getDegree() == degreeprogram)
        {
         
                classRosterArray[i]->Print();
            }
    
};
};
Roster::~Roster(){
    for (int i=0; i<5; ++i){
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
   
}
