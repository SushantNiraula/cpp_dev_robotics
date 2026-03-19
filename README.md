## Workspace Setup: 

Before we dive into Phase 1: Pointers & Memory Management, we need to ensure our environment is ready for professional-grade C++ development.

1. Compiler: Ensure we have g++ (GCC) or clang installed.
2. Build System: We will be using CMake. As noted in our plan, moving away from IDE "auto-magic" is crucial for working with SDKs like the Pico 
3. Editor: I recommend VS Code with the C/C++ Extension Pack: Initialize a local Git repository.


## Phase 1: Pointers & Memory Management

Robots process massive amounts of sensor data (Lidar, IMU, Encoders) multiple times a second. Pointers allow your processor to look directly at the memory where that data lives, ensuring high-speed, zero-delay reactions by avoiding expensive data copying.

## Exercise 1: The Memory Inspector
To start, we need to get comfortable with the physical reality of our RAM. Your first task is to visualize where data actually "lives."

### Our Goal:

1. Create an integer variable named `sensorReading` and assign it a value (e.g., 42).

2. Print the value of the variable.

3. Print the exact `physical memory address` using the `address-of operator (&)`.

4. Create a `pointer that holds that address`, and use it to print the value again via dereferencing (*).


## Excersie 2: 
