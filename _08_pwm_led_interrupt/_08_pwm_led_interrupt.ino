bool flag_1 = false;
bool flag_2 = false;

void setup() {
  // put your setup code here, to run once:
  pinMode(9,OUTPUT);
  pinMode(10,OUTPUT);
  attachInterrupt(0,stop1,FALLING);
  attachInterrupt(1,stop2,FALLING);
}

void stop1()
{
  delay(200);
  flag_1 = !flag_1;
}

void stop2()
{
  delay(200);
  flag_2 = !flag_2;
}

void loop() {
    for(int i=0; i<256; i++)
    {
      if(!flag_1){
        analogWrite(9, i);
      }else{
        analogWrite(9, 0);
      }
      if(!flag_2){
        analogWrite(10, i);
      }else{
        analogWrite(10, 0);
      }
      delay(10);
    }
    for(int i=255; i>=0; i--)
    {
       if(!flag_1){
        analogWrite(9, i);
        delay(10);
      }else{
        analogWrite(9, 0);
      }
      if(!flag_2){
        analogWrite(10, i);
      }else{
        analogWrite(10, 0);
      }
    }
}
