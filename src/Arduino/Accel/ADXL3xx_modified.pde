
/*
 ADXL3xx
 
 Reads an Analog Devices ADXL3xx accelerometer and communicates the
 acceleration to the computer.  The pins used are designed to be easily
 compatible with the breakout boards from Sparkfun, available from:
 http://www.sparkfun.com/commerce/categories.php?c=80

 http://www.arduino.cc/en/Tutorial/ADXL3xx

 The circuit:
 analog 0: accelerometer self test
 analog 1: z-axis
 analog 2: y-axis
 analog 3: x-axis
 analog 4: ground
 analog 5: vcc
 
 created 2 Jul 2008
 by David A. Mellis
 modified 26 Jun 2009
 by Tom Igoe 
 
 Modified by Allen Baker

*/

// these constants describe the pins. They won't change:
const int groundpin = 18;             // analog input pin 4 -- ground
const int powerpin = 19;              // analog input pin 5 -- voltage
const int xpin = 2;                   // x-axis of the accelerometer
const int ypin = 1;                   // y-axis
const int zpin = 0;                   // z-axis (only on 3-axis models)
const int xrpin = 5;
const int yrpin = 4;
const int zrpin = 3;

int inputBlind = 10;

void setup()
{
  // initialize the serial communications:
  Serial.begin(9600);
  
  // Provide ground and power by using the analog inputs as normal
  // digital pins.  This makes it possible to directly connect the
  // breakout board to the Arduino.  If you use the normal 5V and
  // GND pins on the Arduino, you can remove these lines.
  pinMode(groundpin, OUTPUT);
  pinMode(powerpin, OUTPUT);
  digitalWrite(groundpin, LOW); 
  digitalWrite(powerpin, HIGH);
}

void loop()
{
  // print the sensor values:
  Serial.print("X: ");
  if (analogRead(xpin) - 332 >= inputBlind || analogRead(xpin) - 332 <= -inputBlind)
  Serial.print(analogRead(xpin) - 332);
  
  // print a tab between values:
  Serial.print("\t");
  Serial.print("Y: ");
  if (analogRead(ypin) - 343 >= inputBlind || analogRead(ypin) - 343 <= -inputBlind)
  Serial.print(analogRead(ypin) - 343);
  
  //print a tab between values:
  Serial.print("\t");
  Serial.print("Z: ");
  if (analogRead(zpin) - 410 >= inputBlind || analogRead(zpin) - 410 <= -inputBlind)
  Serial.print(analogRead(zpin) - 410);
  
  //x rotation
  Serial.print("\t");
  Serial.print("XR: ");
  Serial.print(analogRead(xrpin) - 1002);
  
  //y rotation
  Serial.print("\t");
  Serial.print("YR: ");
  Serial.print(analogRead(yrpin) - 7);
  
  //z rotation
  Serial.print("\t");
  Serial.print("ZR: ");
  Serial.print(analogRead(zrpin) - 253);
  
  //Print new line
  Serial.println();
  // delay before next reading:
  delay(100);
}
