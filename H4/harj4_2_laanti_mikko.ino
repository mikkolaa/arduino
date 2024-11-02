// C++ code
#include <EEPROM.h>

// TMP36-anturin pin
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
// laskuri
int laskuri = 1;
// Osoite EEPROM:n muistipaikkaan
int eePromAddress = 0;

void setup() {
  Serial.begin(9600);
  pinMode(buttonWrite, INPUT_PULLUP);
  pinMode(buttonPrint, INPUT_PULLUP);
  pinMode(buttonClear, INPUT_PULLUP);    
  // Asetetaan keskeytykset
  attachInterrupt(digitalPinToInterrupt(buttonPrint), printEEPROM, FALLING);
  attachInterrupt(digitalPinToInterrupt(buttonClear), clearEEPROM, FALLING);
}

void loop() {      
   // Tarkista painike "Kirjoita muistiin"
   if (digitalRead(buttonWrite) == LOW) {  
      // Kirjoitetaan EEPROM:iin
      writeToEEPROM(laskuri); 
      // Kasvatetaan laskurin arvoa
      ++laskuri;
   }
}

// Kirjoitetaan value:n arvo EEPROM:iin osoitteeseen eePromAddress
void writeToEEPROM(int value) {  
  EEPROM.write(eePromAddress, value); 
  Serial.print("Laskurin arvo ");
  Serial.print(value);
  Serial.print(" tallennettu EEPROM:n osoitteeseen ");  
  Serial.println(eePromAddress);  
  ++eePromAddress; 
  delay(300); 
}

// Funktio tulostaa EEPROM:n sisällön painonapilla
void printEEPROM() {  
  int storedValue = 0;
    
  if(eePromAddress == 0) {
    Serial.println("EEPROM:n sisalto on tyhja");    
  }
  else {
    Serial.println("EEPROM:n sisalto:");

    for (int i = 0; i < EEPROM.length(); ++i) {      
      storedValue = EEPROM.read(i);
      if(storedValue > 0) {        
        Serial.print("EEPROM osoitteessa ");
        Serial.print(i);
        Serial.print(": ");
        Serial.println(storedValue);
      }
    }
  }
}

// Funktio tyhjentää EEPROM:n painonapilla
void clearEEPROM() {
  Serial.println("Tyhjennetaan EEPROM ....");
  Serial.flush();  
  for (int i = 0; i < EEPROM.length(); ++i) {
     EEPROM.write(i, 0); 
     delay(200);
  }
  // Nollataan osoite
  eePromAddress = 0;
  laskuri = 1;
  Serial.println("EEPROM on tyhja");
}

