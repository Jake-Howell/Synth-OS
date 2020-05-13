#include "synth_os.h"
#include "sensorData.h"



//constructor 
SensorData::SensorData(): trigger(D6), echo(D7){
}
//Serial pc(USBTX, USBRX);

Mail<sensor_mail_t, 16>sensor_mail_box;
//posting sensor mail
void SensorData::updateFrequency(){
	sensor_mail_t *sensor_mail = sensor_mail_box.alloc();
	
	sensor_mail->period = 10e6/getFrequency();
	sensor_mail_box.put(sensor_mail);
	
}
