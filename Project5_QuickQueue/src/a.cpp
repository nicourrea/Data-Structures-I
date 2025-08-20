#include "a.h"
#include <stdexcept>

// Resize function
template <typename T>
void QuickQueue<T>::resize() {
    int newCap = capacity * 2;
    T* temp = new T[newCap];
    for (int i = 0; i < size; i++) {
        temp[i] = data[i];
    }
    delete[] data;
    data = temp;
    capacity = newCap;
}

// Constructor
template <typename T>
QuickQueue<T>::QuickQueue() : capacity(10), size(0) {
    data = new T[capacity];
}

// Destructor
template <typename T>
QuickQueue<T>::~QuickQueue() {
    delete[] data;
}

// Copy constructor
template <typename T>
QuickQueue<T>::QuickQueue(const QuickQueue& other) : capacity(other.capacity), size(other.size) {
    data = new T[capacity];
    for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
    }
}

// Copy assignment
template <typename T>
QuickQueue<T>& QuickQueue<T>::operator=(const QuickQueue& other) {
    if (this != &other) {
        delete[] data;
        capacity = other.capacity;
        size = other.size;
        data = new T[capacity];
        for (int i = 0; i < size; i++) {
            data[i] = other.data[i];
        }
    }
    return *this;
}

// Move constructor
template <typename T>
QuickQueue<T>::QuickQueue(QuickQueue&& other) noexcept
    : data(other.data), capacity(other.capacity), size(other.size) {
    other.data = nullptr;
    other.capacity = 0;
    other.size = 0;
}

// Move assignment
template <typename T>
QuickQueue<T>& QuickQueue<T>::operator=(QuickQueue&& other) noexcept {
    if (this != &other) {
        delete[] data;
        data = other.data;
        capacity = other.capacity;
        size = other.size;
        other.data = nullptr;
        other.capacity = 0;
        other.size = 0;
    }
    return *this;
}

// Enqueue
template <typename T>
void QuickQueue<T>::enqueue(const T& value) {
    if (size == capacity) {
        resize();
    }
    data[size++] = value;
}

// Dequeue
template <typename T>
T QuickQueue<T>::dequeue() {
    if (size == 0) {
        throw std::out_of_range("Queue is empty");
    }
    T front = data[0];
    for (int i = 1; i < size; i++) {
        data[i - 1] = data[i];
    }
    size--;
    return front;
}

// Check if empty
template <typename T>
bool QuickQueue<T>::empty() const {
    return size == 0;
}

// Explicit instantiations
template class QuickQueue<int>;
template class QuickQueue<double>;