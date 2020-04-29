#include "synth_os.h"
#include "updateOutput.cpp"
#include "sensorData.cpp"
//Uncomment next line to turn runtime logging on. View in putty.
//#define RUNTIME_LOGGING			
Serial pc(USBTX, USBRX);
DigitalOut led1(LED1);
AnalogOut dac(D13);

int main() {
	pc.printf("\r\n\r\ninside main\r\n\r\n");
	

	UpdateOutput wave;
	SensorData inputs;
	Timer time;
	Timer runTimeTest;
	
	enum waves {OFF = 0, SINE, TRIANGLE, SAW, SQUARE};
	int waveType = OFF;
	
	float sonarCorrection = inputs.calibrateSonar();//makes a measurement of the acatual run time of the sonar code
	float topFrequency = 1047.0f;										//the highest frequency the synth will play
	float upperSonarThreshold = 1000.0f;						//the furthest distance the sonar will register
	float lowerSonarThreshold = 100.0f;							//the closest distance the sonar will measure
	float period = 2272.73f; 
	float Vout = 0.0f;
	//replace with:
	//float period = inputs.getFrequency(float lowerThreshold, float upperThreshold, int correction, float topFrequency);
	//after bug fixes have been applied
	
	led1 = 1;					//turn on led1 to show code is running properly
	
	time.reset();
	time.start();
	int tmr = time.read_us();
	#ifdef RUNTIME_LOGGING
	int runtime = 0;
	#endif
	
	//test loop before thredding is applied
	while(true)
	{
		waveType = TRIANGLE; //keep synth producing a sine wave for testing
		tmr = time.read_us();
		switch(waveType)
		{
			case OFF:
				Vout = 0.0f;
				break;
			
			case SINE:
				#ifdef RUNTIME_LOGGING
				runTimeTest.reset();
				runTimeTest.start();
				#endif
				Vout = wave.sinWave(tmr , period);
				
				break;
			
			case TRIANGLE:
				#ifdef RUNTIME_LOGGING
				runTimeTest.reset();
				runTimeTest.start();
				#endif
				Vout = wave.triangleWave(tmr , period);
				break;
			
			case SAW:
				#ifdef RUNTIME_LOGGING
				runTimeTest.reset();
				runTimeTest.start();
				#endif
			
				Vout = wave.sawWave(tmr, period);
				break;
			
			case SQUARE:
				#ifdef RUNTIME_LOGGING
				runTimeTest.reset();
				runTimeTest.start();
				#endif
			
				Vout = wave.squareWave(tmr, period);
				break;
			
			default:
				waveType = OFF;
				break;
					
			
		}//end of wave type switch case
		//printf("\r\nVout: %6.5f\t", Vout);
		dac.write(Vout);
		
		#ifdef RUNTIME_LOGGING
		runTimeTest.stop();
		runtime = runTimeTest.read_us();
		printf("Run time of sample:\t %d us\n\r", runtime);
		#endif
	}

}
