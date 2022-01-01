/*
   Set 1
   Pushbutton (D2): digital input
   Grove Buzzer (D3): digital output
   Switch (D6): digital input
   ChainableRGB (D7): 

   Please download the library 'ChainableLED - master' from the Grove GitHub.
   Google search for 'grove chainableLED github pjpmarques'
   
*/

#include <ChainableLED.h>
#include <math.h>

// set pin numbers
#define NUM_LEDS  5
#define buttonPin 2   // the number of the pushbutton pin
#define buzzerPin 3   // the number of the buzzer pin
#define switchPin 6   // the number of the switch pin

// define variables that will change
float hue = 0.0;
boolean up = true;
int buttonState = 0;         // variable to read the pushbutton status
int switchState = 0;         // variable to read the pushbutton status

ChainableLED leds(7, 8, NUM_LEDS);

void setup() 
{
  Serial.begin(9600);       // choose the right baud rate in serial monitor

  leds.init();  // ChainableRGB
  pinMode(buzzerPin, OUTPUT);    // initialize the buzzer pin as an output
  pinMode(buttonPin, INPUT);     // initialize the pushbutton pin as an input
  pinMode(switchPin, INPUT);     // initialize the switch pin as an input
}

void loop()
{
  // main loop for program execution
  
  switchState = digitalRead(switchPin);
  if (switchState) 
  {
    chainableRGB(0.5);
    push_buzzer();
  } else {
    chainableRGB(0);
  }
  
  Serial.print("switchState:");
  Serial.println(switchState);
}

void chainableRGB(float lightness) 
{
  // cycles through all the colors in an uniform way using a HSB color space.

  // sets the HSL for all the LEDs
  // in our case, there is only have 1 LED so this loop is not useful
  for (byte i = 0; i < NUM_LEDS; i++)
    leds.setColorHSL(i, hue, 1.0, lightness);

  delay(500);

  // change the hue value during each main loop
  if (up) 
  {
    hue += 0.025;
  } else {
    hue -= 0.025;
  }

  if (hue >= 1.0 && up) 
  {
    up = false;
  } else if (hue <= 0.0 && !up) {
    up = true;
  }

  Serial.print("hue:");
  Serial.println(hue);
}

void push_buzzer() 
{
  // buzzer makes a sound when the button is pressed
  
  buttonState = digitalRead(buttonPin); // read the state of the pushbutton value

  if (buttonState == HIGH) // check if the pushbutton is pressed
  {        
    digitalWrite(buzzerPin, HIGH);      // turn buzzer on
  } else {
    digitalWrite(buzzerPin, LOW);     // turn buzzer off
  }
  
  Serial.print("buttonState:");
  Serial.println(buttonState);
}
