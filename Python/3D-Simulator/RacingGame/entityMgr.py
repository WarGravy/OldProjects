#######
#Team Purple Flower
#Producer: Britanny McGarr
#Member: Zachary Carlson
#Member: Sara Garic
#######
# Entity manager. 
#     Create and keep track of all game entities.
import ent
from vector import Vector3
import ogre.renderer.OGRE as ogre


class EntityMgr:
    def __init__(self, engine):
        self.engine = engine
        self.entities = {}
        self.nEnts = 0
        pass

    def init(self):
        self.entTypes = [ent.DRONE,]
        self.aiTypes = [ent.AIEnt, ]
        pass

    def tick(self, dt):
        for i in range(len(self.entities)):
            self.entities[i].tick(dt)

    def stop(self):
        del self.entities
        pass

    #Required to add the entity to the graphix node
    def createGent(self, mid, mmesh, mpos, myaw, isPrimaryPlayer = False):
        sceneManager = self.engine.gfxMgr.sceneManager
        e = sceneManager.createEntity(mid, mmesh)
        fileRoot = mmesh.split('.')
        materialName = fileRoot[0]+".material"
        print mid + 'node'
        print "Above is the scene node created for the entity"
        #check if this is the player node
        if isPrimaryPlayer:
            node = sceneManager.getRootSceneNode().createChildSceneNode('player1node', mpos)
            node.yaw(ogre.Degree(-90).valueRadians())
        else:
            node = sceneManager.getRootSceneNode().createChildSceneNode(mid + 'node', mpos)
        
        node.attachObject(e)
        return node

    def createEnt(self, entType, pos = Vector3(0,0,0), yaw = 0, isAI = False, isPrimaryPlayer = False ):
        ai = isAI
        ent = entType(len(self.entities) + 1, pos = pos, yaw = yaw, isAI= ai)
        self.entities[self.nEnts] = ent
        self.nEnts += 1
        #Sushil Louis' Code: Add entity to a node
        gfxNode = self.createGent(ent.uiname + str(ent.eid), ent.mesh, ent.pos, ent.heading, isPrimaryPlayer)
        ent.node = gfxNode
        return ent

    def createWaypoint(self, id, pos = Vector3(0,0,0), heading = 0):
        wp = ent.WayPoint(id, pos = pos, heading = heading)
        sceneManager = self.engine.gfxMgr.sceneManager
        e = sceneManager.createEntity(wp.eid, wp.mesh)
        node = sceneManager.getRootSceneNode().createChildSceneNode(wp.eid + 'node', wp.pos)
        node.attachObject(e)
        wp.node = node
        wp.node.scale(.75, .75, .05) # Change size
        wp.node.yaw(heading) # Change direction
        return wp

    def createApartment(self, id, pos = Vector3(0, 0, 0), heading = 0):
        apartment = ent.Apartment(id, pos = pos, heading = heading)
        sceneManager = self.engine.gfxMgr.sceneManager
        entity = sceneManager.createEntity(apartment.eid, apartment.mesh)
        node = sceneManager.getRootSceneNode().createChildSceneNode(apartment.eid + 'node', apartment.pos)
        node.attachObject(entity)
        apartment.node = node
        apartment.node.scale(3, 5, 5)
        apartment.node.yaw(heading)
        apartment.node.roll(ogre.Degree(90))
        return apartment

    def createHighrise(self, id, pos = Vector3(0, 0, 0), heading = 0):
        apartment = ent.Highrise(id, pos = pos, heading = heading)
        sceneManager = self.engine.gfxMgr.sceneManager
        entity = sceneManager.createEntity(apartment.eid, apartment.mesh)
        node = sceneManager.getRootSceneNode().createChildSceneNode(apartment.eid + 'node', apartment.pos)
        node.attachObject(entity)
        apartment.node = node
        apartment.node.scale(20, 20, 20)
        apartment.node.yaw(heading)
        return apartment