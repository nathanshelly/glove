// led_source.ino
// Michael Gurevich

// Connect the long leg of an LED to pin 3
// Connect the short leg through a ~200Ohm resistor to ground
// Here, the Arduino sources current to the LED, lighting it up when the pin is HIGH

 // constants won't change. They're used here to 
 // set pin numbers:
 const int ledPin =  3;      // the number of the LED pin


 void setup() {
   pinMode(ledPin, OUTPUT);   // initialize the LED pin as an output
   digitalWrite(ledPin, HIGH); // turn on the LED
 }
 
 void loop(){

 }

