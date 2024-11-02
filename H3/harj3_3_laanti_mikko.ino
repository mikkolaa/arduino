// C++ code
// // TMP36-anturin pin
const int sensorPin = A0;  
// Painonapin pin
const int buttonPin = 3; 
// Flagi-muuttuja keskeytykseen 
volatile bool measureFlag = false;

void setup() {
  Serial.begin(9600);
  pinMode(buttonPin, INPUT_PULLUP);
  // Asetetaan keskeytys jossa napin painallaus suorittaa 'startMeasurement' funktion
  attachInterrupt(digitalPinToInterrupt(buttonPin), startMeasurement, FALLING);
}

void loop() {
   // Tarkistetaan lippumuuttuja ja jos se on true, suoritetaan mittaukset
   // alifunktiossa
   if (measureFlag) {
     readTemperature();
     // Palautetaan falseksi
     measureFlag = false;  
  }
}

 // Keskeytysrutiini 
 void startMeasurement() {
    measureFlag = true;
}

// Keskeytysaliohjelma lämpötilan mittaamiseen ja keskiarvon laskemiseen
void readTemperature() {
  // Anturilukemien summa
  long sumADC = 0;
  // Keskiarvo
  float avgADC = 0;
  // Lämpötila
  float temp = 0; 
  // Luetaan 50 kertaa anturilta 20 ms välein ja tulostus
  for (int i = 0; i < 50; i++) {
    // Luetaan lämpötila-anturin arvo
    int adcValue = analogRead(sensorPin);         
    // Arvo summa muuttujaan	
    sumADC += adcValue;
    // 20 ms odotus ennen toistoa
    delay(20);
  }

  // Keskiarvo joka tehtävän mukaan jaetaan 50:lla
  avgADC = sumADC / 50.0; 
  // Lasketaan lämpötila kaavan mukaisesti
  temp = 0.7 * avgADC - 77.4;
  // Tulostus sarjaporttiin
  Serial.print("ADC: ");
  Serial.print(avgADC);
  Serial.print(" LT: ");
  Serial.println(temp);
}
