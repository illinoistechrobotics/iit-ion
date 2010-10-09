import serial
import time
MINVELOCITY=-500
MAXVELOCITY=500
MINRADIUS=-2000
MAXRADIUS=2000
def mmToSci(velocity, radius):
	if velocity >= MINVELOCITY and velocity <= MAXVELOCITY and radius >= MINRADIUS and radius <= MAXRADIUS:
		if velocity<0:
			velocity=velocity+pow(16,4)
		if radius<0:
			radius=radius+pow(16,4)
		velocity=hex(velocity)[2:]
		radius=hex(radius)[2:]
		
		vel1=int(empty(velocity[-4:-2]),16)
		vel2=int(empty(velocity[-2:]),16)
		rad1=int(empty(radius[-4:-2]),16)
		rad2=int(empty(radius[-2:]),16)
		return [vel1, vel2, rad1, rad2 ]
	else:
		return [0, 0, 0, 0]
def goStraight(velocity):
	if velocity >= MINVELOCITY and velocity <= MAXVELOCITY:
		if velocity<0:
			velocity=velocity+pow(16,4)
		velocity=hex(velocity)[2:]
		vel1=int(empty(velocity[-4:-2]),16)
		vel2=int(empty(velocity[-2:]),16)
		drive(vel1,vel2,128,0)
	else:
		drive(0,0,128,0)
def stop():
	drive(0,0,0,0)
def empty(str):
	if str=="":
		return "0"
	else: return str
#def openPort():
#	ser = serial.Serial('COM4',57600)
#roomba must be 
def initialize():		
	ser.write(chr(128))
	ser.write(chr(130))
	ser.write(chr(132))
def go(vel1, vel2, rad1, rad2):
	ser.write(chr(137))
	ser.write(chr(vel1))
	ser.write(chr(vel2))
	ser.write(chr(rad1))
	ser.write(chr(rad2))
def drive(vel, rad):
	sci=mmToSci(vel, rad)
	ser.write(chr(137))
	ser.write(chr(sci[0]))
	ser.write(chr(sci[1]))
	ser.write(chr(sci[2]))
	ser.write(chr(sci[3]))

ser = serial.Serial('COM4',57600)
#openPort()
initialize()
#goStraight(-200)

#time.sleep(3)
#stop()
array=mmToSci(500, -100)
go(array[0],array[1],array[2],array[3])
time.sleep(10)
stop()
