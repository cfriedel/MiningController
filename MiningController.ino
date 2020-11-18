// Mining controller for Star Citizen
// By Cliff Friedel
// Version 0.1

// Includes.  You need the Arduino Joystick Library (https://github.com/MHeironimus/ArduinoJoystickLibrary) and
// the keypad library in the Arduino Library Manager to use this sketch

#include <Joystick.h>
#include <Keypad.h>

// Loop delay for debouncing.  In milliseconds.
const int loopdelay = 50; 

// Initialize the Joystick object.  We only use the X axis and 16 buttons in the options so we don't get any false readings.
Joystick_ Joystick(0x09,JOYSTICK_TYPE_JOYSTICK,16,0,true,false,false,false,false,false,false,false,false,false,false);

// Assign the analog pin for the pot and set up the keypad information.  We are going to use hex so all the buttons have a single character value.

const int potpin = A0;

const byte ROWS = 4; //four rows
const byte COLS = 4; //four columns
char keys[ROWS][COLS] = {
  {'0','1','2','3'},
  {'4','5','6','7'},
  {'8','9','A','B'},
  {'C','D','E','F'}
};
byte rowPins[ROWS] = {9,8,7,6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5,4,3,2}; //connect to the column pinouts of the keypad

Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup() {
  
  // Start having the sketch look at the joystick for actions
  Joystick.begin();
}

void loop() {

  // Check to see if any keys are being pressed on the keypad.  Also initialize a button variable to hold the int version of the button number.

  char key = keypad.getKey();
  signed int button;

  // If a key was pressed go into the loop. Convert hex string to a int, then set the appropriate button on the joystick to pressed (on)
  if (key) {
    button = strtol(&key,NULL,16);
    Joystick.setButton(button,1);
  }
  
  // Check the potentiometer (X-axis).  Values should be between 0(left) and 1023(right).  Set the Y-Axis to a constant value to prevent a floating value
  Joystick.setXAxis(analogRead(potpin));
  Joystick.setYAxis(512);
  
  // Introduce short delay, defined by the constant loopdelay, then turn the button off so it doesn't repeat. 
  delay(loopdelay);
  if (key) { 
    Joystick.setButton(button,0);
  }
}
