#include <Wire.h> // biblioteque
#include "rgb_lcd.h" // biblioteque

rgb_lcd lcd; // initialisation du lcd

byte deg[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b00000,
    0b00000,
    0b00000,
    0b00000,
    0b00000
};

byte pct[8] = {
    0b00000,
    0b10001,
    0b00011,
    0b00110,
    0b01100,
    0b11000,
    0b10001,
    0b00000
};


void setup() 
{

  lcd.begin(16, 2); // config 16 colones 2 lignes
  Serial.begin(9600);
    

}

void loop() 
{

////////////Temperature Interieur///////////////////////////////////////////
  #if 1   
      lcd.createChar(0, deg); 
  #endif
  lcd.setCursor(0, 0);// prémier chiffre, colones, second chiffre ligne.
  lcd.print("Temp Int :"); // texte ligne 1
  lcd.setCursor(5, 1);
  lcd.write((unsigned char)0); // afficher ° 
  lcd.print ("C"); // texte ligne 2
  int temp_int_brute = analogRead(A8); // lecture tempe i
  float ti = temp_int_brute*(5.0/1023*100); // calcul tempe i
  lcd.setCursor(0, 1); // position tempe i
  lcd.print(ti); // Afficher tempe i

  delay(5000);
  lcd.clear();

////////////Temperature Exterieur///////////////////////////////////////////
  #if 1   
    lcd.createChar(0, deg); 
  #endif
  lcd.setCursor(0, 0);// premier chiffre, colones, second chiffre ligne.
  lcd.print("Temp Ext :"); // texte ligne 1
  lcd.setCursor(5, 1);
  lcd.write((unsigned char)0); // afficher ° 
  lcd.print ("C"); // texte ligne 2
  int temp_ext_brute = analogRead(A9); // lecture tempe e
  float te = temp_ext_brute*(5.0/1023*100); // calcul tempe e
  lcd.setCursor(0, 1); // position tempe e
  lcd.print(te); // Afficher tempe e

  delay(5000);
  lcd.clear();

////////////Reserve Batterie///////////////////////////////////////////
  #if 1   
    lcd.createChar(0, pct); 
  #endif
  lcd.setCursor(0, 0);// prémier chiffre, colones, second chiffre ligne.
  lcd.print("Batterie :"); // texte ligne 1
  int batterie_brute = analogRead(A10); // lecture batterie
  Serial.println(batterie_brute);  
  float batterie = (batterie_brute - 532) * 0.073170; // calcul batterie  ( v - vmin) * voltunit 
  float batteriepct = (batterie/12)*100;
  Serial.println(batteriepct);  
  lcd.setCursor(0, 1); // position batterie
  lcd.print("100"); // Afficher 100%
  lcd.write((unsigned char)0); // afficher %
  if (batteriepct<=0.99) // correction pour afficher une valeur > a 0%
  {
    lcd.setCursor(0, 1);
    lcd.print("0");
    lcd.write((unsigned char)0); // afficher %
  }
  if else (batteriepct<=100) // correction pour afficher une valeur < a 100%
  {
    lcd.setCursor(0, 1);
    lcd.print(batteriepct);
    lcd.write((unsigned char)0); // afficher %
  }

  delay(5000);
  lcd.clear();
  
}

void moteur ()
{
}

