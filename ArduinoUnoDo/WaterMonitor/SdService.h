

#pragma once

#include "ISensor.h"
#include <SD.h>
#include "string.h"

class SdService
{

public:
	int chipSelect;
public:
	SdService(ISensor* gravitySensor[]);
	~ SdService ();

	// initialization
	void  setup ();

	// Update write SD card data
	void  update ();

private:
	// points to the pointer to the array of sensors
	ISensor** gravitySensor;
	//String dataString ;

	bool sdReady = false;

	// file handle
	File dataFile;
	unsigned long sdDataUpdateTime;

	// Connect the string data
	void connectString(double value);

};

