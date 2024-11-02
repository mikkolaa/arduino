// C++ code
// Muuttujat
int laskuri = 0;  
const int painonappi = 3; // Painonappi pin 3 (keskeytysrutiini)
const int led1 = 12;      // Led pin 12

void setup() {
  // input_pull moodi
  pinMode(painonappi, INPUT_PULLUP); 
  pinMode(led1, OUTPUT);
  Serial.begin(9600);
  // Keskeytys asettaminen, kutsutaan `nappiPainettu` funktiota, kun nappia painetaan
  attachInterrupt(digitalPinToInterrupt(painonappi), nappiPainettu, FALLING);
}

void loop() {
  // Ei tehdä loop-funktiossa mitään
}

// Keskeytysrutiini
void nappiPainettu() {
  laskuri++;  // Kasvatetaan laskurin arvoa

  // Jos laskuri parillinen, sammutetaan LED, muuten sytytetään
  if (laskuri % 2 == 0) {
    digitalWrite(led1, LOW);  // Sammutetaan LED
  } 
  else {
    digitalWrite(led1, HIGH); // Sytytetään LED
  }

  // Laskurin arvo ja LED:n tila sarjaporttiin
  Serial.print("Laskuri: ");
  Serial.println(laskuri);
}
