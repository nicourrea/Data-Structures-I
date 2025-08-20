#include "a.h"
#include <iostream>
using namespace std;

int main() {
    QuickQueue<int> intQueue;
    for (int i = 1; i <= 5; ++i) {
        intQueue.enqueue(i);
    }

    cout << "Int Queue:" << endl;
    while (!intQueue.empty()) {
        cout << intQueue.dequeue() << " ";
    }
    cout << endl;

    QuickQueue<double> doubleQueue;
    for (double i = 1.5; i <= 5.5; i += 1.0) {
        doubleQueue.enqueue(i);
    }

    cout << "Double Queue:" << endl;
    while (!doubleQueue.empty()) {
        cout << doubleQueue.dequeue() << " ";
    }
    cout << endl;

    return 0;
}