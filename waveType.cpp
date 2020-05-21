//This file is a public member function of the UpdateOutput class.
//It is used to quickly select the type of output wave required 
//and pass any relavent data to them for each sample
//waveType() gets the current sample number and time samplesInPeriod
//from the "output_mail_box" struct that's updated by main()
//it then passes these varibles to the user selected wave type 
//which are all initalised as private member functions of the UpdateOutput class


#include "updateOutput.h"
//#define RUNTIME_LOGGING


void UpdateOutput::type(){
		

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
				Vout = sinWave();
				
				
				break;
			
			case TRIANGLE:
				#ifdef RUNTIME_LOGGING
				runTimeTest.reset();
				runTimeTest.start();
				#endif
				Vout = triangleWave();
				break;
			
			case SAW:
				#ifdef RUNTIME_LOGGING
				runTimeTest.reset();
				runTimeTest.start();
				#endif
			
				Vout = sawWave();
				break;
			
			case SQUARE:
				#ifdef RUNTIME_LOGGING
				runTimeTest.reset();
				runTimeTest.start();
				#endif
			
				Vout = squareWave();
				break;
			
			default:
				waveType = OFF;
				break;
					
		
		}//end of wave type switch case
		//return Vout;
		dac.write(Vout);
}