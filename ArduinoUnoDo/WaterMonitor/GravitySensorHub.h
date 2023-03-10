

#pragma once
#include "ISensor.h"
/*
sensors :
0,ph
1,ec
2.orp
*/
class GravitySensorHub
{
private:
	static const int SensorCount = 10;

public:
	//********************************************************************************************
	// function name: sensors []
	// Function Description: Store the array of sensors
	// Parameters: 0 ph sensor
	// Parameters: 1 temperature sensor
	// Parameters: 2 Dissolved oxygen sensor
	// Parameters: 3 Conductivity sensor
	// Parameters: 4 Redox potential sensor
	//********************************************************************************************
	ISensor *sensors[SensorCount] = {0};
public:
	GravitySensorHub();
	~GravitySensorHub();

	// initialize all sensors
	void  setup ();

	// update all sensor values
	void  update ();

	// Get the sensor data
	double getValueBySensorNumber(int num);
};
