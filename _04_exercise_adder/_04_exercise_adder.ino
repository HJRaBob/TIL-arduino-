char led_bit = 0x00;
int bit_fir = 8;
int bit_sec = 9;
int bit_thir = 10;
int btn_up = 2;
int btn_down = 3;
int btn_reset = 4;

bool btn_current_up = LOW;
bool btn_last_up = LOW;
bool btn_current_down = LOW;
bool btn_last_down = LOW;
bool btn_current_reset = LOW;
bool btn_last_reset = LOW;

bool debounce(bool last,int port_num)
{
  bool current = digitalRead(port_num);
  if(last!=current){
    delay(200);
    current=digitalRead(port_num); //because noise
  }
  return current;
}

void setup() {
  // put your setup code here, to run once:
  pinMode(bit_fir,OUTPUT);
  pinMode(bit_sec,OUTPUT);
  pinMode(bit_thir,OUTPUT);

  pinMode(btn_up,INPUT);
  pinMode(btn_down,INPUT);
  pinMode(btn_reset,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  btn_current_up=debounce(btn_last_up,btn_up);
  btn_current_down=debounce(btn_last_down,btn_down);
  btn_current_reset=debounce(btn_last_reset,btn_reset);
  
  if(btn_last_up==LOW&&btn_current_up==HIGH){
    if(led_bit<0x08){
      led_bit=led_bit+0x01;
    }else{
      led_bit=0x00;
    }
    digitalWrite(bit_fir,led_bit&0x01);
    digitalWrite(bit_sec,led_bit&0x02);
    digitalWrite(bit_thir,led_bit&0x04);
  }

  if(btn_last_down==LOW&&btn_current_down==HIGH){
    if(led_bit>0x00){
      led_bit=led_bit-0x01;
    }else{
      led_bit=0x07;
    }
    digitalWrite(bit_fir,led_bit&0x01);
    digitalWrite(bit_sec,led_bit&0x02);
    digitalWrite(bit_thir,led_bit&0x04);
  }

  if(btn_last_reset==LOW&&btn_current_reset==HIGH){
    led_bit = 0x00;
    digitalWrite(bit_fir,led_bit);
    digitalWrite(bit_sec,led_bit);
    digitalWrite(bit_thir,led_bit);
  }
}


