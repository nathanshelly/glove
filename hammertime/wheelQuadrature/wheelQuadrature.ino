// wheelQuadrature
// Michael Gurevich
// Oct 8, 2013
//
// quadrature signal output for rollerskate wheel
// see accompanying max patch

const int pinA = 13;
const int pinB = 12;

int encoderPos = 0;     // encoder position
int lastPos = 0;        // keep track of last position   
int stateA=LOW;
int stateB=LOW;

void setup() { 
    Serial.begin (115200);
    pinMode(pinA, INPUT); //set encoder pins to inputs
    pinMode(pinB, INPUT); 
} 

void loop() { 
   encoderStep();
   displayStep();
   delay(5);
}

void encoderStep(){

   int readingA,readingB;
   readingA = digitalRead(pinA);
   readingB = digitalRead(pinB);
   if (stateA!=readingA) {  //state has changed->tick
	   if (readingA==readingB)    //CW
          ++encoderPos;
      else
          --encoderPos;         //CCW
    }
   if (stateB!=readingB) { //state has changed->tick
      if (readingA==readingB)   //CCW
          --encoderPos;
      else
          ++encoderPos;         //CW
   }
   stateA = readingA;   //update state to current reading
   stateB = readingB;
    
} 
  
void displayStep() {
  if (encoderPos>lastPos)     //position has changed
    Serial.write(4);          //moved CW
  else if (encoderPos<lastPos)
    Serial.write(2);          //moved CCW
  lastPos=encoderPos;           //store current position
}
