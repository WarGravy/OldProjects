#######
#Team Purple Flower
#Producer: Britanny McGarr
#Member: Zachary Carlson
#Member: Sara Garic
#######
# AI manager.
#    Manages all of the AI entities in the world
import ogre.renderer.OGRE as ogre
import ogre.io.OIS as OIS
import platform
import utils
from vector import Vector3

class AiMgr():
    def __init__(self, engine):
        self.engine = engine
        self.entities = []
        self.order = {}
        self.players = engine.selectionMgr.getSelected()
        print "AI"
        print len(self.players)
        self.ai = []
        self.go = False


    def init(self):
        aiType = self.engine.entityMgr.aiTypes[0]
        ai = self.engine.entityMgr.createEnt(aiType, pos = Vector3(-100, 0, -20), isAI = True)
        self.ai.append(ai)
        pass

    def start(self):
        self.go = True
        self.players = self.engine.selectionMgr.getSelected()
        for i in range(0, len(self.ai)):
            for wp in self.engine.gameMgr.waypoints:
                self.ai[i].goals.append(wp)
        self.entities.extend(self.ai)
        self.entities.extend(self.players)
        self.initializeOrder()

    def initializeOrder(self):
        #Set First place
        self.players[0].place = 1
        self.order["1"] = self.players[0] 
        #Set Second Place
        self.ai[0].place = 2
        self.order["2"] = self.ai[0]

    def tick(self, dt):
        if self.go == True:
            self.checkForCollisions()
            self.setPlaces(self.engine.gameMgr.waypoints)
    def stop(self):
        self.go = False
        pass

    def checkForCollisions(self):
        for i in range(len(self.entities)):
            entBoundingBox = self.entities[i].node._getWorldAABB()
            for j in range(len(self.entities)):
                if i != j:
                    hit = entBoundingBox.intersects( self.entities[j].node._getWorldAABB() )
                    if hit:
                        #Bounce mechanics
                        self.entities[i].pos = self.entities[i].pos + ((self.entities[i].pos - self.entities[j].pos) / 4 )
                        self.entities[j].pos = self.entities[j].pos + ((self.entities[j].pos - self.entities[i].pos) / 4 )
                        #Fix position to keep from bouncing too low or too high.
                        if self.entities[i].pos.y < 10:
                            self.entities[i].pos.y = 11
                        if self.entities[i].pos.y > 900:
                            self.entities[i].pos.y = 899
                        if self.entities[j].pos.y < 10:
                            self.entities[j].pos.y = 11
                        if self.entities[j].pos.y > 900:
                            self.entities[j].pos.y = 899
                        # Slow down
                        self.entities[i].speed -= 10 
                        self.entities[j].speed -= 10

    def setPlaces(self, waypoints):
        i = 1
        while i <= len(self.order):
            pivot = str(i)
            neighbor = str(i+1)
            #check if there is a right neighbor and distance is calculable
            if i + 1 <= len(self.order) and self.order[pivot].score < len(waypoints) and self.order[neighbor].score < len(waypoints):
                #see if right neighbor surpassed i in the placement
                pivotDist = utils.getDistance(self.order[pivot].pos, waypoints[self.order[pivot].score].pos)
                neighborDist = utils.getDistance(self.order[neighbor].pos, waypoints[self.order[neighbor].score].pos)
                if (self.order[pivot].score < self.order[neighbor].score) or (self.order[pivot].score == self.order[neighbor].score and neighborDist < pivotDist):
                    #swap 
                    ent = self.order[pivot]
                    self.order[pivot] = self.order[neighbor]
                    self.order[pivot].place = i
                    self.order[neighbor] = ent
                    self.order[neighbor].place = i+1
                    #decrement i to see if the right neighbor surpassed anyone else -2
                    i -= 2
                    if i < 1:
                        i = 1
            i += 1

        # adjust ai max speed
        if self.ai[0].place > 1:
            self.ai[0].maxSpeed += 1
        else:
            self.ai[0].maxSpeed -= 1
        # cap off max speed
        if self.ai[0].maxSpeed > 250:
            self.ai[0].maxSpeed = 250
        elif self.ai[0].maxSpeed < 150:
            self.ai[0].maxSpeed = 150
