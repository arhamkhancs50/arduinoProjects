#define LEDA  13
#define LEDB  12
#define LEDC  8
#define LEDD  7

void setup() {
  pinMode(LEDA, OUTPUT);
  pinMode(LEDB, OUTPUT);
  pinMode(LEDC, OUTPUT);
  pinMode(LEDD, OUTPUT);
}

void resetLed(){
  digitalWrite(LEDA, LOW);
  digitalWrite(LEDB, LOW);
  digitalWrite(LEDC, LOW);
  digitalWrite(LEDD, LOW);
}

void blinkLed(int i){
  if(i==1){
    digitalWrite(LEDA, HIGH);
  }
  if(i==2){
    digitalWrite(LEDB, HIGH);
  }
  if(i==3){
    digitalWrite(LEDC, HIGH);
  }
  if(i==4){
    digitalWrite(LEDD, HIGH);
  }

}

void binaryDisplay(int rem){
  int num[5] = {0, 0, 0, 0, 0};
  resetLed();
  do{
    if(rem > 7){
      rem = rem - 8;
      num[1]=1;
    }
    else if(rem > 3){
      rem = rem - 4;
      num[2]=1;      
    }
    else if(rem > 1){
      rem = rem - 2;
      num[3]=1;      
    }
    else if(rem > 0){
      rem = rem - 1;
      num[4]=1;      
    }
  }
  while(rem != 0);
  for(int i=1;i<=4;i++){
    if(num[i] ==1){
      blinkLed(i);
    }
  }
}

void loop() {
  for(int i=0;i<16;i++){
    binaryDisplay(i);
    delay(1000);
  }

}
