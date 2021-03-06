/*
   Set 3
   LED Socket Kit (D2): digital output
   Line Finder (D3): digital input
   Water Sensor (D4): digital/analog input
   Servo (D6): digital output
*/

// import libraries
#include <Servo.h>

// set pin numbers
#define LED ...                   // number of the LED pin
#define linePin ...               // number of the lineFinder pin
#define waterPin ...              // number of the waterSensor pin
#define servoPin ...              // number of the servo pin

// set helpful values
#define FULL_SERVO_ANGLE 150  //full value of the servo is 150 degrees

// define variables that will change
int pos = 0;    // variable to store the servo position
bool black = false;
bool dry = true;

Servo myServo;  // create servo object to control a servo

/*
    Initial set up function to set pin modes and serial monitor.

    @param
    @return null
*/
void setup()
{
  Serial.begin(...);         // choose 9600 baud rate for serial monitor

  pinMode(LED, ...);       // initialize the LED pin as an output
  pinMode(..., ...);   // initialize the waterPin as an input
  pinMode(..., ...);    // initialize the linePin as an input
  myServo.attach(servoPin);   // attaches the servo on servoPin to the servo object
}

/*
    Main loop function for program execution. Calls all the module functions.

    @param
    @return null
*/
void loop()
{
  delay(...);   // delay by 200ms
  servoControl();
  controlLED();
  lineFinder();
  waterSensor();
}

/*
    Rotates the servo CCW if black is detected. Rotates CW otherwise.

    @param
    @return null
*/
void servoControl()
{
  if (black && pos <= FULL_SERVO_ANGLE)
  {
    ...;   // increase servo position by 5 degrees
  } else if (!black && pos >= 0)
  {
    ...   // decrease servo position by 5 degrees
  }

  myServo.write(pos);

  //Serial.println(pos);

  //  Serial.print("pos:");
  //  Serial.println(pos);

  //  // sample code to rotate servo slowly
  //  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
  //    // in steps of 1 degree
  //    myServo.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(15);                       // waits 15ms for the servo to reach the position
  //  }
  //  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
  //    myServo.write(pos);              // tell servo to go to position in variable 'pos'
  //    delay(15);                       // waits 15ms for the servo to reach the position
  //  }
}

/*
    Lights up LED if black is detected.

    @param
    @return null
*/
void controlLED()
{
  if (black)
  {
    ...   // switch off LED
  } else {
    ...  // switch on LED
  }
}

/*
    Detects the presence of black. Changes the global black variable accordingly.

    @param
    @return null
*/
void lineFinder()
{
  if (digitalRead(...) == HIGH)
  {
    Serial.println("black");
    black = ...;
  } else {
    Serial.println("white");
    black = ...;
  }
}

/*
    Detects the presence of water. Changes the global dry variable accordingly.

    @param
    @return null
*/
void waterSensor()
{
  dry = digitalRead(...);
  if (...)
  {
    Serial.println("Water sensor is DRY");
  } else {
    Serial.println("Water sensor is WET");
  }
}
