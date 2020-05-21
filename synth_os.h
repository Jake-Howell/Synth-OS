#ifndef SYNTH_OS_H
#define SYNTH_OS_H

//enum to assign types of wave
enum waves {OFF = 0, SINE, TRIANGLE, SAW, SQUARE};

#define PI 3.14159265f						
#define WAVE_DEVIDOR 2.0f					//keeps wave well within 0 - 3.3v output voltage
#define SAMPLE_PERIOD_us 23				//us
#define SAMPLES_PER_SECOND 44100	//Hz

//////////sensor data//////////

//distance thresholds
#define UPPER_THRESHOLD 60.0f			//cm
#define LOWER_THRESHOLD 10.0f			//cm
#define OFF_DISTANCE 100.0f				//cm

//frequency thresholds
#define TOP_FREQUENCY 880.0f			//Hz
#define BOTTOM_FREQUENCY 220.0f		//Hz
#define OFF_FREQUENCY 1.0f				//Hz


#define UPDATE_INPUT_RATE 0.05f		//s


//#define LOGGING
#endif