////////////////////////////////
//														//
//	ELEC 145 Design and build //
//					Synth-OS					//
//														//
////////////////////////////////

#include "mbed.h"
//#include "rtos.h"
#include "cmath"


#include "updateOutput.h"
#include "sensorData.h"

Serial pc(USBTX, USBRX);
DigitalOut led1(LED1);

Timer trigger;

UpdateOutput wave;
SensorData inputs;


//Uncomment next line to turn runtime logging on. View in putty.
//#define RUNTIME_LOGGING			


int main() {
	pc.printf("\r\n\r\ninside main\r\n\r\n");
	
	led1 = 1;					//turn on led1 to show main is running

	wave.setWaveType(SINE);
	
	trigger.reset();
	trigger.start();
	//UPDATING OUTPUT
	while(true){
		while (trigger.read() < UPDATE_INPUT_RATE){
			//updating output while inputs arnt being updated
			wave.createSample();
		}
		trigger.reset();
		
		//getting inputs at specified 'UPDATE_INPUT_RATE'
		inputs.waveTypeSelector();
		inputs.updateFrequency();
	}//end of while
}//end of main
