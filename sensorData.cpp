#include "synth_os.h"

//DigitalOut trigger(D6);
//DigitalIn  echo(D7);


class SensorData{
	public:
			
		//constructor 
		SensorData(): trigger(D6), echo(D7){
		}
	
		float getFrequency(float lowerThreshold, float upperThreshold, int correction, float topFrequency = 1047.0f);		
		
		float calibrateSonar();

	
	private:
		//private attributes
		DigitalOut trigger;
		DigitalIn  echo;
		Timer sonar;		
};