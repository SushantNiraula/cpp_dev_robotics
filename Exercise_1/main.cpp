#include <iostream>

using namespace std;

int main(){

    int sensorReading = 42; // storing the value into the variable
    cout<<"Sendsor Reading is: "<<sensorReading<<endl; //Printing the value of the reading in the cout i.e output 1, monitor
    int* address_of_sensorReading = &sensorReading; //get the address of the stored variable
    cout<<"Address of sensorReading is: "<<address_of_sensorReading<<endl; //print the address of the sensorReading
    cout<<"Value in address_of_sensorReading: "<<*address_of_sensorReading<<endl; //print the value in the memory address of Sensor_reading
    return 0;

    /*
    Feedback & Refinements
    While your code works perfectly, here are two professional 
    "Robotics Standard" tips to consider as we move forward:
    Avoid using namespace std;: In large robotics frameworks like
     ROS2, using the entire standard namespace can lead to 
     "naming collisions" (where two different libraries have a 
     function with the same name). 
     It is safer to use std::cout and std::endl explicitly.

    Pointer Naming: Your variable name address_of_sensorReading
     is very clear. In professional C++,
      you'll often see this shortened to sensorPtr or p_sensor.
    */


}