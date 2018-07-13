// debounceCount.ino
// Michael Gurevich

// Counts button presses with debouncing

const int buttonPin =  2; // pin number of the button pin
const int LEDPin = 13;    // pin number for LED
int count = 0;            // button-press counter
int timer;                // debounce timer

enum btn{ON,DEBOUNCE,OFF}; // our own type for button states

btn state;    // variable to store state

void setup() {
  Serial.begin(9600);           // intialize Serial port
  pinMode(buttonPin, INPUT_PULLUP);  // initialize the button pin as an input
                                     // and activate pull-up resistor
  pinMode(LEDPin, OUTPUT);
   
}
 
void loop(){
  buttonStep();
  delay(10);
}

void buttonStep() {
  
  int reading = digitalRead(buttonPin);  // check pin reading
  switch (state) {
    case OFF: 
      if (reading == LOW) { // button press?
        state = DEBOUNCE;
        timer = 5;
      } break;
    case DEBOUNCE:
     if (reading == LOW) {  // if button reading remains low
        if (timer <= 0) {   // and the time elapses
          state = ON;       // this is a "real" button press"
          digitalWrite(LEDPin, HIGH);
          Serial.println(++count);    
        } else timer--;     // if time hasn't elapsed, but button is still low, keep waiting
     } else state = OFF;     
     break;
    case ON:
      if (reading == HIGH) {
        state = OFF;
        digitalWrite(LEDPin,LOW);
      }
  }
}
       
          
        
