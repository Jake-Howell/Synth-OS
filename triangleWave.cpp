#include "updateOutput.h"

float UpdateOutput::triangleWave(){

				float Vout = 0.0f;
				float wave;
				wave = (2*(float)(currentSampleNo % (int)samplesInPeriod)/samplesInPeriod);
				//decide if wave should rise or fall
				if (wave > 1.0f){	
					wave = 1.0f + (1.0f - wave);
				}

				//translate wave to work between 0 and 1 rather than -1 and 1
				Vout = (wave/WAVE_DEVIDOR)+(0.25f); 
				if (Vout > 1.0f){
					clipLed = 1;
					Vout = 1;					
				}
				else if (Vout < 0.0f){
					clipLed = 1;
					Vout = 0.0f;
				}
				return Vout;
}//end of triangle