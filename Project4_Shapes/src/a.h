#include <iostream>
#include <cmath>

using namespace std;
// declare the Shape class
class Shape {
public:
    virtual double GetPerimeter() const = 0;
    virtual double GetArea() const = 0;
    virtual ~Shape() {}
};
//declare the Square, Circle, and Triangle classes
class Square : public Shape {
private:
    double side;

public:
    Square(double side);
    double GetPerimeter() const override;
    double GetArea() const override;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double radius);
    double GetPerimeter() const override;
    double GetArea() const override;
};

class Triangle : public Shape {
private:
    double side1;
    double side2;
    double side3;

public:
    Triangle(double side1, double side2, double side3);
    double GetPerimeter() const override;
    double GetArea() const override;
};
