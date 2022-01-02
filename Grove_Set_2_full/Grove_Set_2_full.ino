/*
   Set 2
   LED (D3): analog output
   Rotary Angle Sensor (A3): analog input
   Servo (D6): digital output
*/

// import libraries
#include <Servo.h>

// set pin numbers
#define LED 3                   // number of the LED pin
#define servoPin 6              // number of the servo pin
#define ROTARY_ANGLE_SENSOR A3  // number of the rotary angle sensor pin

// set helpful values
#define FULL_ROT_ANGLE 300      // full value of the rotary angle is 300 degrees
#define FULL_SERVO_ANGLE 150    // full value of the servo is 150 degrees
#define GROVE_VCC 5             // VCC of the grove interface is normally 5v
#define ADC_REF 5               // reference voltage of ADC is 5v. If the Vcc switch on the seeeduino
//if the board switches to 3V3, the ADC_REF should be 3.3

// define variables that will change
int pos = 0;    // variable to store the servo position
int brightness;
float voltage;
int sensor_value;
float degrees;

Servo myServo;  // create servo object to control a servo

/*
    Initial set up function to set pin modes and serial monitor.

    @param
    @return null
*/
void setup()
{
  Serial.begin(9600);       // choose 9600 baud rate for serial monitor
  
  pinMode(ROTARY_ANGLE_SENSOR, INPUT);   // initialize the rotary angle pin as an input
  pinMode(LED, OUTPUT);                  // initialize the LED pin as an output
  myServo.attach(servoPin);              // attaches the servo on servoPin to the servo object
}

/*
    Main loop function for program execution. Calls all the module functions.

    @param
    @return null
*/
void loop()
{
  degrees = rotarySensor();   // global degrees variable
  controlLED(degrees);
  servoControl(degrees);
}

/*
    Rotate servo based on the angle measured by rotary angle sensor.

    @param float degrees to map to servo position
    @return null
*/
void servoControl(float degrees)
{
  pos = map(degrees, 0, FULL_ROT_ANGLE, 0, FULL_SERVO_ANGLE);
  myServo.write(pos);

  //  Sample code to rotate servo slowly
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
    Read rotary angle and return the current mark angle in degrees

    @param
    @return float degrees measured by rotary angle sensor
*/
float rotarySensor()
{
  float degrees;      // local degrees variable
  sensor_value = analogRead(ROTARY_ANGLE_SENSOR);    // read value on the rotary angle sensor
  voltage = (float)sensor_value * ADC_REF / 1023;
  degrees = (voltage * FULL_ROT_ANGLE) / GROVE_VCC;

  //  Serial.print("sensor_value:");
  //  Serial.println(sensor_value);
  //  Serial.print("The angle between the mark and the starting position:");
  //  Serial.println(degrees);

  return degrees;
}

/*
    Set LED brightness depending on rotary sensor angle

    @param float degrees to map to LED brightness
    @return null
*/
void controlLED(float degrees)
{
  // map sensor value from 0-FULL_ROT_ANGLE to 0-255
  brightness = map(degrees, 0, FULL_ROT_ANGLE, 0, 255);
  analogWrite(LED, brightness);   // set LED to the calculated brightness value

  //  Serial.print("brightness:");
  //  Serial.println(brightness);
}
