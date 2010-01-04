/*
 * Global settings for the puma project
 * 
 * Jesse Young <jesse@jlyo.org>
 */

#ifndef TRUE
#  define TRUE 1
#endif

#ifndef FALSE
#  define FALSE 0
#endif

typedef signed long ssize_t;

/*
 * Serial Rate, be sure to change this along with serial_baud rate in
 * Settings.py
 */
const int BAUD_RATE = 9600;

/************************************************************************  
 * Begin pin definitions                                                *
 ************************************************************************/

// Unused pins are: 0,1,6

/* Pin Definitions for accelerometer */
const int xAxisPin = 4;
const int yAxisPin = 3;
const int zAxisPin = 2;

/* Pin Definitions of the gyroscope */
const int xRatePin = 0;
const int yRatePin = 1;

/*Pin Definitions for the sonars*/
const int frontsonarPin = 7;
const int backsonarPin = 8;
const int rightsonarPin = 12;
const int leftsonarPin = 13;
const int servo_pin = 9;

/*Pin Definitions for the Rotary Encoders*/
// we need two more pins to run the OTHER rotary encoder 
const int encoderdirection = 4;
const int encoderrate = 5;

/*Pin Definitions for the Motors*/
// pins 10 and 11

/* ----------------------------------------------------------------------  
 * Begin Function Declarations
 * ----------------------------------------------------------------------  
 */

/*Sonar constants */
const int BAD_SONAR_RESULT = 0;
/*Servo Constants*/
const int servo_time_delay = 1000; //describes servo speed in ms
const int angle = 20; //Describes the angle the servo moves per tick. 180 must be divisible by this number
