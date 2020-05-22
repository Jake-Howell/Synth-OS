#include "synth_os.h"
#include "updateOutput.h"
		//constructor for class, with member initializer list
		UpdateOutput::UpdateOutput(): clipLed(LED3), dac(D13){
			sampleClock.reset();
			sampleClock.start();
			sampleTriggerClock.reset();
			sampleTriggerClock.start();
		}
		
		