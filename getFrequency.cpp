#include "synth_os.h"
#include "sensorData.h"


float SensorData::getFrequency()
		{
			float resultingFrequency = 0.0f;
			float frequencyMultiplyer = 0.0f;
			float distance = 0.0f;
			// trigger sonar to send pulse of 10us time period
			trigger = 1;
			sonar.reset();
			wait_us(10.0);
			trigger = 0;
			//wait for echo high
			while (echo==0) {};
			//echo high, so start timer
			sonar.start();
			//wait for echo low
			while (echo==1) {};
			//stop timer and read value
			sonar.stop();
			//subtract software overhead timer delay and scale to cm
			distance = ((sonar.read_us()-correction)/5.80f);
			
			
			if (distance >= UPPER_THRESHOLD){
				distance = 0.0f;
			}
			else if (distance <= LOWER_THRESHOLD){
				distance = 0.0f;
			}
			frequencyMultiplyer = (distance - LOWER_THRESHOLD)/(UPPER_THRESHOLD - LOWER_THRESHOLD);
			
			if (frequencyMultiplyer < 0.0f){
				frequencyMultiplyer = 0.000001;
			}
			else if (frequencyMultiplyer > 1.0f){
				frequencyMultiplyer = 1.0f;
			}
			
			resultingFrequency = TOP_FREQUENCY-(TOP_FREQUENCY*frequencyMultiplyer);
			//resultingFrequency = 440.0f;
			
			return resultingFrequency;
		
		}
		