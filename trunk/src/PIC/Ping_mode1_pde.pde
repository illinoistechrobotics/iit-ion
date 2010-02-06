/* Ping))) Sensor
  
   This sketch reads a PING))) ultrasonic rangefinder and returns the
   distance to the closest object in range. To do this, it sends a pulse
   to the sensor to initiate a reading, then listens for a pulse 
   to return.  The length of the returning pulse is proportional to 
   the distance of the object from the sensor.
     
   The circuit:
	* +V connection of the PING))) attached to +5V
	* GND connection of the PING))) attached to ground
	* SIG connection of the PING))) attached to digital pin 7

   http://www.arduino.cc/en/Tutorial/Ping
   
   created 3 Nov 2008
   by David A. Mellis
   modified 30 Jun 2009
   by Tom Igoe
   
   Modified by Allen Baker
 */

// this constant won't change.  It's the pin number
// of the sensor's output:
const int pingPin1 = 3;
const int pongPin1 = 2;
const int pingPin2 = 5;
const int pongPin2 = 4;

void setup() {
  // initialize serial communication:
  Serial.begin(9600);
  
  pinMode(pingPin1, OUTPUT);
  pinMode(pingPin2, OUTPUT);
  
  pinMode(pongPin1, INPUT);
  pinMode(pongPin2, INPUT);
}

void loop()
{
  // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration1, inches1, cm1;
  long duration2, inches2, cm2;

  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  digitalWrite(pingPin1, LOW);
  digitalWrite(pingPin2, LOW);
  delayMicroseconds(2);
  //10microsecond pulse to start ranging
  digitalWrite(pingPin1, HIGH);
  digitalWrite(pingPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(pingPin1, LOW);
  digitalWrite(pingPin2, LOW);

  // Different pins used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  duration1 = pulseIn(pongPin1, HIGH);
  duration2 = pulseIn(pongPin2, HIGH);

  // convert the time into a distance
  inches1 = microsecondsToInches(duration1);
  cm1 = microsecondsToCentimeters(duration1);
  inches2 = microsecondsToInches(duration2);
  cm2 = microsecondsToCentimeters(duration2);
  
  Serial.print("Sonar#1: ");
  Serial.print(inches1);
  Serial.print("in, ");
  Serial.print(cm1);
  Serial.print("cm");
  Serial.println();
  Serial.print("Sonar#2: ");
  Serial.print(inches2);
  Serial.print("in, ");
  Serial.print(cm2);
  Serial.print("cm");
  Serial.println();
  
  //50ms delay between each round pulses in case of false echoes
  delay(100);
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

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
