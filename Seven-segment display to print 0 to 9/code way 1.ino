//use cathode display
//use Design 1


int pin_start = 2, pin_end = 9, displayed=0;
int pin_num[10][7] = {
  {1, 1, 1, 1, 1, 1, 0},
  {0, 1, 1, 0, 0, 0, 0},
  {1, 1, 0, 1, 1, 0, 1},
  {1, 1, 1, 1, 0, 0, 1},
  {0, 1, 1, 0, 0, 1, 1},
  {1, 0, 1, 1, 0, 1, 1},
  {1, 0, 1, 1, 1, 1, 1},
  {1, 1, 1, 0, 0, 0, 0},
  {1, 1, 1, 1, 1, 1, 1},
  {1, 1, 1, 1, 0, 1, 1}
};


void setup() {
  for (int i = pin_start ; i <= pin_end ; i++) {
    pinMode(i, OUTPUT);
  }
}


void printnum(int digit) {
  int cnt = 0;


  for (int i = pin_start ; i < pin_end ; i++) {
    int status = pin_num[digit][cnt];
    digitalWrite(i, status);
    cnt++;
  }


  digitalWrite(pin_end, HIGH);
}


void loop() {
  if(!displayed){
    for (int i = 9 ; i >= 0 ; i--) {
      printnum(i);
      delay(1000);
    }
    displayed = 1;
  }
  return;
}
