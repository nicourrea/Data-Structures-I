#include "a.h"


int main() {
    Student student1("Tom");
    Student student2("Jerry");
    Student student3("Nico");

    Roster roster;
    roster.addStudent(student1);
    roster.addStudent(student2);
    roster.addStudent(student3);

    cout << roster << endl;

    Course course("COP3330");
    course.addStudent(student1);
    course.addStudent(student2);
    course.addStudent(student3);

    cout << course << endl;

    course.removeStudent("Tom");

    cout << course << endl;

    return 0;
}