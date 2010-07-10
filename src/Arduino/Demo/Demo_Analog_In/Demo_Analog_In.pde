// This program is to demonstrate an analog input from a potentiometer
// Connect pot pins 1 and 3 to +V and GND
// Connect pin 2 to analog input 0


void setup() {
  pinMode(resetpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  in0 = analogRead(0); // read analog pin 0 - connected to potentiomater pin 2
  delay(250); //delay for 250ms (no need to read toooo fast)
  Serial.println(in0); //Display resultant analog input value
}

