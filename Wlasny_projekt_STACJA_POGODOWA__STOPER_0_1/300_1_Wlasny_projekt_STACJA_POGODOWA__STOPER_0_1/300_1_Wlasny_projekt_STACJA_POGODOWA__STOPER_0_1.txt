/* 
14.06.19  
UPDATE 0.1 
Zmiany w pinach:
S1 zastąpiony S3
S3 zastąpiony S2
S2 zastąpiony S1
*/

//+++++++++++++++++++++++++ U S T A W I E N I A ++ G L O B A L N E +++++++++++++++++++//
#include <LiquidCrystal.h> //dołączenie biblioteki
LiquidCrystal lcd(2, 3, 4, 5, 6, 7); //info o podlaczeniu nowego wyswietlacza

#include "DHT.h"
DHT dht;

#define DHT11_PIN 13
#define LM35 A0
#define s1 10
#define s2 9
#define s3 8

unsigned long aktualnyCzas = 0;
unsigned long zapamietanyCzas = 0;

int dane = 0;
float czas = 0.00;
boolean koniec = false;
boolean blokada = false;
boolean tryb = true;   // ustawienia domyslne trybu
boolean trybSuma = false;  // ustawienia domyslne czujnika
boolean dalej = false;

boolean stoper = false;

float temp = 0.0;
float tempMin = 150.0;
float tempMax = 0.0;
float wilMin = 100.0;
float wilMax = 0.0;


float temp1 = dht.getTemperature();
float  wil = dht.getHumidity();
float tempA = 0.0;

int stanLED_G = LOW;
int stanLED_B = LOW;

int czasMigania = 0;


//+++++++++++++++++++++++++ U S T A W I E N I A +++++++++++++++++++//

void setup() {
  
  Serial.begin(9600);

  dht.setup(DHT11_PIN);
  
  lcd.begin(16, 2); // eklaracja typu czyli ilosc miejsc na znaki linia i wrsy
  lcd.clear(); //czyscimy wyswietlacz

  pinMode(s1, INPUT_PULLUP);  //S1
  pinMode(s2, INPUT_PULLUP);  //S2
  pinMode(s3, INPUT_PULLUP);  //S3

  pinMode(11, OUTPUT); //dioda green
  pinMode(12, OUTPUT); //dioda blue

  pinMode(A0, INPUT); //czujnik analogowy
  
//---------pierwszy pomiar-------------------//

  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("Witaj!"); //wyswietlanie tekstu
  lcd.setCursor(0, 1); //zmiana miejsca kursora
  lcd.print("Wczytywanie..."); //Wyswietlanie tekstu
  lcd.blink();

  tempA = ((analogRead(LM35) * 5.0) / 1024.0) * 100.0;
  
  delay(5000);
  lcd.noBlink();
  
  float temp1 = dht.getTemperature();
  float  wil = dht.getHumidity();
  tempA = ((analogRead(LM35) * 5.0) / 1024.0) * 100.0;
  
  if (trybSuma == true) {  // tryb srednia
    temp = (temp1 + tempA) /2;
  } else {   // tryb 1 czujnik
  
if (tryb == true) {
  temp = temp1;
} else {
  temp = tempA;
}
}
  

  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("Temp:"); //wyswietlanie tekstu
  lcd.setCursor(9, 0); //zmiana miejsca kursora
  lcd.print(temp); //Wyswietlanie tekstu
  lcd.setCursor(13, 0); //ustawienie miejsca kursora
  lcd.print("'C"); //wyswietlanie tekstu
  
  lcd.setCursor(0, 1); //ustawienie miejsca kursora
  lcd.print("Wilg:"); //wyswietlanie tekstu
  lcd.setCursor(9, 1); //zmiana miejsca kursora
  lcd.print(wil); //Wyswietlanie tekstu
  lcd.setCursor(13, 1); //ustawienie miejsca kursora
  lcd.print("%RH"); //wyswietlanie tekstu

if (temp <= 18.0) {
  int stanLED_G = LOW;
  int stanLED_B = HIGH;
  digitalWrite(11, stanLED_G);
  digitalWrite(12, stanLED_B);
}
if (temp > 18.0 && temp < 24.0) {
  int stanLED_G = HIGH;
  int stanLED_B = LOW;
  digitalWrite(11, stanLED_G);
  digitalWrite(12, stanLED_B);
}
if (temp >= 24.0) {
  int stanLED_G = HIGH;
  int stanLED_B = HIGH;
  digitalWrite(11, stanLED_G);
  digitalWrite(12, stanLED_B);
}

//--------------------------------------//

}

