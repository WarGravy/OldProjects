import math

class MyVector():
	"""Simple Vector Class"""
	def __init__(self, x = 0.0, y = 0.0, z = 0.0 ):
		self.x = x
		self.y = y
		self.z = z
		self.length = self.getMagnitude()
	def getMagnitude(self):
		return math.sqrt((self.x*self.x) + (self.y*self.y) + (self.z*self.z))
	def __mul__(self, k):
		return MyVector(self.x * k, self.y * k, self.z * k)
	def __rmul__(self, k):
		return MyVector(self.x * k, self.y * k, self.z * k)
	def __div__(self, k):
		return MyVector(self.x / k, self.y / k, self.z / k)
	def __rdiv__(self, k):
		return MyVector(self.x / k, self.y / k, self.z / k)
	def __add__(self, vect):
		return MyVector(self.x + vect.x, self.y + vect.y, self.z + vect.z)
	def __radd__(self, vect):
		return MyVector(self.x + vect.x, self.y + vect.y, self.z + vect.z)
	def __sub__(self, vect):
		return MyVector(self.x - vect.x, self.y - vect.y, self.z - vect.z)
	def __rsub__(self, vect):
		return MyVector(self.x - vect.x, self.y - vect.y, self.z - vect.z)
	def __str__(self):
		return "( " + str(self.x) + ", " + str(self.y) + ", " + str(self.z) + " )"
