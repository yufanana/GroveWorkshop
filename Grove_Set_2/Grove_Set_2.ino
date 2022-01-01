/*
   Set 2
   LED (D3): analog output
   Rotary Angle Sensor (A3): analog input
   Servo (D6): digital output
*/

#include <Servo.h>

// set pin numbers
#define LED 3
#define servoPin 6
#define ROTARY_ANGLE_SENSOR A3

// set helpful values
#define FULL_ROT_ANGLE 300    //full value of the rotary angle is 300 degrees
#define FULL_SERVO_ANGLE 150  //full value of the servo is 150 degrees
#define GROVE_VCC 5           //VCC of the grove interface is normally 5v
#define ADC_REF 5             //reference voltage of ADC is 5v. If the Vcc switch on the seeeduino
//if the board switches to 3V3, the ADC_REF should be 3.3

// define variables that will change
int pos = 0;    // variable to store the servo position
int brightness;
float voltage;
int sensor_value;
float degrees;

Servo myServo;  // create servo object to control a servo

void setup()
{
  Serial.begin(9600);
  pinMode(ROTARY_ANGLE_SENSOR, INPUT);
  pinMode(LED, OUTPUT);
  myServo.attach(servoPin);  // attaches the servo on servoPin to the servo object
}

void loop()
{
  // main loop for program execution

  degrees = rotarySensor();   // global degrees variable
  controlLED(degrees);
  servoControl(degrees);
}

void servoControl(float degrees)
{
  // set servo position depending on rotary sensor

  pos = map(degrees, 0, FULL_ROT_ANGLE, 0, FULL_SERVO_ANGLE);
  myServo.write(pos);

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

float rotarySensor()
{
  // read rotary angle and return the current mark angle in degrees

  float degrees;      // local degrees variable
  sensor_value = analogRead(ROTARY_ANGLE_SENSOR);
  voltage = (float)sensor_value * ADC_REF / 1023;
  degrees = (voltage * FULL_ROT_ANGLE) / GROVE_VCC;

  //  Serial.print("sensor_value:");
  //  Serial.println(sensor_value);
  //  Serial.print("The angle between the mark and the starting position:");
  //  Serial.println(degrees);

  return degrees;
}

void controlLED(float degrees)
{
  // set LED brightness depending on rotary sensor

  brightness = map(degrees, 0, FULL_ROT_ANGLE, 0, 255);
  analogWrite(LED, brightness);

  //  Serial.print("brightness:");
  //  Serial.println(brightness);
}
