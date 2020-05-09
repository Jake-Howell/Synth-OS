#include "mbed.h"
#include "rtos.h"
#include "cmath"

//Shared Data
typedef struct {
	float period = 2272.73f;
}mail_t;
Mail<mail_t, 16>mailBox; 

//float period = 2272.73;

#include "updateOutput.h"
#include "sensorData.cpp"

//Uncomment next line to turn runtime logging on. View in putty.
//#define RUNTIME_LOGGING			
Serial pc(USBTX, USBRX);
DigitalOut led1(LED1);
Mutex mutex;
Thread outputThread;
Thread inputThread;


extern void beginHere();

//protect shared data



//Mail<mail_t, 16> mailBox; 

int main() {
	pc.printf("\r\n\r\ninside main\r\n\r\n");
	
	
	
	Timer sampleClock;
	UpdateOutput wave;
	SensorData inputs;
	

	int currentSampleNo = 0;
	enum processes {UPDATE_OUTPUT = 0, GET_FREQUENCY};
	enum waves {OFF = 0, SINE, TRIANGLE, SAW, SQUARE};
	int waveType = OFF;
	 
	float Vout = 0.0f;
	//replace with:
	//float period = inputs.getFrequency(int correction);
	//after bug fixes have been applied
	
	led1 = 1;					//turn on led1 to show code is running properly
	
	
	while(true)
	{
		sampleClock.start();
		if (sampleClock.read_us() >= SAMPLE_PERIOD_us){
			Vout = wave.type(SINE, currentSampleNo, period);
			sampleClock.reset();
		}
	}

}
