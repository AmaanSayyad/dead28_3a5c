

#include "SensorDo.h"
//#include "SoftwareSerial.h"

//SoftwareSerial mySerial(10, 11);

SensorDo::SensorDo()
{

}


SensorDo::~SensorDo()
{
}


//********************************************************************************************
// function name: setup ()
// Function Description: Initializes the sensor
//********************************************************************************************
void SensorDo::setup()
{
	sensorstring.reserve(30);
	//mySerial.begin(9600);
}


//********************************************************************************************
// function name: update ()
// Function Description: Update the sensor value
//********************************************************************************************
void SensorDo::update()
{
	static boolean sensorStringComplete = false;
	if (Serial.available() > 0)
	{
		char inchar = (char)Serial.read();
		this->sensorstring += inchar;
		if (inchar == '\r')
		{
			sensorStringComplete = true;
			//Serial.println("Do avaible");
		}		
	}
	if (sensorStringComplete == true)
	{
		if (isdigit(this->sensorstring[0]))
			doValue = this->sensorstring.toFloat();
		this->sensorstring = "";
		sensorStringComplete = false;
	}
}

//********************************************************************************************
// function name: getValue ()
// Function Description: Returns the sensor data
//********************************************************************************************
double SensorDo::getValue()
{
	return doValue;
}

//
//void serialEvent() {                                  //if the hardware serial port_0 receives a char
//	inputstring = Serial.readStringUntil(13);           //read the string until we see a <CR>
//	input_string_complete = true;                       //set the flag used to tell if we have received a completed string from the PC 
//}
