void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); //통신 속도 1초에: 9600개의 데이터를 보내겠다
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println("Hello Arduion"); //보드에서 컴퓨터로 데이터를 보냄(tx:trasport 가 반짝임)
  delay(1000);
}
