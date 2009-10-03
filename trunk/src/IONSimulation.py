"""
A pyrobotics simulation of the ION 2008 playing field.
"""

from pyrobot.simulators.pysim import *
from math import pi
import random

def INIT():
	#(width,height), (offset x, offset y), scale:
	sim = TkSimulator((1900,1640),(0,0),40) #Note: assumed dimensions in meters. Change if different dimensions.
	#x1,y1,x2,y2 in meters:

	#Paint the safety zone (which will serve as the border)
	sim.addBox(0,0,19,-2,"green",wallcolor="green")
	sim.addBox(17,-2,19,-14.4,"green",wallcolor="green")
	sim.addBox(12.6,-14.4,19,-16.4,"green",wallcolor="green")
	sim.addBox(12.6,-12,14.6,-14.4,"green",wallcolor="green")
	sim.addBox(0,-12,12.6,-14,"green",wallcolor="green")
	sim.addBox(0,-2,2,-12,"green",wallcolor="green")

	#Paint the flower bed
	x=random.randint(2,12)
	y=random.randint(-7,-2)
	sim.addBox(x,y,x+5,y-2,"blue",wallcolor="blue")
	sim.addBox(x,y-3,x+5,y-5,"blue",wallcolor="blue")
	sim.addBox(x+1,y-2,x+5,y-3,"blue",wallcolor="blue")

	#Paint the trash can
	#x=random.randint(2,18)
	#y=random.randint(-11,-2)
	#sim.addBox(x,y,x+0.5,y-0.5,"gray",wallcolor="gray")

	#Instantiate the robot
	#port,name,x,y,th,bounding X, bounding Y, color:
	sim.addRobot(60000,TkPioneer("Mower",2.5, -11.5, -math.pi/2,((.225,.225,-.225,-.225),(.175,-.175,-.175,.175))))

	#Instantiate the robot's sensor capability
	#For ease of programming, we will simulate the robot's ability using PioneerFrontSonars(). This gives decent coverage of the area that we actually will be able to sense, if we ignore the sensors perpendicular to the front.
	sim.robots[0].addDevice(PioneerFrontSonars())
	return sim
