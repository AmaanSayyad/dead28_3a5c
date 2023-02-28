

#include "GravityPh.h"

extern uint16_t readMedianValue(int* dataArray, uint16_t arrayLength);

GravityPh::GravityPh():pin(PHPIN), offset(0.0f),pHValue(0)
{
}

//********************************************************************************************
// function name: setup ()
// Function Description: Initializes the ph sensor
//********************************************************************************************
void GravityPh::setup()
{
	pinMode(pin, INPUT);
}


//********************************************************************************************
// function name: update ()
// Function Description: Update the sensor value
//********************************************************************************************
void GravityPh::update()
{

	double averageVoltage = 0;

	for (uint8_t i = 0; i < ARRAYLENGTH; i++)
	{
		pHArray[i] = analogRead(this->pin);
		delay(10);
	}
	averageVoltage = readMedianValue(pHArray, ARRAYLENGTH);
	averageVoltage = averageVoltage*5.0 / 1024.0;
	pHValue = 3.5*averageVoltage + this->offset;

}


//********************************************************************************************
// function name: getValue ()
// Function Description: Returns the sensor data
//********************************************************************************************
double GravityPh::getValue()
{
	return this->pHValue;
}

void GravityPh::setOffset(float offset)
{
	this->offset = offset;
}


