#include <iostream>
#include <cstring>
#include "a.h"
using namespace std;

// RULE OF THREE

// Default constructor
GroceryItem::GroceryItem() : price(0.0) {
    strncpy(this->name, "Default Item", sizeof(this->name));
}


GroceryItem::GroceryItem(const char* name, float price) {
    this->price = price;
    strncpy(this->name, name, sizeof(this->name));
    }

//get function to return name
const char* GroceryItem :: getName() const {
        return this->name;
    }

// get function to return price
float GroceryItem :: getPrice() const {
        return this->price;
    }


// Constructor to initialize the sack
GrocerySack::GrocerySack() : size(0), capacity(3) {
    this->items = new GroceryItem[this->capacity];

    for (int i = 0; i < this->capacity; i++) {
        this->items[i] = GroceryItem("Default Item", 0.0);
    }
}


GrocerySack::GrocerySack(const GrocerySack& gs) {
    this->size = gs.size;
    this->capacity = gs.capacity;
    this->items = new GroceryItem[this->capacity];
    for(int i = 0; i < this->size; i++) {
        this->items[i] = gs.items[i];
    }
}

// destructor to delete
GrocerySack::~GrocerySack() {
    delete[] this->items;
    }


// operator overload f
GrocerySack& GrocerySack::operator=(const GrocerySack& rhs) {
    if(this != &rhs) {
        delete[] this->items;
        this->size = rhs.size;
        this->capacity = rhs.capacity;
        this->items = new GroceryItem[this->capacity];
        for(int i = 0; i < this->size; i++) {
            this->items[i] = rhs.items[i];
        }
    }
    return *this;
}


// function to add items and increase array by 3
void GrocerySack::Add(const GroceryItem& item) {
    if (this->size == this->capacity) {
        int newCapacity = this->capacity + 3; // Expand by 3 slots
        GroceryItem* temp = new GroceryItem[newCapacity];
        for (int i = 0; i < this->size; i++) {
            temp[i] = this->items[i];
        }
        delete[] this->items;
        this->items = temp;
        this->capacity = newCapacity;
    }
    this->items[this->size] = item;
    this->size++;
}

// function to remove items
void GrocerySack::Remove(int index) {
    if(index < 0 || index >= this->size) {
        return;
    }
    for(int i = index; i < this->size - 1; i++) {
        this->items[i] = this->items[i + 1];
    }
    this->size--;
}

// function to get index to delete sack items
GroceryItem GrocerySack::GetAt(int index) {
    return this->items[index];
}

// function to get size and capacity
int GrocerySack::getSize() const {
    return this->size;
}

int GrocerySack::getCapacity() const {
    return this->capacity;
}
