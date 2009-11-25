/*
 theoiwhoawef
 */

int SOut =  1;    // Sonar trigger connected to digital pin 1
int SIn =  2;     // Sonar listen on digital pin 2

int count = 0;
int timeout = 10000;

// The setup() method runs once, when the sketch starts

void setup()   {                
  // initialize the digital pin as an output:
  pinMode(SOut, OUTPUT);
  
  // initalize outputs
  pinMode(SIn, INPUT);
  
  Serial.begin(9600);      // open the serial port at 9600 bps:

}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop()                     
{
  digitalWrite(SOut, HIGH);   // set the LED on
  count += 1;                 // wait for a second
  
  digitalRead(SIn);
  
  if(SIn == HIGH || count >= timeout)
      {  
        SIn = LOW;
        //output count
        Serial.print("\nPong: ");
        Serial.print(count);       // print as an ASCII-encoded decimal - same as "DEC"
        count = 0; 
 
 
        digitalWrite(SOut, LOW);
        delay(2); 
        Serial.print("\nPing");
      }
}
