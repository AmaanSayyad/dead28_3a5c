

#pragma once

#define RTC_Address   0x32  //RTC_Address 

class GravityRtc
{
public:
	GravityRtc();
	~GravityRtc();

public:
	//Year Month Day Weekday Minute Second
	unsigned int year;
	unsigned char month;
	unsigned char day;
	unsigned char week;
	unsigned char hour;
	unsigned char minute;
	unsigned char second;
	
	//Initialize RTC time to set the corresponding year, month, day, Weekday Minute Second
	void initRtc(unsigned int year,	unsigned char month,unsigned char day,unsigned char week,
            	unsigned char hour,unsigned char minute,unsigned char second);

	//initialization
	void setup();

	//Update sensor data
	void update();
	

private:
	unsigned char date[7];

	//Read RTC Time
	void readRtc();

	//Analysis RTC Time
	void processRtc();

	//Decimal turn to BCD
	char decTobcd(char num);
	void WriteTimeOn(void);
	void WriteTimeOff(void);
	unsigned long timeUpdate;


};

