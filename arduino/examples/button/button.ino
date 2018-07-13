// button.ino
// Michael Gurevich
// based on http://arduino.cc/en/Tutorial/Button


// constants won't change. They're used here to 
// set pin numbers:
const int buttonPin = 2;     // the number of the pushbutton pin
const int ledPin =  13;      // the number of the LED pin

int buttonState = 0;         // variable for reading the pushbutton status

void setup() {
  pinMode(ledPin, OUTPUT);   // initialize the LED pin as an output
  pinMode(buttonPin, INPUT); // initialize the button pin as an input   

  digitalWrite(ledPin, LOW); // start with LED OFF
}

void loop(){
  buttonState = digitalRead(buttonPin);   // read the state of the button bin 

    // check if the pushbutton is pressed.
  if (buttonState == LOW) {      // if it is, the buttonState is LOW
    digitalWrite(ledPin, HIGH);  // if it is, turn on the LED
  } 
  else {                        // buttonState is HIGH
    digitalWrite(ledPin, LOW);   // turn LED off
  }
}



