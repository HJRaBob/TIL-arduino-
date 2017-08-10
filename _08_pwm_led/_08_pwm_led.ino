bool btn_1_current = LOW;
bool btn_1_last = LOW;
bool btn_2_current = LOW;
bool btn_2_last = LOW;

bool flag_1 = false; //led1 state
bool flag_2 = false; //led2 state

bool i_flag = false; //led1 bright change check
bool j_flag = false; //led2 bright change check

int i=0,j=0; //pwm value
bool debounce(bool last,int pin)
{
  bool current = digitalRead(pin);
  if(last!=current){
    delay(200);
    current=digitalRead(pin); //because noise
  }
  return current;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(3,INPUT); //button 1 check
  pinMode(4,INPUT); //button 2 check
}

void loop() {
  // put your main code here, to run repeatedly:
  btn_1_current=debounce(btn_1_last,3);
  btn_2_current=debounce(btn_2_last,4);

  delay(10);
  
  if(btn_1_last==LOW&&btn_1_current==HIGH){
    flag_1 = !flag_1;
  }

  if(btn_2_last==LOW&&btn_2_current==HIGH){
    flag_2 = !flag_2;
  }

  if(flag_1 == true){
    analogWrite(9,i%256);
    if(i == 0 || i == 255){
      i_flag = !i_flag;
    }
    if(i_flag)
      i++;
    else
      i--;
  }else{
    analogWrite(9,0);
  }

  if(flag_2 == true){
    analogWrite(10,j%256);
    if(j == 0 || j == 255){
      j_flag = !j_flag;
    }
    if(j_flag)
      j++;
    else
      j--;
  }else{
    analogWrite(10,0);
  }

}
