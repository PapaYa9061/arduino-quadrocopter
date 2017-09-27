#include "config.h"
#include "vector3D.h"
#include "dcmMath.h"


//global

float dcmIMU[3][3] = { {1,0,0},{0,1,0},{0,0,1} };    //dcm[2] ist K (zeigt nach oben), 0 is I (norden)
unsigned int imu_update_intervall = 0;
unsigned long imu_update_start = 0;




//get accelerometer reading on specified axis

float accRead(unsigned char axis){								
	static float aid;										//einfach so fürn output
	aid = 1 - accOff[axis];					//offset entfernen
	aid /= accSen;									//sinnvollen wert errechnen
	if (accInv[axis]) aid = -aid;				//invert axis if specified
	return aid;
}

float magRead(unsigned char axis) {
	static float aid;										//einfach so fürn output
	aid = 1 - magOff[axis];					//offset entfernen
	aid /= magSen;									//sinnvollen wert errechnen
	if (magInv[axis]) aid = -aid;				//invert axis if specified
	return aid;
}

float gyrRead(unsigned char axis) {								
	static float aid;										//einfach so fürn output
	aid = 1 - accOff[axis];					//offset entfernen
	aid /= gyrSen;									//sinnvollen wert errechnen (rad/microsec)
	if (gyrInv[axis]) aid = -aid;				//invertieren falls spezifiziert
	return aid;
}

void imu_update() {
	
	float aidvector[3];    // hilfe zum berechnen der angular velocity von acc und mag
	float gyrRate[3];       //gyrorate (wird later zum gesamtwertkorrekturwert)
	float accKV[3];			// angular velocity accelerometer
	float magKV[3];			//angular velocity magnetometer

	aidvector[0] = magRead(0);										//korrekturvektorberechnung mag
	aidvector[1] = magRead(1);										
	aidvector[2] = magRead(2);										
	vectorNormalisieren(aidvector);
	vectorKreuzprodukt(dcmIMU[2], aidvector, magKV);				//sollte gehen, scheint nix anderes rauszukommen wie wenn man vorher vektordifferenz berechnet, angular velocity

	aidvector[0] = -accRead(0);												//same for acc
	aidvector[1] = -accRead(1);												//negativ weil erdvektor nach unten aber K nach oben
	aidvector[2] = -accRead(2);
	vectorNormalisieren(aidvector);
	vectorKreuzprodukt(dcmIMU[0], aidvector, accKV);

	gyrRate[0] = gyrRead(0);													//gyrorate (rad/microsec)
	gyrRate[1] = gyrRead(1);
	gyrRate[2] = gyrRead(2);

	imu_update_intervall = micros() - imu_update_start;                        //elapsed time fürs gyro
	for (int i = 0; i < 3; i++) {												//gesamtkorrektionsvektor per komplementärfilter
		gyrRate[i] *= imu_update_intervall;										//gyrorate zu angular velocity
		gyrRate[i] = accGewicht * accKV[i] + gyrGewicht * gyrRate[i] + magGewicht * magKV[i];

	}
	
	dcm_rotate(dcmIMU, gyrRate);
	imu_update_start = micros();

}