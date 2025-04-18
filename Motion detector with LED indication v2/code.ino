int pir = 6;
int relay = 3;
int sw = 0;


unsigned long t;


void setup() {
  // Serial.begin(9600);


  pinMode(pir, INPUT);
  pinMode(relay, OUTPUT);


  digitalWrite(relay, LOW);
}


void loop() {
  // Serial.println(sw);


  if (sw == 0) {
    if (digitalRead(pir) == HIGH) {
      sw = 1;
      t = millis();
      digitalWrite(relay, HIGH);
    }
  }
  else {
    if ((millis() - t) > 10000) {
      if (digitalRead(pir) == HIGH) {
        t = millis();
      }
      else {
        sw = 0;
        digitalWrite(relay, LOW);
      }
    }
  }
}
