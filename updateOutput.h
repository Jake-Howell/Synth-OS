#include "synth_os.h"
//not to self
//these global may cause problems if multiple 
//instances of this class are used at once.
//be carefull!

//DigitalOut runLed(LED2);
//DigitalOut clipLed(LED3);
//AnalogOut dac(D13);
#ifndef UPDATEOUTPUT_H
#define UPDATEOUTPUT_H

class UpdateOutput{
	
	public:
	
		//constructor for class, with member initializer list
		UpdateOutput();
		
		//public member functions
		float type(int waveType, int currentSampleNo, float period);
				

	private:

		//class attributes
		DigitalOut runLed;
		DigitalOut clipLed;
		AnalogOut dac;
	
		Timer runTimeTest;	
	
		int runTime = runTimeTest.read_us();
		float Vout;
		
		//private member functions
		float sinWave(int currentSampleNo, float period);

		float sawWave(int currentSampleNo, float period);

		float triangleWave(int currentSampleNo, float period);

		float squareWave(int currentSampleNo, float period);
		
		//extern float frequency(float lowerThreshold, float upperThreshold, int correction);
		bool waveState = 0;
		//float lastVout;
};

#endif