#include "updateOutput.h"

float UpdateOutput::sawWave(){
	float Vout = 0.0f;
	//	float period5 = samplesInPeriod/1.587401052f;
	float resultingWave;
	float wave1 = 0.0f;
	//float wave2 = 0.0f;
	
	//wave2 = ((float)(currentSampleNo % (int)period5)/period5);
	wave1 = (0.5f*(float)(currentSampleNo % (int)samplesInPeriod)/samplesInPeriod);
	
	if (wave1 > 1.0f){
		clipLed = 1;
		wave1 = 0.0f;
	}

	
	resultingWave = wave1; //producing harmonics (root and dominant)
	Vout = (resultingWave/2.0f*WAVE_DEVIDOR)+(0.25f); //translate wave to work between 0 and 1 rather than -1 and 1
	if (Vout > 1){
		clipLed = 1;
		Vout = 1.0f;
	}
	else if (Vout < 0){
		clipLed = 1;
		Vout = 0.0f;
	}
	//printf("Vout = %5.3f\n\r", Vout);
	return Vout;
} //end of SAW