/*
   Set 5
   Tilt Sensor (D2): digital input
   Vibration Sensor (D3): digital input
   Magnetic Switch (D4): digital input
   Servo (D6): digital output
*/

// import libraries
#include <Servo.h>

// set pin numbers
#define servoPin 6      // number of the servo pin
#define tiltPin 2       // number of the tilt sensor pin
#define vibrationPin 3  // nubmer of the vibration sensor pin
#define magnetPin 4     // number of the magnetic switch pin

// set helpful values
#define FULL_SERVO_ANGLE 150  //full value of the servo is 150 degrees

// define variables that will change
int pos = 0;    // variable to store the servo position
bool tilt = false;
bool vibrate = false;

Servo myServo;  // create servo object to control a servo

/*
    Initial set up function to set pin modes and serial monitor.

    @param
    @return null
*/
void setup()
{
  Serial.begin(9600);         // choose 9600 baud rate for serial monitor
  
  pinMode(tiltPin, INPUT);    // initialize the tilt pin as an input
  pinMode(magnetPin, INPUT);  // initialize the magnet pin as an input
  myServo.attach(servoPin);   // attaches the servo on servoPin to the servo object
}

/*
    Main loop function for program execution. Calls all the module functions.

    @param
    @return null
*/
void loop()
{
  tilt = isTilt();
  readVibration();

  servoControl(tilt);
  delay(200);         // delay by 200ms
}

/*
    The servo is enabled by the magnet switch
    Rotates the servo CCW when the tilt sensor is tilted. Rotates CCW otherwise.

    @param boolean tilt
    @return null
*/
void servoControl(bool tilt)
{
  if (tilt && pos <= FULL_SERVO_ANGLE)
  {
    pos += 5;       // increase servo position by 5 degrees
  } else if (!tilt && pos >= 0)
  {
    pos -= 5;       // decrease servo position by 5 degrees
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

/*
    Reads the tilt sensor.

    @param
    @return boolean tilt
*/
bool isTilt()
{
  return digitalRead(tiltPin);  // read the tilt sensor
}

/*
    Reads the vibration sensor.

    @param
    @return null
*/
void readVibration()
{
  // output HIGH when module is stable
  // output LOW when module is moving

  vibrate = digitalRead(vibrationPin);  // read the vibration sensor

  if (vibrate)
  {
    Serial.println("Module is stable");
  } else {
    Serial.println("Module is moving");
  }
}

/*
    Reads the magnetic switch.

    @param
    @return boolean on whether the switch is near a magnet
*/
bool isNearMagnet()
{
   int sensorValue = digitalRead(magnetPin);  // read the magnet switch
   
   if(sensorValue == HIGH)//if the sensor value is HIGH
    {
        return true;
    }
    else
    {
        return false;
    }
}
