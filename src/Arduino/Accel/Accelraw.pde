/*
 * accelraw.pde - raw read ADXL330 values
 * stripped-down version of 
 * * Accelerometer Slave Code by Jesse Young <jesse@jlyo.org>
 */

#include "settings.h" 
#define ACCEL_ZERO 0
/* 376*/ 

const int delayTime = 10;

int xa0, ya0, za0;
int xv, yv, zv;
long xr, yr, zr;
int t0;

char loop_ct = 0;

void setup()
{
    Serial.begin(BAUD_RATE);
    xv = yv = zv = 0;
    xr = yr = zr = 0;
    t0 = millis();
}

void loop()
{
    int xa, ya, za;
	int p0,p1;
    // int xRate, yRate;
    int t1, dt;

    t1 = millis();
    dt = t1 - t0;

    if (dt != 0) {
        // Read analogs
        xa = analogRead(xAxisPin) - ACCEL_ZERO;
        ya = analogRead(yAxisPin) - ACCEL_ZERO;
        za = analogRead(zAxisPin) - ACCEL_ZERO;
		p0 = analogRead(0);
		p1 = analogRead(1);

        
        Serial.print(xa, DEC); Serial.print(" ");
        Serial.print(ya, DEC); Serial.print(" ");
        Serial.print(za, DEC); Serial.print(" - ");
        Serial.print(p0, DEC); Serial.print(" ");
        Serial.println(p1, DEC);
    }
}

/* vim: ft=cpp
*/
