
void setup() {
  pinMode(resetpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {

  in0 = analogRead(0);
  
  time=micros();
  Serial.println(in0);
}

