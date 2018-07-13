// opticalCounter
// Michael Gurevich
// Oct 8, 2013
//
// Count High-low transitions on input from reflective optical sensor
// You will need to calibrate the high and low thresholds

#define HI_THRESH 800  // above this threshold, we consider the signal "high"
#define LO_THRESH 650  // below this threshold, we consider the signal "low"


int wheelTurned = 0;        // count ticks
enum s{LIGHT,DARK};
s state=DARK;

void setup() { 
    Serial.begin (9600);
} 

void loop() { 
   opticalStep();
   delay(1);
}

void opticalStep(){

   int opticalSensor;
   opticalSensor = analogRead(0);
   if (state==DARK) {
	   if (opticalSensor < LO_THRESH) { //sensor reads "light"
        Serial.println(++wheelTurned);  //we moved one tick
        state=LIGHT;					//toggle state
   		}
    }
    else { //state is "LIGHT"
       if (opticalSensor > HI_THRESH) { //sensor reads "dark"
       	Serial.println(++wheelTurned);  //we moved another tick
		state=DARK;      
       }
    }
    // uncomment this to inspect the raw sensor value
    //Serial.println(opticalSensor);
} 
  
