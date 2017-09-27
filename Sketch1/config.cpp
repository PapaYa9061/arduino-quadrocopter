

//accelerometer trim

float accOff[3] = { 0,0,0 };
bool accInv[3] = { false,false,false };
float accSen = 0;


//magnetometer trim

float magOff[3] = { 0,0,0 };
bool magInv[3] = { false,false,false };
float magSen = 0;


//gyro trim

float gyrOff[3] = { 0,0,0 };
bool gyrInv[3] = { false,false,false };
float gyrSen = 0;



//komplementärfilter

float accGewicht = 0;
float gyrGewicht = 0;
float magGewicht = 0;
