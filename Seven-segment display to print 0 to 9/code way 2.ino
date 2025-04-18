//used cathode display
//use Design 1
int done = 0;


char digits[10][7] {
  "1111110",
  "0110000",
  "1101101",
  "1111001",
  "0110011",
  "1011011",
  "1011111",
  "1110000",
  "1111111",
  "1111011"
};


void setup() {
  customizePin();




}


void customizePin() {
  for (int i = 2 ; i <= 8 ; i++) {
    pinMode(i, OUTPUT);
  }
}


void setDigit(int digit) {
  int x = 0;
  for (int i = 2 ; i <= 8 ; i++) {
    digitalWrite(i, (int)(digits[digit][x] - '0') );
    x++;
  }
}


void reset() {
  for (int i = 2 ; i <= 8 ; i++) {
    digitalWrite(i, 0);
  }
}


void loop() {
  if (done == 0) {
    int i = 9;
    while (i >= 0) {
      setDigit(i--);
      delay(1000);
    }
    done++;
  }
  if (done == 1) {
    reset();
    done++;
  }
}
