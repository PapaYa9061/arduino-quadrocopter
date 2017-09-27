
#ifndef CONFIG_H
#define CONFIG_H

//accelerometer trim

float accOff[];
bool accInv[];
float accSen;

//magnetometer trim

float magOff[3];
bool magInv[3];
float magSen;

//gyro trim

float gyrOff[];
bool gyrInv[];
float gyrSen;

//komplementärfilter gewichte

float accGewicht;
float gyrGewicht;
float magGewicht;



#endif CONFIG_H
