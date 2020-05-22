#include "updateOutput.h"

float UpdateOutput::squareWave(){
	float Vout = 0.0f;
	float wave;
	
	float x = (float)(currentSampleNo % (int)samplesInPeriod)/samplesInPeriod;
	
	if (x > 0.5f){
		wave = 1.0f;
	}
	else{
		wave = 0.0f;
	} 
	Vout = (wave/WAVE_DEVIDOR)+(0.25f); 
	if (Vout > 1){
		clipLed = 1;
		Vout = 1.0f;
	}
	else if (Vout < 0.0f){
		clipLed = 1;
		Vout = 0.0f;
	}
	return Vout;
}//end of squareWave