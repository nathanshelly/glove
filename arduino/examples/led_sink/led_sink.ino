// led_sink.ino
// Michael Gurevich

// Connect the short leg of an LED to pin 3
// Connect the long leg through a resistor to +5V
// Here, the Arduino sinks current flowing through the LED, lighting it up when the pin is LOW

 const int ledPin =  3;      // the number of the LED pin

 void setup() {
   pinMode(ledPin, OUTPUT);   // initialize the LED pin as an output
   digitalWrite(ledPin, LOW); // turn on the LED
 }
 
 void loop(){

 }

