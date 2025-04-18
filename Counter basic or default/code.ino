#include <TM1637.h>


int clk = 12, dio = 13, a[4];
unsigned long cnt = 0;


TM1637 timer1(clk, dio);


void setup() {
  timer1.init();
  timer1.set(7);
}


void loop() {
  myCounter();
}


void myCounter() {
  a[0] = cnt / 1000;
  a[1] = (cnt / 100) % 10;
  a[2] = (cnt / 10) % 10;
  a[3] = cnt % 10;


  for (int i = 0 ; i < 4 ; i++) {
    timer1.display(i, a[i]);
  }


  cnt++;
  if (cnt > 9999) {
    cnt = 0;
  }


  delay(100);
}
