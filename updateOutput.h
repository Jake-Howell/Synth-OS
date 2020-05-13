#ifndef UPDATEOUTPUT_H
#define UPDATEOUTPUT_H
#include "mbed.h"
#include "rtos.h"
#include "synth_os.h"


//Shared Data
typedef struct {
	int waveType = SINE;
	int currentSampleNo = 0;
	float period = 2272.73;
}output_mail_t;

extern Mail<output_mail_t, 16>output_mail_box; 

class UpdateOutput{
	
	public:
	
		//constructor for class, with member initializer list
		UpdateOutput();
		
		//public member functions
		void type();
				

	private:

		//class attributes
		DigitalOut runLed;
		DigitalOut clipLed;
		AnalogOut dac;
	
		Timer runTimeTest;	
	
		int runTime = runTimeTest.read_us();
		float Vout;
		
		//private member functions
		float sinWave(int currentSampleNo, float period);

		float sawWave(int currentSampleNo, float period);

		float triangleWave(int currentSampleNo, float period);

		float squareWave(int currentSampleNo, float period);
		
		//extern float frequency(float lowerThreshold, float upperThreshold, int correction);
		bool waveState = 0;
		//float lastVout;

		//extern mail_t;
		//extern Mail<mail_t, 16>mail_box; 
		
};

#endif