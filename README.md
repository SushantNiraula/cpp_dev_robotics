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


## Exercise 2: The Teleporter (Pass-by-Reference)
Now that you can find the data, let's move it—without actually moving it. In robotics, passing a large Lidar scan (thousands of data points) by value creates a copy, which wastes CPU cycles and memory. We use `pointers or references` to "teleport" the function's focus to the original data.

Your Goal:

1. Write a function called updateSensorData(int* p_sensorValue).

2. Inside this function, change the value of the sensor data to something new (e.g., 100) using the pointer.

3. In your main() function, print the sensorReading before and after calling updateSensorData.


4. The Proof: If the value in main() changes even though the function returned void, you’ve successfully "teleported" your access to that memory.

### Key Terms to Master

1. Dereferencing (`*`): The act of saying "Go to the address held by this pointer and grab the value inside".


2. Address-of (`&`): The act of asking the computer "Where is this variable physically located in the RAM?".

3. Null Pointer: A pointer that points to "nowhere" (`nullptr`). In robotics, trying to dereference a null pointer usually results in your robot's software crashing (a "Segfault")

## Exercise 3: The Controlled Memory Leak
Before we build your Sensor Circular Buffer, we have to talk about the "Heap." Most variables we've used so far live on the "Stack" and are deleted automatically. But for large data, like a 3D Lidar map, we use `new` to put data on the Heap.

The Danger: If you use `new` but forget `delete`, your robot will slowly run out of RAM until it freezes—this is a <b>Memory Leak</b>.

Your Goal:

1. Create an array of 10 integers dynamically using `new int[10]`.

2. The Experiment: Wrap this in a `while(true)` loop (but maybe add a small `count` limit so you don't actually crash your PC!).

3. Observe that if you don't use `delete[]`, the memory stays "taken."


4. The Fix: Use `delete[]` to properly free that memory.


The Robotics Danger: A robot is designed to run for hours or days. A small leak of just 40 bytes (10 integers) every sensor cycle (say, 100 times per second) adds up to 14 MB per hour. After a day of autonomous flight, your drone's brain will freeze and fall out of the sky.

### The Complications of Manual Management

1. Relying on new and delete is "Old School" C++. It is dangerous for a few reasons:

2. Dangling Pointers: If you delete a pointer but try to use it later, your program crashes.

3. Double Free: If you try to delete the same memory twice, your program crashes.

4. Exceptions: If an error happens between new and delete, the delete line might never be reached, causing a leak anyway.

### The Modern Solution: Smart Pointers
In modern robotics (and the Pico 2 SDK/ROS2), we prefer Smart Pointers (like std::unique_ptr). These are objects that live on the Stack but manage memory on the Heap. When the object on the stack is destroyed, it automatically calls delete for you. It's like a tool that puts itself back in the warehouse!

## Phase 1 Milestone: The Sensor Circular Buffer
You are now ready for your first big project.

The "Why": Robots often need the "last 10 seconds" of Lidar data. We don't want to keep allocating and deleting memory (which is slow). Instead, we use a Circular Buffer—a fixed-size array where new data overwrites the oldest data.

Your Goal:

1. Create a fixed-size array of double (representing distance readings).

2. Use a pointer to track the "Head" (where the next piece of data goes).

3. Write a function addReading(double newValue) that:

    * Places the value at the current "Head."

    * Moves the "Head" to the next spot.

    * Crucial: If the "Head" reaches the end of the array, it must "wrap around" back to the first element.