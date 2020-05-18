#include "synth_os.h"
#include "sensorData.h"


float SensorData::getFrequency()
		{
			float resultingFrequency = 0.0f;
			float frequencyMultiplyer = 0.0f;
			float distance = 0.0f;
			// trigger sonar to send pulse for 10us
			trigger = 1; //signal 'high' to trigger pin
			sonar.reset(); //reset timer
			wait_us(10.0); //wait 10us
			trigger = 0;//signal 'low' to trigger pin
			//wait for echo high
			while (echo==0) {}; //loops empty body until echo is 'high'
			//echo high, so start timer
			sonar.start(); 
			//wait for echo low
			while (echo==1) {}; //loops empty body until echo is 'low'
			//stop timer and read value
			sonar.stop();
			//subtract software overhead timer calculate distance in cm
			distance = ((sonar.read_us()-correction)/58.8f);
			
			
			if (distance >= UPPER_THRESHOLD){  //check if distance is beyond desired operating threshold
				distance = 0.0f; //set distance to 0
			}
			else if (distance <= LOWER_THRESHOLD){  //check if distance is below desired operating threshold 
				distance = 0.0f; //set distance to 0
			}
			frequencyMultiplyer = (distance - LOWER_THRESHOLD)/(UPPER_THRESHOLD - LOWER_THRESHOLD); //calculate what frequency the distance corresponds to
			
			if (frequencyMultiplyer < 0.0f){ //check if multiplier is less than 0 (occurs when distance is below lower threshold or above upper threshold)
				frequencyMultiplyer = 0.000001; 
			}
			else if (frequencyMultiplyer > 1.0f){  //check if multiplier is above 1 
				frequencyMultiplyer = 1.0f;  //set multiplier to 1 if it is above 1, as 1 is the max value
			}
			
			resultingFrequency = TOP_FREQUENCY-(TOP_FREQUENCY*frequencyMultiplyer);
			//resultingFrequency = 440.0f;
			
			return resultingFrequency;
		
		}
		
