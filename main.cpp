#include "mbed.h"
#include "MMA7660.h" // include header file for MMA7660 accelerometer
#include <cmath> // include math library for using sqrt and atan functions

#define PI 3.141592654 // define the value of PI

MMA7660 MMA(p28, p27); // create an object of MMA7660 class and initialize it with pin numbers
DigitalOut connectionLed(LED1); // create an object of DigitalOut class for LED1

 
// function to calculate the angle of the accelerometer data
float calculateAngle(float x, float y, float z){
    float angle = 0; // initialize the angle variable to 0
    float bott_part = sqrt((y*y)+(z*z)); // calculate the square root of y^2 + z^2
    angle = atan(x/bott_part); // calculate the arctangent of x / bott_part
    angle = (angle * 180.0)/PI; // convert the angle to degrees from radians
    return angle; // return the calculated angle   
} 

// main function
int main() {
    if (MMA.testConnection()) // test if the MMA7660 accelerometer is connected
        connectionLed = 1; // if connected, turn on the LED1

    while(1) { // loop forever
        printf("angle is %f \r\n" , calculateAngle(MMA.x(), MMA.y(), MMA.z())); // print the angle calculated from x, y, and z accelerometer data
        wait(1); // wait 1 second
    }
}
