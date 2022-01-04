/*
   Set 1
   Pushbutton (D2): digital input
   Grove Buzzer (D3): digital output
   Switch (D6): digital input
   ChainableRGB (D7): digital output

   Please download the library 'ChainableLED - master' from the Grove GitHub.
   Google search for 'grove chainableLED github pjpmarques'

*/

// import libraries
#include <ChainableLED.h>
#include <math.h>

// set pin numbers
#define NUM_LEDS  1   // number of LEDs chained together
#define ledPin0 10
#define ledPin1 11
#define buttonPin 2   // number of the pushbutton pin
#define buzzerPin 3   // number of the buzzer pin
#define switchPin 6   // number of the switch pin

// set helpful values
#define FULL_SERVO_ANGLE 150  // full value of the servo is 150 degrees

// define variables that will change
float hue = 0.0;              // to store hue value
boolean up = true;            // to determine hue addition or subtraction
int buttonState = 0;          // to read the pushbutton status
int switchState = 0;          // to read the switch status

ChainableLED leds(7, 8, NUM_LEDS);

/*
    Initial set up function to set pin modes and serial monitor.

    @param
    @return null
*/
void setup()
{
  Serial.begin(9600);       // choose 9600 baud rate for serial monitor

  leds.init();              // ChainableRGB
  pinMode(buzzerPin, OUTPUT);    // initialize the buzzer pin as an output
  pinMode(buttonPin, INPUT);     // initialize the pushbutton pin as an input
  pinMode(switchPin, INPUT);     // initialize the switch pin as an input
}

/*
    Main loop function for program execution. Calls all the module functions.
    ChainableRGB amd buzzer are enabled by the switch.

    @param
    @return null
*/
void loop()
{
  switchState = digitalRead(switchPin);   // read switch pin value
  if (switchState)
  {
    chainableRGB(0.5);                    // set LED brightness to 0.5
    push_buzzer();
  } else {
    chainableRGB(0);                      // set LED brightness to 0.5
  }

  Serial.print("switchState:");
  Serial.println(switchState);            // print the value of switchState
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

  delay(500);   // delay for 500 ms

  // change the hue value during each main loop
  if (up)
  {
    hue += 0.025;   // increase hue value by 0.025
  } else {
    hue -= 0.025;   // decrease hue value by 0.025
  }

  if (hue >= 1.0 && up)             // if hue exceeds 1 and is still going up
  {
    up = false;                     // change the arithmetic operation on hue to subtraction
  } else if (hue <= 0.0 && !up) {   // if hue goes below 0 and is still going down
    up = true;                      // change the arithmetic operation on hue to addition
  }

  Serial.print("hue:");
  Serial.println(hue);    // print the value of hue
}

/*
    Buzzer sounds off when the button is pressed

    @param
    @return null
*/
void push_buzzer()
{
  buttonState = digitalRead(buttonPin); // read the state of buttonPin

  if (buttonState == HIGH)              // check if the pushbutton is pressed
  {
    digitalWrite(buzzerPin, HIGH);      // turn buzzer on
  } else {
    digitalWrite(buzzerPin, LOW);       // turn buzzer off
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
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  for (pos = FULL_SERVO_ANGLE; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    myServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
  }
  
  Serial.print("pos:");
  Serial.println(pos);
}
