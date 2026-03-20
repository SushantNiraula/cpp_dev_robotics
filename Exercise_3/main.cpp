#include <iostream>

void simulateSensorCycle(bool fixLeak) {
    // 1. Allocate an array of 10 ints on the HEAP
    int* leakPtr = new int[10]; 

    if (fixLeak) {
        // TODO: What command goes here to free the array?
        // Hint: Since it's an array [], use the array version of delete
        delete[] leakPtr;
    }
    // If we don't fix it, leakPtr goes out of scope, 
    // but the 10 integers stay in the "Warehouse" (Heap) forever!
}

int main() {
    std::cout << "Starting sensor cycles..." << std::endl;
    
    for (int i = 0; i < 1000; ++i) {
        simulateSensorCycle(false); // Change to 'true' later to fix it
    }

    std::cout << "Cycles complete. If fixLeak was false, we just lost memory!" << std::endl;
    return 0;
}