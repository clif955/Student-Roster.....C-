#include <iostream>
#include <string>
#include <vector>
using namespace std;
#include "student.h"
#include "degree.h"
#pragma once//;
//functions for the roster class
class Roster {
public:
    
    void ParseStudentId(string studentData);
    void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeprogram);
    void remove(string studentID);
    void Printf();
    void printAll();
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeProgram(DegreeProgram degreeProgram);
    ~Roster();
    int lastIndex = -1;

    Student* classRosterArray[5];
    


    
};
