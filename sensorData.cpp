#include "synth_os.h"
#include "sensorData.h"



//constructor 
SensorData::SensorData(): trigger(D6), echo(D7){
}
//Serial pc(USBTX, USBRX);


void SensorData::updateFrequency(){
	
	//setting period in terms of samples per second
	samplesInPeriod = SAMPLES_PER_SECOND/(int)getFrequency();
	wave.setWavePeriod(samplesInPeriod);
	
}
