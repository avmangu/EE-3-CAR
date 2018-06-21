/* 
 *  Animesh Mangu
 *  Jason Levine
 *  EE3 - Briggs
 */
 
 
// Left Wheel
int analogLeft = 5;
int digitalForwardLeft = 6;      
int digitalBackwardsLeft = 9; 

// Right Wheel
int analogRight = 10; 
int digitalForwardRight = 3;      
int digitalBackwardsRight = 11;

void setup() { 
  // For sensor values
  Serial.begin(9600);
  
  attachInterrupt(digitalPinToInterrupt(2), blink, RISING);
    
  // Set Left Wheel
  pinMode(analogLeft, OUTPUT);
  pinMode(digitalForwardLeft, OUTPUT);
  pinMode(digitalBackwardsLeft, OUTPUT);
   
  // Set Right Wheel
  pinMode(analogRight, OUTPUT);
  pinMode(digitalForwardRight, OUTPUT);
  pinMode(digitalBackwardsRight, OUTPUT);

  // LED Blink
  pinMode(LED_BUILTIN, OUTPUT);

  digitalWrite(digitalForwardLeft, HIGH); 
  digitalWrite(digitalForwardRight, HIGH);
  digitalWrite(digitalBackwardsLeft, LOW); 
  digitalWrite(digitalBackwardsRight, LOW); 
}

// Move the car
void progress(int right, int left) {
  analogWrite(analogRight, right);  
  analogWrite(analogLeft, left);  
}

// LED blink
void blink() {
  digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);
}

// Return left sensor values
int sensorLeft() {
  // read the input on analog pin 1:
  int sensorValue = analogRead(A4);
  return sensorValue;
}

// Return right sensor values
int sensorRight() {
  // read the input on analog pin 4:
  int sensorValue = analogRead(A0);
  return sensorValue;
}

// MAIN 
void loop()  {
  // When its white
  while(sensorLeft() > 900 && sensorRight() > 900) {
    // Keep going...75 < 80 because left motor is slightly slower than right
    progress(75, 80); 
  }
  // Turn Left
  while(sensorLeft() < 900) {
    progress(100, 55);
  }
  // Turn Right
  while(sensorRight() < 900) {
    progress(55, 110);
  }
}
