const int trigPin = 2;    //Trig pin sensor
const int echoPin = 4;    //Echo pin sensor
 
void setup()
{
    Serial.begin(9600);    //serial for debug
    Serial.println("Hello Arduino!!");
 
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}
 
void loop()
{
    long duration, distance;    //senor return value, change to 'cm'
 
    //to get 'duration' method of handling sonic sensor 
    digitalWrite(trigPin, LOW);     
    delayMicroseconds(2);           
    digitalWrite(trigPin, HIGH);  
    delayMicroseconds(10);         
    digitalWrite(trigPin, LOW);    
 
    duration = pulseIn(echoPin, HIGH); //period that receiver get HIGH
    distance = duration / 29 / 2;        //change to 'cm'

    //handling motor
    if(distance<256)
      analogWrite(9,distance*10);
    else
      analogWrite(9,255);
    analogWrite(10,0);

    //to debug
    Serial.print(distance);
    Serial.print("cm");
    Serial.println();
 
    delay(100);
}

