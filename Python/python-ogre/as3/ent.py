import ogre.renderer.OGRE as ogre
import ogre.io.OIS as OIS
import SampleFramework as sf
from physics import PhysicsAspect as phys
class MyEntity():
	"""Simple Entity Class"""
	def __init__(self, name, scene, vel = ogre.Vector3(0,0,0), pos = ogre.Vector3(0,0,0), mesh = '', yaw = 0.0, aspects = [], aspectTypes = [] ):
		self.id = name
		self.entityScene = scene
		self.vel = vel
		self.meshname = mesh
		self.yaw = yaw
		self.aspects = aspects
		self.aspectTypes = aspectTypes
		self.entityScene.setPosition(pos)
		aspects.append(phys(self))
	def tick(self, dtime):
		for a in self.aspects:
			a.tick(dtime)
	def __str__(self):
		return "Name: " + str(self.id) + " Position: " + str(self.entityScene.getPosition())