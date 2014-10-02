#!/usr/bin/python3

#Zachary Carlson
#CPE 400 Project 1
import random
#classes
class simulation():
	def __init__(self, errorRate):
		self._flag = False #this is the flag that indicates that all packets have been sent
		self._sendHandshake = False
		self._recHandshake = False
		self._inbox = [] #where the receiver looks for packets
		self._ackbox = [] #where the sender receives acknowledgements
		self._queue = [] #where the packets that need to be sent live 
		self._timer = 0;
		self._rtt = random.randint(10,50) #random 10-50ms
		self._timeout = 45; #ms
		self._error = errorRate
		i = 0
		while(i < 100):
			tempPacket = packet(i)
			self._queue.append(tempPacket)
			i += 1

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
#main
def main():	
	#initialize simulations for Stop and Wait
	simulations = [simulation(0.0),simulation(0.1),simulation(0.2),simulation(0.3),simulation(0.4),simulation(0.5)]
	#while there are still packets to be sent
	for sim in simulations:
		while sim._flag == False:
			#call algorithm function for stop n go
			stopAndWait(sim)
			sim._flag = True

	#output graph to screen
	
#functions
def stopAndWait(sim):
	sender(sim)
	receiver(sim)

def sender(sim):
	print('a')

def receiver(sim):
	print('b')


if __name__ == "__main__": main()
