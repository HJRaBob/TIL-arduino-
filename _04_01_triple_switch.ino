void setup() {
  // put your setup code here, to run once:
  pinMode(1,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);

  pinMode(8,INPUT);
  pinMode(9,INPUT);
  pinMode(10,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int read8 = digitalRead(8);
  int read9 = digitalRead(9);
  int read10 = digitalRead(10);

  digitalWrite(1,HIGH);

  if(read8==HIGH){
    digitalWrite(4,HIGH);
  }else{
    digitalWrite(4,LOW);
  }
  if(read9==HIGH){
    digitalWrite(5,HIGH);
  }else{
    digitalWrite(5,LOW);
  }
  if(read10==HIGH){
    digitalWrite(6,HIGH);
  }else{
    digitalWrite(6,LOW);
  }
}
