# Assignment 4
# by Zachary Carlson

import ogre.renderer.OGRE as ogre
import ogre.io.OIS as OIS
import SampleFramework as sf

import ent as Ship

class EntityMgr():
	"Creates and manages all of the entities in the game"
	def __init__(self, sceneManager, camera):
		self.sceneManager = sceneManager
		self.entities = []
		self.xCamOffSet = 0
		self.yCamOffSet = 50
		self.zCamOffSet = 500
		self.selectedEntityIndex = 0
		self.buildShips(camera)

	def buildShips(self, camera):
		# Setup the first camera node and pitch node and aim it.
		self.createShip(Ship.Sleek(1, pos = ogre.Vector3(0, 0, 0)), camera, True)
		self.createShip(Ship.SailBoat(2, pos = ogre.Vector3(200, 0, 0)), camera)
		self.createShip(Ship.Missile(3, pos = ogre.Vector3(400, 0, 0)), camera)
		self.createShip(Ship.CVN68(4, pos = ogre.Vector3(600, 0, 0)), camera)
		self.createShip(Ship.DDG51(5, pos = ogre.Vector3(800, 0, 0)), camera)
		self.createShip(Ship.Cigarette(6, pos = ogre.Vector3(1000, 0, 0)), camera)
		self.createShip(Ship.Boat(7, pos = ogre.Vector3(1200, 0, 0)), camera)
		self.createShip(Ship.Boat5086(8, pos = ogre.Vector3(1400, 0, 0)), camera)
		self.createShip(Ship.PersonalWaterCR(9, pos = ogre.Vector3(1600, 0, 0)), camera)
		self.createShip(Ship.Monterey(10, pos = ogre.Vector3(1800, 0, 0)), camera)

	def createShip(self, shipEnt, camera, isAttached = False):
		camnode = self.sceneManager.getRootSceneNode().createChildSceneNode('CamNode' + str(shipEnt.id), (shipEnt.pos.x + self.xCamOffSet, shipEnt.pos.y + self.yCamOffSet, shipEnt.pos.z + self.zCamOffSet))
		node = camnode.createChildSceneNode('PitchNode' + str(shipEnt.id))
		if isAttached:
			node.attachObject(camera)#only do this for the first entity
		pEnt    = self.sceneManager.createEntity(str(shipEnt.id), shipEnt.mesh)
		shipEntSceneNode   = self.sceneManager.getRootSceneNode().createChildSceneNode( str(shipEnt.id) + 'node')
		shipEntSceneNode.attachObject(pEnt)
		self.entities.append(shipEnt)

	def nextEntity(self, camera, camNode):
		self.sceneManager.getSceneNode( str(self.entities[self.selectedEntityIndex].id) + 'node').showBoundingBox(False)
		self.selectedEntityIndex = self.selectedEntityIndex + 1;
		#check if pass bounds
		if self.selectedEntityIndex > len(self.entities) - 1:
			self.selectedEntityIndex = 0
		#reference selected ent
		ent = self.entities[self.selectedEntityIndex]
		self.sceneManager.getSceneNode( str(ent.id) + 'node').showBoundingBox(True)
		#change camera
		camera.parentSceneNode.detachObject(camera)
		camNode = self.sceneManager.getSceneNode("CamNode" + str(ent.id))
		camNode.setPosition(ent.pos.x + self.xCamOffSet, ent.pos.y + self.yCamOffSet, ent.pos.z + self.zCamOffSet)
		self.sceneManager.getSceneNode("PitchNode" + str(ent.id)).attachObject(camera)
		pass
	def tick(self, dt, keyboard, delta):
		for ent in self.entities:
			if keyboard.isKeyDown(OIS.KC_Y):
				ent.vel = ogre.Vector3(0,0,0)
			ent.tick(dt, self.sceneManager)
		self.inputForCurrentEntity(keyboard, delta)
	def inputForCurrentEntity(self, keyboard, delta):
		i = self.selectedEntityIndex
		print("Currently Selected on Ship Entity: " + str(i))
		#self.Keyboard.capture() not necessary
		if keyboard.isKeyDown(OIS.KC_NUMPAD8):
			self.entities[i].desiredSpeed -= delta
			#increase forward speed-Z
		if keyboard.isKeyDown(OIS.KC_NUMPAD2):
			self.entities[i].desiredSpeed += delta
			#increase backward speed +z
		if keyboard.isKeyDown(OIS.KC_NUMPAD4):
			self.entities[i].desiredHeading += 0.02
			#turn left
		if keyboard.isKeyDown(OIS.KC_NUMPAD6):
			self.entities[i].desiredHeading -= 0.02
			#turn right
		if keyboard.isKeyDown(OIS.KC_SPACE):
			self.entities[i].vel = ogre.Vector3(0,0,0)
			self.entities[i].desiredSpeed = 0
			self.entities[i].speed = 0
			self.entities[i].desiredHeading = self.entities[i].heading = 0
			#stop movement


