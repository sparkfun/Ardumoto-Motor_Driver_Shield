    /* Ardumoto Example Sketch
  by: Jim Lindblom
  date: November 8, 2013
  license: Public domain. Please use, reuse, and modify this 
  sketch!

  Adapted to v20 hardware by: Marshall Taylor
  date: March 31, 2017
  
  Three useful functions are defined:
    setupArdumoto() -- Setup the Ardumoto Shield pins
    driveArdumoto([motor], [direction], [speed]) -- Drive [motor] 
      (0 for A, 1 for B) in [direction] (0 or 1) at a [speed]
      between 0 and 255. It will spin until told to stop.
    stopArdumoto([motor]) -- Stop driving [motor] (0 or 1).

  setupArdumoto() is called in the setup().
  The loop() demonstrates use of the motor driving functions.
*/

// Clockwise and counter-clockwise definitions.
// Depending on how you wired your motors, you may need to swap.
#define FORWARD  0
#define REVERSE 1

// Motor definitions to make life easier:
#define MOTOR_A 0
#define MOTOR_B 1

// Pin Assignments //
//Default pins:
#define DIRA 2 // Direction control for motor A
#define PWMA 3  // PWM control (speed) for motor A
#define DIRB 4 // Direction control for motor B
#define PWMB 11 // PWM control (speed) for motor B

////Alternate pins:
//#define DIRA 8 // Direction control for motor A
//#define PWMA 9 // PWM control (speed) for motor A
//#define DIRB 7 // Direction control for motor B
//#define PWMB 10 // PWM control (speed) for motor B


void setup()
{
  setupArdumoto(); // Set all pins as outputs
}

void loop()
{
  // Drive motor A (and only motor A) at various speeds, then stop.
  driveArdumoto(MOTOR_A, REVERSE, 255); // Set motor A to REVERSE at max
  delay(1000);  // Motor A will spin as set for 1 second
  driveArdumoto(MOTOR_A, FORWARD, 127);  // Set motor A to FORWARD at half
  delay(1000);  // Motor A will keep trucking for 1 second 
  stopArdumoto(MOTOR_A);  // STOP motor A 

  // Drive motor B (and only motor B) at various speeds, then stop.
  driveArdumoto(MOTOR_B, REVERSE, 255); // Set motor B to REVERSE at max
  delay(1000);  // Motor B will spin as set for 1 second
  driveArdumoto(MOTOR_B, FORWARD, 127);  // Set motor B to FORWARD at half
  delay(1000);  // Motor B will keep trucking for 1 second
  stopArdumoto(MOTOR_B);  // STOP motor B 

  // Drive both
  driveArdumoto(MOTOR_A, FORWARD, 255);  // Motor A at max speed.
  driveArdumoto(MOTOR_B, FORWARD, 255);  // Motor B at max speed.
  delay(1000);  // Drive forward for a second
  // Now go backwards at half that speed:
  driveArdumoto(MOTOR_A, REVERSE, 127);  // Motor A at max speed.
  driveArdumoto(MOTOR_B, REVERSE, 127);  // Motor B at max speed.
  delay(1000);  // Drive forward for a second

  // Now spin in place!
  driveArdumoto(MOTOR_A, FORWARD, 255);  // Motor A at max speed.
  driveArdumoto(MOTOR_B, REVERSE, 255);  // Motor B at max speed.
  delay(2000);  // Drive forward for a second
  stopArdumoto(MOTOR_A);  // STOP motor A 
  stopArdumoto(MOTOR_B);  // STOP motor B 

}

// driveArdumoto drives 'motor' in 'dir' direction at 'spd' speed
void driveArdumoto(byte motor, byte dir, byte spd)
{
  if (motor == MOTOR_A)
  {
    digitalWrite(DIRA, dir);
    analogWrite(PWMA, spd);
  }
  else if (motor == MOTOR_B)
  {
    digitalWrite(DIRB, dir);
    analogWrite(PWMB, spd);
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
}
