#include "a.h"

// --- Student ---
Student::Student() : name(""), id(""), classification('U') {}
Student::Student(string name) : name(name), id(""), classification('U') {}

string Student::getName() const { return this->name; }
void   Student::setName(string name) { this->name = name; }

string Student::getId() const { return this->id; }
void   Student::setId(string id) { this->id = id; }

char   Student::getClassification() const { return this->classification; }
void   Student::setClassification(char classification) { this->classification = classification; }

// --- Roster ---
Roster::Roster() : size(0), capacity(5) {
    this->students = new Student[this->capacity]; // needs Student()
}

Roster::Roster(const Roster& roster) : size(roster.size), capacity(roster.capacity) {
    this->students = new Student[this->capacity];
    for (int i = 0; i < this->size; i++) this->students[i] = roster.students[i];
}

Roster::~Roster() {
    delete[] this->students;
}

void Roster::addStudent(const Student& student) {
    if (this->size == this->capacity) grow();
    this->students[this->size++] = student;
}

void Roster::removeStudent(const string& studentName) {
    for (int i = 0; i < this->size; i++) {
        if (this->students[i].getName() == studentName) {
            for (int j = i; j < this->size - 1; j++) this->students[j] = this->students[j + 1];
            this->size--;
            return;
        }
    }
}

ostream& operator<<(ostream& os, const Roster& roster) {
    os << "Roster:\n";
    for (int i = 0; i < roster.size; i++) {
        os << " - " << roster.students[i].getName() << '\n';
    }
    return os;
}

void Roster::grow() {
    this->capacity *= 2; 
    Student* temp = new Student[this->capacity];
    for (int i = 0; i < this->size; i++) temp[i] = this->students[i];
    delete[] this->students;
    this->students = temp;
}

Student Roster::getStudent(const string& studentName) {
    for (int i = 0; i < this->size; i++) {
        if (this->students[i].getName() == studentName) return this->students[i];
    }
    return Student(""); // sentinel
}

// --- Course ---
Course::Course(string name) : name(name) {}

void Course::addStudent(const Student& student) { this->roster.addStudent(student); }
void Course::removeStudent(const string& studentName) { this->roster.removeStudent(studentName); }

ostream& operator<<(ostream& os, const Course& course) {
    os << "Course: " << course.name << '\n';
    os << course.roster;
    return os;
}