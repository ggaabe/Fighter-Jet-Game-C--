/*Author: Gabriel Garrett
Assignment 4
Description: User flies a F-16 or B-2 bomber to fight Russian troops
*/

#include "F_16.h"			//includes F_16.h header file
#include "B_2.h"
#include <iostream>			//includes input/output stream

using namespace std;		//uses namespace std;	

int main()					//calls main function
{
char takeoff = 'Y';			//declares char takeoff variable, initalized to 'Y'
bool launch = true;			//declares boolean variable launch to be equal to true
char bomberFighter = 'B';

cout << "Welcome to the U.S. Air Force B-2 / F-16 flight-controls system." << endl;

cout << "COMMAND REPORT: Russian BTR-4's, tanks, and Mig fighters are \n approaching the Estonian and Maldovan borders through Crimea."
	<< "\nUkranian forces are overwhelmed. UN Security forces are moving towards the Polish and Ukrainian borders."
	<< "\nRussian troops are invading to establish a tactical position against NATO."
	<< "\nNATO forces are under duress. Poland, Sweden, France, and Britain are sending ground forces."
	<< "\nWe are scrambling all fighters and bombers to the western borders."
	<< "\nYou are the first line of defense. \nPrepare to engage." << endl;

cout << "Would you like to fly the B-2 Stealth Bomber or the F-16 Fighter Jet? (B for Bomber/F for fighter) "<< endl;
cin >> bomberFighter;

if (bomberFighter == 'F' || bomberFighter == 'f')
{
	cout << "\nTake off? (Y/N)";				//prompt for takeoff
	cin >> takeoff;								//user chooses his fate
	if (takeoff == 'Y' || takeoff == 'y')
	{
		launch == true;
	}
	else if (takeoff == 'N' || takeoff == 'n')			//if user chooses poorly he lets his country down
	{
		launch == false;
		cout << "You are a failure to your country." << endl;
		system("pause");					//hangs system output in console window
		return 1;
	}

	F_16 F16(launch);						//calls constructor with parameters
	cout << "\nTaking off..." << endl;	
	F16.checkFlightStatus();				//calls checkFlightStatus to show to user whether plane is successfully flying
	cout << endl;
	system("pause");						//hangs system output in console window
	cout << endl;
	F16.increaseSpeed();					//calls increaseSpeed automatically as plane rises and accelerates
	cout << endl;
	F16.fighterStatus();					//calls fighterStatus to display to user the status of his aircraft at the end of his flight
}

else if (bomberFighter == 'B' || bomberFighter == 'b')
{
cout << "\nTake off pls? (Y/N)";				//prompt for takeoff
cin >> takeoff;								//user chooses his fate
if (takeoff == 'Y' || takeoff == 'y')
{
	launch == true;
}
else if (takeoff == 'N' || takeoff == 'n')			//if user chooses poorly he lets his country down
{
	launch == false;
	cout << "You are a failure to your country." << endl;
	system("pause");					//hangs system output in console window
	return 1;
}

B_2 B2(launch);						//calls constructor with parameters
cout << "\nTaking off..." << endl;		
B2.checkFlightStatus();				//calls checkFlightStatus to show to user whether plane is successfully flying
cout << endl;
system("pause");						//hangs system output in console window
cout << endl;
B2.increaseSpeed();					//calls increaseSpeed automatically as plane rises and accelerates
cout << endl;
B2.bomberStatus();					//calls fighterStatus to display to user the status of his aircraft at the end of his flight
}


cout << endl;
system("pause");						//hangs system output in console window.
return 0;
}