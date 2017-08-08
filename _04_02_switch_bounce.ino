bool flag = 0;
void setup() {
  // put your setup code here, to run once:
 // Serial.begin(9600);
  pinMode(6,OUTPUT);
  pinMode(8,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = digitalRead(8);
  
  if(val == HIGH)
  {
    flag = !flag;
    delay(200);
  }
  digitalWrite(6,flag%2);
 // Serial.println(flag);
}
