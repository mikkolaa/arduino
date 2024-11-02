// C++ code
// Alustukset
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
}

// Loopissa valot ledeihin vuorotellen peräkkäin
void loop() {
  digitalWrite(13, HIGH);
  delay(1000);  
  
  digitalWrite(13, LOW);
  digitalWrite(12, HIGH);
  delay(1000);  
  
  digitalWrite(12, LOW);
  digitalWrite(8, HIGH);
  delay(1000);  
  
  digitalWrite(8, LOW);
}