#include "sensorData.cpp"

float SensorData::calibrateSonar(){
				Timer time;
			
				float distance = 0;
				int correction = 0;
				sonar.reset();
				// measure actual software polling timer delays
				// delay used later in time correction
				// start timer
				sonar.start();
				// min software polling delay to read echo pin
				while (echo==2) {};
				// stop timer
				sonar.stop();
				// read timer
				correction = sonar.read_us();
				
				time.reset();
				time.start();
				int tmr = time.read_ms();
				while (tmr >= 2000){}
					
			return correction;	//returns correction of 
		}//end of calibrate sonar