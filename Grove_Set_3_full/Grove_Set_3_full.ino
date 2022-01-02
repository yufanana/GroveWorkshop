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
#define LED 2                   // number of the LED pin
#define linePin 3               // number of the lineFinder pin
#define waterPin 4              // number of the waterSensor pin
#define servoPin 6              // number of the servo pin

// set helpful values
#define FULL_SERVO_ANGLE 150  //full value of the servo is 150 degrees

// define variables that will change
int pos = 0;    // variable to store the servo position
bool black = false;
bool dry = true;

Servo myServo;  // create servo object to control a servo

void setup()
{
  Serial.begin(9600);         // choose 9600 baud rate for serial monitor

  pinMode(LED, OUTPUT);       // initialize the LED pin as an output
  pinMode(waterPin, INPUT);   // initialize the waterPin as an input
  pinMode(linePin, INPUT);    // initialize the linePin as an input
  myServo.attach(servoPin);   // attaches the servo on servoPin to the servo object
}

/*
    Main loop function for program execution. Calls all the module functions.
    ChainableRGB amd buzzer are enabled by the switch.

    @param
    @return null
*/
void loop()
{
  delay(200);   // delay by 200ms
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
  // set servo position depending on the presence of line

  if (black && pos <= FULL_SERVO_ANGLE)
  {
    pos += 5;   // increase servo position by 5 degrees
  } else if (!black && pos >= 0)
  {
    pos -= 5;   // decrease servo position by 5 degrees
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
    digitalWrite(LED, LOW);   // switch off LED
  } else {
    digitalWrite(LED, HIGH);  // switch on LED
  }
}

/*
    Detects the presence of black. Changes the global black variable accordingly.

    @param
    @return null
*/
void lineFinder()
{
  if (digitalRead(linePin) == HIGH)
  {
    Serial.println("black");
    black = true;
  } else {
    Serial.println("white");
    black = false;
  }
}

/*
    Detects the presence of water. Changes the global dry variable accordingly.

    @param
    @return null
*/
void waterSensor()
{
  dry = digitalRead(waterPin);
  if (dry)
  {
    Serial.println("Water sensor is DRY");
  } else {
    Serial.println("Water sensor is WET");
  }
}
