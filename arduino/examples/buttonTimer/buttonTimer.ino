// buttonTimer.ino
// Michael Gurevich

// After Loe Feijs' "Multitasking" Example

const int buttonPin =  2; // pin number of the button pin
const int LEDPin = 13;    // pin number for LED
int timer;

enum btn{
  ON,OFF}; // our own type for button states
btn state;        // variable to store state

void setup() {
  Serial.begin(9600);           // intialize Serial port
  pinMode(buttonPin, INPUT_PULLUP);  // initialize the button pin as an input
  // and activate pull-up resistor
  pinMode(LEDPin, OUTPUT);

}

void loop(){
  LEDStep();
  delay(10);
}

void LEDStep() {

  int reading = digitalRead(buttonPin);  // get pin reading
  switch(state) {
  case OFF:
    if (reading == LOW) {          //button is pressed
      state = ON;  
      digitalWrite(LEDPin,HIGH);   // turn on LED
      timer = 1000;
    } 
    break;
  case ON:
    if (timer <= 0) {           
      state = OFF;
      digitalWrite(LEDPin,LOW);    // turn off LED
    } else timer--;
    break;
  }
}


