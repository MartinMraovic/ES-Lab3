#include "mbed.h"
#include "MMA7660.h"
#include <cmath>

#define PI 3.141592654

MMA7660 MMA(p28, p27);
DigitalOut connectionLed(LED1);

 
float calculateAngle(float x, float y, float z){
    float angle = 0;
    float bott_part = sqrt((y*y)+(z*z));
    angle = atan(x/bott_part);
    angle = (angle * 180.0)/PI;
    return angle;   

} 

int main() {
    if (MMA.testConnection())
        connectionLed = 1;

while(1) {
    printf("angle is %f \r\n" , calculateAngle(MMA.x(), MMA.y(), MMA.z()));
    wait(1);
  }
}
