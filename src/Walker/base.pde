#include <Servo.h> 

Servo rWaist;
Servo lWaist;
Servo rFoot;
Servo lFoot;

void setup() 
{ 
	//Order prevents most startup collisions
	
	rFoot.attach(10);
	rFoot.write(80);
	delay(250);
	
	lFoot.attach(11);
	lFoot.write(100);
	delay(250); 
	
	rWaist.attach(6);
	rWaist.write(135);
	delay(250);

	lWaist.attach(9);
	lWaist.write(90);
	delay(250);
}

//Relative motion
void rWRel(int pos) {
	rWaist.write(135+pos);
}

void lWRel(int pos) {
	lWaist.write(90+pos);
}

void rFRel(int pos) {
	 rFoot.write(80+pos);
}

void lFRel(int pos) {
	lFoot.write(100+pos);
}


void leftStep(int pause) {
	lFRel(-45);
	delay(pause);
	
	rFRel(25);
	delay(pause);
	
	rWRel(-45);
	lWRel(-45);
	delay(pause);
	
	lFRel(0);
	delay(pause);
	
	rFRel(0);
	delay(pause);
}

void rightStep(int pause) {
	rFRel(-45);
	delay(pause);
	
	lFRel(25);
	delay(pause);
	
	lWRel(45);
	rWRel(45);
	delay(pause);
	
	rFRel(0);
	delay(pause);
	
	lFRel(0);
	delay(pause);
}
	
	
/*
void leftStep() {
	lFoot.write(55);
	delay(pause);
	rFoot.write(135);
	delay(pause);
	rWaist.write(100);
	lWaist.write(55);
	delay(pause);
	lFoot.write(100);
	delay(pause);
	rFoot.write(90);
	delay(pause); 
}

void rightStep() {
	rFoot.write(55);
	delay(pause);
	lFoot.write(125);
	delay(pause);
	lWaist.write(125);
	rWaist.write(170);
	delay(pause);
	rFoot.write(90);
	delay(pause);
	lFoot.write(100);
	delay(pause);
}


void stand() {
	rWaist.write(135);
	delay(1000);
	
	lWaist.write(90);
	delay(1000);

	rFoot.write(90);
	delay(1000);

	lFoot.write(100);
	delay(1000);
}
*/

void inchworm(int pause) {
  	rWRel(45);
  	lWRel(45);
  	delay(50);
  
  	lFRel(25);
  	rFRel(25);
  	delay(100);
  
  	lFRel(0);
  	rFRel(0);
  	delay(100);
  
}

void shoulders(int pause) {
  
  	for (int i=0; i<70; i++) {
    	 rFRel(-i-40);
    	 lFRel(i);
     
    	 delay(15);
  	}
	//  delay(500);
  
 
  	for (int i=70; i>0; i--) {
  	   lFRel(i);
  	   rFRel(-i-20);
  	   delay(15);
  	}
  
 	 rFRel(0);
  
 	// delay(1000);
 	 for (int i=0; i<70; i++) {
 	   lFRel(-i-40);
  	  rFRel(i);
  	  delay(15);
 	 }
  
 	 for (int i=70; i>0; i--) {
 	   rFRel(i);
  	  lFRel(-i-20);
   	 delay(15);
 	 }
  
  	lFRel(0);
       }
  
void shimmyLeft() {
 	rFRel(-45);
 	delay(100);
 	lFRel(45);
 	delay(250);
 	lWRel(45);
 	delay(250);
	lWRel(-45);
 	delay(250); 
}  
 
void dance1() {
  	rFRel(-25);
 	delay(100);
  	lFRel(35);
  	delay(250);
   	lWRel(50);
  	delay(700);
 	lWRel(-50);
  	delay(700);
}

void loop() 
{ 
	int pause=1000;  
//        leftStep(pause);
//	rightStep(pause);
  //inchworm(pause);
      dance1();
}
