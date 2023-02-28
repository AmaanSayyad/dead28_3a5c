
#pragma once
#include "ISensor.h"
#include "Arduino.h"

class SensorDo: public ISensor
{
public:
	SensorDo();
	~SensorDo();

public:
	// initialization
	void  setup ();

	// update the sensor data
	void  update ();

	// Get the sensor data
	double getValue();

private:

	String sensorstring = "";

	// do the data
	double doValue;

};

