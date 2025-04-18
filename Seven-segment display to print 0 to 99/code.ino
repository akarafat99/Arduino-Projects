// use cathode display


#define d1 500
#define d2 1000
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


int start = 0, finish = 99;


void setup() {
  customizePin();
}


void loop() {
  for(int i=start ; i<=finish ; i++){
    if(i<10) {
      printL(0);
      printR(i);
    }
    else {
      printL(i/10);
      printR(i%10);
    }
    delay(d1);
  }
 
}


void customizePin() {
  for (int i = 2 ; i <= 13 ; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(A0, OUTPUT);
  pinMode(A1, OUTPUT);
}




void printL(int num) {
  int j = 0;
  for (int i = 9 ; i <= 13 ; i++) {
    digitalWrite(i, (digits[num][j] - '0') );
    j++;
  }
  digitalWrite(A0, (digits[num][j] - '0') );
  j++;
  digitalWrite(A1, (digits[num][j] - '0') );
}


void printR(int num) {
  int j = 0;
  for (int i = 2 ; i <=8 ; i++) {
    digitalWrite(i, (digits[num][j] - '0') );
    j++;
  }
}
