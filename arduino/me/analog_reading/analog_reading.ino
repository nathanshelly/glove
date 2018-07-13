int button_pin = 2;

void setup() {
  pinMode(button_pin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  int num_analog_signals = 6;
  int analog_readings[num_analog_signals];

  // read values from sensors
  for(int i = 0; i < num_analog_signals; i++) {
    analog_readings[i] = analogRead(i);
  }
  int button_read = digitalRead(button_pin);

  // write delimiter between every set of values
  Serial.write(255);

  // write analog values to serial stream
  for(int i = 0; i < num_analog_signals; i++) {
    Serial.write(analog_readings[i] >> 3);
    Serial.write(analog_readings[i] & 7); 
  }

  // read button value
  Serial.write(button_read == HIGH ? 0 : 1);

  // delay in order to not overwhelm computer
  delay(10);
}
