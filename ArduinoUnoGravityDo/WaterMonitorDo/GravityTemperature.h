

#pragma once
#include "ISensor.h"
#include "OneWire.h"
#define StartConvert 0
#define ReadTemperature 1

class GravityTemperature : public ISensor
{
public:
	// temperature sensor pin
	int temperaturePin;
	double temperature;

public:
	GravityTemperature(int pin);
	~GravityTemperature();

	// initialization
	void  setup ();

	// update the sensor data
	void  update ();

	// Get the sensor data
	double getValue();

private:

	OneWire * oneWire;
	unsigned  long tempSampleInterval = 850 ;
	unsigned  long tempSampleTime;

	// Analyze temperature data
	double TempProcess(bool ch);
};

