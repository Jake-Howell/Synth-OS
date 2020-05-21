#include "synth_os.h"
#include "mbed.h"
#include "updateOutput.h"

extern UpdateOutput wave;

void UpdateOutput::createSample(int setWaveType){
	
	
	int currentTime = sampleClock.read_us();						//read sampleClock function
	
	//figure out which sample we need to create depending on sampleClock
	currentSampleNo = currentTime/SAMPLE_PERIOD_us;			
	
	//adjust time offset to syincronise sample and avoid jitter
	//caused by unknown runtime of other code
	int jitterAdjust = currentTime % SAMPLE_PERIOD_us;  
	
	//start
	int sampleTrigger = sampleTriggerClock.read_us();
	
	if (sampleTrigger >= SAMPLE_PERIOD_us - jitterAdjust){
		//update output when sampleTriggerClock equals SAMPLE_PERIOD_us - the time offset (to subtract the jitter)
		type();
		
		if (currentSampleNo > SAMPLES_PER_SECOND){
			sampleClock.reset();	//reset sampleClock each second to prevent overflow 
		}
		sampleTriggerClock.reset();
		
		//add one or reset sampleNo after outputTicker or reset if it's reached 1 second of samples
		//currentSampleNo = (currentSampleNo < SAMPLES_PER_SECOND)?(currentSampleNo+1):0;
		//sampleTimer.reset();
		//sampleTimer.start();
	}// end of if
}