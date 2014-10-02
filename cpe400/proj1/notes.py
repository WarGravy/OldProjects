#!/usr/bin/python3

#Zachary Carlson
#CPE 400 Project 1

#classes
class mailbox():
	def __init__(self, flaga, flagb):
		self.flagA = flaga
		self.flagB = flagb
		self.flag_Sender = True
		self.flag_Receiver = True
#main
def main():	
	print("START")
	l = [ 1, 2, 3, 4 ]
	textfile = 'test.txt'
	for i in CountToNextPrime():
		if i > 100: break
		print(i)

	try:
		fh = open(textfile)
		for f in fh.readlines():
			print(f, end ="")
	except:
		print('failed to open file {}'.format(textfile))

	mb = mailbox(True, True)
	if mb.flagA:
		print('FLAG A')
	if mb.flagB:
		print('FLAG B')
	if mb.flag_Sender:
		print('FLAG Sender')
	if mb.flag_Receiver:
		print('FLAG Receiver')

	mb.number = 3
	print(mb.number)
	i = id(mb.number)
	print(i)

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
