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
  
  // initialize outputs
  pinMode(SIn, INPUT);
  
  Serial.begin(9600);      // open the serial port at 9600 bps:

}

// the loop() method runs over and over again,
// as long as the Arduino has power

void loop()                     
{
  Serial.print("\nPing"); 
  digitalWrite(SOut, HIGH); 	//ping the sonar
  count += 1;                 	//increment count every cycle to track time
  
  digitalRead(SIn);
  
  if(SIn == HIGH || count >= timeout)	//wait for a reply from the sonar
      {  
        SIn = LOW;
        //output count
        Serial.print("\nPong: ");
        Serial.print(count);       	//display total count when reply is heard
        							//add scaling values based on clock frequency to determine actual time
        count = 0; 

        digitalWrite(SOut, LOW);
        delay(2); 
      }
      
}
