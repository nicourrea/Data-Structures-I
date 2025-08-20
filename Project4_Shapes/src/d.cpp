#include "a.h"
#include <iostream>

using namespace std;

// max number for array
const int MAX_SHAPES = 10;  

int main() {
    // array of pointers to Shape objects
    Shape* shapes[MAX_SHAPES]; 

    int shapeCount = 0;  

    // menu
    int choice;
    do {
        cout << "1. Add Square" << endl;
        cout << "2. Add Circle" << endl;
        cout << "3. Add Triangle" << endl;
        cout << "4. Calculate Aggregate Perimeter" << endl;
        cout << "5. Calculate Aggregate Area" << endl;
        cout << "6. Quit" << endl;
        cout << "Enter your choice 1-6: ";
        cin >> choice;

        // switch statement for menu
        switch (choice) {
            case 1: {
                if (shapeCount < MAX_SHAPES) {
                    double side;
                    cout << "Enter side length: ";
                    cin >> side;
                    shapes[shapeCount++] = new Square(side);
                } else {
                    cout << "Array is full." << endl;
                }
                break;
            }
            case 2: {
                if (shapeCount < MAX_SHAPES) {
                    double radius;
                    cout << "Enter radius: ";
                    cin >> radius;
                    shapes[shapeCount++] = new Circle(radius);
                } else {
                    cout << "Array is full." << endl;                }
                break;
            }
            case 3: {
                if (shapeCount < MAX_SHAPES) {
                    double side1, side2, side3;
                    cout << "Enter side 1 length: ";
                    cin >> side1;
                    cout << "Enter side 2 length: ";
                    cin >> side2;
                    cout << "Enter side 3 length: ";
                    cin >> side3;
                    shapes[shapeCount++] = new Triangle(side1, side2, side3);
                } else {
                    cout << "Array is full." << endl;                }
                break;
            }
            case 4: {
                double perimeter = 0;
                for (int i = 0; i < shapeCount; ++i) {
                    perimeter += shapes[i]->GetPerimeter();
                }
                cout << "Total perimeter: " << perimeter << endl;
                break;
            }
            case 5: {
                double area = 0;
                for (int i = 0; i < shapeCount; ++i) {
                    area += shapes[i]->GetArea();
                }
                cout << "Total area: " << area << endl;
                break;
            }
            case 6: {
                cout << "Exit" << endl;
                break;
            }
            default: {
                cout << "Invalid choice" << endl;
                break;
            }
        }
        // end switch statement
    } while (choice != 6);

    // delete all shapes
    for (int i = 0; i < shapeCount; ++i) {
        delete shapes[i];
    }

    return 0;
}
