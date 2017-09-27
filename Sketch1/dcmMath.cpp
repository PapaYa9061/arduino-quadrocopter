#include"vector3D.h"



void dcm_rotate(float dcm[3][3], float rotationvector[3]) {
	float hilfsvector[3];
	for (int i = 0; i < 3; i++) {
		vectorKreuzprodukt(rotationvector, dcm[i], hilfsvector);
		vectorSumme(dcm[i], hilfsvector, dcm[i]);
	}
	dcm_orthonormalisieren(dcm);
}

void dcm_orthonormalisieren(float dcm[3][3]) {
	float fehler = vectorSkalarprodukt(dcm[0], dcm[1]);
	float korrektionsvektoren[2][3];
	vectorSkalarmultiplikation(dcm[0], -fehler / 2, korrektionsvektoren[0]);
	vectorSkalarmultiplikation(dcm[0], -fehler / 2, korrektionsvektoren[1]);
	vectorSumme(dcm[0], korrektionsvektoren[0], dcm[0]);
	vectorSumme(dcm[1], korrektionsvektoren[1], dcm[1]);
	vectorKreuzprodukt(dcm[0], dcm[1], dcm[2]);
	vectorNormalisieren(dcm[0]);
	vectorNormalisieren(dcm[1]);
	vectorNormalisieren(dcm[2]);
}