#include "updateOutput.h"

float UpdateOutput::sinWave(int currentSampleNo, float samplesInPeriod){
	float omega = (2.0f*PI/samplesInPeriod)*(float)currentSampleNo;
	float wave = sin(omega);
	float Vout = (wave/(2.0f*WAVE_DEVIDOR))+0.5f; //translate wave to work between 0 and 1 rather than -1 and 1
	
	if (Vout > 1.0f){
		clipLed = 1;
		Vout = 1.0f;
	}
	else if (Vout < 0.0f){
		clipLed = 1.0f;
		Vout = 0.0f;
	}
	//printf("Vout = %5.3f\n\r", Vout);
	
	return Vout;
}//end of SIN