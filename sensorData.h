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
		

	
	private:
		//private member functions
		float getFrequency();
		float calibrateSonar();
		
		//private attributes
		DigitalOut trigger;
		DigitalIn  echo;
		Timer sonar;		
		int correction = calibrateSonar();

		float samplesInPeriod = 100.0f;

};
#endif