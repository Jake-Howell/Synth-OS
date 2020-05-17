////////////////////////////////
//														//
//	This code is not finished	//
//	and has some parts that 	//
//	will be removed or 				//
//	updated soon.							//
//														//
////////////////////////////////

#include "mbed.h"
#include "rtos.h"
#include "cmath"


#include "updateOutput.h"
#include "sensorData.h"



//Uncomment next line to turn runtime logging on. View in putty.
//#define RUNTIME_LOGGING			
Serial pc(USBTX, USBRX);
DigitalOut led1(LED1);

Thread outputThread;
//Thread inputThread;

LowPowerTicker inputTicker;


Timer sampleTimer;

UpdateOutput wave;
SensorData inputs;

//callback to run the inputs.updateFrequency() instance as a thread
void updateInput(){
	inputs.updateFrequency();
}

int main() {
	pc.printf("\r\n\r\ninside main\r\n\r\n");


	int sampleNo = 20;
	enum processes {UPDATE_OUTPUT = 0, GET_FREQUENCY};
	int setWaveType = SINE;
	int sampleTmr;
	 
	float timePeriodInSamples = 100.0f;
	
	led1 = 1;					//turn on led1 to show main is running
	
	//getting inputs 
	inputTicker.attach(callback(updateInput),UPDATE_INPUT_RATE);
		
	sampleTimer.reset();
	sampleTimer.start();
	//UPDATING OUTPUT
	while(true){
		
		//reciveing sensor mail
		if (sensor_mail_box.empty() == false){
			osEvent evt = sensor_mail_box.get();
			if (evt.status == osEventMail) {
				sensor_mail_t *sensor_mail = (sensor_mail_t*)evt.value.p;
				timePeriodInSamples = sensor_mail->samplesInPeriod;
				sensor_mail_box.free(sensor_mail);
			}
		}//end of send sensor mail
		
		sampleTmr = sampleTimer.read_us();
		if(sampleTmr >= SAMPLE_PERIOD_us){

			//update output
			wave.type(setWaveType,sampleNo, timePeriodInSamples);
			
			//add one or reset sampleNo after outputTicker
			sampleNo = (sampleNo < SAMPLES_PER_SECOND)?(sampleNo+1):0;
			
			//reset timer
			sampleTimer.reset();
			sampleTimer.start();
		}//end of if
	}//end of while
}//end of main
