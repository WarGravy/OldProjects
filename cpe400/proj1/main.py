#!/usr/bin/python3

#Zachary Carlson
#CPE 400 Project 1
import random
#classes
class mailbox():
	def __init__(self, queueFlag = False):
		self._flag = False #this is the flag that indicates there is mail
		self._inbox = []
		self._queue = []
		if queueFlag: #generate 100 packets of 100bytes each
			i = 0
			while(i < 100):
				tempPacket = packet(i)
				self._queue.append(tempPacket)
				i += 1
class packet():
	def __init__(self, packid):
		#generate 24 random binary int32 to simulate 100bytes 
		#(32bit * 24 + One 23bit id = 100bytes) 
		self.data = []
		i = 0
		while i < 24:
			self.data.append(random.randrange(10))
			i += 1
		self.id = packid
#main
def main():	
	#initialize mailbox
	Server = mailbox(False)
	Client = mailbox(True)
	for p in Client._queue:
		print('{} ID:{}'.format(p.data, p.id))
	#initialize 100byte example packets

	#fork into two processes
	
	#child process, call client function
	
	#parent process, call server function -> ouput terminal w/ graph and file
	
#functions
def IsEven(n):
	if n % 2 == 0:
		return True
	else:
		return False

def IsPrime(n):
	if n == 1: return False
	for x in range(2, n):
		if n % x == 0: return False
	else:
		return True

def CountToNextPrime(n = 1):
	while(True):
		if IsPrime(n): yield n
		n+=1
if __name__ == "__main__": main()
