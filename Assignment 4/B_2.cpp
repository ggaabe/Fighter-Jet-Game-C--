#include "B_2.h"

B_2::B_2()
{
		fuel = 2000;
		flightStatus = false;
		landingGear = true;
		flightSpeed = 0;
		engineOn = false;
		bombs = 500;
		altitude = 0;
};

B_2::B_2(bool checkTakeoff)
{
		 if (checkTakeoff)				//if user wants to take off, initialize to these variables
	 {
		 engineOn = true;
		 flightSpeed = 162;
		 flightStatus = true;
		 landingGear = true;
		 fuel = 2000;
		 bombs = 500;
		 altitude = 50;
	 }
	 else						//if user doesn't want to take off, initialize to these variables
	 {
		fuel = 2000;
		flightStatus = false;
		landingGear = true;
		flightSpeed = 0;
		bombs = 500;
		engineOn = false;
		altitude = 0;
	 }
};

void B_2::checkFlightStatus()	//defines checkflight status, tells user whether the aircraft is in the air or not
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

void B_2::land()		//defines land, allows user to land bomber, deploys landing gear, reduces flight speed
{
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


void B_2::checkSpeed()		//defines checkSpeed, displays flight speed to user
{
	if (flightSpeed < 0)
	{
		flightSpeed = 0;
	}

	  cout << " Flight Speed: " << flightSpeed << " mph" << endl;
}

void B_2::checkFuel()		//defines checkFuel, displays the fuel level to user
{
		 if (fuel < 0)
	 {
		 fuel = 0;
	 }

	 cout << "Fuel Level: " << fuel << " gallons";
}


void B_2::checkHeight()		//defines checkHeight, displays the altitude/height of the bomber to the pilot
{
	cout << "Altitude: " << altitude << " feet";
}

void B_2::bombCheck(int i)	//defines bombCheck, displays how many bombs have been dropped to the pilot
{
	if (bombs < 0)
	{
		bombs = 0;
	}

	cout << "Bombs dropped: " << i << endl;
}


void B_2::engage()		//defines engage, allows pilot to drops their bombs, shows pilot total bombs dropped
{
	cout << "BEGINNING AIRSTRIKE.\nBOMB HATCH OPENING....\nBOMBS DROPPING|||||" << endl;
	system("pause");
	for (int i = 0; i <= 500; i++)
	{
		bombCheck(i);
		bombs -= 1;
	}
}


void B_2::increaseSpeed()		//increases speed of bomber, presents options to pilot to withdraw landing gear, to engage, and to land
{
checkFlightStatus();

	  for (flightSpeed; flightSpeed < 202; flightSpeed += 0) //standard loop to increase speed/spend fuel/increase altitude
	  {
		  srand(0);
		  checkSpeed();
		  cout << "\t ";
		  //checkFuel();
		  flightSpeed += 1;
		  altitude += 10;
		  fuel -= 0.5;

		  if (flightSpeed == 200)		//break if flight speed equals 200
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

	  while(flightSpeed < 560)			//run this while flight speed is less than 560, increases speed and height, decreases fuel
	  {
		//  srand(1776);
		  checkSpeed();
		  cout << "\t ";
		  checkHeight();
		  flightSpeed += 1;
		  altitude += 10;
		  fuel -= 0.2;
	  }

	  	  while(altitude < 50000)		//run this while altitude is less than 50,000, increase height, decrease fuel
	  {
		  srand(1776);
		  checkSpeed();
		  cout << "\t ";
		  checkHeight();
		  altitude += 50;
		  fuel -= 0.2;
	  }

		if (altitude > 50000)
		{
			altitude = 50000;
		}


	 		//allows user to engage enemy combatants
	  cout << "\n ALERT! Russian tank columns detected within the vicinity. Engage? (Y/N)" << endl;		//prompts pilot to engage
	  cin >> yn2;
	  if (yn2 == 'Y' || yn2 == 'y')
	  {
		  engage();
		  system("pause");
	  }
	  else if (yn2 == 'N' || yn2 == 'n')		//bomber is destroyed if pilot makes wrong choice
	  {
		  cout << "\nEnemy Anti-Aircraft has fired missiles. Rudders under critical damage. Ejecting." << endl;	
		  system("pause");
		  return;
	  }
	
 	  	  while(fuel > 200)		//decreases fuel after engagement
	  {
		  srand(8);
		  checkSpeed();
		  cout << "\t ";
		  checkFuel();
//		  flightSpeed += (rand() % 10);
		  fuel -= 5;
	  }
		
	  
	  cout << "\nWARNING! Fuel is low. Land? (Y/N)" << endl;	//warns pilot of low fuel, prompts to land
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
		  cout << "\t ";
		  checkFuel();
		  milesLeft();
//		  flightSpeed += (rand() % 10);
		  fuel -= 1.0;
		 }

		   cout << "\nWARNING: IF YOU TRAVEL ANY FARTHER YOU WILL NOT HAVE ENOUGH FUEL TO RETURN TO BASE.\n CENTRAL COMMAND ORDERS YOU BACK TO BASE."
		   << "\nReturn? (Y/N)" << endl;	//final warning to land due to low fuel
	  
	  cin >> yn4;

		  if (yn4 == 'Y' || yn4 == 'y')
		  {
			  land();
		  }
	  else if (yn4 == 'N' || yn4 == 'n')
	  {

	  while(fuel >= 0)		//B-2 runs out of fuel, plane is destroyed
	  {
		  srand(4);
		  checkSpeed();
		  cout << "\t ";
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

  void B_2::bomberStatus()			//displays the status of all variables involved in the functioning of the B-2 Bomber
  {
	  cout << "\nB-2 craft status: ";
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

	  if (bombs < 0)
	  {
		  bombs = 0;
	  }

	  cout << "Bombs remaining: " << bombs;
	  if (landingGear)
	  {
		cout << "\nLanding gear: Deployed." << endl;
	  }
	  else if (!landingGear)
	  {
		  cout << "\nLanding gear is not deployed. It seems you may have crashed." << endl;
	  }
  }
