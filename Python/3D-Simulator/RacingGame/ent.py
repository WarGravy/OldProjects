#######
#Team Purple Flower
#Producer: Britanny McGarr
#Member: Zachary Carlson
#Member: Sara Garic
#Last edited by: Sara 4/17 Testing Saving to Git
#######
# Entity class to hold information about entities for 38Engine
# Sushil Louis

from vector import Vector3
from physics import Physics
from render import Renderable
from goalbasedai import AiNavigation


class Entity:
    aspectTypes = [Physics, Renderable]
    
    def __init__(self, id, pos = Vector3(0,100,0), mesh = 'robot.mesh', vel = Vector3(0, 0, 0), yaw = 0, isAI = False):
        self.eid = id
        self.pos = pos
        self.vel = vel
        self.mesh = mesh
        self.yaw = yaw
        self.node = None
        self.deltaSpeed = 5
        self.deltaYaw = 0.8
        self.speed = 0.0
        self.heading = 0.0
        self.isAI = isAI
        self.AI_UP = False
        self.AI_DOWN = False
        self.AI_LEFT = False
        self.AI_RIGHT = False
        self.AI_FORWARD = False
        self.AI_REVERSE = False
        self.aspects = []
        self.goals = []
        self.score = 0
        self.place = 0
        self.initAspects()
        self.uiname = "Basic Entity"

    def initAspects(self):
        for aspType in self.aspectTypes:
            self.aspects.append(aspType(self))
        if self.isAI:
            self.aspects.append(AiNavigation(self))

    def tick(self, dtime):
        for aspect in self.aspects:
            aspect.tick(dtime)

    def __str__(self):
        x = "Entity: %s \nPos: %s, Vel: %s,  mesh = %s\nSpeed: %f, Heading: %f" % (self.eid, str(self.pos), str(self.vel), self.mesh, self.speed, self.heading)
        return x


class DRONE(Entity): # General settings. Other Drone stats can be modified from this.
    def __init__(self, id, pos = Vector3(0,0,0), vel = Vector3(0, 0, 0), yaw = 0, isAI = False):
        Entity.__init__(self, id, pos = pos, vel = vel, yaw = yaw, isAI = isAI)
        self.mesh = 'EnemyFighter.mesh'
        self.uiname = 'DRONE'
        self.acceleration = 80 # Changed by Sara for better drone speed
        self.drift = 2 # Added by Sara. The speed at which an entity slows down after after acceleration (or reverse) key is no longer being pushed.
        self.turningRate = .0002 # Changed by Sara for better drone
        self.climbingSpeed = .009 # Added by Sara. Speed at which drone can go up
        self.maxSpeed = 200 # Changed by Sara for better drone speed
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = 0
        self.height = 0 # Added by Sara. For 3D physics


class AIEnt(Entity):
    def __init__(self, id, pos = Vector3(0,0,0), vel = Vector3(0, 0, 0), yaw = 0, isAI = True):
        Entity.__init__(self, id, pos = pos, vel = vel, yaw = yaw, isAI = isAI)
        self.mesh = 'alienship.mesh'#Zack: When AI is set to true these settings can be randomized
        self.uiname = 'ALIENAI'
        self.acceleration = 80
        self.drift = 2
        self.turningRate = .0002
        self.climbingSpeed = .009
        self.maxSpeed = 180 # Set intro AI speed to less of the player
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = 0
        self.height = 0


class WayPoint(Entity):
    def __init__(self, id, pos = Vector3(0,0,0), vel = Vector3(0, 0, 0), yaw = 0, isAI = True, heading = 0):
        Entity.__init__(self, id, pos = pos, vel = vel, yaw = yaw, isAI = isAI)
        self.mesh = 'cube.mesh'
        self.uiname = 'Waypoint'
        self.acceleration = 0
        self.drift = 0
        self.turningRate = 0
        self.climbingSpeed = 0
        self.maxSpeed = 0
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = heading
        self.height = 0


class Apartment(Entity):
    def __init__(self, id, pos = Vector3(0, 0, 0), vel = Vector3(0, 0, 0), yaw = 0, isAI = False, heading = 0):
        Entity.__init__(self, id, pos = pos, vel = vel, yaw = yaw, isAI = isAI)
        self.mesh = 'tower.mesh'
        self.uiname = 'Apartment'
        self.acceleration = 0
        self.drift = 0
        self.turningRate = 0
        self.climbingSpeed = 0
        self.maxSpeed = 0
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = heading
        self.height = 0


class Highrise(Entity):
    def __init__(self, id, pos = Vector3(0, 0, 0), vel = Vector3(0, 0, 0), yaw = 0, isAI = False, heading = 0):
        Entity.__init__(self, id, pos = pos, vel = vel, yaw = yaw, isAI = isAI)
        self.mesh = 'highriseGlass.mesh'
        self.uiname = 'Highrise'
        self.acceleration = 0
        self.drift = 0
        self.turningRate = 0
        self.climbingSpeed = 0
        self.maxSpeed = 0
        self.desiredSpeed = 0
        self.desiredHeading = 0
        self.speed = 0
        self.heading = heading
        self.height = 0