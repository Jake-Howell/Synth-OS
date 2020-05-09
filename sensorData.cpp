#include "synth_os.h"

//DigitalOut trigger(D6);
//DigitalIn  echo(D7);


class SensorData{
	public:
			
		//constructor 
		SensorData(): trigger(D6), echo(D7){
		}
		
		void updateFrequency(){
			
				period = 10e6/getFrequency();
			
			/*
			mail_t *mail = mailBox.alloc();
			mail->period = frequency;
      mailBox.put(mail);
			*/
		}
				
		

	
	private:
		//private member functions
		float getFrequency();
		float calibrateSonar();
		//private attributes
		DigitalOut trigger;
		DigitalIn  echo;
		Timer sonar;		
		int correction = calibrateSonar();
};