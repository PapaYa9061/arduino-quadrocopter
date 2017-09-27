#ifndef VECTOR3D_H
#define VECTOR3D_H

float vectorBetrag(float vector[3]);
void vectorNormalisieren(float *vector);
float vectorSkalarprodukt(float vector1[3], float vector2[3]);
void vectorKreuzprodukt(float vector1[3], float vector2[3], float vectorKreuz[3]);
void vectorSumme(float vector1[3], float vector2[3], float vectorKreuz[3]);
void vectorSkalarmultiplikation(float vector1[3], float skalar, float vectorErgebnis[3]);


#endif	VECTOR3D_H