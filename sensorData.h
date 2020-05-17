#ifndef SENSOR_DATA_H
#define SENSOR_DATA_H

#include "synth_os.h"
#include "mbed.h"
#include "rtos.h"
//DigitalOut trigger(D6);
//DigitalIn  echo(D7);

//extern mail_t;
//extern Mail<mail_t, 16>mail_box; 

//Shared Data
typedef struct {
	float samplesInPeriod = 2272.73f;
}sensor_mail_t;

extern Mail<sensor_mail_t, 16>sensor_mail_box; 

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

};
#endif