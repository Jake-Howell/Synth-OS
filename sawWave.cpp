#include "updateOutput.h"

float UpdateOutput::sawWave(){
	float Vout = 0.0f;
	float wave = 0.0f;

	wave = (0.5f*(float)(currentSampleNo % (int)samplesInPeriod)/samplesInPeriod);
	
	if (wave > 1.0f){
		clipLed = 1;
		wave = 0.0f;
	}
	
	//translate wave to work between 0 and 1 rather than -1 and 1
	Vout = (wave/2.0f*WAVE_DEVIDOR)+(0.25f); 
	if (Vout > 1){
		clipLed = 1;
		Vout = 1.0f;
	}
	else if (Vout < 0){
		clipLed = 1;
		Vout = 0.0f;
	}
	return Vout;
} //end of SAW