#include "synth_os.h"

//not to self
//these global may cause problems if multiple 
//instances of this class are used at once.
//be carefull!

//DigitalOut runLed(LED2);
//DigitalOut clipLed(LED3);
//AnalogOut dac(D13);

class UpdateOutput{

	
	public:
	
	
			//constructor for class, with member initializer list
				UpdateOutput(): runLed(LED2), clipLed(LED3) 
				{}
			
			float sinWave(int tmr, float period);

			float sawWave(int tmr, float period);

			float triangleWave(int tmr, float period);

			float squareWave(int tmr, float period);
				

	private:

	//class attributes
	DigitalOut runLed;
	DigitalOut clipLed;
	
	//extern float frequency(float lowerThreshold, float upperThreshold, int correction);
	bool waveState = 0;
	//float lastVout;
};