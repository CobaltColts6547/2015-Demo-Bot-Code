#pragma config(Hubs, S1, HTMotor, HTMotor, none, none)
#pragma config(Sensor, S1, , sensorI2CMuxController)
#pragma config(Motor, mtr_S1_C1_1, backRight, tmotorTetrix, openLoop)
#pragma config(Motor, mtr_S1_C1_2, frontRight, tmotorTetrix, openLoop)
#pragma config(Motor, mtr_S1_C2_1, frontLeft, tmotorTetrix, openLoop, reversed)
#pragma config(Motor, mtr_S1_C2_2, backLeft, tmotorTetrix, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard !!*//

/*
|
|		 ______            _        ____        _   
|		|  ____|          (_)      |  _ \      | |  
|		| |__   _ __ _ __  _  ___  | |_) | ___ | |_ 
|		|  __| | '__| '_ \| |/ _ \ |  _ < / _ \| __|
|		| |____| |  | | | | |  __/ | |_) | (_) | |_ 
|		|______|_|  |_| |_|_|\___| |____/ \___/ \__|
|		                                            
|
|		Team: Cobalt Colts 6547 � 2014-15
|		Head Tele-Op Programmer: Ryan Pope
|
|			 How to Drive the Robot: Arcade Drive
|			--------------------------------------
|
|		Left Joystick Up/Down = Drive Forward
|		Left Joystick Left/Right = Turn Robot Left/Right
|
*/

//	Joystick code
#include "JoystickDriver.c"

/*
| ------------------------------------------------------------------------------
| Controller buttons
| ------------------------------------------------------------------------------
*/
int x = 1, a = 2, b = 3, y = 4; /* Buttons */
int leftBumper = 5, rightBumper = 6; /* Bumpers */
int leftTrigger = 7, rightTrigger = 8; /* Triggers */
int backButton = 9, startButton = 10; /* Start and Back Buttons */
int x1 = joystick.joy1_x1, y1 = joystick.joy1_y1, y2 = joystick.joy1_y2; /* Joystick 1 */
int isArcade = 1; /* Allows switching between arcade and tank */

task main()
{

	while(true)
	{
		//	Update joystick values
		getJoystickSettings(joystick);

		//	Drive code
		if (isArcade) // For arcade drive
		{
			motor[frontLeft] = y1 + x1;
			motor[backLeft] = y1 + x1;
			motor[frontRight] = y1 - x1;
			motor[backRight] = y1 - x1;	
		}
		else // For tank drive
		{
			motor[frontLeft] = y1;
			motor[backLeft] = y1;
			motor[frontRight] = y2;
			motor[backRight] = y2;	
		}

		// Start Button toggles between tank and arcade
		if (joy1Btn(startButton))
		{
			isArcade = 0 ? 1 : 0;
		} 
	}
}