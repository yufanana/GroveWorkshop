/*
   Set 4
   Thumb Joystick (A0/A1): analog input
   LED Socket Kit (D2): digital output
   Servo (D6): digital output
*/

#include <Servo.h>

// set pin numbers
#define LED 2
#define servoPin 6
#define stickPin0 A0
#define stickPin1 A1

// set helpful values
#define FULL_SERVO_ANGLE 150  //full value of the servo is 150 degrees
#define STICK_MIN 245
#define STICK_MAX 780

// define variables that will change
int pos = 0;    // variable to store the servo position
int x = 0;
int y = 0;

Servo myServo;  // create servo object to control a servo

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(stickPin0, INPUT);
  pinMode(stickPin1, INPUT);
  myServo.attach(servoPin);  // attaches the servo on servoPin to the servo object
}

void loop()
{
  // main loop for program execution

  delay(1500);
  x, y = readJoystick();

  controlLED(y);
  delay(200);
  servoControl(y);
}

void servoControl(int y)
{
  // set servo position depending on the presence of line

  //Serial.println(y);
  if (y > 20 && pos <= FULL_SERVO_ANGLE)
  {
    pos += 5;
  } else if (y < -20 && pos >= 0)
  {
    pos -= 5;
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

void controlLED(int y)
{
  if (y > 20)
  {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}

int readJoystick()
{
  int stickValue0 = analogRead(stickPin0);
  int stickValue1 = analogRead(stickPin1);

  int x = map(stickValue0, STICK_MIN, STICK_MAX, -100, 100);
  int y = map(stickValue1, STICK_MIN, STICK_MAX, -100, 100);

  //  Serial.print("(A0,A1) : ");
  //  Serial.print(stickValue0);
  //  Serial.print(",");
  //  Serial.println(stickValue1);
  //
  //  Serial.print("(x,y) : ");
  //  Serial.print(x);
  //  Serial.print(",");
  //  Serial.println(y);

  return x, y;
}
