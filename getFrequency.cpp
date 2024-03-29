#include "synth_os.h"
#include "sensorData.h"
DigitalOut led(LED3);

float SensorData::getFrequency()
		{
			led = !led; //shows how often this function is running
			float resultingFrequency = 0.0f;
			float frequencyMultiplyer = 0.0f;
			float distance = 0.0f;
			// trigger sonar to send pulse for 10us
			trigger = 1; //signal 'high' to trigger pin
			
			//produce one wave sample to keep trigger on for 25us
			wave.createSample(); //this function takes about 25us to execute
			sonar.reset(); //reset timer
			trigger = 0;//signal 'low' to trigger pin
			//wait for echo high
			
			//----The next two while loops cause a 1-3 ms blocking problem//
			while (echo==0) {
				wave.createSample();		//this line keeps creating new samples while waiting for echo to become 1 to prevent blocking
			}; //loops empty body until echo is 'high'
			//echo high, so start timer
			sonar.start(); 
			//wait for echo low
			while (echo==1) {
				wave.createSample();		//this line keeps creating new samples while waiting for echo to become 0 to prevent blocking
			}; //loops empty body until echo is 'low'
			//stop timer and read value
			sonar.stop();
			//subtract software overhead timer calculate distance in cm
			distance = ((sonar.read_us()-correction)/58.8f);
			
			if(distance >= OFF_DISTANCE){
				resultingFrequency = OFF_FREQUENCY;
				return resultingFrequency;
			}
			else if (distance >= UPPER_THRESHOLD){  //check if distance is beyond desired operating threshold
				resultingFrequency = BOTTOM_FREQUENCY;	//set to min frequency
				return resultingFrequency;
			} 
			else if (distance <= LOWER_THRESHOLD){  //check if distance is below desired operating threshold 
				resultingFrequency = TOP_FREQUENCY;		//set to max frequency
				
				return resultingFrequency;
			}
			frequencyMultiplyer = (distance - LOWER_THRESHOLD)/(UPPER_THRESHOLD - LOWER_THRESHOLD); //calculate what frequency the distance corresponds to
			
			if (frequencyMultiplyer < 0.0f){ //check if multiplier is less than 0 (occurs when distance is below lower threshold or above upper threshold)
				frequencyMultiplyer = 0.000001f; 
			}
			else if (frequencyMultiplyer > 1.0f){  //check if multiplier is above 1 
				frequencyMultiplyer = 1.0f;  //set multiplier to 1 if it is above 1, as 1 is the max value
			}
			
			//This line sets frequency: the further away your hand 
			//is from the sensor, the lower the frequency
			resultingFrequency = ((frequencyRange) - ((frequencyRange)*frequencyMultiplyer))+ BOTTOM_FREQUENCY;
			//resultingFrequency = 440.0f;
			
			return resultingFrequency;
		//
		}
		