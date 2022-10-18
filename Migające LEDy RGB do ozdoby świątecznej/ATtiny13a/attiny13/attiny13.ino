#define LED1 0  //pin PWM diody led 
#define LED2 1  //pin PWM diody led 
#define LED3 2  //pin PWM diody led 
#define LED4 3  //pin PWM diody led 
#define LED5 4  //pin PWM diody led 
#define LED6 5  //pin PWM diody led 

void setup(){
  pinMode(LED1,OUTPUT); //pin jako wyjscie
  pinMode(LED2,OUTPUT); //pin jako wyjscie
  pinMode(LED3,OUTPUT); //pin jako wyjscie
  pinMode(LED4,OUTPUT); //pin jako wyjscie
  pinMode(LED5,OUTPUT); //pin jako wyjscie
  pinMode(LED6,OUTPUT); //pin jako wyjscie

}

void loop() {
  

digitalWrite(LED3,HIGH);
digitalWrite(LED4,HIGH);
digitalWrite(LED5,HIGH);
delay(500);
digitalWrite(LED3,LOW);
digitalWrite(LED4,LOW);
digitalWrite(LED5,LOW);
delay(500);
digitalWrite(LED3,HIGH);
digitalWrite(LED4,HIGH);
digitalWrite(LED5,HIGH);
delay(500);
digitalWrite(LED3,LOW);
digitalWrite(LED4,LOW);
digitalWrite(LED5,LOW);
delay(500);
digitalWrite(LED3,HIGH);
digitalWrite(LED4,HIGH);
digitalWrite(LED5,HIGH);
delay(500);
digitalWrite(LED3,LOW);
digitalWrite(LED4,LOW);
digitalWrite(LED5,LOW);
delay(500);
digitalWrite(LED3,HIGH);
digitalWrite(LED4,HIGH);
digitalWrite(LED5,HIGH);
delay(500);
digitalWrite(LED3,LOW);
digitalWrite(LED4,LOW);
digitalWrite(LED5,LOW);
delay(500);
digitalWrite(LED3,HIGH);
digitalWrite(LED4,HIGH);
digitalWrite(LED5,HIGH);
delay(500);
digitalWrite(LED3,LOW);
digitalWrite(LED4,LOW);
digitalWrite(LED5,LOW);
delay(500);
digitalWrite(LED3,HIGH);
digitalWrite(LED4,HIGH);
digitalWrite(LED5,HIGH);
delay(500);
digitalWrite(LED3,LOW);
digitalWrite(LED4,LOW);
digitalWrite(LED5,LOW);
delay(500);
}
