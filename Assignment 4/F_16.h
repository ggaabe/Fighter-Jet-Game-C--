#ifndef F_16_h				//preprocessor directives to define F_16_h
#define F_16_h

#include <iostream>			//preprocessor directives for input/output stream, cstdib, and ctime
#include <cstdlib>
#include <ctime>

using namespace std;		//namespace std::

class F_16					//declares class name F_16
{
public:							//declares the public functions with all their headers
	F_16();
	F_16(bool checkTakeoff);
	void engage();
	void land();
	void landGear();
	void milesLeft();
	void increaseSpeed();
	void checkSpeed();
	void checkFlightStatus();
	void checkFuel();
	void fighterStatus();

private:					//declares the private members, all variables to be modified by public functions.
	double fuel;
	bool flightStatus;
	bool landingGear;
	int flightSpeed;
	int missiles;
	bool takeoff;
	bool engineOn;
};


#endif					//ends definition