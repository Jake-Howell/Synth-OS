#include "synth_os.h"
#include "updateOutput.h"
		//constructor for class, with member initializer list
		UpdateOutput::UpdateOutput():runLed(LED2), clipLed(LED3), dac(D13)
		{}
			
		Mail<output_mail_t, 16>output_mail_box;