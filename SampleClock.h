#ifndef SAMPLE_CLOCK_H
#define SAMPLE_CLOCK_H

#include "synth_os.h"
#include "mbed.h"
#include "rtos.h"
#include 
//DigitalOut trigger(D6);
//DigitalIn  echo(D7);


class SampleClock{
	public:
			
		//constructor 
		SampleClock();
		
	`	void createSample(int setWaveType, int sampleNo, float timePeriod);
		

	
	private:
		//private member functions
		Timer sampleTimer;
		extern UpdateOutput wave;
		
		//private attributes
		int sampleTmr;
};
#endif