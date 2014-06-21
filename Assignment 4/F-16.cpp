/*Author: Gabriel Garrett
Problem: Assignment 3
Description: F-16 control console
*/

#include "F_16.h"					//preprocessor directive, includes F_16 header

 F_16::F_16()					//default constructor for F_16
	{
		fuel = 1073;
		flightStatus = false;
		landingGear = true;
		flightSpeed = 0;
		missiles = 4;
		engineOn = false;
	}

 F_16::F_16(bool checkTakeoff)	//parameter constructor for F_16
 {
	 if (checkTakeoff)				//if user wants to take off, initialize to these variables
	 {
		 engineOn = true;
		 flightSpeed = 140;
		 flightStatus = true;
		 landingGear = true;
		 fuel = 1073;
		 missiles = 4;
	 }
	 else						//if user doesn't want to take off, initialize to these variables
	 {
		fuel = 1073;
		flightStatus = false;
		landingGear = true;
		flightSpeed = 0;
		missiles = 4;
		engineOn = false;
	 }
 }

  void F_16::engage()			//defines engage function. Launches a missile at a target, decreases missile inventory by 1
 {
	cout << "Target Engaged. \nMissile Launched." << endl;
	missiles -= 1;
	cout << missiles << " missiles remaining." << endl;
 }

  void F_16::landGear()			//defines landGear function, deploys landing gear if it is not deployed, withdraws it if it is deployed.
  {
	  if (landingGear)
	  {
		  landingGear = false;
		  cout << "Landing gear withdrawn." << endl;
	  }
	  else if (!landingGear)
	  {
		  landingGear = true;
		  cout << "\nLanding gear deployed.";
	  }
	  cout << endl;
	  system("pause");
  }

  void F_16::land()		//defines land function, allows user to land. deploys landing gear. decreases flight speed. Sets flight status to false.
  {						//returns if landing was successful
	  if (!landingGear)
	  {
	  landGear();
	  }
	  do
	  {
	  srand(0);
	  flightSpeed -= (rand() % 7);
	  fuel -= 0.15;
	  cout << "Flight Speed: " << flightSpeed << endl;
	  }
	  while(flightSpeed > 0);
	  flightSpeed = 0;
	  cout << "Landing Successful";
	  flightStatus = false;
  }

  void F_16::milesLeft()		//defines milesLeft, tells user how many miles left based on fuel and standard F-16 MPG
  {
	  cout << "Miles left: "<< fuel * 2.5 << endl;

  }
  
  void F_16::checkSpeed()		//defines checkSpeed, returns to user the speed of the aircraft in miles per hour
  {
	  cout << " Flight Speed: " << flightSpeed << " mph" << endl;
  }

  void F_16::checkFlightStatus()	//defines checkflight status, tells user whether the aircraft is in the air or not
  {
	  cout << "Flight status: ";
	  if (flightStatus)
	  {
		  cout << "In Flight ";
	  }
	  else if (!flightStatus)
	  {
		  cout << "Grounded";
	  }

  }

 void F_16::checkFuel()		//defines checkFuel function, returns to user fuel level in gallons
 {
	 if (fuel < 0)
	 {
		 fuel = 0;
	 }

	 cout << "Fuel Level: " << fuel << " gallons";
 }


  void F_16::increaseSpeed()	//defines increaseSpeed function, increases F-16 speed, allows user to withdraw landing gear,
  {								// to engage in combat with enemy jets, warns user of low fuel, and allows user to land
	  checkFlightStatus();

	  for (flightSpeed; flightSpeed < 600; flightSpeed += 0) //standard loop to increase speed/spend fuel
	  {
		  srand(0);
		  checkSpeed();
		  cout << "\t";
		  checkFuel();
		  flightSpeed += (rand() % 3);
		  fuel -= 0.25;

		  if (flightSpeed == 599)
		  {
			  break;
		  }

	  }

  	  char yn;			//yes/no input variable declarations
	  char yn2;
	  char yn3;
	  char yn4;

	  if (landingGear)		//if landing gear is deployed, prompt appears for user to withdraw it
	  cout << "\nALERT! Landing gear is still deployed. Withdraw landing gear? (Y/N)" << endl;
	  cin >> yn;
	  if (yn == 'Y' || yn == 'y')
	  {
		  landGear();
	  }

	  while(flightSpeed < 1200)
	  {
		  srand(1776);
		  checkSpeed();
		  cout << "\t";
		  checkFuel();
		  flightSpeed += 1;
		  fuel -= 0.25;
	  }

	 		//allows user to engage enemy combatants
	  cout << "\n ALERT! Enemy combatants detected within the vicinity. Engage? (Y/N)" << endl;
	  cin >> yn2;
	  if (yn2 == 'Y' || yn2 == 'y')
	  {
		  engage();
		  system("pause");
	  }
	  else if (yn2 == 'N' || yn2 == 'n')
	  {
		  cout << "\nEnemy plane has fired missiles. Rudders under critical damage. Ejecting." << endl;
		  system("pause");
		  return;
	  }
	
 	  	  while(fuel > 200)
	  {
		  srand(8);
		  checkSpeed();
		  cout << "\t";
		  checkFuel();
//		  flightSpeed += (rand() % 10);
		  fuel -= 2.0;
	  }
		
	  
	  cout << "\nWARNING! Fuel is low. Land? (Y/N)" << endl;	//warns user of low fuel, prompts to land
	  cin >> yn3;

	  if (yn3 == 'Y' || yn3 == 'y')
	  {
		  land();
	  }
	  else if (yn3 == 'N' || yn3 == 'n')
	  {
  	  	
		 while(fuel > 100)
		 {
		  srand(6);
		  checkSpeed();
		  cout << "\t";
		  checkFuel();
		  milesLeft();
//		  flightSpeed += (rand() % 10);
		  fuel -= 0.25;
		 }

		   cout << "\nWARNING: IF YOU TRAVEL ANY FARTHER YOU WILL NOT HAVE ENOUGH FUEL TO RETURN TO BASE.\n CENTRAL COMMAND ORDERS YOU BACK TO BASE."
		   << "\nReturn? (Y/N)" << endl;
	  
	  cin >> yn4;

		  if (yn4 == 'Y' || yn4 == 'y')
		  {
			  land();
		  }
	  else if (yn4 == 'N' || yn4 == 'n')
	  {

	  while(fuel >= 0)		//user runs out of fuel, jet is destroyed
	  {
		  srand(4);
		  checkSpeed();
		  cout << " ";
		  checkFuel();
		  milesLeft();
//		  flightSpeed += (rand() % 10);
		  fuel -= 0.25;
	  }

	  cout << "You have run out of gas and are about to be ejected from the aircraft in 10 seconds. "
		   << "Please direct your craft to a safe landing zone and prepare to eject.\n";
	  for (int i = 10; i < 0; i++)
	  {
		  cout << i << flush << "\r";
	  }
	  engineOn = false;
	  return;
	  }

	  }

  }

  void F_16::fighterStatus()		//shows aircraft status at end of flight/ejection to the user
  {
	  cout << "\nF-16 craft status: ";
	  cout << endl;
	  checkFlightStatus();
	  cout << endl;
	  checkFuel();
	  cout << endl;
	  checkSpeed();
	  cout << endl;
	  if (engineOn)
	  {
		  cout << "Engine: On" << endl;
	  }
	  else if(!engineOn)
	  {
		  cout << "Engine: Off" << endl;
	  }


	  cout << "Missiles remaining: " << missiles;
	  if (landingGear)
	  {
		cout << "\nLanding gear: Deployed." << endl;
	  }
	  else if (!landingGear)
	  {
		  cout << "\nLanding gear is not deployed. It seems you may have crashed." << endl;
	  }
  }