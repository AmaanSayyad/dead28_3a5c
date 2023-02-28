

#pragma once

#define RTC_Address   0x32  //RTC_Address

class GravityRtc
{
public:
	GravityRtc();
	~GravityRtc();

public:
	// Year Month Day Weekday Minute Seconds
	unsigned int year;
	unsigned char month;
	unsigned char day;
	unsigned char week;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;

	// initialize the RTC time to set the corresponding year, month, day, day, minute, minute
	void initRtc();

	// initialization
	void  setup ();

	// update the sensor data
	void  update ();
	// read the clock data
	void  readRtc();

	// parse RTC data
	void processRtc();


private:
	unsigned char date[7];

	// decimal to BCD
	char decTobcd(char num);
	void WriteTimeOn(void);
	void WriteTimeOff(void);
	unsigned long timeUpdate;


};

