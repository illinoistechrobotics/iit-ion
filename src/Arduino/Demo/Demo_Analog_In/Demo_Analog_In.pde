// This program is to demonstrate an analog input from a potentiometer
// Connect pot pins 1 and 3 to +V and GND
// Connect pin 2 to analog input 0


void setup() {  
  Serial.begin(9600);
}

void loop() {
  delay(250); //delay for 250ms (no need to read toooo fast)
  Serial.println(analogRead(0)); // Display analog input value from pin 0
}
