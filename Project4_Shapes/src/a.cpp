#include "a.h"
using namespace std;

Square::Square(double side) : side(side) {}

double Square::GetPerimeter() const {
    return 4 * side;
}

double Square::GetArea() const {
    return side * side;
}

Circle::Circle(double radius) : radius(radius) {}

double Circle::GetPerimeter() const {
    return 2 * 3.14159 * radius;
}

double Circle::GetArea() const {
    return 3.14159 * radius * radius;
}

Triangle::Triangle(double side1, double side2, double side3) : side1(side1), side2(side2), side3(side3) {}

double Triangle::GetPerimeter() const {
    return side1 + side2 + side3;
}

double Triangle::GetArea() const {
    double s = (side1 + side2 + side3) / 2;
    return sqrt(s * (s - side1) * (s - side2) * (s - side3));
}
