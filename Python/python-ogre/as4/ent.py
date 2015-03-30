# Entity class 
# Zachary Carlson

#from vector import MyVector
import ogre.renderer.OGRE as ogre
from physics import Physics
from physics import Renderable

class Entity:
    def __init__(self, id, pos = ogre.Vector3(0,0,0), mesh = 'robot.mesh', vel = ogre.Vector3(0, 0, 0), yaw = 0):
        self.id = id
        self.pos = pos
        self.vel = vel
        self.mesh = mesh
        self.yaw = yaw
        self.aspects = []
    	self.aspectTypes = [Physics, Renderable,]
        self.initAspects()
        self.deltaSpeed = 10
        #new additions for as4
        self.speed = 0
        self.heading = 0
        self.desiredHeading = 0 #kept in degrees
        self.desiredSpeed = 0
        self.acceleration = 1 #this is a scalar rate
        self.turningRate = 1#this is a scalar rate for turning
        self.maxSpeed = 100        

    def initAspects(self):
        for aspType in self.aspectTypes:
            self.aspects.append(aspType(self))
        

    def tick(self, dtime, sceneManager):
        #print "Ent tick", str(self.vel)
        for aspect in self.aspects:
            aspect.tick(dtime, sceneManager)


    def __str__(self):
        x = "Entity: %s \nPos: %s, Vel: %s, yaw: %f" % (self.id, str(self.pos), str(self.vel), self.yaw)
        return x

class Sleek(Entity):
    def __init__(self, id, pos = ogre.Vector3(0,0,0), mesh = 'sleek.mesh', vel = ogre.Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, id, pos, mesh, vel, yaw)
        #new additions for as4
        self.acceleration = 15
        self.turningRate = 0.002
        self.maxSpeed = 100

class SailBoat(Entity):
    def __init__(self, id, pos = ogre.Vector3(0,0,0), mesh = 'sailboat.mesh', vel = ogre.Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, id, pos, mesh, vel, yaw)
        #new additions for as4
        self.turningRate = 0.008
        self.maxSpeed = 300

class Missile(Entity):
    def __init__(self, id, pos = ogre.Vector3(0,0,0), mesh = 'missile.mesh', vel = ogre.Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, id, pos, mesh, vel, yaw)
        #new additions for as4
        self.turningRate = 0.007
        self.maxSpeed = 100

class CVN68(Entity):
    def __init__(self, id, pos = ogre.Vector3(0,0,0), mesh = 'cvn68.mesh', vel = ogre.Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, id, pos, mesh, vel, yaw)
        #new additions for as4
        self.turningRate = 0.005
        self.maxSpeed = 100

class DDG51(Entity):
    def __init__(self, id, pos = ogre.Vector3(0,0,0), mesh = 'ddg51.mesh', vel = ogre.Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, id, pos, mesh, vel, yaw)
        #new additions for as4
        self.turningRate = 0.004
        self.acceleration = 40
        self.maxSpeed = 10000

class Cigarette(Entity):
    def __init__(self, id, pos = ogre.Vector3(0,0,0), mesh = 'cigarette.mesh', vel = ogre.Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, id, pos, mesh, vel, yaw)
        #new additions for as4
        self.turningRate = 0.009
        self.maxSpeed = 200

class Monterey(Entity):
    def __init__(self, id, pos = ogre.Vector3(0,0,0), mesh = '3699_Monterey_189_92.mesh', vel = ogre.Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, id, pos, mesh, vel, yaw)
        #new additions for as4
        self.turningRate = 0.007
        self.maxSpeed = 400

class PersonalWaterCR(Entity):
    def __init__(self, id, pos = ogre.Vector3(0,0,0), mesh = '4685_Personal_Watercr.mesh', vel = ogre.Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, id, pos, mesh, vel, yaw)
        #new additions for as4
        self.turningRate = 0.003
        self.maxSpeed = 100

class Boat5086(Entity):
    def __init__(self, id, pos = ogre.Vector3(0,0,0), mesh = '5086_Boat.mesh', vel = ogre.Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, id, pos, mesh, vel, yaw)
        #new additions for as4
        self.turningRate = 0.004
        self.maxSpeed = 100

class Boat(Entity):
    def __init__(self, id, pos = ogre.Vector3(0,0,0), mesh = 'boat.mesh', vel = ogre.Vector3(0, 0, 0), yaw = 0):
        Entity.__init__(self, id, pos, mesh, vel, yaw)
        #new additions for as4
        self.turningRate = 0.005
        self.maxSpeed = 100