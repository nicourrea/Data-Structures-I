#pragma once
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
using namespace std;

class Student {
private:
    string name;
    string id;
    char classification;

public:
    Student();                 
    Student(string name);      

    string getName() const;
    void setName(string name);
    string getId() const;
    void setId(string id);
    char getClassification() const;
    void setClassification(char classification);
};

class Roster {
private:
    Student* students;
    int size, capacity;

    void grow();

public:
    Roster();
    Roster(const Roster& roster);
    ~Roster();

    void addStudent(const Student& student);
    void removeStudent(const string& studentName);
    Student getStudent(const string& studentName);
    friend ostream& operator<<(ostream& os, const Roster& roster);
};

class Course {
private:
    string name;
    string code;
    Roster roster;

public:
    Course(string name);
    void addStudent(const Student& student);
    void removeStudent(const string& studentName);
    friend ostream& operator<<(ostream& os, const Course& course);
};