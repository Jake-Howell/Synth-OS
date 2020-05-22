#include "synth_os.h"
#include "sensorData.h"
DigitalIn button(USER_BUTTON);

void SensorData::waveTypeSelector(){
	enum {RELEASED = 0, PRESSED};
	while(button == 1){
		debounce.reset();
		debounce.start();
		
		//debouncing rising edge
		while (debounce.read_ms() <= 50){
		}
		debounce.stop();
		debounce.reset();
		//check if button still = 1 after debounce buffer
		if (button == PRESSED){ 
			currentWaveType = currentWaveType + 1;
				//make sure we stay only select existing wave types
			if (currentWaveType > SQUARE){	
				currentWaveType = OFF;
			}
			
			//wait for button to be released
			while(button == PRESSED){
				
			} //end of wait for release
			wave.setWaveType(currentWaveType);
		}
		//if button was off before debounce buffer ended
		else{
			return;
		}
		
	}//end of while
}//end of waveTypeSelector
