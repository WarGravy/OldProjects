#!/usr/bin/python3

#Zachary Carlson
#CPE 400 Project 1
import random
#classes
class simulation():
	def __init__(self, errorRate):
		#MEMBERS		
		self._flag = False #this is the flag that indicates that all packets have been sent
		self._timer = 0;
		self._rtt = random.randint(10,50) #random 10-50ms
		self._timeout = 45; #ms
		self._error = errorRate
		#SENDER
		self._ackbox = []
		self._queue = []
		i = 0
		while(i < 100):
			tempPacket = packet(i)
			self._queue.append(tempPacket)
			i += 1
		#RECEIVER
		self._inbox = []

	#FUNCTIONS
	def stopAndGoTrip():
		if sendPacket():
			#if packet is not in inbox
				#copy a packet into inbox
			#send ACK
			if sendACK():
				#place an ack in the ackbox
		else if self._queue.count == 0:
			self._flag = True
		
	def isSuccess():
		chance = random.randint(0,10)
		if chance < 10 * self._error:
			return False
		else:
			return True
	#RECEIVER
	def sendACK():
		return isSuccess()
	#SENDER
	def sendPacket():
		cleanAckBox()
		return isSucess

	def cleanAckBox():
		return False


				

#RECEIVER CLASS
class receiver():
	def __init__(self):
		self._inbox = []

	def sendACK(p):
		chance = random.randint(0,10)
		if chance < 10 * self._error:
			return False
		else:
			return True
		
#PACKET CLASS
class packet():
	def __init__(self, packid):
		#generate 24 random binary int32 to simulate 100bytes 
		#(24 random ints * 32bit + One int id (32bit) = 100bytes) 
		self.data = []
		i = 0
		while i < 24:
			self.data.append(random.randint(0,65535))
			i += 1
		self.id = packid
#MAIN
def main():	
	#initialize simulations for Stop and Wait
	simulations = [simulation(0.0),simulation(0.1),simulation(0.2),simulation(0.3),simulation(0.4),simulation(0.5)]
	#while there are still packets to be sent
	for sim in simulations:
		while sim._flag == False:
			#call algorithm function for stop n go
			sim._flag = True

	#output graph to screen
if __name__ == "__main__": main()
