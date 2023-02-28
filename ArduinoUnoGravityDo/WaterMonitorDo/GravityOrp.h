

#pragma once
#include <Arduino.h>
#include "ISensor.h"
#include "Config.h"
#include "debug.h"

class GravityOrp:public ISensor
{
public:
	//orp sensor pin
	int pin;

	//Voltage value
	double voltage;

	// Calibration offset
	float offset;

private:
	//orp value
	double orpValue;

	int orpArray[ARRAYLENGTH];

public:
	GravityOrp();
	~GravityOrp();

	// Initialize the sensor
	void setup();

	//Update sensor data
	void update();

	// Get sensor data
	double getValue();
};

