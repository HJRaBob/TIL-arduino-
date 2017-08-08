unsigned int nu[16];
int i = 0;
int pin_a = 5;
int pin_b = 6;
int pin_c = 7;
int pin_d = 8;
int pin_e = 9;
int pin_f = 10;
int pin_g = 11;

void setup() {
  // put your setup code here, to run once:

  pinMode(pin_a,OUTPUT);
  pinMode(pin_b,OUTPUT);
  pinMode(pin_c,OUTPUT);
  pinMode(pin_d,OUTPUT);
  pinMode(pin_e,OUTPUT);
  pinMode(pin_f,OUTPUT);
  pinMode(pin_g,OUTPUT);
  
  nu[0] =0b01100000;
  nu[1] = 0b11011010;
  nu[2] = 0b11110010;
  nu[3] = 0b01100110;
  nu[4] = 0b10110110;
  nu[5] = 0b00111110;
  nu[6] = 0b11100000;
  nu[7] = 0b11111111;
  nu[8] = 0b11100111;
  nu[9] = 0b11101111;
  nu[10] = 0b00111110;
  nu[11] = 0b10011100;
  nu[12] = 0b00111110;
  nu[13] = 0b10011110;
  nu[14] = 0b10001110;
  nu[15] = 0b11111100;
}

void loop() {
  // put your main code here, to run repeatedly:
  if(i != 15){
    i++;
  }else{
    i = 0;
  }
  delay(1000);

  digitalWrite(pin_a,nu[i]&0b10000000);
  digitalWrite(pin_b,nu[i]&0b01000000);
  digitalWrite(pin_c,nu[i]&0b00100000);
  digitalWrite(pin_d,nu[i]&0b00010000);
  digitalWrite(pin_e,nu[i]&0b00001000);
  digitalWrite(pin_f,nu[i]&0b00000100);
  digitalWrite(pin_g,nu[i]&0b00000010);
}
