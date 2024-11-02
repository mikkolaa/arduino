// C++ code
//
#include <LiquidCrystal.h>
// LCD näyttö ja sen käyttämät pinnit
LiquidCrystal lcd(12, 11, 5, 4, 3, 2);
// Pin TileSwitchiin
const int switchPin = 6;
// TileSwitchin tila
int switchState = 0;
// TileSwitchin edellinen tila
int prevSwitchState = 0;
int reply;

void setup() {
   // Alustetaan LCD näyttö ja switch
   lcd.begin(16, 2);   
   pinMode(switchPin,INPUT);
   lcd.print("Ask the");
   lcd.setCursor(0, 1);
   lcd.print("Crystal Ball!");
}

void loop() 
{
   switchState = digitalRead(switchPin);
   // Kun Swithcin tilaa vaihdettu
   if (switchState != prevSwitchState) 
   {
      // Tilassa LOW tulostetaan randomisti LCD:hen toinen teksti
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
      // Tila muistiin seuraavaa valintaa varten
      prevSwitchState = switchState;        
   }                        
}        
  