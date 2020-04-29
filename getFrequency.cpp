#include "synth_os.h"
#include "sensorData.cpp"

float SensorData::getFrequency(float lowerThreshold, float upperThreshold, int correction, float topFrequency)
		{
			
			float resultingFrequency = 0;
			float frequencyMultiplyer = 0;
			float distance = 0;
			// trigger sonar to send a ping
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

				
			if (distance >= upperThreshold){
				distance = 0;
			}
			else if (distance <= lowerThreshold){
				distance = 0;
			}
			frequencyMultiplyer = (distance - lowerThreshold)/(upperThreshold - lowerThreshold);
			
			if (frequencyMultiplyer < 0){
				frequencyMultiplyer = 0;
			}
			else if (frequencyMultiplyer > 1){
				frequencyMultiplyer = 1;
			}
				
			resultingFrequency = topFrequency*frequencyMultiplyer;
			//resultingFrequency = 440.0f;
			
			return resultingFrequency;
			
		}