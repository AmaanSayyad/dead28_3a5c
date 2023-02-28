
#include <SPI.h>
#include <SD.h>
#include <Wire.h>
#include "GravitySensorHub.h"
#include "GravityRtc.h"
#include "GravityEc.h"
#include "GravityPh.h"
#include "GravityDo.h"
#include "OneWire.h"
#include "SdService.h"
#include "Debug.h"

// Alias clock module logic as rtc
GravityRtc rtc;

// Alias sensor logic as sensorHub 
GravitySensorHub sensorHub;

// Alias SD logic as sdService applied to sensors
SdService sdService = SdService(sensorHub.sensors);

void setup() {
	
	//Open communication at 9600 baud
	Serial.begin(9600);
	Debug::println("Serial begin");
	
	//initialize RTC module with computer time
	Debug::println("rtc.setup");
	rtc.setup();

	//Reset and initialize sensors
	Debug::println("sensorHub setup");
	sensorHub.setup();

	//Apply calibration offsets
	//Calibrate pH
	((GravityPh*)(sensorHub.sensors[phSensor]))->setOffset(PHOFFSET);
	Debug::print("pH offset: ");
	Debug::println(PHOFFSET);
	
	// Calibrate EC if present
	#ifdef SELECTEC
	((GravityEc*)(sensorHub.sensors[ecSensor]))->setKValue(ECKVALUE);
	Debug::print("EC K Value: ");
	Debug::println(ECKVALUE);
	#endif
	
	//Check for SD card and configure datafile
	Debug::println("sdService setup");
	sdService.setup();
}

//Create variable to track time
unsigned long updateTime = 0;

void loop() {
	//Update time from clock module
	rtc.update();

	//Collect sensor readings
	sensorHub.update();

	//Write data to SD card
	sdService.update();
}
