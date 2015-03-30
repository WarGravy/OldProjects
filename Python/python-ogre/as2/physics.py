class PhysicsAspect():
	"""Simple Physics Aspect"""
	def __init__(self, other):
		self.ent = other

	def tick(self, dtime):
		self.ent.pos = self.ent.pos + self.ent.vel * dtime
		pass