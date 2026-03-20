#include <iostream>

void updateSensorData(int* p_sensorValue){
    *p_sensorValue = 100; 
}
void updateSensorData2(int &p_sensorValue){
    p_sensorValue = 200; 
}

int main(){
    int sensor_value = 42;
    int *p_sensor_value = &sensor_value;
    std::cout<<"Before updating sensor value via pass by reference: "<<*p_sensor_value<<std::endl;
    updateSensorData(p_sensor_value);
    std::cout<<"after updating sensor value via pass by reference: "<<*p_sensor_value<<std::endl;
    updateSensorData2(sensor_value);
    std::cout<<"after updating sensor value via pass by reference agin : "<<*p_sensor_value<<std::endl;


    return 0;

    /*
    1. Pointer vs. Reference: What's the difference?
    
    In robotics, you’ll see both, but they have distinct "personalities":
    Passing a Pointer (int* ptr): You are passing a memory address. 
    The function receives a copy of that address. 
    This is common in older C-style hardware SDKs (like the Pico SDK).

    Passing by Reference (int &ref): You are passing an alias. 
    The function doesn't get a "copy" of the address; it essentially treats the variable 
    name inside the function as a nickname for the original variable in main. 
    It is safer because a reference cannot be "null"—it must always point to something.*/
}