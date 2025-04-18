int pir = 6;
int relay = 3;
int sw = 0;


// light indicator
int red = 4;
int green = 2;


unsigned long t;




void setup() {
  // Serial.begin(9600);


  pinMode(pir, INPUT);
  pinMode(relay, OUTPUT);


  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);


  digitalWrite(relay, LOW);


  digitalWrite(red, HIGH);
  digitalWrite(green, LOW);
}


void loop() {
  // Serial.println(sw);


  if (sw == 0) {
    if (digitalRead(pir) == HIGH) {
      sw = 1;
      t = millis();
      digitalWrite(relay, HIGH);


      digitalWrite(red, LOW);
      digitalWrite(green, HIGH);
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


        digitalWrite(red, HIGH);
        digitalWrite(green, LOW);
      }
    }
  }
}
