#include <iostream>
#include "a.h"
using namespace std;

int main() {
    GrocerySack gs, g2;
    GrocerySack gs2 = gs;
    
    //Create menu to add, remove, display, and checkout
    bool stillShopping = true;
    int menuChoice;

    // while loop for menu
    while (stillShopping) {
        //display menu options
        cout << "   Welcome to the Grocery Store!" << endl;
        cout << "1. Add a Grocery Item To The Cart!" << endl;
        cout << "2. Remove a Grocery Item From The Cart!" << endl;
        cout << "3. Display The Cart's Items!" << endl;
        cout << "4. Check Out!" << endl;
        //enter menu choice
        cin >> menuChoice;

        //switch cases for menu
        switch (menuChoice) {
            //case 1 adding items
            case 1: {
                float price;
                char name[250];
                cout << "Enter The Name of The Grocery Item: ";
                cin >> name;
                cout << "Enter The Price of The Grocery Item: ";
                cin >> price;
                gs.Add(GroceryItem(name, price));
                break;
            }
            case 2: {
                //case 2 removing items
                int index;
                cout << "Enter The Number of The Item You Would Like To Remove: ";
                cin >> index;
                gs.Remove(index);
                break;
            }
            case 3: {
                //case 3 display contents in sack
                cout << "The Cart Contains: " << endl;
                for (int i = 0; i < gs.getSize(); i++) {  // Use getSize() here
                    GroceryItem item = gs.GetAt(i);
                    cout << i << ". " << item.getName() << " $" << item.getPrice() << endl;
                }
                break;
            }
            case 4: {
                //case 4 checkout add 7%
                stillShopping = false;
                float totalGroceries = 0.0;

                for (int i = 0; i < gs.getSize(); i++) {  
                    totalGroceries += gs.GetAt(i).getPrice();
                }

                //use float for tax
                float tax = totalGroceries * 0.07;
                totalGroceries += tax;

                // display checkout
                // show total cost of groceries
                // show total cost of groceries with tax
                // set precision to 2 decimal places for accurate checkout results.
                cout << "The Total Cost of The Groceries is: $" << fixed << setprecision(2) << totalGroceries - tax << endl;
                cout << "The Total Cost of The Groceries with tax is: $" << fixed << setprecision(2) << totalGroceries << endl;
                break;
            }
            // if invalid option is chosen:
            default: {
                cout << "Choose a Valid Option!" << endl;
                break;
            }
        }
    }

    return 0;
}
