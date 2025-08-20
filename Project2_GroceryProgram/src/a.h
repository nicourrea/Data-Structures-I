#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>
using namespace std;

// Grocery item class
class GroceryItem {
    private:
    float price;
    char name[250];

public:
    // public section of class GroceryItem
    GroceryItem();
    GroceryItem(const char* name, float price);
    const char* getName() const;
    float getPrice() const;
};

// Grocery sack class
class GrocerySack {
private:
    // private section of class GrocerySack 
    GroceryItem* items;
    int size, capacity;

public:
    // public section of class GrocerySack
    //default constructor
    GrocerySack();
    //copy constructor
    GrocerySack(const GrocerySack& gs);
    //destructor
    ~GrocerySack();
    //operator overload
    GrocerySack& operator=(const GrocerySack& rhs);
    //add, remove, getAt, getSize, getCapacity
    void Add(const GroceryItem& item);
    void Remove(int index);
    GroceryItem GetAt(int index);
    int getSize() const;
    int getCapacity() const;
};
