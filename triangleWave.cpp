#include "updateOutput.h"

float UpdateOutput::triangleWave(){

				float Vout = 0.0f;
				float resultingWave;
				float wave1;
				
				wave1 = (2*(float)(currentSampleNo % (int)samplesInPeriod)/samplesInPeriod);

				//decide if wave should rise or fall
				if (wave1 > 1.0f){	
					wave1 = 1.0f + (1.0f - wave1);
				}


				
				resultingWave = wave1; //producing harmonics (root and dominant)
				Vout = (resultingWave/WAVE_DEVIDOR)+(0.25f); //translate wave to work between 0 and 1 rather than -1 and 1
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