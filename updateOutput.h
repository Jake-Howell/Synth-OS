#ifndef UPDATEOUTPUT_H
#define UPDATEOUTPUT_H
#include "mbed.h"
//#include "rtos.h"
#include "synth_os.h"


class UpdateOutput{
	
	public:
	
		//constructor for class, with member initializer list
		UpdateOutput();
		
		//public member functions
		void createSample(int setWaveType);
		void setWavePeriod(float samplesInPeriod);
		
				

	private:

		//class attributes
		DigitalOut runLed;
		DigitalOut clipLed;
		AnalogOut dac;
	
		Timer runTimeTest;
		Timer sampleTimer;
	
		int runTime = runTimeTest.read_us();
		float Vout;
		
		//private member functions
		void type();
		float sinWave();
		float sawWave();
		float triangleWave();
		float squareWave();
	
		//private attributes
		int waveType = SINE;
		int currentSampleNo = 20;
		float samplesInPeriod = 100.0f;
		bool waveState = 0;
		//float lastVout;

		
};

#endif