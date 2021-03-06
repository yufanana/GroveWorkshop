/*
   Set 6
   LED Socket Kit (D3): digital output
   Light Sensor (A0): analog input
   Servo (D6): digital output
*/

// import libraries
#include <Servo.h>
#include <math.h>

// set pin numbers
#define LED ...         // number of the LED pin
#define lightPin ...   // number of the light sensor pin
#define servoPin ...   // number of the servo pin
#define tempPin ...    // number of the temperature pin

// set helpful values
#define FULL_SERVO_ANGLE 150  //full value of the servo is 150 degrees
#define MAX_LIGHT_VALUE 760

const int B = 4275;               // B value of the thermistor
const int R0 = 100000;            // R0 = 100k

// define variables that will change
int pos = 0;    // variable to store the servo position
int light = 0;

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
  pinMode(..., ...);   // initialize the light sensor pin as an input
  myServo.attach(servoPin);   // attaches the servo on servoPin to the servo object
}

/*
    Main loop function for program execution. Calls all the module functions.

    @param
    @return null
*/
void loop()
{
  readLight();
  readTemp();

  controlLED();
  servoControl();
  delay(...);   // delay by 200ms
}

/*
    Rotates the servo CCW if light is detected. Rotates CW otherwise.

    @param
    @return null
*/
void servoControl()
{
  // set servo position depending on the presence of light

  //Serial.println(light);
  
  if (light > MAX_LIGHT_VALUE / 2 && pos <= FULL_SERVO_ANGLE)
  {
    ...;       // increase servo position by 5 
  } else if (light < MAX_LIGHT_VALUE / 2 && pos >= 0)
  {
    ...       // decrease servo position by 5 
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
    Lights up the LED when no light is detected.

    @param
    @return null
*/
void controlLED()
{
  if (light > MAX_LIGHT_VALUE / 2)
  {
    ...     // switch off LED
  } else {
    ...    // switch on LED
  }
}

/*
    Reads the value of the light sensor and store it in the global light variable.

    @param
    @return null
*/
void readLight()
{
  ... = ...;   // read the light sensor pin
  
  //  Serial.println(light);
}

/*
    Reads the value of the temperature sensor and convert to celsius.

    @param
    @return null
*/
void readTemp()
{
  int a = ...;    // read the temperature sensor pin

  float R = 1023.0 / a - 1.0;
  R = R0 * R;

  // convert to temperature via datasheet
  float temperature = 1.0 / (log(R / R0) / B + 1 / 298.15) - 273.15;

  Serial.print("temperature = ");
  Serial.println(...);

  delay(...);   // delay by 100 ms
}
