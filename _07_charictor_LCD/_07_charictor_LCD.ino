#include<LiquidCrystal.h>
int count = 0;
bool btn_current_up = LOW;
bool btn_last_up = LOW;
bool btn_current_down = LOW;
bool btn_last_down = LOW;
bool btn_current_reset = LOW;
bool btn_last_reset = LOW;

bool debounce(bool last,int pin)
{
  bool current = digitalRead(pin);
  if(last!=current){
    delay(200);
    current=digitalRead(pin); //because noise
  }
  return current;
}

LiquidCrystal lcd(12,11,5,4,3,2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16,2);
  lcd.print("button counter");

}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.setCursor(0,1);
  btn_current_up=debounce(btn_last_up,8);
  btn_current_down=debounce(btn_last_down,9);
  btn_current_reset=debounce(btn_last_reset,10);
  
  if(btn_last_up==LOW&&btn_current_up==HIGH){
    count++;
//    lcd.clear();
//    lcd.setCursor(0,0);
//    lcd.print("button counter");
    lcd.print("                  ");
  }

  if(btn_last_down==LOW&&btn_current_down==HIGH){
    count--;
    lcd.print("                  ");
  }

  if(btn_last_reset==LOW&&btn_current_reset==HIGH){
    count = 0;
    lcd.print("                  ");
  }

//  if (!count%10){
//    if(!((count/10)%10)){
//      lcd.setCursor((count/10)%10,1);
//      lcd.print("                            ");
//    }
 //  lcd.clear();
 //  lcd.setCursor(0,0);
 //  lcd.print("button counter");
 //  lcd.setCursor(0,1);
//  }
  
  lcd.print(count);
//  lcd.print("               ");
}
