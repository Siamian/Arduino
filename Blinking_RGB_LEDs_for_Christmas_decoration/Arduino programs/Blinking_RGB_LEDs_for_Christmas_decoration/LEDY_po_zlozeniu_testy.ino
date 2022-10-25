
/*
pinMode(3,OUTPUT); // Zielony środek    Aktywacja LOW
pinMode(4,OUTPUT); // Zielony boki      Aktywacja HIGH
pinMode(1,OUTPUT); // Zielony środek    Aktywacja LOW 
pinMode(2,OUTPUT); // Czerwony x2 boki  Aktywacja HIGH
pinMode(0,OUTPUT); // Niebieski x2 boki Aktywacja HIGH
*/


/* Włączenie niebieskiego LED wraz z innym ledem:
pierwsza od wewnątrz zworka :  z czerwonymi x2
środkowa zworka             :  z niebieskimi x2
pierwsza od zewnątrz zworka :  z zielonymi x2
*/

int wypelnienie = 0;
int i = 0;
int wypelnienie2 = 0;
int j = 0;

void setup() {
pinMode(3,OUTPUT); // Zielony środek    Aktywacja LOW
pinMode(4,OUTPUT); // Zielony x2 boki   Aktywacja HIGH
pinMode(1,OUTPUT); // Czerwony środek   Aktywacja LOW 
pinMode(2,OUTPUT); // Czerwony x2 boki  Aktywacja HIGH
pinMode(0,OUTPUT); // Niebieski x2 boki Aktywacja HIGH

}

void loop() {


////////////////////////////////////////////////////////////


digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Zielony środek     Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony boki       Aktywacja HIGH
delay(50); //opoznienie

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

digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(50); //opoznienie

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
digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(50); //opoznienie





 ////////// S E K W E N C J E ///////////////////////////
digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,LOW); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(500); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,LOW); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(500); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,LOW); // Zielony środek     Aktywacja LOW
digitalWrite(4,HIGH); //  Zielony x2 boki    Aktywacja HIGH
delay(500); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,LOW); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); //  Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(500); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,LOW); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,LOW); //  Zielony środek     Aktywacja LOW
digitalWrite(4,HIGH); //  Zielony x2 boki    Aktywacja HIGH
delay(500); //opoznienie

digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,LOW); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,LOW); //  Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(500); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,HIGH); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,HIGH); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie


digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,HIGH); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,HIGH); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,HIGH); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,HIGH); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,LOW); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,HIGH); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,HIGH); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,HIGH); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,LOW); // Zielony środek     Aktywacja LOW
digitalWrite(4,HIGH); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,LOW); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,HIGH); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,HIGH); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,HIGH); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,LOW); // Zielony środek     Aktywacja LOW
digitalWrite(4,HIGH); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,LOW); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,LOW); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,HIGH); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,HIGH); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,LOW); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,LOW); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,HIGH); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,LOW); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,LOW); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,HIGH); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,LOW); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,LOW); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,LOW); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

digitalWrite(0,HIGH); //  Niebieski x2 boki  Aktywacja HIGH
digitalWrite(1,HIGH); // Czerwony środek    Aktywacja LOW 
digitalWrite(2,LOW); //  Czerwony x2 boki   Aktywacja HIGH
digitalWrite(3,HIGH); // Zielony środek     Aktywacja LOW
digitalWrite(4,LOW); //  Zielony x2 boki    Aktywacja HIGH
delay(300); //opoznienie

}
