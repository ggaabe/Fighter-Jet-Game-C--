#ifndef B_2_h			//defines the preprocessor directives
#define B_2_h

#include "F_16.h"		//includes the header file for the base class


class B_2: public F_16	//declares and defines the class name B_2 to include all public members of F_16 to be public members of B_2
{
public:							//declares the public functions with all their headers
	B_2();
	B_2(bool checkTakeoff);
	void checkFlightStatus();
	void increaseSpeed();
	void checkHeight();
	void engage();
	void bombCheck(int i);
	void bomberStatus();
	void checkSpeed();
	void checkFuel();
	void land();

private:						//declares the private members, all variables to be modified by public functions.
	int supplyCrate;
	double fuel;
	bool flightStatus;
	bool landingGear;
	int flightSpeed;
	bool takeoff;
	bool engineOn;
	int altitude;
	int bombs;
};


#endif							//ends definition