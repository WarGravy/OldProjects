#######
#Team Purple Flower
#Producer: Britanny McGarr
#Member: Zachary Carlson
#Member: Sara Garic
#######
from vector import Vector3
import ogre.renderer.OGRE as ogre
import utils
from pygame import mixer


class GameMgr:
    def __init__(self, engine):
        self.engine = engine
        self.secondLevel = False
        self.player = 0
        self.states = ["Menu Screen", "Playing", "Stopped"]
        self.levels = ["WaterLevel", "CityLevel"]
        self.waypoints = []
        self.features = []
        self.completed = 0
        self.falsePositive = True
        self.player = 0
        self.levelRange = 0
        self.outOfBounds = False
        self.gameFinished = False
        self.loadWaypoints = False
        print "starting Game mgr"
        pass

    def init(self):
        self.loadWaterLevel()
        self.currentLevel = self.levels[0]
        self.currentState = self.states[0]

    def loadWaterLevel(self):
        #Level Range
        self.levelRange = 2000
        x = 0
        #Create Primary Player Entity
        entType = self.engine.entityMgr.entTypes[0]
        ent = self.engine.entityMgr.createEnt(entType, pos = Vector3(x, 0, 0), isPrimaryPlayer = True)
        self.player = ent
        self.player.place = 0
        x += 300

        # Scene node change for skybox and ground plane
        self.engine.gfxMgr.sceneManager.setSkyDome(True, "Examples/MountainSkyBox", 5, 8)
        plane = ogre.Plane((0, 1, 0), 0)
        meshManager = ogre.MeshManager.getSingleton()
        self.plane = meshManager.createPlane('Ground', 'General', plane,
                                     10000, 10000, 20, 20, True, 1, 5, 5, (0, 0, 1))
        ent = self.engine.gfxMgr.sceneManager.getEntity("GroundEntity")
        ent.setMaterialName("OceanCg")
        ent.castShadows = False
        self.loadWaterWaypoints()
        pass
        
    def loadWaterWaypoints(self):
        #Create AI Entities
        if self.loadWaypoints == True:
            #Create Waypoints
            del self.waypoints[:]
            # Sara Changed from getting the pos of wp to just getting wp. Had to add in .pos where needed including in aiMgr.py and goalbasedai.py and below
            self.waypoints = []
            self.waypoints.append(self.engine.entityMgr.createWaypoint('1', pos = Vector3(700, 100, 0), heading = ogre.Degree(90)))
            self.waypoints.append(self.engine.entityMgr.createWaypoint('2', pos = Vector3(1300, 300, -400), heading = 0))
            self.waypoints.append(self.engine.entityMgr.createWaypoint('3', pos = Vector3(1000, 400, -800), heading = 80))
            self.waypoints.append(self.engine.entityMgr.createWaypoint('4', pos = Vector3(-700, 200, -800), heading = ogre.Degree(270)))
            self.waypoints.append(self.engine.entityMgr.createWaypoint('5', pos = Vector3(-1000, 200, -1000), heading = ogre.Degree(180)))
            self.waypoints.append(self.engine.entityMgr.createWaypoint('6', pos = Vector3(-1500, 0, -800), heading = 0))
            self.waypoints.append(self.engine.entityMgr.createWaypoint('7', pos = Vector3(-1500, 0, 0), heading = 0))

            # show bounding box on first wp
            self.waypoints[0].node.showBoundingBox(True)
        pass

    def loadCityLevel(self):
        # Level Range
        self.levelRange = 5000

        # Set the player entity at the start of the level (Center map)
        self.player.place = 0
        self.player.pos = Vector3(0, 0, 0)
        self.player.speed = 0

        # Reset the sky dome and ground plane
        self.engine.gfxMgr.sceneManager.setSkyDome(True, "Examples/CitySkyBox", 5, 8)
        plane = ogre.Plane((0, 1, 0), 0)
        meshManager = ogre.MeshManager.getSingleton()
        self.plane = meshManager.createPlane('Ground', 'General', plane,
                                     10000, 10000, 20, 20, True, 1, 5, 5, (0, 0, 1))
        ent = self.engine.gfxMgr.sceneManager.getEntity("GroundEntity")
        ent.setMaterialName("Examples/Dirt")
        ent.castShadows = False
        if self.loadWaypoints == True:
            #clear waypoint list
            del self.waypoints[:]
            # Move the Waypoints (Move as demanded when level will load)
            self.waypoints = []
            self.waypoints.append(self.engine.entityMgr.createWaypoint('8', pos = Vector3(700, 100, 0), heading = ogre.Degree(90)))
            self.waypoints.append(self.engine.entityMgr.createWaypoint('9', pos = Vector3(1300, 300, 250), heading = ogre.Degree(90)))
            self.waypoints.append(self.engine.entityMgr.createWaypoint('10', pos = Vector3(1800, 200, 250), heading = 80))
            self.waypoints.append(self.engine.entityMgr.createWaypoint('11', pos = Vector3(2300, 300, -100), heading = 0))
            self.waypoints.append(self.engine.entityMgr.createWaypoint('12', pos = Vector3(1500, 250, -700), heading = ogre.Degree(90)))
            self.waypoints.append(self.engine.entityMgr.createWaypoint('13', pos = Vector3(700, 200, -900), heading = ogre.Degree(90)))
            self.waypoints.append(self.engine.entityMgr.createWaypoint('14', pos = Vector3(0, 150, -1200), heading = ogre.Degree(90)))
            # show bounding box on first wp
            self.waypoints[0].node.showBoundingBox(True)

            # Create features and populate
            self.features = []
            self.features.append(self.engine.entityMgr.createApartment('Apt1', pos = Vector3(1500, 50, 0), heading = 0))
            self.features.append(self.engine.entityMgr.createApartment('Apt2', pos = Vector3(1500, 50, 700), heading = 0))
            self.features.append(self.engine.entityMgr.createApartment('Apt3', pos = Vector3(100, 50, -700), heading = 0))
            self.features.append(self.engine.entityMgr.createApartment('Apt4', pos = Vector3(-700, 20, 300), heading = 0))
            self.features.append(self.engine.entityMgr.createApartment('Apt5', pos = Vector3(2500, 50, 0), heading = 0))
            self.features.append(self.engine.entityMgr.createApartment('Apt6', pos = Vector3(2000, 50, 500), heading = 0))
            self.features.append(self.engine.entityMgr.createApartment('Apt7', pos = Vector3(-1500, 50, -1700), heading = ogre.Degree(90)))
            self.features.append(self.engine.entityMgr.createApartment('Apt8', pos = Vector3(-800, 50, -800), heading = 0))
            self.features.append(self.engine.entityMgr.createApartment('Apt9', pos = Vector3(2500, 50, -1500), heading = 0))
            self.features.append(self.engine.entityMgr.createApartment('AptA', pos = Vector3(1500, 50, -400), heading = 0))
            self.features.append(self.engine.entityMgr.createHighrise('HR1', pos = Vector3(1500, 200, -200), heading = 0))
            self.features.append(self.engine.entityMgr.createHighrise('HR2', pos = Vector3(1500, 100, 500), heading = 0))
            self.features.append(self.engine.entityMgr.createHighrise('HR3', pos = Vector3(1000, 100, 0), heading = 0))
            self.features.append(self.engine.entityMgr.createHighrise('HR4', pos = Vector3(2500, 400, 500), heading = 0))
            self.features.append(self.engine.entityMgr.createHighrise('HR5', pos = Vector3(-1500, 200, -200), heading = 0))
            self.features.append(self.engine.entityMgr.createHighrise('HR6', pos = Vector3(-500, 100, 500), heading = 0))
            self.features.append(self.engine.entityMgr.createHighrise('HR7', pos = Vector3(1000, 600, -400), heading = 0))
            self.features.append(self.engine.entityMgr.createHighrise('HR8', pos = Vector3(2500, 400, -1000), heading = ogre.Degree(90)))

    def startGame(self):
        print "Game Started"
        self.currentState = self.states[1]
        if self.secondLevel == True:
            self.loadCityLevel()
        else:
            self.loadWaterWaypoints()
        #Select Player
        self.engine.selectionMgr.selectPlayer()
        #set the camera to behind the player
        self.engine.gfxMgr.setPlayerCamera()
        #this is for camera controls
        self.engine.inputMgr.updateCamNode()
        self.engine.inputMgr.camNode.yaw(ogre.Degree(-45).valueRadians())
        #Turn on AI Management
        self.engine.aiMgr.start()
        self.engine.aiMgr.go = True
        self.start = True
        #Countdown Sequence
        self.startRace()
        pass

    def startRace(self):
        self.gameFinished = False

        for e in self.engine.aiMgr.entities:
            e.score = 0

    def calcRangeError(self, dist):
        severity = (dist - self.levelRange) / 4 #400 = 100% severity
        if severity < 30:
            self.outOfBounds = True
        elif severity < 70:
            self.outOfBounds = True
        elif severity > 99:
            print "Reseting Player to ORIGIN"
            self.player.pos = Vector3(0,0,0)
            self.player.speed = 0
            self.outOfBounds = False

    def tick(self, dt):
        if self.currentState == self.states[1]:
            #Check if leader finished the race!
            if self.gameFinished == False and self.engine.aiMgr.order["1"].score == len(self.waypoints):
                self.gameFinished = True
                if self.player.place == 1:
                    print "Congratulations! You won!"
                    self.currentLevel = self.levels[1]
                else:
                    print "Your Place: ",
                    print self.player.place
            #Out of Range Mechanics
            distFromOrigin = max(abs(self.player.pos.x), abs(self.player.pos.y))
            distFromOrigin = max(distFromOrigin, abs(self.player.pos.z))
            if distFromOrigin > self.levelRange:
                self.calcRangeError(distFromOrigin)
            else:
                self.outOfBounds = False
            #Checkpoint/Flag Completion
            if self.completed > len(self.waypoints) - 1:
                print "GAME OVER"
                self.stop()
                self.engine.aiMgr.go = False
            else:
                dist = utils.getDistance(self.player.pos, self.waypoints[self.completed].pos)
                if dist < 50:
                    # Play collection sound
                    collectionSound = mixer.Sound("data/music/collection.wav")
                    mixer.Sound.play(collectionSound)

                    #Turn off bounding box for passed goal
                    self.waypoints[self.completed].node.showBoundingBox(False)
                    self.player.score += 1 #Increment the player score for the ai Manager
                    self.completed = self.completed + 1
                    #Turn on bounding box for next goal
                    if self.completed < len(self.waypoints):
                        self.waypoints[self.completed].node.showBoundingBox(True)
        pass

    def stop(self):
        self.currentState = self.states[2]
        pass
        

