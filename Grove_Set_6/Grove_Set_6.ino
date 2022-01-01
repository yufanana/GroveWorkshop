/*
   Set 6
   LED Socket Kit (D3): digital output
   Light Sensor (A0): analog input
   Servo (D6): digital output
*/

#include <Servo.h>
#include <math.h>

// set pin numbers
#define LED 3
#define lightPin A0
#define servoPin 6
#define tempPin A1

// set helpful values
#define FULL_SERVO_ANGLE 150  //full value of the servo is 150 degrees
#define MAX_LIGHT_VALUE 760

const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k

// define variables that will change
int pos = 0;    // variable to store the servo position
int light = 0;

Servo myServo;  // create servo object to control a servo

void setup()
{
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
  pinMode(lightPin, INPUT);
  myServo.attach(servoPin);  // attaches the servo on servoPin to the servo object
}

void loop()
{
  // main loop for program execution
  readLight();
  readTemp();

  controlLED();
  servoControl();
  delay(200);
}

void servoControl()
{
  // set servo position depending on the presence of light

  //Serial.println(light);
  if (light > MAX_LIGHT_VALUE / 2 && pos <= FULL_SERVO_ANGLE)
  {
    pos += 5;
  } else if (light < MAX_LIGHT_VALUE / 2 && pos >= 0)
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
  if (light > MAX_LIGHT_VALUE / 2)
  {
    digitalWrite(LED, LOW);
  } else {
    digitalWrite(LED, HIGH);
  }
}

void readLight()
{
  light = analogRead(lightPin);
  //  Serial.println(light);
}

void readTemp()
{
  int a = analogRead(tempPin);

  float R = 1023.0 / a - 1.0;
  R = R0 * R;

  float temperature = 1.0 / (log(R / R0) / B + 1 / 298.15) - 273.15; // convert to temperature via datasheet

  Serial.print("temperature = ");
  Serial.println(temperature);

  delay(100);
}
