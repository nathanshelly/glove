// buttonCount.ino
// Michael Gurevich

// Counts button presses
// Demonstrates pull-up resistor and need for debouncing

const int buttonPin =  2; // pin number of the button pin
const int LEDPin = 13;    // pin number for LED
int count = 0;            // button-press counter

enum btn{ON,OFF}; // our own type for button states
btn state;        // variable to store state


void setup() {
  Serial.begin(9600);           // intialize Serial port
  pinMode(buttonPin, INPUT_PULLUP);  // initialize the button pin as an input
                                     // and activate pull-up resistor
  pinMode(LEDPin, OUTPUT);
   
}
 
void loop(){
  buttonStep();
}

void buttonStep() {

  int reading = digitalRead(buttonPin);  // check pin reading
  switch(state) {
    case OFF:
      if (reading == LOW) {    //button is pressed
        digitalWrite(LEDPin,HIGH);   // turn on LED
        Serial.println(++count);   // increment count
        state = ON;
      } break;
    case ON:
      if (reading == HIGH) {   // button is released
        digitalWrite(LEDPin,LOW);    // turn off LED
        state = OFF;
      } break;
  }
}

