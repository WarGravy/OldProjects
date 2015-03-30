from vector import MyVector
from physics import PhysicsAspect as phys
class Entity():
	"""Simple Entity Class"""
	def __init__(self, name, vel = MyVector(), pos = MyVector(), mesh = "", yaw = 0.0, aspects = [], aspectTypes = [] ):
		self.id = name
		self.vel = vel
		self.pos = pos
		self.meshname = mesh
		self.yaw = yaw
		self.aspects = aspects
		self.aspectTypes = aspectTypes
		self.aspects.append(phys(self))
	def tick(self, dtime):
		for a in self.aspects:
			a.tick(dtime)
	def __str__(self):
		return "Name: " + str(self.id) + " Position: " + str(self.pos)