void loop() {

//===================== T E M P == A K T U A L N A ===========//
  aktualnyCzas = millis();

if ((aktualnyCzas - zapamietanyCzas >= 10000UL) && stoper == false) {
  
 float temp1 = dht.getTemperature();
  float  wil = dht.getHumidity();
  tempA = ((analogRead(LM35) * 5.0) / 1024.0) * 100.0;
  
  if (trybSuma == true) {  // tryb srednia
    temp = (temp1 + tempA) /2;
  } else {   // tryb 1 czujnik
  
if (tryb == true) {
  temp = temp1;
} else {
  temp = tempA;
}
}
  
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("Temp:"); //wyswietlanie tekstu
  lcd.setCursor(9, 0); //zmiana miejsca kursora
  lcd.print(temp); //Wyswietlanie tekstu
  lcd.setCursor(13, 0); //ustawienie miejsca kursora
  lcd.print("'C"); //wyswietlanie tekstu
  
  lcd.setCursor(0, 1); //ustawienie miejsca kursora
  lcd.print("Wilg:"); //wyswietlanie tekstu
  lcd.setCursor(9, 1); //zmiana miejsca kursora
  lcd.print(wil); //Wyswietlanie tekstu
  lcd.setCursor(13, 1); //ustawienie miejsca kursora
  lcd.print("%RH"); //wyswietlanie tekstu
  
  zapamietanyCzas = aktualnyCzas;

  if (temp > tempMax) {
  tempMax = temp;
}
if (temp < tempMin) {
  tempMin = temp;
}
  if (wil > wilMax) {
  wilMax = wil;
}
if (wil < wilMin) {
  wilMin = wil;
}
if (temp <= 18.0) {
  int stanLED_G = LOW;
  int stanLED_B = HIGH;
  digitalWrite(11, stanLED_G);
  digitalWrite(12, stanLED_B);
}
if (temp > 18.0 && temp < 24.0) {
  int stanLED_G = HIGH;
  int stanLED_B = LOW;
  digitalWrite(11, stanLED_G);
  digitalWrite(12, stanLED_B);
}
if (temp >= 24.0) {
  int stanLED_G = HIGH;
  int stanLED_B = HIGH;
  digitalWrite(11, stanLED_G);
  digitalWrite(12, stanLED_B);
}





}

//=====================T E M P == M I N I M A L N A ===========//

if ((digitalRead(s2) == LOW) && stoper == false) {

  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("TempMIN:"); //wyswietlanie tekstu
  lcd.setCursor(9, 0); //zmiana miejsca kursora
  lcd.print(tempMin); //Wyswietlanie tekstu
  lcd.setCursor(13, 0); //ustawienie miejsca kursora
  lcd.print("'C"); //wyswietlanie tekstu

  lcd.setCursor(0, 1); //ustawienie miejsca kursora
  lcd.print("WilgMIN:"); //wyswietlanie tekstu
  lcd.setCursor(9, 1); //zmiana miejsca kursora
  lcd.print(wilMin); //Wyswietlanie tekstu
  lcd.setCursor(13, 1); //ustawienie miejsca kursora
  lcd.print("%RH"); //wyswietlanie tekstu
  delay(1000);
  
  float temp1 = dht.getTemperature();
  float  wil = dht.getHumidity();
  tempA = ((analogRead(LM35) * 5.0) / 1024.0) * 100.0;
  
  if (trybSuma == true) {  // tryb srednia
    temp = (temp1 + tempA) /2;
  } else {   // tryb 1 czujnik
  
if (tryb == true) {
  temp = temp1;
} else {
  temp = tempA;
}
}

 //Odczyt temp
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("Temp:"); //wyswietlanie tekstu
  lcd.setCursor(9, 0); //zmiana miejsca kursora
  lcd.print(temp); //Wyswietlanie tekstu
  lcd.setCursor(13, 0); //ustawienie miejsca kursora
  lcd.print("'C"); //wyswietlanie tekstu

  lcd.setCursor(0, 1); //ustawienie miejsca kursora
  lcd.print("Wilg:"); //wyswietlanie tekstu
  lcd.setCursor(9, 1); //zmiana miejsca kursora
  lcd.print(wil); //Wyswietlanie tekstu
  lcd.setCursor(13, 1); //ustawienie miejsca kursora
  lcd.print("%RH"); //wyswietlanie tekstu
  
  zapamietanyCzas = aktualnyCzas;

  if (temp > tempMax) {
  tempMax = temp;
}
if (temp < tempMin) {
  tempMin = temp;
}
  if (wil > wilMax) {
  wilMax = wil;
}
if (wil < wilMin) {
  wilMin = wil;
}
}

//===================== T E M P == M A K S Y M A L N A ===========//

if ((digitalRead(s1) == LOW) && stoper == false) {

  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("TempMAX:"); //wyswietlanie tekstu
  lcd.setCursor(9, 0); //zmiana miejsca kursora
  lcd.print(tempMax); //Wyswietlanie tekstu
  lcd.setCursor(13, 0); //ustawienie miejsca kursora
  lcd.print("'C"); //wyswietlanie tekstu

  lcd.setCursor(0, 1); //ustawienie miejsca kursora
  lcd.print("WilgMAX:"); //wyswietlanie tekstu
  lcd.setCursor(9, 1); //zmiana miejsca kursora
  lcd.print(wilMax); //Wyswietlanie tekstu
  lcd.setCursor(13, 1); //ustawienie miejsca kursora
  lcd.print("%RH"); //wyswietlanie tekstu
  delay(1000);
  
 float temp1 = dht.getTemperature();
  float  wil = dht.getHumidity();
  tempA = ((analogRead(LM35) * 5.0) / 1024.0) * 100.0;
  
  if (trybSuma == true) {  // tryb srednia
    temp = (temp1 + tempA) /2;
  } else {   // tryb 1 czujnik
  
if (tryb == true) {
  temp = temp1;
} else {
  temp = tempA;
}
}
  
 //Odczyt temp i wil
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("Temp:"); //wyswietlanie tekstu
  lcd.setCursor(9, 0); //zmiana miejsca kursora
  lcd.print(temp); //Wyswietlanie tekstu
  lcd.setCursor(13, 0); //ustawienie miejsca kursora
  lcd.print("'C"); //wyswietlanie tekstu
  
  lcd.setCursor(0, 1); //ustawienie miejsca kursora
  lcd.print("Wilg:"); //wyswietlanie tekstu
  lcd.setCursor(9, 1); //zmiana miejsca kursora
  lcd.print(wil); //Wyswietlanie tekstu
  lcd.setCursor(13, 1); //ustawienie miejsca kursora
  lcd.print("%RH"); //wyswietlanie tekstu
  
  zapamietanyCzas = aktualnyCzas;

  if (temp > tempMax) {
  tempMax = temp;
}
if (temp < tempMin) {
  tempMin = temp;
}
  if (wil > wilMax) {
  wilMax = wil;
}
if (wil < wilMin) {
  wilMin = wil;
}
}



//======================= S T O P E R ====================//


if (digitalRead(s3) == LOW) {
  stoper = !stoper;
  lcd.noBlink();
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("Termometr/Stoper,"); //wyswietlanie tekstu
  lcd.setCursor(0, 1); //zmiana miejsca kursora
  lcd.print("Nacisnij S1 V S2"); //Wyswietlanie tekstu
  delay(500);
}


if (stoper == true) {
if (digitalRead(s2) == LOW && koniec == false && stoper == true) {

dane = 2;
blokada = false;
lcd.noBlink();
delay(500);
}
else if (digitalRead(s1) == LOW && koniec == false && blokada == false && stoper == true) {
  
dane = 1;
koniec = true;
lcd.noBlink();
delay(500);
}
else if (digitalRead(s2) == LOW && koniec == true && stoper == true) {

  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("S1: Pomiar, PS2"); //wyswietlanie tekstu
  lcd.setCursor(0, 1); //zmiana miejsca kursora
  lcd.print("S3: Termometr"); //Wyswietlanie tekstu
  lcd.blink();
  blokada = true;
  dane = 0; 
  czas = 0;
  koniec = false;
  delay(10);
  ////////////////////////////////////////////////////////////////////
  if (digitalRead(s1) == LOW) {  //S2                         /// zmiana trybu pomiaru
  trybSuma = !trybSuma;
  delay(50);
  
  if (trybSuma == true) {
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("Zmiana trybu:"); //wyswietlanie tekstu
  lcd.setCursor(0, 1); //zmiana miejsca kursora
  lcd.print("pomiar sredniej"); //Wyswietlanie tekstu
  lcd.blink();
  delay(1500);
  } else {
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("Zmiana trybu:"); //wyswietlanie tekstu
  lcd.setCursor(0, 1); //zmiana miejsca kursora
  lcd.print("pomiar osobno"); //Wyswietlanie tekstu
  lcd.blink();
  delay(1500);
  }
  delay(50);
  }
  ////////////////////////////////////////////////////////////////////
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("S1: Pomiar, PS2"); //wyswietlanie tekstu
  lcd.setCursor(0, 1); //zmiana miejsca kursora
  lcd.print("S3: Termometr"); //Wyswietlanie tekstu
  lcd.blink();
  blokada = true;
  dane = 0; 
  czas = 0;
  koniec = false;
  dalej = true;
  delay(200);
}

  if (digitalRead(s1) == LOW && dalej == true && trybSuma == false) {  //S2           /// zmiana czujnika
  tryb = !tryb;
  delay(50);
  
  if (tryb == false) {
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("Zmiana czujnika:"); //wyswietlanie tekstu
  lcd.setCursor(0, 1); //zmiana miejsca kursora
  lcd.print("Analogowy"); //Wyswietlanie tekstu
  lcd.blink();
  delay(1500);
  } else {
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("Zmiana czujnika:"); //wyswietlanie tekstu
  lcd.setCursor(0, 1); //zmiana miejsca kursora
  lcd.print("Cyfrowy"); //Wyswietlanie tekstu
  lcd.blink();
  delay(1500);
  }
  delay(50);
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("S1: Pomiar, PS2"); //wyswietlanie tekstu
  lcd.setCursor(0, 1); //zmiana miejsca kursora
  lcd.print("S3: Termometr"); //Wyswietlanie tekstu
  lcd.blink();
  blokada = true;
  dane = 0; 
  czas = 0;
  koniec = false;
  dalej = false;
  
  }
//           POMIAR           //

if (dane == 2 && stoper == true) {
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("POMIAR::"); //wyswietlanie tekstu
  lcd.setCursor(7, 1); //zmiana miejsca kursora
  lcd.print("sek"); //Wyswietlanie tekstu
  lcd.setCursor(0, 1); //zmiana miejsca kursora
  lcd.print(czas); //Wyswietlanie tekstu
  delay(100);
  while (digitalRead(s1) == HIGH) {
  czas = czas + 0.1;
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("POMIAR CZASU:"); //wyswietlanie tekstu
  lcd.setCursor(6, 1); //zmiana miejsca kursora
  lcd.print("sek     S2"); //Wyswietlanie tekstu
  lcd.setCursor(0, 1); //zmiana miejsca kursora
  lcd.print(czas); //Wyswietlanie tekstu
  delay(100);
  czasMigania = czasMigania + 100;
  if (czasMigania >= 500) {
  int stanLED_G = !stanLED_G;
  int stanLED_B = LOW;
  digitalWrite(11, stanLED_G);
  digitalWrite(12, stanLED_B);
  czasMigania = 0;
  }
  
}
}

else if (dane == 1 && stoper == true) {
  lcd.clear(); //czyscimy wyswietlacz
  lcd.setCursor(0, 0); //ustawienie miejsca kursora
  lcd.print("KONIEC POMIARU:"); //wyswietlanie tekstu
  lcd.setCursor(5, 1); //zmiana miejsca kursora
  lcd.print("sek S1+PS2"); //Wyswietlanie tekstu
  lcd.setCursor(0, 1); //zmiana miejsca kursora
  lcd.print(czas); //Wyswietlanie tekstu
  int stanLED_G = LOW;
  int stanLED_B = HIGH;
  digitalWrite(11, stanLED_G);
  digitalWrite(12, stanLED_B);
  delay(200);
  dalej = false;
}

  

  
}
}
