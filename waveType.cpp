#include "updateOutput.h"
//#define RUNTIME_LOGGING


float UpdateOutput::type(int waveType, int currentSampleNo, float period){


enum waves {OFF = 0, SINE, TRIANGLE, SAW, SQUARE};

		switch(waveType)
		{
			case OFF:
				Vout = 0.0f;
				break;
			
			case SINE:
				#ifdef RUNTIME_LOGGING
				runTimeTest.reset();
				runTimeTest.start();
				#endif
				Vout = sinWave(currentSampleNo , period);
				
				
				break;
			
			case TRIANGLE:
				#ifdef RUNTIME_LOGGING
				runTimeTest.reset();
				runTimeTest.start();
				#endif
				Vout = triangleWave(currentSampleNo , period);
				break;
			
			case SAW:
				#ifdef RUNTIME_LOGGING
				runTimeTest.reset();
				runTimeTest.start();
				#endif
			
				Vout = sawWave(currentSampleNo, period);
				break;
			
			case SQUARE:
				#ifdef RUNTIME_LOGGING
				runTimeTest.reset();
				runTimeTest.start();
				#endif
			
				Vout = squareWave(currentSampleNo, period);
				break;
			
			default:
				waveType = OFF;
				break;
					
		dac.write(Vout);
		}//end of wave type switch case
		return Vout;
	}