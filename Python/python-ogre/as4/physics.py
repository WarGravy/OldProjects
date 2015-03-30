import math

class Physics:
    def __init__(self, ent):
        self.ent = ent
  
    def tick(self, dtime, sceneManager):
    	if self.ent.desiredHeading > 360:
    		self.ent.desiredHeading -= 360
        #AS4 Advanced Physics and Orientation: speed, heading, desiredHeading, desiredSpeed, acceleration, turningRate
        if self.ent.heading > self.ent.desiredHeading:
            self.ent.heading -= self.ent.turningRate
        elif self.ent.heading < self.ent.desiredHeading:
            self.ent.heading += self.ent.turningRate
           #update with current heading
        rads = math.radians(self.ent.heading)
        #Move to the desired heading if possible
        #Accelerate to the appropriate speed
        if self.ent.desiredSpeed > self.ent.maxSpeed:
            self.ent.desiredSpeed = self.ent.maxSpeed
        if self.ent.speed > self.ent.desiredSpeed:
            self.ent.speed -= self.ent.acceleration
        elif self.ent.speed < self.ent.desiredSpeed:
            self.ent.speed += self.ent.acceleration
        if self.ent.speed > self.ent.maxSpeed:
            self.ent.speed = self.ent.maxSpeed
        #update velocity
        self.ent.vel.x = math.cos(rads) * self.ent.speed
        self.ent.vel.z = math.sin(rads) * self.ent.speed
        #AS3 Basic Physics
        self.ent.pos = self.ent.pos + (self.ent.vel * dtime)

class Renderable:
    def __init__(self, ent):
        self.ent = ent
        
    def tick(self, dtime, sceneManager):
        node = sceneManager.getSceneNode( str(self.ent.id) + 'node')
        node.position = self.ent.pos
        #node.setDirection(self.ent.vel)
        print self.ent.heading
        print self.ent.desiredHeading
        if self.ent.heading > self.ent.desiredHeading + 1 or self.ent.heading < self.ent.desiredHeading - 1:
            node.yaw(math.radians(self.ent.heading))
