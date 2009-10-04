/*
 * Sonar Test Code
 * Christopher Jones
 * 10/02/2009
 *
 * Designed for Zack's Sonar Contraption
 *
 */
void main(){

     TRISB = 0b00010000;	//set pins as input (1) or outputs (0)
     LATB = 0;				//clear PORTB pins
     PORTB = 0;				//initialize PORTB pins to 0 on the output

     int i=0;
     const int timeout = 10000;		//set count timeout
     int count[4];

     while(1)
     {
     count = 0;
         for(i=0;i<4;i++)	//loop on sonar device number, 4 devices total
         {
              PORTB = 0b00000001<<i;	//set the PORTB output pin for the desired sonar
              while(PORTBbits.RB4 != 1 || count[i] <= timeout)		//wait for the sonar to send a reply signal - might want to include a timeout failsafe
                  {
                  count[i]++;	//increment the sonar count
                  }
              PORTB = 0;
         }
	 printf("\nCount 1: %d\t2: %d\t3: %d\t4:%d",count[0],count[1],count[2],count[3]); //print the outputs after each acquisition
     }
 }
