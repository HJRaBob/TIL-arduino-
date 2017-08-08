bool lastbtn = LOW;
bool currentbtn = LOW;
bool flag = LOW;

bool debounce(bool last)
{
  bool current = digitalRead(8);
  if(last!=current){
    delay(5);
    current=digitalRead(8); //because noise
  }
  return current;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(6,OUTPUT);
  pinMode(8,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  currentbtn=debounce(lastbtn);
  if(lastbtn==LOW&&currentbtn==HIGH){
    flag = !flag;
  }
  lastbtn = currentbtn;
  digitalWrite(6,flag);
}
