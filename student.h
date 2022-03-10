#include <iostream>
#include <string>
using namespace std;
#include "degree.h"
#pragma once//;

//get and set methods declarations
class Student {
public:
    
    void SetID(string studentID);
    void SetFname(string firstName);
    void SetLname(string lastName);
    void SetEmail(string emailAddress);
    void SetAge(int age);
    void SetDays(int daysInCourse[]);
    void SetDegree(DegreeProgram degreeprogram);
    string GetID();
    string GetFname();
    string GetLname();
    string GetEmail();
    string students;
    int GetAge();
    int* GetDays();
    DegreeProgram getDegree();
    void Print();
    void Printf();
    Student(string studentId, string firstName, string lastName, string emailAddress, string age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    Student ();
    Student (string);
    Student (*wstring);
    //string classRosterArray[];
private:
    string ID;
    string first;
    string last;
    string email;
    int Age;
    int daysInCourse[3];
    
    DegreeProgram degree;
    
};

