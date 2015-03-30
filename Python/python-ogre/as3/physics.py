class PhysicsAspect():
	"""Simple Physics Aspect"""
	def __init__(self, other):
		self.ent = other

	def tick(self, dtime):
		self.ent.entityScene.setPosition( self.ent.entityScene.getPosition() + self.ent.vel * dtime)