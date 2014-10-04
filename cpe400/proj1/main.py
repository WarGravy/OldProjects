#!/usr/bin/python

#Zachary Carlson
#CPE 400 Project 1
import random
import os
import matplotlib.pyplot as plt

#SIMULATOR CLASS
class simulation():
	def __init__(self, errorRate, windowSize = 1):
		#TOTALS
		self._totalThroughput = 0
		self._cycles = 0
		#MEMBERS		
		self._flag = False #this is the flag that indicates that all packets have been sent
		self._timer = 0;
		self._timeout = 45; #ms
		self._error = errorRate
		self._winSize = windowSize #USED FOR Go-Back-N and Selective Repeat
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

	#SELECTIVE REPEAT
	def selectiveRepeat(self):
		#no more packets to be sent		
		if not self._queue:
			self._totalThroughput = self._timer
			self._flag = True
			return self._flag
		#send packets within the window size
		i = 1
		sequenceNumber = 0
		for n in list(range(self._winSize)):
			try:
				if self.sendPacket(self._queue[sequenceNumber]):
					#send ACK if packet doesn't fail
					if not self.sendACK(self._queue[sequenceNumber]): i-=1#it failed- wait the entire rtt
				else: i -= 1 #it failed- wait the entire rtt
				i+=1
				self._cycles += 1
			except:
				break
			sequenceNumber += 1
		#All packets were successful
		if i > self._winSize or not self._queue:
			self._timer += random.randint(10,50)
		#A packet was lost
		else:
			self._timer += self._timeout
		return self._flag

	#GO BACK N
	def goBackNTrip(self):
		#no more packets to be sent		
		if not self._queue:
			self._totalThroughput = self._timer
			self._flag = True
			return self._flag
		#send packets within the window size
		i = 1
		for n in list(range(self._winSize)):
			if self._queue:
				if self.sendPacket(self._queue[0]):
					#send ACK if packet doesn't fail
					if not self.sendACK(self._queue[0]):
						#it failed- wait the entire rtt
						#ignore the rest of the packets sent we failed on ack
						break
				else:
					#it failed- wait the entire rtt
					#ignore the rest of the packets because we failed
					break
				i+=1
				self._cycles += 1
		#All packets were successful
		if i > self._winSize or not self._queue:
			self._timer += random.randint(10,50)
		#A packet was lost
		else:
			self._timer += self._timeout
		return self._flag

	#STOP AND GO
	def stopAndGoTrip(self):
		self._cycles += 1
		#no more packets to be sent		
		if not self._queue:
			self._totalThroughput = self._timer
			self._flag = True
		#send packet
		elif self.sendPacket(self._queue[0]):
			#send ACK if packet doesn't fail (timer is handled inside ack
			if self.sendACK(self._queue[0]):
				#it was a success so our rtt is a random value between 10 and 50.
				self._timer += random.randint(10,50)
			else:
				#it failed so we wait the entire rtt
				self._timer += self._timeout
		else:
			#it failed so we wait the entire timeout period
			self._timer += self._timeout

	#RECEIVER
	def sendACK(self, p):
		if self.isSuccess():
			#place an ack in the ackbox
			self._ackbox.append(p)
			return True
		return False

	#SENDER
	def sendPacket(self, p):
		self.cleanAckBox() #clean up queue based on the Acks in the ackbox
		if not self._queue:
			return False
		if self.isSuccess():
			#if packet is not in inbox
			if not filter(lambda x: x.sequenceNumber == p.sequenceNumber, self._inbox):
				#copy a packet into inbox
				self._inbox.append(p)
			return True
		return False

	#RANDOM CHANCE OF FAILURE
	def isSuccess(self):
		chance = random.randint(0,10)
		if chance < 10 * self._error:
			return False
		else:
			return True

	#Packet and Ack MAINTENANCE
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
		return self.sequenceNumber == other.sequenceNumber

	def __init__(self, packid):
		#generate 24 random binary int32 to simulate 100bytes 
		#(96 random bytes + a single 32 bit int id = 100bytes) 
		self.data = []
		i = 0
		while i < 24:
			self.data.append(os.urandom(96))
			i += 1
		self.sequenceNumber = packid * 100#the sequence number increases with the size of the packets
