//Ardumoto test sketch

//This sketch tests control and status LEDs

//The sketch walks through both default and alternate pins.  It sends
//serial data indicating which LEDs should be lit for a configuration,
//then waits for user input before continuing.

//Please do not connect any motors to the driver.

//(This is also the source location for pin defines)

//// Pin Assignments //
////Default pins:
//#define DIRA 2 // Direction control for motor A
//#define PWMA 3  // PWM control (speed) for motor A
//#define DIRB 4 // Direction control for motor B
//#define PWMB 11 // PWM control (speed) for motor B
//
//////Alternate pins:
////#define DIRA 8 // Direction control for motor A
////#define PWMA 9 // PWM control (speed) for motor A
////#define DIRB 7 // Direction control for motor B
////#define PWMB 10 // PWM control (speed) for motor B

//Test specific namings:
#define DIRA 2 // Direction control for motor A
#define PWMA 3  // PWM control (speed) for motor A
#define DIRB 4 // Direction control for motor B
#define PWMB 11 // PWM control (speed) for motor B
#define ALT_DIRA 8 // Direction control for motor A
#define ALT_PWMA 9 // PWM control (speed) for motor A
#define ALT_DIRB 7 // Direction control for motor B
#define ALT_PWMB 10 // PWM control (speed) for motor B



void setup()
{
	Serial.begin(115200);
}

void loop()
{
	//Set up for standard
	pinMode(PWMA, OUTPUT);
	pinMode(PWMB, OUTPUT);
	pinMode(DIRA, OUTPUT);
	pinMode(DIRB, OUTPUT);
	digitalWrite(PWMA, LOW);
	digitalWrite(PWMB, LOW);
	digitalWrite(DIRA, LOW);
	digitalWrite(DIRB, LOW);
	Serial.println("Testing default mode:");
	
	//Display PWMA
	Serial.println("PWMA should be lit, Drive A should be orange");
	digitalWrite(PWMA, HIGH);
	waitForInput();

	//Display PWMA and DIRA
	Serial.println("PWMA and DIRA should be lit, Drive A should be blue");
	digitalWrite(DIRA, HIGH);
	waitForInput();
	digitalWrite(PWMA, LOW);
	digitalWrite(DIRA, LOW);
	
	//Display PWMB
	Serial.println("PWMB should be lit, Drive B should be orange");
	digitalWrite(PWMB, HIGH);
	waitForInput();

	//Display PWMB and DIRA
	Serial.println("PWMB and DIRB should be lit, Drive B should be blue");
	digitalWrite(DIRB, HIGH);
	waitForInput();
	digitalWrite(PWMB, LOW);
	digitalWrite(DIRB, LOW);	

	pinMode(PWMA, INPUT);
	pinMode(PWMB, INPUT);
	pinMode(DIRA, INPUT);
	pinMode(DIRB, INPUT);
	
	//Set up for standard
	pinMode(ALT_PWMA, OUTPUT);
	pinMode(ALT_PWMB, OUTPUT);
	pinMode(ALT_DIRA, OUTPUT);
	pinMode(ALT_DIRB, OUTPUT);
	digitalWrite(ALT_PWMA, LOW);
	digitalWrite(ALT_PWMB, LOW);
	digitalWrite(ALT_DIRA, LOW);
	digitalWrite(ALT_DIRB, LOW);
	
	Serial.println("Testing alternate mode:");
	
	//Display PWMA
	Serial.println("PWMA should be lit, Drive A should be orange");
	digitalWrite(ALT_PWMA, HIGH);
	waitForInput();

	//Display PWMA and DIRA
	Serial.println("PWMA and DIRA should be lit, Drive A should be blue");
	digitalWrite(ALT_DIRA, HIGH);
	waitForInput();
	digitalWrite(ALT_PWMA, LOW);
	digitalWrite(ALT_DIRA, LOW);
	
	//Display PWMB
	Serial.println("PWMB should be lit, Drive B should be orange");
	digitalWrite(ALT_PWMB, HIGH);
	waitForInput();

	//Display PWMB and DIRA
	Serial.println("PWMB and DIRB should be lit, Drive B should be blue");
	digitalWrite(ALT_DIRB, HIGH);
	waitForInput();
	digitalWrite(ALT_PWMB, LOW);
	digitalWrite(ALT_DIRB, LOW);	

	pinMode(ALT_PWMA, INPUT);
	pinMode(ALT_PWMB, INPUT);
	pinMode(ALT_DIRA, INPUT);
	pinMode(ALT_DIRB, INPUT);

	
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