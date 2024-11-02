// C++ code
const int button = 3, // Painonappi
          led = 12;   // Led 
int state = 0;        // Tilamuuttuja ledille

void setup()
{
  pinMode(button, INPUT); // Painonappi
  pinMode(led, OUTPUT);   // Led
  Serial.begin(9600);
}

void loop()
{   
  // If-else ledin syttymisen ja sammumisen hoitamiseen
  if (digitalRead(button) == LOW) {
    state = 1;
  }  
  else if (digitalRead(button) == HIGH) {   
    state = 0;
  }
  
  digitalWrite(led, state);
}