// wheelQuadrature
// Michael Gurevich

// send one tick per wheel on dark-light transition
// not a true quadrature signal

const int pins[2] = {12, 13};
int state[2] = {LOW, LOW};

void setup() {
  Serial.begin (115200);

  pinMode(pins[0], INPUT); //set encoder pins to inputs
  pinMode(pins[1], INPUT);
}

void loop() {
  sensorStep();
  delay(5);
}

void sensorStep() {

  for (int i = 0; i < 2; i++) {
    int reading = digitalRead(pins[i]);
    if (state[i] != reading) { //state has changed->tick
      Serial.write(i);
    }
    state[i] = reading;   //update state to current reading
  }

}
