#pragma once
#include <iostream>

template <typename T>
class QuickQueue {
private:
    T* data;
    int capacity;
    int size;
    void resize();

public:
    QuickQueue();
    ~QuickQueue();
    QuickQueue(const QuickQueue& other);
    QuickQueue& operator=(const QuickQueue& other);
    QuickQueue(QuickQueue&& other) noexcept;
    QuickQueue& operator=(QuickQueue&& other) noexcept;

    void enqueue(const T& value);
    T dequeue();
    bool empty() const;
};