//Copied from Tom Lord 8/24/10 
//(following crashing the quadcopter) 

const int MOTOR1 = 10;
const int MOTOR2 = 11;
const int MOTOR3 = 3;
const int MOTOR4 = 9;

int MS1=0;
int MS2=0;
int MS3=0;
int MS4=0;

const int hoverSpeed = 215;

const float a=0;//.25;//1.5;
const float b=0;//5;//25;
const float c=0;//.1;

const int aXPin = 5;
const int aYPin = 4;
const int aZPin = 3;
const int gXPin = 1;
const int gYPin = 0;
const int gZPin = 2;

float accelX=0;
float accelY=0;
float accelZ=0;
float gyroX=0;
float gyroY=0;

float zeroAX =0;//335;
float zeroAY =0;//335;
float zeroAZ =0;//335;
float zeroGX =0;//248;
float zeroGY =0;//250;

long sonar=0;
long h=0;

long timer=0;

const int echoPin = 7;
const int triggerPin = 7;
boolean startSwitch=true;

void setup() 
{
 Serial.begin(9600);
}
void loop()
{
  
  if (startSwitch)
  {    
    
    //start all the motors at low, and zero all the sensors (not sonar).
    startAndZero();
    
    timer=millis();
    
   startSwitch=false; 
  }
  
  if ((millis()-timer)>10)
  {
    joyStick();
    if (h<0)
    {h=0;}
    timer=millis();
  }
  
  updateGyro();
  sonarPing();
  //if (sonar=207)
  //{sonar=0;}
  //Autonomous Balancing Code

  MS1=hoverSpeed+a*(h-sonar) +b*(accelX)-c*(gyroX);
  MS2=hoverSpeed+a*(h-sonar)+b*(accelY)-c*(gyroY);
  MS3=hoverSpeed+a*(h-sonar)-b*(accelX)+c*(gyroX);
  MS4=hoverSpeed+a*(h-sonar)-b*(accelY)+c*(gyroY);
 
  analogWrite(MOTOR1, MS1);
  analogWrite(MOTOR2, MS2);
  analogWrite(MOTOR3, MS3);
  analogWrite(MOTOR4, MS4);
  printMEMS();
    
}
long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}
void updateGyro()
{
  float X1=0;
  float Y1=0;
  float Z1=0;
  float X2=0;
  float Y2=0;
  X1=analogRead(aXPin)- zeroAX;
  Y1=analogRead(aYPin)- zeroAY;
  Z1=analogRead(aZPin)- zeroAZ;
  X2=analogRead(gXPin)- zeroGX;
  Y2=analogRead(gYPin) - zeroGY;
 
  accelX=(((X1*4.9)/300)+accelX*2)/3;
  accelY=(((Y1*4.9)/300)+accelY*2)/3;
  accelZ=(((Z1*4.9)/300)+accelZ*2)/3;
  gyroX=(((X2*4.9)/3.33)+gyroX*2)/3;
  gyroY=(((Y2*4.9)/3.33)+gyroY*2)/3;
}
void sonarPing()
{
  long duration, inches;
  pinMode(triggerPin, OUTPUT);
  digitalWrite(triggerPin, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(triggerPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  sonar = microsecondsToInches(duration);
}
void startAndZero()
{
    analogWrite(MOTOR1, 185);
    analogWrite(MOTOR2, 185);
    analogWrite(MOTOR3, 185);
    analogWrite(MOTOR4, 185);
    delay(5000);
    
    int counter = 0;
    while(counter < 50)
    {
      zeroAX=zeroAX+analogRead(aXPin);
      zeroAY=zeroAY+analogRead(aYPin);
      zeroAZ=zeroAZ+analogRead(aZPin);
      zeroGX=zeroGX+analogRead(gXPin);
      zeroGY=zeroGY+analogRead(gYPin);
      counter++;
      delay(10);
    }
    
    zeroAX=zeroAX/counter;
    zeroAY=zeroAY/counter;
    zeroAZ=(zeroAZ/counter)-61;
    zeroGX=zeroGX/counter;
    zeroGY=zeroGY/counter;
    
    analogWrite(MOTOR2, 190);
    delay(500);
    analogWrite(MOTOR2, 185);
    delay(5000);
}
void printMS()
{
  Serial.print(MS1);
  Serial.print(" , ");
  Serial.print(MS2);
  Serial.print(" , ");
  Serial.print(MS3);
  Serial.print(" , ");
  Serial.println(MS4);
}
void printMEMS()
{
  Serial.print(sonar);
  Serial.print(" , ");
  Serial.print(accelX);
  Serial.print(" , ");
  Serial.print(accelY);
  Serial.print(" , ");
  Serial.print(accelZ);
  Serial.print(" , ");
  Serial.print(gyroX);
  Serial.print(" , ");
  Serial.println(gyroY);
}
void joyStick()
{
  if (Serial.available()>0)
  {
    int a=0;
     a=Serial.read();
     a=a-5;
     h=h+a;
  }
}