#!/usr/bin/python

#Zachary Carlson
#CPE 400 Project 1
import random
import os
import matplotlib.pyplot as plt
import numpy as np
#SIMULATOR CLASS
class simulation():
	def __init__(self, errorRate):
		#TOTALS
		self._totalThroughput = 0
		#MEMBERS		
		self._flag = False #this is the flag that indicates that all packets have been sent
		self._timer = 0;
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
	def stopAndGoTrip(self):
		#no more packets to be sent		
		if not self._queue:
			self._totalThroughput = self._timer
			self._flag = True
		#send packet
		elif self.sendPacket(self._queue[0]):
			#send ACK if packet doesn't fail
			self.sendACK(self._queue[0])
		else:
			#it failed so we wait the entire timeout period
			self._timer += self._timeout
	
	def isSuccess(self):
		chance = random.randint(0,10)
		if chance < 10 * self._error:
			return False
		else:
			return True

	#RECEIVER
	def sendACK(self, p):
		if self.isSuccess():
			#it was a success so our rtt is a random value between 10 and 50.
			self._timer += random.randint(10,50)
			#place an ack in the ackbox
			self._ackbox.append(p)
			return True
		#it failed so we wait the entire rtt
		self._timer += self._timeout
		return False

	#SENDER
	def sendPacket(self, p):
		self.cleanAckBox() #clean up queue based on the Acks in the ackbox
		if not self._queue:
			return False
		if self.isSuccess():
			#if packet is not in inbox
			if not filter(lambda x: x.id == p.id, self._inbox):
				#copy a packet into inbox
				self._inbox.append(p)
			return True
		return False

	def cleanAckBox(self):
		if not self._ackbox:
			return 0
		#foreach acknowledgement in the ack box
		for ack in self._ackbox:
			#find the corresponding packet in the queue and remove it from the queue
			try:
				self._queue.remove(ack)
			except:
				print('Tried removing a packet that didn\'t exist.')
					
		#clear ackbox
		while self._ackbox:
			self._ackbox.pop()
		return 0

		
#PACKET CLASS
class packet():
	def __eq__(self, other):
		return self.id == other.id

	def __init__(self, packid):
		#generate 24 random binary int32 to simulate 100bytes 
		#(96 random bytes + a single 32 bit int id = 100bytes) 
		self.data = []
		i = 0
		while i < 24:
			self.data.append(os.urandom(96))
			i += 1
		self.id = packid
#MAIN
def main():	
	maxRange = 0
	minRange = 0
	xAxis = []
	yAxis = []
	loopcount = 50
	for n in list(range(loopcount)):
		#initialize simulations for Stop and Wait
		simulations = [simulation(0.0),simulation(0.1),simulation(0.2),simulation(0.3),simulation(0.4),simulation(0.5)]
		#while there are still packets to be sent
		for sim in simulations:
			while not sim._flag:
				#call algorithm function for stop n' go
				sim.stopAndGoTrip()
				#print(sim._timer)
			#update max
			if maxRange < sim._totalThroughput:
				maxRange = sim._totalThroughput
			#update min
			if minRange == 0 or minRange > sim._totalThroughput:
				minRange = sim._totalThroughput
			
			#add point to the list.
			xAxis.append(sim._error)
			yAxis.append(sim._totalThroughput)	

	#output graph to screen
	plt.figure(1)
	plt.plot(xAxis, yAxis, 'ro')
	maxRange += 1000
	minRange -= 1000
	plt.axis([-0.1, 0.6, minRange, maxRange])
	plt.ylabel('Throughput Time in ms')
	plt.xlabel('Error Rate')
	plt.title('Stop and Go Comparison with {} simulations for each Error Rate'.format(loopcount))
	plt.show()
if __name__ == "__main__": main()
