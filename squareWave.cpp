#include "updateOutput.h"

float UpdateOutput::squareWave(){
	float Vout = 0.0f;
	//float period5 = period/1.587401052;
	float resultingWave;
	
	float x = (float)(currentSampleNo % (int)samplesInPeriod)/samplesInPeriod;
	
	if (x > 0.5f){
		resultingWave = 1.0f;
	}
	else{
		Vout = 0.0f;
	}
	
	Vout = (resultingWave/WAVE_DEVIDOR)+(0.25f); //translate wave to work between 0 and 1 rather than -1 and 1
	if (Vout > 1){
		clipLed = 1;
		Vout = 1.0f;
	}
	else if (Vout < 0.0f){
		clipLed = 1;
		Vout = 0.0f;
	}
	//printf("Vout = %5.3f\n\r", Vout);
	return Vout;
}//end of squareWave