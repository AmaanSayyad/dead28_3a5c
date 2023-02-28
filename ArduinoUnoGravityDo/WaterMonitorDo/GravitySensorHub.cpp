


#include "GravitySensorHub.h"
#include "GravityPh.h"
#include "GravityOrp.h"
#include "GravityEc.h"
#include "GravityTemperature.h"
#include "GravityDo.h"
#include "Config.h"

//********************************************************************************************
// function name: sensors []
// Function Description: Store the array of sensors
// Parameters: 0 ph sensor
// Parameters: 1 temperature sensor
// Parameters: 2 Dissolved oxygen sensor
// Parameters: 3 Conductivity sensor
// Parameters: 4 Redox potential sensor
//********************************************************************************************

GravitySensorHub::GravitySensorHub()
{
	for (size_t i = 0; i < this->SensorCount; i++)
	{
		this->sensors[i] = NULL;
	}

	this->sensors[phSensor] = new GravityPh();
	this->sensors[temperatureSensor] = new GravityTemperature(TEMPPIN);
	this->sensors[doSensor] = new GravityDo();
	#ifdef SELECTEC
		this->sensors[ecSensor] = new GravityEc();
	#else
		this->sensors[tdsSensor] = new GravityTDS();
	#endif
	this->sensors[orpSensor] = new GravityOrp();
}

//********************************************************************************************
// function name: ~ GravitySensorHub ()
// Function Description: Destructor, frees all sensors
//********************************************************************************************
GravitySensorHub::~GravitySensorHub()
{
	for (size_t i = 0; i < SensorCount; i++)
	{
		if (this->sensors[i])
		{
			delete this->sensors[i];
		}
	}
}


//********************************************************************************************
// function name: setup ()
// Function Description: Initializes all sensors
//********************************************************************************************
void GravitySensorHub::setup()
{
	for (size_t i = 0; i < SensorCount; i++)
	{
		if (this->sensors[i])
		{
			this->sensors[i]->setup();
		}
	}
}


//********************************************************************************************
// function name: update ()
// Function Description: Updates all sensor values
//********************************************************************************************
void GravitySensorHub::update()
{
	for (size_t i = 0; i < SensorCount; i++)
	{
		if (this->sensors[i])
		{
			this->sensors[i]->update();
		}
	}
}

//********************************************************************************************
// function name: getValueBySensorNumber ()
// Function Description: Get the sensor data
// Parameters: 0 ph sensor
// Parameters: 1 temperature sensor
// Parameters: 2 Dissolved oxygen sensor
// Parameters: 3 Conductivity sensor
// Parameters: 4 Redox potential sensor
// Return Value: Returns the acquired sensor data
//********************************************************************************************
double GravitySensorHub::getValueBySensorNumber(int num)
{
	if (num >= SensorCount)
	{
		return 0;
	}
	return this->sensors[num]->getValue();
}
