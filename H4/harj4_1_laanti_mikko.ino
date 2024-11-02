// C++ code
#include <EEPROM.h>
// // TMP36-anturin pin
const int sensorPin = A0;  
// Painonappi kirjoita
const int buttonWrite = 13; 
// Painonappi tulosta
const int buttonPrint = 3; 
// Painonappi tyhjennä
const int buttonClear = 2; 
// Led pin 12
const int led1 = 12;      
// Led pin 12
const int led2 = 5;      
// Laskuriosoite EEPROM:n muistipaikkaan
int eePromAddress = 0;
// Arvo (voisi käyttää myös eePromAddress muutujaa tässä tehtävässä)
int laskuri = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonWrite, INPUT_PULLUP);
  pinMode(buttonPrint, INPUT_PULLUP);
  pinMode(buttonClear, INPUT_PULLUP);
  // Ei keskeytyksiä käytössä
}

void loop() {   	
   // Painettu "Kirjoitaa muistiin" painiketta
   if (digitalRead(buttonWrite) == LOW) {  
      // EEPROM:iin kirjoitus
      writeToEEPROM(laskuri); 
      // Kasvatetaan laskurin arvoa
      ++laskuri;
   }  
}

// Kirjoitetaan value:n arvo osoitteeseen eePromAddress
void writeToEEPROM(int value) {  
  EEPROM.put(eePromAddress, value); 
  Serial.print("Laskurin arvo ");
  Serial.print(value);
  Serial.print(" tallennettu EEPROM:n osoitteeseen ");  
  Serial.println(eePromAddress);  
  delay(300); 
  // Kasvatetaan osoitteen arvoa
  ++eePromAddress;
}
