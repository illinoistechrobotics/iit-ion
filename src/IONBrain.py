#A skeleton of an ION brain

from pyrobot.brain import Brain
import math

class IONBrain(Brain):

#Initialization code goes here
	def setup(self):
		self.numx = 100			#Number of cells to use in Map Grid
		self.numy = 100

		self.conversionx = self.numx / 40	#Convsersion factors between in-simulator coordinates and Map Grid
		self.conversiony = self.numy / 40	#Conversion factors assume we start in the corner of a 20 meter by 20 meter room

		self.basex = int(round(self.numx / 2))		#Position of the origin in Map Grid
		self.basey = int(round(self.numy / 2))

		self.currentx = self.basex	#Current position in Map Grid
		self.currenty = self.basey

		self.goalx = self.basex		#Next position to visit in Map Grid
		self.goaly = self.basey

		#Instantiate the Map
		self.blockmap = [[ 0 for x in range(self.numx)] for y in range(self.numy)]	#The map of blocked cells
		self.mowmap = [[ 0 for x in range(self.numx)] for y in range(self.numy)]	#The map of visited cells

		#Sensor setup
		self.sen=[]	#The list of available 'legit' sonars to use for purposes of this simulation
		self.sang=[]	#The list of corresponding angles of above sonars
		for i in range(0, len(self.robot.sonar[0])): #Check each available sonar
			if self.robot.sonar[0][i].angle('radians') < (math.pi / 2) and self.robot.sonar[0][i].angle('radians') > (-math.pi / 2):
				self.sen=self.sen+[i] #if it's within a forward range, then use it
				self.sang=self.sang+[self.robot.sonar[0][i].angle('radians')]
		if self.sen == []:
			print('Error: No available sonar. Expect poor performance.')
		self.slength = len(self.sen)

#Code that gets executed every simulation step goes here
	def step(self):

		#Figure out current position in Map Grid
		self.currentx = int(round((self.robot.x * self.conversionx) + self.basex))
		self.currenty = int(round((self.robot.y * self.conversiony) + self.basey))

		#Mark current position visited
		self.mowmap[self.currentx][self.currenty] = 1

		#Figure out sensed blockages in Map Grid, and mark them Blocked
		for i in range(0, self.slength):
			#At this point we currently have the location of a blocked square in polar. Convert to Cartesian, then convert to Grid.
			self.blockmap[int(round(self.currentx + self.robot.sonar[0][self.sen[i]].value*math.cos(self.robot.thr + self.sang[i])))][int(round(self.currenty + self.robot.sonar[0][self.sen[i]].value*math.sin(self.robot.thr + self.sang[i])))] = 1
		#Note: for purposes of simulation, we will ignore the possibility of errors occurring in the above calculation

		#Do we need a new goal cell?
		if (self.mowmap[self.goalx][self.goaly] == 1) or (self.blockmap[self.goalx][self.goaly] == 1):
			(self.goalx, self.goaly) = self.newgoal()
		#At this point, we definitely have an open goal cell. Drive there.
		self.drivetocell(self.goalx, self.goaly)

#This function causes the robot to drive to the new location.
	def drivetocell(self, cellx, celly):
#################### Note: find an existing implementation of a good pathfinding algorithm, like A*?

		#First, figure out where the cell is in pyrobotics' internal coordinate system:
		tempgoalx = (cellx - self.basex) / self.conversionx
		tempgoaly = (celly - self.basey) / self.conversiony

		#Move toward the temporary goal:
		#First, subtract the two coordinates to obtain a displacement vector.
		diffx = tempgoalx - self.robot.x
		diffy = tempgoaly - self.robot.y
		#Compare this vector to the angle of the orientation of the robot.
		goalangle = math.atan2(diffy,diffx)
		if goalangle < 0:
			goalangle = goalangle + 2*math.pi
		goalangle = self.robot.thr-goalangle
		while goalangle >= math.pi or goalangle < -math.pi:
			if goalangle < -math.pi:
				goalangle = goalangle + 2*math.pi
			if goalangle >= math.pi:
				goalangle = goalangle - 2*math.pi
		
		#Depending on where the goal cell is in relation to the robot, turn and adjust speed accordingly
		#This is a relatively simple control scheme, might want something better/more stable/more complicated: 
		m2 = -2*math.sin(goalangle/2)
		m1 = (math.fabs(diffx)+abs(diffy))/((math.fabs(diffx)+abs(diffy))+0.75)
		self.robot.move(m1, m2)
		
#This function defines the algorithm. 
	def newgoal(self):
#################### ALGORITHM TO TEST GOES HERE!!!!!!!!!!!!!#######################################################
		#Placeholder activity (delete this):
		return (60,60)

def INIT(engine):
    return IONBrain('IONBrain', engine)
