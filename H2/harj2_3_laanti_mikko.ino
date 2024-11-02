// C++ code
// Alustus sekä sarjaportin alustus
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

// Kaikki ledit päälle ja kirjoitus sarjaporttiin,
// kaikki ledit pois päältä ja kirjoitus sarjaporttiin
void loop() {    
  digitalWrite(13, HIGH);
  digitalWrite(12, HIGH);
  digitalWrite(8, HIGH);
  Serial.print("LED ON");
  delay(2000);
  digitalWrite(13, LOW);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);  
  Serial.print("LED OFF");
  delay(1000);
}