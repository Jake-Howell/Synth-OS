#include "synth_os.h"
#include "mbed.h"
#include "updateOutput.h"

extern UpdateOutput wave;

void UpdateOutput::createSample(int setWaveType){
	
	
	int sampleTmr = sampleTimer.read_us();
	
	
	if (sampleTmr >= SAMPLE_PERIOD_us){
		//update output
		type();
		//add one or reset sampleNo after outputTicker or reset if it's reached 1 second of samples
		currentSampleNo = (currentSampleNo < SAMPLES_PER_SECOND)?(currentSampleNo+1):0;
		sampleTimer.reset();
		sampleTimer.start();
	}// end of if
}