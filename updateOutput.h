#ifndef UPDATEOUTPUT_H
#define UPDATEOUTPUT_H
#include "mbed.h"
#include "rtos.h"
#include "synth_os.h"


//Shared Data
typedef struct {
	int waveType = SINE;
	int currentSampleNo = 0;
	float samplesInPeriod = 2272.73;
}output_mail_t;



class UpdateOutput{
	
	public:
	
		//constructor for class, with member initializer list
		UpdateOutput();
		
		//public member functions
		void type(int waveType, int currentSampleNo, float samplesInPeriod);
				

	private:

		//class attributes
		DigitalOut runLed;
		DigitalOut clipLed;
		AnalogOut dac;
	
		Timer runTimeTest;	
	
		int runTime = runTimeTest.read_us();
		float Vout;
		
		//private member functions
		float sinWave(int currentSampleNo, float samplesInPeriod);

		float sawWave(int currentSampleNo, float samplesInPeriod);

		float triangleWave(int currentSampleNo, float samplesInPeriod);

		float squareWave(int currentSampleNo, float samplesInPeriod);
		
		bool waveState = 0;
		//float lastVout;

		
};

#endif