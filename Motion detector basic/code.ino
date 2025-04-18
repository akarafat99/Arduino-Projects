#define pirPin 6
#define relayPin 3


int time = 0;
int sw = 0;
unsigned long time_x, time_y;


void setup() {
  // Serial.begin(115200);
  pinMode(pirPin, INPUT);
  pinMode(relayPin, OUTPUT);
  digitalWrite(relayPin, LOW);


}


void loop() {
  // Serial.print(sw);
  // Serial.print("\n");
  if (sw == 0) {
    if (digitalRead(pirPin) == HIGH) {
      sw = 1;
      time_x = millis();
      digitalWrite(relayPin, HIGH);
    }
  } else {
    if ((millis() - time_x) > 10000) {
      if (digitalRead(pirPin) == HIGH) {
        time_x = millis();
      } else {
        digitalWrite(relayPin, LOW);
        sw = 0;
      }
    }
  }
}
