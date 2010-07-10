//Accelerometer IDG500
//Tom Lord 7/10/2010.

//pinout
//analog:
//0:vref
//2:xout
//3:*4.5xout
//4:yout
//5:*4.5yout
//digital:
//2:AutoZero

const int vrefpin = 0;
const int xglpin = 2;
const int xghpin = 3;
const int yglpin = 4;
const int yghpin = 5;
const int resetpin = 2; //digital

float time=0;
float time2=0;
float degxh=0;
float degyh=0;
float degxl=0;
float degyl=0;
float xgl=0;
float xgh=0;
float ygl=0;
float ygh=0;
float xglz=0;
float xghz=0;
float yglz=0;
float yghz=0;
float xh=0;
float yh=0;
float xl=0;
float yl=0;
float xtrue=0;
float ytrue=0;
float xtdeg=0;
float ytdeg=0;
boolean flag = true;

void setup() {
  pinMode(resetpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  
  if (flag) 
  {
    
    digitalWrite(resetpin, HIGH);
    delay(1);
    digitalWrite(resetpin, LOW);
    
    int counter = 0;
    while(counter < 50)
    {
      xghz=xghz+analogRead(xghpin);
      yghz=yghz+analogRead(yghpin);
      xglz=xglz+analogRead(xglpin);
      yglz=yglz+analogRead(yglpin);
      
      counter++;
      delay(10);
    }
    
    xghz=(xghz/counter);
    yghz=(yghz/counter);
    xglz=(xglz/counter);
    yglz=(yglz/counter);
    
    flag=false;
  }
  
  xgl = analogRead(xglpin)-xglz;
  xgh = analogRead(xghpin)-xghz;
  ygl = analogRead(yglpin)-yglz;
  ygh = analogRead(yghpin)-yghz;
  
  xh=(4.9/9.1)*xgh;
  yh=(4.9/9.1)*ygh;
  xl=(4.9/2)*xgl;
  yl=(4.9/2)*ygl;
  
  if (abs(xh)<1.5)
  {xh=0;}
  if (abs(yh)<1.5)
  {yh=0;}
  if (abs(xl)<4)
  {xl=0;}
  if (abs(yl)<3)
  {yl=0;}
  
  if (abs(xh)<90)
  {xtrue=xh;}
  else {xtrue = xl;}
  if (abs(yh)<90)
  {ytrue=yh;}
  else {ytrue = yl;}
  
  time=micros()-time;
  time2=time/1000000;
  
  xtdeg=time2*xtrue+xtdeg;
  ytdeg=time2*ytrue+ytdeg;
  
  degxh=time2*xh+degxh;
  degyh=time2*yh+degyh;
  degxl=time2*xl+degxl;
  degyl=time2*yl+degyl;
  
  time=micros();
  Serial.print(degxh);
  Serial.print(", ");
  Serial.print(degyh);
  Serial.print(", ");
  Serial.print(degxl);
  Serial.print(", ");
  Serial.print(degyl);
  Serial.print(" | ");
  Serial.print(xtdeg);
  Serial.print(", ");
  Serial.println(ytdeg);
}


