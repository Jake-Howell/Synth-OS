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

Ticker inputTicker;
//Ticker outputTicker;

UpdateOutput wave;
SensorData inputs;

void updateInput(){
	inputs.updateFrequency();
}

void updateOutput(){
	wave.type();
}

int main() {
	pc.printf("\r\n\r\ninside main\r\n\r\n");


	int sampleNo = 0;
	enum processes {UPDATE_OUTPUT = 0, GET_FREQUENCY};
	int setWaveType = OFF;
	 
	float timePeriod;
	
	led1 = 1;					//turn on led1 to show main is running
	
	//Updating output
	outputThread.start(callback(updateOutput));
	
	//getting inputs 
	inputTicker.attach(callback(updateInput),0.1f);
		
	//add one or reset sampleNo after outputTicker
	sampleNo = (sampleNo > SAMPLES_PER_SECOND)?(sampleNo++):0;
	
	//UPDATING OUTPUT
	while(true){
		
		//reciveing sensor mail
		osEvent evt = sensor_mail_box.get();
		if (evt.status == osEventMail) {
			sensor_mail_t *sensor_mail = (sensor_mail_t*)evt.value.p;
			timePeriod = sensor_mail->period;
			sensor_mail_box.free(sensor_mail);
		}//end of send sensor mail
		
		//posting output_mail
		extern Mail<output_mail_t, 16>output_mail_box;
		output_mail_t *output_mail = output_mail_box.alloc();
		output_mail->waveType = setWaveType;
		output_mail->currentSampleNo = sampleNo;
		output_mail->period = timePeriod; 
		output_mail_box.put(output_mail);
		}//end of while
}//end of main
