/*
   Set 4
   Thumb Joystick (A0/A1): analog input
   LED Socket Kit (D2): digital output
   Servo (D6): digital output
*/

#include <Servo.h>

// set pin numbers
#define LED 2         // number of the LED pin
#define servoPin ...    // numer of the servo pin
#define stickPin0 A0  // number of joystock pin0
#define stickPin1 A1  // number of joystock pin1

// set helpful values
#define FULL_SERVO_ANGLE 150  //full value of the servo is 150 degrees
#define STICK_MIN 245
#define STICK_MAX 780

// define variables that will change
int pos = 0;    // variable to store the servo position
int x = 0;
int y = 0;

Servo myServo;  // create servo object to control a servo

/*
    Initial set up function to set pin modes and serial monitor.

    @param
    @return null
*/
void setup()
{
  Serial.begin(...);           // choose 9600 baud rate for serial monitor
  
  pinMode(LED, OUTPUT);         // initialize the LED pin as an output
  pinMode(stickPin0 , INPUT);    // initialize stickPin0 as an input
  pinMode(..., ...);    // initialize stickPin1 as an input
  
  myServo.attach(servoPin);     // attaches the servo on servoPin to the servo object
}

/*
    Main loop function for program execution. Calls all the module functions.

    @param
    @return null
*/
void loop()
{
  delay(...);  // delay by 1500ms
  x, y = readJoystick();

  controlLED(...);
  delay(200);
  servoControl(...);
}

/*
    Set servo position depending on the y-coordinate of the thumb joystick.

    @param integer y as y-coordinate of the joystick
    @return null
*/
void servoControl(int y)
{
  //Serial.println(y);
  if (y > 20 && pos <= FULL_SERVO_ANGLE)
  {
    ...;       // increase servo position by 5 degrees
  } else if (y < -20 && pos >= 0)
  {
    ...;       // decrease servo position by 5 degrees
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
    Lights up the LED when the thumb joystick is pushed up.

    @param integer y as y-coordinate of the joystick
    @return null
*/
void controlLED(int y)
{
  if (y > 20)
  {
    ...    // switch on the LED
  } else {
    ...     // switch off the LED
  }
}

/*
    Reads the analog x and y position of the joystick,
    and remapping them into a -100 to 100

    @param
    @return integer x,y coordinate of joystick
*/
int readJoystick()
{
  int stickValue0 = ...;      // read the value on stickPin0
  int ...      // read the value on stickPin1

  // map stickValue from STICK_MIN-STICK_MAX to -100 - 100
  int x = map(stickValue0, ..., ..., ..., ...);
  int y = map(stickValue1, ..., ..., ..., ...);

  //  Serial.print("(A0,A1) : ");
  //  Serial.print(stickValue0);
  //  Serial.print(",");
  //  Serial.println(stickValue1);
  //
  //  Serial.print("(x,y) : ");
  //  Serial.print(x);
  //  Serial.print(",");
  //  Serial.println(y);

  return ..., ...;
}