#MAIN
def main():	
	#Number of simulation loops
	loopcount = 50
	totalSims = 5

	#Stop and Go Procedure
	print('Running simulation 1 of {}...'.format(totalSims))
	simulate(loopcount, 'stop-and-go', 1)

	#Go Back N with varying Error Rates	
	print('Running simulation 2 of {}...'.format(totalSims))
	simulate(loopcount, 'gbn-error-rate', 2)
	
	#Go Back N with varying Window Sizes
	print('Running simulation 3 of {}...'.format(totalSims))	
	simulate(loopcount, 'gbn-win-size', 3)
	
	#Selective Repeat with varying Error Rates	
	print('Running simulation 4 of {}...'.format(totalSims))
	simulate(loopcount, 'sr-error-rate', 4)
	
	#Selective Repeat with varying Window Sizes
	print('Running simulation 5 of {}...'.format(totalSims))	
	simulate(loopcount, 'sr-win-size', 5)

	print('Finished simulation.')
	print('Closing all figures will end the program...')
	#show all figures
	plt.show()

#Simulator
def simulate(loopnum, simType, fignum = 1):
	maxRange = 0
	minRange = 0
	startX = -0.1
	endX = 0.6
	xLabel = 'Error Rate'
	title = ' '
	xAxis = []
	yAxis = []
	for n in list(range(loopnum)):
		#initialize simulations
		simulations = []
		#initialize by sim type
		if simType == 'stop-and-go':
			simulations = [simulation(0.0),simulation(0.1),simulation(0.2),simulation(0.3),simulation(0.4),simulation(0.5)]
			title = 'Stop and Go Comparison: {} simulations per Error Rate'.format(loopnum)
		
		elif simType == 'gbn-error-rate':
			title = 'Go-Back-N Comparison: {} simulations per Error Rate; Window Size of 4'.format(loopnum)
			simulations = [simulation(0.0, 4), simulation(0.1, 4), simulation(0.2, 4), simulation(0.3, 4), simulation(0.4, 4), simulation(0.5, 4)]
				
		elif simType == 'gbn-win-size':
			simulations = [simulation(0.2, 4),simulation(0.2, 8),simulation(0.2, 12),simulation(0.2, 16)]
			title = 'Go-Back-N Comparison: {} simulations per Window Size; Error Rate of 0.2'.format(loopnum)
			xLabel = 'Window Size'
			startX = 0
			endX = 20
		
		elif simType == 'sr-error-rate':
			title = 'Selective Repeat Comparison: {} simulations per Error Rate; Window Size of 4'.format(loopnum)
			simulations = [simulation(0.0, 4), simulation(0.1, 4), simulation(0.2, 4), simulation(0.3, 4), simulation(0.4, 4), simulation(0.5, 4)]
				
		elif simType == 'sr-win-size':
			simulations = [simulation(0.2, 4),simulation(0.2, 8),simulation(0.2, 12),simulation(0.2, 16)]
			title = 'Selective Repeat Comparison: {} simulations per Window Size; Error Rate of 0.2'.format(loopnum)
			xLabel = 'Window Size'
			startX = 0
			endX = 20

		#while there are still packets to be sent
		for sim in simulations:
			while not sim._flag:
				#Call Appropriate Algorithm
				if simType == 'stop-and-go': sim.stopAndGoTrip()
				elif simType == 'gbn-error-rate' or simType == 'gbn-win-size': sim.goBackNTrip()
				elif simType == 'sr-error-rate' or simType == 'sr-win-size': sim.selectiveRepeat()
				else: sim._flag = False#break loop if incorrect simType
			
			#update max
			if maxRange < sim._totalThroughput:
				maxRange = sim._totalThroughput
			#update min
			if minRange == 0 or minRange > sim._totalThroughput:
				minRange = sim._totalThroughput
			
			#add point to the list.
			if simType == 'stop-and-go' or simType == 'gbn-error-rate' or simType == 'sr-error-rate':
				xAxis.append(sim._error)
				yAxis.append(sim._totalThroughput)
			
			elif simType == 'gbn-win-size' or simType == 'sr-win-size':
				xAxis.append(sim._winSize)
				yAxis.append(sim._totalThroughput)

	#output graph to screen
	plt.figure(fignum)
	plt.plot(xAxis, yAxis, 'ro')
	maxRange += 1000
	minRange -= 1000
	plt.axis([startX, endX, minRange, maxRange])
	plt.ylabel('Throughput Time in ms')
	plt.xlabel(xLabel)
	plt.title(title)

if __name__ == "__main__": main()
