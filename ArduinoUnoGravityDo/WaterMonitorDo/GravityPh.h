

#pragma once
#include <Arduino.h>
#include "ISensor.h"
#include "Config.h"

class GravityPh:public ISensor
{
public:
	// ph sensor pin
	int pin;

	// offset compensation
	float offset;

private:
	int pHArray[ARRAYLENGTH];    // stores the average value of the sensor return data
	double pHValue;

public:
	GravityPh();
	~GravityPh() {};
	// initialization
	void  setup ();

	// update the sensor data
	void  update ();

	// Get the sensor data
	double getValue();

	//set offset
	void setOffset(float offset);
};

