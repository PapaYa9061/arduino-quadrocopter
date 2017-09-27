#include <cmath>




float vectorBetrag(float vector[3]) {
	static float aid;
	aid = vector[0] * vector[0];
	aid += vector[1] * vector[1];
	aid += vector[2] * vector[2];
	return sqrt(aid);
}


void vectorNormalisieren(float *vector) {
	static float aid;
	aid = vectorBetrag(vector);
	vector[0] /= aid;
	vector[1] /= aid;
	vector[2] /= aid;	
}


float vectorSkalarprodukt(float vector1[3], float vector2[3]) {
	return vector1[0] * vector2[0] + vector1[1] * vector2[1] + vector1[2] * vector2[2];
}


//nur rechthandraum
void vectorKreuzprodukt(float vector1[3], float vector2[3], float vectorKreuz[3]) {
	vectorKreuz[0] = vector1[1] * vector2[2] - vector1[2] * vector2[1];
	vectorKreuz[1] = vector1[2] * vector2[0] - vector1[0] * vector2[2];
	vectorKreuz[2] = vector1[0] * vector2[1] - vector1[1] * vector2[0];
}


void vectorSumme(float vector1[3], float vector2[3], float vectorSumme[3]) {
	vectorSumme[0] = vector1[0] + vector2[0];
	vectorSumme[1] = vector1[1] + vector2[1];
	vectorSumme[2] = vector1[2] + vector2[2];
}


void vectorSkalarmultiplikation(float vector1[3], float skalar, float vectorErgebnis[3]) {
	vectorErgebnis[0] = vector1[0] * skalar;
	vectorErgebnis[1] = vector1[1] * skalar;
	vectorErgebnis[2] = vector1[2] * skalar;
}
