/*
   Set 5
   Tilt Sensor (D2): digital input
   Vibration Sensor (D3): digital input
   Servo (D6): digital output
*/

#include <Servo.h>

// set pin numbers
#define servoPin 6
#define tiltPin 2
#define vibrationPin 3
#define magnetPin 4

// set helpful values
#define FULL_SERVO_ANGLE 150  //full value of the servo is 150 degrees

// define variables that will change
int pos = 0;    // variable to store the servo position
bool tilt = false;
bool vibrate = false;

Servo myServo;  // create servo object to control a servo

void setup()
{
  Serial.begin(9600);
  pinMode(tiltPin, INPUT);
  pinMode(magnetPin, INPUT);
  myServo.attach(servoPin);  // attaches the servo on servoPin to the servo object
}

void loop()
{
  // main loop for program execution

  tilt = isTilt();
  readVibration();

  servoControl(tilt);
  delay(200);
}

void servoControl(bool tilt)
{
  // set servo position depending on the presence of line

  //Serial.println(y);
  if (tilt && pos <= FULL_SERVO_ANGLE)
  {
    pos += 5;
  } else if (!tilt && pos >= 0)
  {
    pos -= 5;
  }

  if(isNearMagnet())
  {
    myServo.write(pos);
  }

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

bool isTilt()
{
  return digitalRead(tiltPin);
}

void readVibration()
{
  // output HIGH when module is stable
  // output LOW when module is moving

  vibrate = digitalRead(vibrationPin);

  if (vibrate)
  {
    Serial.println("Module is stable");
  } else {
    Serial.println("Module is moving");
  }
}

bool isNearMagnet()
{
   int sensorValue = digitalRead(magnetPin);
    if(sensorValue == HIGH)//if the sensor value is HIGH
    {
        return true;
    }
    else
    {
        return false;
    }
}
