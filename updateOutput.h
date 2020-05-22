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
		void createSample();
		void setWavePeriod(int samplesInPeriod);
		void setWaveType(int newWaveType);
		
				

	private:

		//private member functions
		DigitalOut clipLed;
		AnalogOut dac;
	
		Timer runTimeTest;
		Timer sampleClock;
		Timer sampleTriggerClock;
		void type();
		float sinWave();
		float sawWave();
		float triangleWave();
		float squareWave();
	
		//private attributes
		int runTime = runTimeTest.read_us();
		float Vout;
		int waveType = OFF;
		int currentSampleNo = 0;
		int samplesInPeriod = 100;

		
};

#endif