class TutorialFrameListener(sf.FrameListener):
    """A FrameListener class that handles basic user input."""
 
    def __init__(self, renderWindow, camera, entityMgr):
        # Subclass any Python-Ogre class and you must call its constructor.
        sf.FrameListener.__init__(self, renderWindow, camera)
 
        #For as3
        self.delta = 1
        self.entMgr = entityMgr

        # Key and mouse state tracking.
        self.toggle = 0
        self.mouseDown = False
 
        # Populate the camera and scene manager containers.
        self.camNode = camera.parentSceneNode.parentSceneNode
        self.sceneManager = self.entMgr.sceneManager
 
        # Set the rotation and movement speed.
        self.rotate = 0.13
        self.move = 250
 
    def frameStarted(self, frameEvent):
        # If the render window has been closed, end the program.
        if(self.renderWindow.isClosed()):
            return False
 
        # Capture and update each input device.
        self.Keyboard.capture()
        self.Mouse.capture()
 
        # Get the current mouse state.
        currMouse = self.Mouse.getMouseState()
 
        # Use the Left mouse button to turn Light1 on and off.         
        if currMouse.buttonDown(OIS.MB_Left) and not self.mouseDown:
            light = self.sceneManager.getLight('Light1')
            light.visible = not light.visible
 
        # Update the mouseDown boolean.            
        self.mouseDown = currMouse.buttonDown(OIS.MB_Left)
 
        # Update the toggle timer.
        if self.toggle >= 0:
            self.toggle -= frameEvent.timeSinceLastFrame
 
        # Swap the camera's viewpoint with the keys 1 or 2.
        if self.toggle < 0 and self.Keyboard.isKeyDown(OIS.KC_TAB):
            # Update the toggle timer.
            self.toggle = 0.1
            # Attach the camera to the next entity pitch node.
            self.entMgr.nextEntity(self.camera, self.camNode)
 
        # Move the camera using keyboard input.
        transVector = ogre.Vector3(0, 0, 0)
        # Move Forward.
        if self.Keyboard.isKeyDown(OIS.KC_W):
           transVector.z -= self.move
        # Move Backward.
        if self.Keyboard.isKeyDown(OIS.KC_S):
            transVector.z += self.move
        # Strafe Left.
        if self.Keyboard.isKeyDown(OIS.KC_A):
            transVector.x -= self.move
        # Strafe Right.
        if self.Keyboard.isKeyDown(OIS.KC_D):
           transVector.x += self.move
        # Move Up.        
        if self.Keyboard.isKeyDown(OIS.KC_F):
            transVector.y += self.move
        # Move Down.
        if self.Keyboard.isKeyDown(OIS.KC_E):
            transVector.y -= self.move
 
        # Translate the camera based on time.
        self.camNode.translate(self.camNode.orientation
                              * transVector
                              * frameEvent.timeSinceLastFrame)
 
        # Rotate the camera when the Right mouse button is down.
        if currMouse.buttonDown(OIS.MB_Right):
           self.camNode.yaw(ogre.Degree(-self.rotate 
                            * currMouse.X.rel).valueRadians())
           self.camNode.getChild(0).pitch(ogre.Degree(-self.rotate
                                          * currMouse.Y.rel).valueRadians())


        self.entMgr.tick(frameEvent.timeSinceLastFrame, self.Keyboard, self.delta)

 
        # If the escape key is pressed end the program.
        return not self.Keyboard.isKeyDown(OIS.KC_ESCAPE)

class TutorialApplication(sf.Application):
	"""The Application class."""
	def _createScene(self):
		# Setup a scene with a low level of ambient light.
		sceneManager = self.sceneManager
		#sceneManager.ambientLight = 0.25, 0.25, 0.25
		sceneManager.ambientLight = 1.0, 1.0, 1.0

		surfaceHeight = -100
		# Setup a ground plane.
		plane = ogre.Plane ((0, 1, 0), surfaceHeight)
		meshManager = ogre.MeshManager.getSingleton ()
		meshManager.createPlane ('Ground', 'General', plane, 10000, 10000, 20, 20, True, 1, 5, 5, (0, 0, 1))
		ent = sceneManager.createEntity('GroundEntity', 'Ground')
		sceneManager.getRootSceneNode().createChildSceneNode ().attachObject (ent)
		ent.setMaterialName ('Examples/TextureEffect2')
		ent.castShadows = False
		self.sceneManager.setSkyDome (True, "Examples/CloudySky", 5, 8)
		#camnode.yaw(ogre.Degree(-45))
		self.entityManager = EntityMgr(sceneManager, self.camera)

	def _createCamera(self):
		self.camera = self.sceneManager.createCamera('PlayerCam')
		self.camera.nearClipDistance = 5

	def _createFrameListener(self):
		self.frameListener = TutorialFrameListener(self.renderWindow, self.camera, self.entityManager)
		self.root.addFrameListener(self.frameListener)
		self.frameListener.showDebugOverlay(True)

if __name__ == '__main__':
	try:
		ta = TutorialApplication()
		ta.go()
	except ogre.OgreException, e:
		print e