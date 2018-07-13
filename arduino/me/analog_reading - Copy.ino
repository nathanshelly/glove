int sensor_pin_one = 0;
int sensor_pin_two = 1;
int pressure_sensor_pin = 2;

int led_pin = 2;
int button_pin = 3;

void setup() {
  // put your setup code here, to run once:
  pinMode(led_pin, OUTPUT);
  pinMode(button_pin, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  int num_analog_signals = 3;
  int analog_readings[num_analog_signals];

  for(int i = 0; i < num_analog_signals; i++) {
    analog_readings[i] = analogRead(i);
  }
  int button_read = digitalRead(button_pin);

  // write delimiter
  Serial.write(255);

  for(int i = 0; i < num_analog_signals; i++) {
    Serial.write(analog_readings[i] >> 3);
    Serial.write(analog_readings[i] & 7); 
  }
  
  if(button_read == HIGH) {
    digitalWrite(led_pin, LOW);
    Serial.write(0);
  } else {
    digitalWrite(led_pin, HIGH);
    Serial.write(1);
  }
  
  delay(10);
}

