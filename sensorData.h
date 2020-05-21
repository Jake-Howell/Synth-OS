#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include "synth_os.h"
#include "mbed.h"
//#include "rtos.h"
#include "updateOutput.h"

extern UpdateOutput wave;
extern Serial pc;

class SensorData{
	public:
			
		//constructor 
		SensorData();
		
		void updateFrequency();
		void waveTypeSelector();
		

	
	private:
		//private member functions
		float getFrequency();
		float calibrateSonar();
		
		//private attributes
		DigitalOut trigger;
		DigitalIn  echo;
		Timer debounce;
		Timer sonar;		
		int currentWaveType = OFF;
		int correction = calibrateSonar();
		float frequencyRange = (TOP_FREQUENCY - BOTTOM_FREQUENCY);
		float samplesInPeriod = 100.0f;

};
#endif