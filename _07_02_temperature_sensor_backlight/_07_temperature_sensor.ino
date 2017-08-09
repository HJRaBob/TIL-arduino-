#include<LiquidCrystal.h>

LiquidCrystal lcd(12,11,5,4,3,2);
int temp;
int lux;
int i;

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  pinMode(9,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  lux = analogRead(0); //bright
  temp = analogRead(1); //temperature
  delay(1000);
  analogWrite(9,i); //backlight bright
  i+=10;
  if (i>255){
    i=0;
  }
  lcd.setCursor(0,0);
  lcd.print("brite: ");
  lcd.print(lux);
  lcd.setCursor(0,1);
  lcd.print("temper: ");
  lcd.print((5.0*temp*100.0)/1024.0);
}
