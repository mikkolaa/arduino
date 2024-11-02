// C++ code
//
#include <LiquidCrystal.h>
// LCD näyttö ja sen käyttämät pinnit
LiquidCrystal lcd(12, 11, 5, 4, 7, 2);
// Pin TileSwitchille
const int switchPin = 6;
// Tila TileSwitchille
int switchState = 0;
// TileSwitchin edellinen tila
int prevSwitchState = 0;
// Random funktion apumuuttuja
int reply;
// Pin lämpötila painonapille
const int buttonWarm = 3; 
// TMP36-anturin pin
const int sensorPin = A0;

void setup() {   
   // LCD:n asetukset
   lcd.begin(16, 2);
   pinMode(switchPin,INPUT);
   pinMode(buttonWarm, INPUT_PULLUP);
   lcd.print("Ask the");
   lcd.setCursor(0, 1);
   lcd.print("Crystal Ball!");
   // Asetetaan keskeytysrutiini
   attachInterrupt(digitalPinToInterrupt(buttonWarm), readTemperature, FALLING);
}

// Funktio lukee lämpötilan TMP36:lta ja tulostaa sen LCD:lle
void readTemperature() { 
  float temp = 0;
  int adcValue = analogRead(sensorPin); 
  // Muunnetaan keskiarvo Celsius-lämpötilaksi kaavalla
  temp = 0.7 * adcValue - 77.4;  
  // Näytetään lämpötila LCD-näytössä (poistetaan sensorin tekstit)
  lcd.clear();
  lcd.print("Temp is now: ");
  lcd.setCursor(0, 1);
  // Tulostetaan lämpötila kahden desimaalin tarkkuudella 
  lcd.print(temp, 2);  
}

// Loop jossa luetaan Switchin tila ja sen muuttuessa
// kirjoitetaan LCD-näytölle random funktion arpoma teksti
void loop() 
{
   switchState = digitalRead(switchPin);
   if (switchState != prevSwitchState) 
   {
      if (switchState == LOW) 
      {
         reply = random(8);
         lcd.clear();
         lcd.setCursor(0, 0);
         lcd.print("The ball says:");
         lcd.setCursor(0, 1);
            switch(reply){
              case 0:
              lcd.print("Yes");
            break;
            case 1:
              lcd.print("Most likely");
            break;
            case 2:
              lcd.print("Certainly");
            break;
            case 3:
              lcd.print("Outlook good");
            break;
            case 4:
              lcd.print("Unsure");
            break;
            case 5:
              lcd.print("Ask again");
            break;
            case 6:
              lcd.print("Doubtful");
            break;
            case 7:
              lcd.print("No");
            break;
          }        
      }     
      // Edellinen tila
      prevSwitchState = switchState;        
   }                        
}        
  