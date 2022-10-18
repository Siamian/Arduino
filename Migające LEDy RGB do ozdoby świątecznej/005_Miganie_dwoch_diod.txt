int wypelnienie = 0;
int i = 0;
int wypelnienie2 = 0;
int j = 0;

void setup() {
pinMode(3,OUTPUT); //lewa red
pinMode(4,OUTPUT); // lewa green
pinMode(1,OUTPUT); // green l i s
pinMode(2,OUTPUT); // red l i s
pinMode(0,OUTPUT); //blue l i s

}

void loop() {


////////////////////////////////////////////////////////////

digitalWrite(0,LOW); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,LOW); // red l i s
digitalWrite(3,HIGH); //lewa red
digitalWrite(4,LOW); // lewa green
delay(50); //opoznienie 1 

for (int j = 255; j > 0; j--) { 
analogWrite(1,wypelnienie2); //generujemy sygnal o podanym wypelnieniu
wypelnienie2 = wypelnienie2 - 1;
delay(5);
}

for (int j = 1; j < 255; j++) { 
analogWrite(1,wypelnienie2); //generujemy sygnal o podanym wypelnieniu
wypelnienie2 = wypelnienie2 + 1;
delay(5);
}

 digitalWrite(0,LOW); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,LOW); // red l i s
digitalWrite(3,LOW); //lewa red
digitalWrite(4,LOW); // lewa green
delay(50); //opoznienie 1 

for (int i = 0; i < 255; i++) { 
analogWrite(0,wypelnienie); //generujemy sygnal o podanym wypelnieniu
wypelnienie = wypelnienie + 1;
delay(5);
}

for (int i = 255; i > 0; i--) { 
analogWrite(0,wypelnienie); //generujemy sygnal o podanym wypelnieniu
wypelnienie = wypelnienie - 1;
delay(5);
}
////////////////////////////////////////////////////////////
  
  delay(1000); //opoznienie 1 sek
  
digitalWrite(3,HIGH); //lewa red
digitalWrite(4,LOW); // lewa green

digitalWrite(0,HIGH); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,HIGH); //  red l i s
  delay(1000); //opoznienie 1 sek
   digitalWrite(0,LOW); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,LOW); // red l i s
  delay(100); //opoznienie 1 sek
 digitalWrite(0,HIGH); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,LOW); // red l i s
  delay(100); //opoznienie 1 sek
 digitalWrite(0,LOW); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,LOW); // red l i s
  delay(100); //opoznienie 1 sek
 digitalWrite(0,HIGH); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,LOW); // red l i s
  delay(1000); //opoznienie 1 sek

 digitalWrite(0,LOW); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,LOW); // red l i s
digitalWrite(3,HIGH); //lewa red
digitalWrite(4,HIGH); // lewa green
delay(50); //opoznienie 1 
  
analogWrite(0,255);
delay(1000); //opoznienie 1 sek
analogWrite(0,0);

digitalWrite(3,HIGH); //lewa red
digitalWrite(4,LOW); // lewa green

digitalWrite(0,LOW); // blue l i s
digitalWrite(1,HIGH); // green l i s
digitalWrite(2,LOW); //  red l i s

    delay(1000); //opoznienie 1 sek
    digitalWrite(3,LOW); //lewa red
digitalWrite(4,LOW); // lewa green
    digitalWrite(0,HIGH); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,LOW); //  red l i s

    delay(1000); //opoznienie 1 sek
    digitalWrite(3,LOW); //lewa red
digitalWrite(4,HIGH); // lewa green
    digitalWrite(0,LOW); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,HIGH); //  red l i s

    delay(1000); //opoznienie 1 sek
digitalWrite(3,LOW); //lewa red
digitalWrite(4,LOW); // lewa green

digitalWrite(0,LOW); // blue l i s
digitalWrite(1,HIGH); // green l i s
digitalWrite(2,HIGH); // red l i s

  delay(1000); //opoznienie 1 sek

  
digitalWrite(3,LOW); //lewa red
digitalWrite(4,LOW); // lewa green

digitalWrite(0,HIGH); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,HIGH); // red l i s

  delay(1000); //opoznienie 1 sek
  
digitalWrite(3,HIGH); //lewa red
digitalWrite(4,LOW); // lewa green
delay(50); //opoznienie 1 sek
digitalWrite(3,LOW); //lewa red
digitalWrite(4,HIGH); // lewa green
delay(50); //opoznienie 1 
digitalWrite(3,LOW); //lewa red
digitalWrite(4,LOW); // lewa green
delay(50); //opoznienie 1 
digitalWrite(3,HIGH); //lewa red
digitalWrite(4,LOW); // lewa green
delay(50); //opoznienie 1 
digitalWrite(3,LOW); //lewa red
digitalWrite(4,HIGH); // lewa green
delay(50); //opoznienie 1 

digitalWrite(0,HIGH); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,LOW); // red l i s
delay(50); //opoznienie 1 

digitalWrite(0,LOW); // blue l i s
digitalWrite(1,HIGH); // green l i s
digitalWrite(2,LOW); // red l i s
delay(50); //opoznienie 1

digitalWrite(0,HIGH); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,LOW); // red l i s
delay(50); //opoznienie 1 

digitalWrite(0,LOW); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,HIGH); // red l i s
delay(50); //opoznienie 1 

digitalWrite(0,LOW); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,LOW); // red l i s
delay(50); //opoznienie 1 

digitalWrite(0,HIGH); // blue l i s
digitalWrite(1,LOW); // green l i s
digitalWrite(2,HIGH); // red l i s
delay(50); //opoznienie 1 

digitalWrite(0,LOW); // blue l i s
digitalWrite(1,HIGH); // green l i s
digitalWrite(2,LOW); // red l i s
delay(50); //opoznienie 1 

}
