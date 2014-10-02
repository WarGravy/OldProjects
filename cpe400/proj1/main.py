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
	def stopAndGoTrip(self):
		#no more packets to be sent		
		if not self._queue:
			self._flag = True
		#send packet
		elif self.sendPacket(self._queue[0]):
			#send ACK if packet doesn't fail
			self.sendACK(self._queue[0])
		
		
	def isSuccess(self):
		chance = random.randint(0,10)
		if chance < 10 * self._error:
			return False
		else:
			return True

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
		self._ackbox.clear()
		return 0

		
#PACKET CLASS
class packet():
	def __eq__(self, other):
		return self.id == other.id

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
		while not sim._flag:
			#call algorithm function for stop n' go
			sim.stopAndGoTrip()
			sim._flag = True

	#output graph to screen
if __name__ == "__main__": main()
