////////////////////////////////
//														//
//	This code is not finished	//
//	and has some parts that 	//
//	will be removed or 				//
//	updated soon.							//
//														//
////////////////////////////////

#include "mbed.h"
//#include "rtos.h"
#include "cmath"


#include "updateOutput.h"
#include "sensorData.h"

Serial pc(USBTX, USBRX);
DigitalOut led1(LED1);

//Thread outputThread;
//Thread inputThread;

//LowPowerTicker inputTicker;
Timer trigger;

UpdateOutput wave;
SensorData inputs;


//Uncomment next line to turn runtime logging on. View in putty.
//#define RUNTIME_LOGGING			


//callback to run the inputs.updateFrequency() instance as a thread
void updateInput(){
	inputs.updateFrequency();
}

int main() {
	pc.printf("\r\n\r\ninside main\r\n\r\n");
	
	led1 = 1;					//turn on led1 to show main is running
	int setWaveType = TRIANGLE;
	
	//getting inputs 
	//inputTicker.attach(callback(updateInput),UPDATE_INPUT_RATE);
	
	
	led1 = 1;					//turn on led1 to show main is running

	trigger.reset();
	trigger.start();
	//UPDATING OUTPUT
	while(true){
		while (trigger.read() < UPDATE_INPUT_RATE){
			wave.createSample(setWaveType);
		}
		trigger.reset();
		inputs.updateFrequency();
	}//end of while
}//end of main
