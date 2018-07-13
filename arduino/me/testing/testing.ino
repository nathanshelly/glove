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
  if(digitalRead(button_pin) == HIGH) {
   digitalWrite(led_pin, LOW);
//   Serial.println("OFF");
    Serial.write(0);
  } else {
    digitalWrite(led_pin, HIGH);
//    Serial.println("**ON**");
    Serial.write(1);
  }

  delay(10);
}
