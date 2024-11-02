// C++ code
// Alustukset
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(8, OUTPUT);
}

// Ensimmäinen led vilkuu neljä kertaa jonka jälkeen muut ledit syttyvät palamaan
// ensimmäisen ledin kanssa.
void loop() {
  
  for(int i = 0; i < 3; ++i)
  {
    digitalWrite(13, HIGH);
    digitalWrite(13, LOW);
    delay(1000);  
  }
  
  digitalWrite(13, HIGH);
  delay(1000);     
  digitalWrite(12, HIGH);
  delay(1000);   
  digitalWrite(8, HIGH);
  delay(1000); 
  digitalWrite(13, HIGH);
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
}