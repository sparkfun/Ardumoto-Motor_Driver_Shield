//This sketch walks through various drive states.
//Use the serial terminal to advance states.  Enter some serial data and press return.
//The sketch only check for the existance of data, not what it is.
//
//The Ardumoto must have all pins set to alternate, timer1 only works on
//pins 9 and 10.
//
//Marshall Taylor
//March 3, 2017

#include "TimerOne.h"

// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
#define FORWARD  0
#define REVERSE 1

	// Motor definitions to make life easier:
#define MOTOR_A 0
#define MOTOR_B 1

// Pin Assignments //
// Timer1 connects only to PWM pins 9 and 10.

//Alternate pins:
#define DIRA 8 // Direction control for motor A
#define PWMA 9 // PWM control (speed) for motor A
#define DIRB 7 // Direction control for motor B
#define PWMB 10 // PWM control (speed) for motor B

void setup()
{
	Serial.begin(115200);
	setupArdumoto(); // Set all pins as outputs
}

void loop()
{
	int loopRunning = 1;
	int counter = 0;
	int state = 0;
	while( loopRunning == 1 )
	{
		//ramp up
		switch( state )
		{
		case 0:
			driveArdumoto(MOTOR_A, FORWARD, counter);
			driveArdumoto(MOTOR_B, FORWARD, counter);
			counter++;
			if( counter == 256 )
			{
				counter = 255;
				state = 1;
			}
			break;
		case 1:
			driveArdumoto(MOTOR_A, FORWARD, counter);
			driveArdumoto(MOTOR_B, FORWARD, counter);
			counter--;
			if( counter == 1 )
			{
				counter = 0;
				state = 0;
			}
			break;
		case 2:
			break;
		default:
			break;
		}
		delay(3);
		if( Serial.available() )
		{
			loopRunning = 0;
		}
	}
	waitForInput();

	// Now spin both!
	driveArdumoto(MOTOR_A, FORWARD, 255);  // Motor A at max speed.
	driveArdumoto(MOTOR_B, FORWARD, 255);  // Motor B at max speed.
	waitForInput();

	// Now go backwards at half that speed:
	driveArdumoto(MOTOR_A, REVERSE, 127);  // Motor A at max speed.
	driveArdumoto(MOTOR_B, REVERSE, 127);  // Motor B at max speed.
	waitForInput();
	
	stopArdumoto(MOTOR_A);  // STOP motor A 
	stopArdumoto(MOTOR_B);  // STOP motor A 
	waitForInput();
}

// driveArdumoto drives 'motor' in 'dir' direction at 'spd' speed
void driveArdumoto(byte motor, byte dir, byte spd)
{
	if (motor == MOTOR_A)
	{
		digitalWrite(DIRA, dir);
		//analogWrite(PWMA, spd);
		Timer1.pwm(PWMA, spd << 2);
	}
	else if (motor == MOTOR_B)
	{
		digitalWrite(DIRB, dir);
		//analogWrite(PWMB, spd);
		Timer1.pwm(PWMB, spd << 2);
	}  
}

// stopArdumoto makes a motor stop
void stopArdumoto(byte motor)
{
	driveArdumoto(motor, 0, 0);
}

// setupArdumoto initialize all pins
void setupArdumoto()
{
	// All pins should be setup as outputs:
	pinMode(PWMA, OUTPUT);
	pinMode(PWMB, OUTPUT);
	pinMode(DIRA, OUTPUT);
	pinMode(DIRB, OUTPUT);

	// Initialize all pins as low:
	digitalWrite(PWMA, LOW);
	digitalWrite(PWMB, LOW);
	digitalWrite(DIRA, LOW);
	digitalWrite(DIRB, LOW);
 
	Timer1.initialize(200);         // initialize timer1

}

void waitForInput( void )
{
	while( Serial.available() == 0 )
	{
		delay(1);
	}
	while( Serial.available() == 1 )
	{
		Serial.read();
		delay(1);
	}
}