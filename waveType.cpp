//This file is a public member function of the UpdateOutput class.
//It is used to quickly select the type of output wave required 
//and pass any relavent data to them for each sample
//waveType() gets the current sample number and time period
//from the "output_mail_box" struct that's updated by main()
//it then passes these varibles to the user selected wave type 
//which are all initalised as private member functions of the UpdateOutput class


#include "updateOutput.h"
//#define RUNTIME_LOGGING


void UpdateOutput::type(){
		int waveType;
		int currentSampleNo;
		float period;
	
		//reciving output mail
		osEvent evt = output_mail_box.get();
		if (evt.status == osEventMail) {
			output_mail_t *output_mail = (output_mail_t*)evt.value.p;
			waveType = output_mail->waveType;
			currentSampleNo = output_mail->currentSampleNo;
			period = output_mail->period;
			output_mail_box.free(output_mail);
		}//end of output_mail get
		

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
		//return Vout;
}