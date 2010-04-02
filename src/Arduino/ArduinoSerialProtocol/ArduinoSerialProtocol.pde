int ledPin = 13;
int SerialData = 0;
int MotorSpeed1 = 0;
int MotorSpeed2 = 0; 
int counter;
const int MOTOR1 = 9;
const int MOTOR2 = 10;

void setup() 
{
 pinMode ( ledPin, OUTPUT);
 Serial.begin(9600);
 Serial.print("READY TO GO");
 Serial.println(33, BYTE);
}

void loop()
{
  
  while ( Serial.available()>0)
  {
    //Serial.println("New Data!!");   
    //digitalWrite(ledPin, HIGH);
    //delay(300);
    //digitalWrite(ledPin, LOW);
    //delay(200);    
    //i++;
    counter++;  
    SerialData = Serial.read();  
    if(SerialData == 10 ) // 10 shows the end of a data frame
    {
       if(counter ==3)// Received data is 10 and counter is 3 so data are valid
       {
         run();        // data is valid => Run command
         counter = 0;  // it is ready for new data frame      
       }
       else // Received data is 10 but counter is not 3 so some data is lost
       {    // reset values
         MotorSpeed1 = 0;
         MotorSpeed2 = 0;
         counter = 0;
       }
    }   
    if(counter ==1) // first byte in data frame is Motor1 Speed value
       {
         MotorSpeed1 = SerialData;       
       }
    else if(counter ==2) // second byte in data frame is Motor2 Speed value
       {
         MotorSpeed2 = SerialData;       
       }
       else if(counter >3) // if counter is greater than 3 something is wrong 
       {                   // Reset values
         MotorSpeed1 = 0;
         MotorSpeed2 = 0;
         counter=0;
       }
      Serial.print(SerialData, BYTE); // for testing  
  }
}
void run ()
{
    analogWrite(MOTOR1,MotorSpeed1);  
    analogWrite(MOTOR2,MotorSpeed2);  
     
  // To test the operation
    if ( MotorSpeed1 > 175)  //  
    {
      digitalWrite(ledPin, HIGH);
    //Serial.println(120, BYTE);
    }
    else 
    {
      digitalWrite(ledPin, LOW);
    //   Serial.println(i, DEC);  
    }
    
}
