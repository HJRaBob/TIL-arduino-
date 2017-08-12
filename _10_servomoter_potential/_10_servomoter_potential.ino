#include<Servo.h>
Servo servo;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  servo.attach(9);
}

void loop() {
  // put your main code here, to run repeatedly:
  int val = analogRead(A0);
  Serial.print("potentialmeter :");
  Serial.println(val);

  val = map(val,0,1023,0,179);
  servo.write(val);
  Serial.print("angle is");
  Serial.println(val);
  delay(200);
}
