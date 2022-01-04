/*
   Set 1
   Pushbutton (D2): digital input
   Grove Buzzer (D3): digital output
   Switch (D6): digital input
   ChainableRGB (D10 D11): digital output

   Please download the library 'ChainableLED - master' from the Grove GitHub.
   Google search for 'grove chainableLED github pjpmarques'

*/

// import libraries
#include <ChainableLED.h>
#include <Servo.h>
#include <math.h>

// set pin numbers
#define NUM_LEDS  1   // number of LEDs chained together
#define ledPin0 10
#define ledPin1 11
#define buttonPin ...   // number of the pushbutton pin
#define buzzerPin ...  // number of the buzzer pin
#define switchPin ...   // number of the switch pin

// set helpful values
#define FULL_SERVO_ANGLE 150  // full value of the servo is 150 degrees

// define variables that will change
float hue = 0.0;              // to store hue value
boolean up = true;            // to determine hue addition or subtraction
int buttonState = 0;          // to read the pushbutton status
int switchState = 0;          // to read the switch status

ChainableLED leds(ledPin0, ledPin1, NUM_LEDS);

/*
    Initial set up function to set pin modes and serial monitor.

    @param
    @return null
*/
void setup()
{
  Serial.begin(...);       // choose 9600 baud rate for serial monitor

  leds.init();              // ChainableRGB
  pinMode(buzzerPin, ...);    // initialize the buzzer pin as an output
  pinMode(..., ...);     // initialize the pushbutton pin as an input
  pinMode(..., ...);     // initialize the switch pin as an input
}

/*
    Main loop function for program execution. Calls all the module functions.
    ChainableRGB amd buzzer are enabled by the switch.

    @param
    @return null
*/
void loop()
{
  switchState = ...;   // read switch pin value
  if (switchState)
  {
    chainableRGB(...);                    // set LED brightness to 0.5
    push_buzzer();
  } else {
    chainableRGB(...);                      // set LED brightness to 0.5
  }

  Serial.print("switchState:");
  Serial.println(...);            // print the value of switchState
}


/*
    Cycles through all the colors in an uniform way using a HSB color space.

    @param float value for LED lightness
    @return null
*/
void chainableRGB(float lightness)
{

  // sets the HSL for all the LEDs
  // H,S,L are between 0 and 1
  // in our case, there is only have 1 LED so this loop is not useful
  for (byte i = 0; i < NUM_LEDS; i++)
    leds.setColorHSL(i, hue, 1.0, lightness);

  delay(...);   // delay for 500 ms

  // change the hue value during each main loop
  if (up)
  {
    ...   // increase hue value by 0.025
  } else {
    ...   // decrease hue value by 0.025
  }

  if (hue >= 1.0 && up)             // if hue exceeds 1 and is still going up
  {
    ...                     // change the arithmetic operation on hue to subtraction
  } else if (hue <= 0.0 && !up) {   // if hue goes below 0 and is still going down
    ...                      // change the arithmetic operation on hue to addition
  }

  Serial.print("hue:");
  Serial.println(...);    // print the value of hue
}

/*
    Buzzer sounds off when the button is pressed

    @param
    @return null
*/
void push_buzzer()
{
  buttonState = ...; // read the state of buttonPin

  if (...)              // check if the pushbutton is pressed
  {
    ...      // turn buzzer on
  } else {
    ...       // turn buzzer off
  }

  Serial.print("buttonState:");
  Serial.println(buttonState);
}

/*
    Rotate servo slowly

    @param
    @return null
*/
void servoControl()
{
  for (pos = 0; pos <= FULL_SERVO_ANGLE; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(...);                       // waits 15ms for the servo to reach the position
  }
  for (pos = FULL_SERVO_ANGLE; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(...);                       // waits 15ms for the servo to reach the position
  }
  
  Serial.print("pos:");
  Serial.println(pos);
}
