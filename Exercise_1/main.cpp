#include <iostream>

using namespace std;

int main(){

    int sensorReading = 42; // storing the value into the variable
    cout<<"Sendsor Reading is: "<<sensorReading<<endl; //Printing the value of the reading in the cout i.e output 1, monitor
    int* address_of_sensorReading = &sensorReading; //get the address of the stored variable
    cout<<"Address of sensorReading is: "<<address_of_sensorReading<<endl; //print the address of the sensorReading
    cout<<"Value in address_of_sensorReading: "<<*address_of_sensorReading<<endl; //print the value in the memory address of Sensor_reading
    return 0;



}