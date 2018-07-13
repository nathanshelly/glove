// flash.ino
// Michael Gurevich

// Flashes an LED connected to pin 3

// Connect the long leg of an LED to pin 3
// Connect the short leg through a resistor to ground
// Here, the Arduino sources current to the LED, lighting it up when the pin is HIGH


const int ledPin =  3;     // the number of the LED pin
const int onTime = 500;    // amount of time the LED will be on
const int offTime = 500;   // amount of time the LED will be off

void setup() {
   pinMode(ledPin, OUTPUT);   // initialize the LED pin as an output
}
 
void loop(){
  digitalWrite(ledPin, HIGH); // turn on the LED
  delay(onTime);              // wait 
  digitalWrite(ledPin, LOW);  // turn off the LED
  delay(offTime);             // wait
}

