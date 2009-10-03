/*
mikroC Version
PIC 18F2250
Test LED blinking 10/2/09
*/

void main() {
  PORTC = 0;                 // Initialize PORTC
  TRISC = 0;                 // Configure PORTC as output

  while(1) {
    PORTC =  ~PORTC;         // toggle PORTC
    Delay_ms(1000);          // one second delay
  }
}
