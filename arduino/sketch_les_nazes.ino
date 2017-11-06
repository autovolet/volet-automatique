
#include <Wire.h> // biblioteque
#include "rgb_lcd.h" // biblioteque

rgb_lcd lcd; // initialisation du lcd

byte heart[8] = {
    0b00000,
    0b01010,
    0b11111,
    0b11111,
    0b11111,
    0b01110,
    0b00100,
    0b00000
};

byte smiley[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b10001,
    0b01110,
    0b00000
};

byte frownie[8] = {
    0b00000,
    0b00000,
    0b01010,
    0b00000,
    0b00000,
    0b00000,
    0b01110,
    0b10001
};

byte armsDown[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b00100,
    0b01110,
    0b10101,
    0b00100,
    0b01010
};

byte armsUp[8] = {
    0b00100,
    0b01010,
    0b00100,
    0b10101,
    0b01110,
    0b00100,
    0b00100,
    0b01010
};


void setup() 
{

    lcd.begin(16, 2); // config 16 colones 2 lignes
    
 #if 1   
    lcd.createChar(0, heart); 
    lcd.createChar(1, smiley);
    lcd.createChar(2, frownie);
    lcd.createChar(3, armsDown);
    lcd.createChar(4, armsUp);
#endif
    
    
    lcd.setCursor(0, 0);
    lcd.print("SALUT ");
    lcd.write((unsigned char)0);
    lcd.print(" LES NAZES ");
    lcd.write(1);
}

void loop() 
{
    
    lcd.setCursor(4, 1);
    // Appel naze bras en bas
    lcd.write(3); // écriture nazes bras en bas
    delay(1000);
    lcd.setCursor(4, 1);
    // pareil bras en haut
    lcd.write(4);
    delay(1000);
}


