/*
   Set 3
   LED Socket Kit (D2): digital output
   Line Finder (D3): digital input
   Water Sensor (D4): digital/analog input
   Servo (D6): digital output
*/

#include <Servo.h>

// set pin numbers
#define LED 2
#define linePin 3
#define waterPin 4
#define servoPin 6

// set helpful values
#define FULL_SERVO_ANGLE 150  //full value of the servo is 150 degrees

// define variables that will change
int pos = 0;    // variable to store the servo position
bool black = false;
bool dry = true;

Servo myServo;  // create servo object to control a servo

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(waterPin, INPUT);
  pinMode(linePin, INPUT);
  myServo.attach(servoPin);  // attaches the servo on servoPin to the servo object
}

void loop()
{
  // main loop for program execution

  delay(200);
  servoControl(black);
  controlLED();
  lineFinder();
  waterSensor();
}

void servoControl(bool black)
{
  // set servo position depending on the presence of line

  if (black && pos <= FULL_SERVO_ANGLE)
  {
    pos += 5;
  } else if (!black && pos >= 0)
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

void controlLED()
{
  if (black)
  {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }
}

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

void waterSensor()
{
  dry = digitalRead(waterPin);
  if(dry)
  {
    Serial.println("Water sensor is DRY");
  } else {
    Serial.println("Water sensor is WET");
  }
}
