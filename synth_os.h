#ifndef SYNTH_OS_H
#define SYNTH_OS_H

//enum to assign types of wave
enum waves {OFF = 0, SINE, TRIANGLE, SAW, SQUARE};

#define PI 3.14159265f						
#define WAVE_DEVIDOR 2.0f					//keeps wave well within 0 - 3.3v output voltage
#define SAMPLE_PERIOD_us 23				//us
#define SAMPLES_PER_SECOND 44100	//Hz

//sensor data
#define LOWER_THRESHOLD 10.0f			//cm
#define UPPER_THRESHOLD 60.0f			//cm
#define TOP_FREQUENCY 784.0f			//Hz
#define BOTTOM_FREQUENCY 1.0f			//Hz
#define UPDATE_INPUT_RATE 0.05f		//s


//#define LOGGING
#endif