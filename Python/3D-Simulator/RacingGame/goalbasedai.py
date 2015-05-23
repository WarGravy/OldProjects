#######
#Team Purple Flower
#Producer: Britanny McGarr
#Member: Zachary Carlson
#Member: Sara Garic
#######
# Simple Goal Based Navigation Aspect for AI
import ogre.renderer.OGRE as ogre
from vector import Vector3
import utils
import math

class AiNavigation:
    def __init__(self, ent):
        self.ent = ent
        self.range = 50
        self.finished = False
        self.currentGoal = None

    def nextGoal(self):
        self.ent.goals.pop(0)
        if self.ent.goals == []:
            self.currentGoal = None
            self.finished = True
            #FORCE STOP
            #self.ent.vel = Vector3(0,0,0)
            #self.ent.speed = 0
        else:
            self.currentGoal = self.ent.goals[0].pos

    def setControls(self, dest):
        if dest != None:
            self.ent.AI_FORWARD = True
            direction = dest - self.ent.node.getPosition()
            distance = direction.normalise()
            src = self.ent.node.getOrientation() * ogre.Vector3().UNIT_X
            quat = src.getRotationTo(direction)
            radian = quat.getYaw()
            if radian < ogre.Radian(0):
                self.ent.AI_RIGHT = True
            elif radian > ogre.Radian(0) or radian == ogre.Radian(-0):
                self.ent.AI_LEFT = True
            if dest.y > self.ent.pos.y + 5:
                self.ent.AI_UP = True
            elif dest.y < self.ent.pos.y - 5:
                self.ent.AI_DOWN = True

    def tick(self, dtime):
        self.ent.AI_UP = False
        self.ent.AI_DOWN = False
        self.ent.AI_LEFT = False
        self.ent.AI_RIGHT = False
        self.ent.AI_FORWARD = False
        self.ent.AI_REVERSE = False
        if self.ent.goals:
            self.currentGoal = self.ent.goals[0].pos
        if self.finished == False:
            dist = self.range
            if self.currentGoal != None:
                #get distane from goal
                dist = utils.getDistance(self.ent.pos, self.currentGoal)
                self.setControls(self.currentGoal)
            #if distance is within range, complete goal and move onto the next one
            if dist < self.range:
                self.ent.score += 1 #increment score counter for ai to keep track of the winner and losers
                self.nextGoal()