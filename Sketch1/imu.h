
#ifndef IMU_H
#define IMU_H


float dcmIMU[3][3];




float accRead(unsigned char axis);
float magRead(unsigned char axis);
float gyrRead(unsigned char axis);
void imu_update();



#endif