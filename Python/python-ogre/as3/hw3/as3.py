import ogre.renderer.OGRE as ogre
import ogre.io.OIS as OIS
import SampleFramework as sf
from ent import MyEntity
from physics import PhysicsAspect as phys

surfaceHeight = 0
entities = []
#timeSinceLastFrame
class TutorialFrameListener(sf.FrameListener):
    def __init__(self, renderWindow, camera, sceneManager):
        sf.FrameListener.__init__(self, renderWindow, camera)
 
        # Key and mouse state tracking.
        self.toggle = 0
        self.mouseDown = False
 
        # Populate the camera and scene manager containers.
        self.camNode = camera.parentSceneNode.parentSceneNode
        self.sceneManager = sceneManager
 
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
        if self.toggle < 0 and self.Keyboard.isKeyDown(OIS.KC_1):
            # Update the toggle timer.
            self.toggle = 0.1
            # Attach the camera to PitchNode1.
            self.camera.parentSceneNode.detachObject(self.camera)
            self.camNode = self.sceneManager.getSceneNode("CamNode1")
            self.sceneManager.getSceneNode("PitchNode1").attachObject(self.camera)
 
        elif self.toggle < 0 and self.Keyboard.isKeyDown(OIS.KC_2):
            # Update the toggle timer.
            self.toggle = 0.1
            # Attach the camera to PitchNode2.
            self.camera.parentSceneNode.detachObject(self.camera)
            self.camNode = self.sceneManager.getSceneNode("CamNode2")
            self.sceneManager.getSceneNode("PitchNode2").attachObject(self.camera)
        # Move the camera using keyboard input.
        transVector = ogre.Vector3(0, 0, 0)
        # Move Camera Forward.
        if self.Keyboard.isKeyDown(OIS.KC_W):
           transVector.z -= self.move
        # Move Camera Backward.
        if self.Keyboard.isKeyDown(OIS.KC_S):
            transVector.z += self.move
        # Strafe Camera Left.
        if self.Keyboard.isKeyDown(OIS.KC_A):
            transVector.x -= self.move
        # Strafe Camera Right.
        if self.Keyboard.isKeyDown(OIS.KC_D):
           transVector.x += self.move
        # Move Camera Up.        
        if self.Keyboard.isKeyDown(OIS.KC_F):
            transVector.y += self.move
        # Move Camera Down.
        if self.Keyboard.isKeyDown(OIS.KC_E):
            transVector.y -= self.move
        # Change the cube's velocity using keyboard input.
        entVector = ogre.Vector3(0, 0, 0)
        #Up Arrow or 8
        if self.Keyboard.isKeyDown(OIS.KC_UP) or self.Keyboard.isKeyDown(OIS.KC_8):
           entVector.z -= 8
        #Down Arrow or 2
        if self.Keyboard.isKeyDown(OIS.KC_DOWN) or self.Keyboard.isKeyDown(OIS.KC_2):
            entVector.z += 8
        #Left Arrow or 4
        if self.Keyboard.isKeyDown(OIS.KC_LEFT) or self.Keyboard.isKeyDown(OIS.KC_4):
            entVector.x -= 8
        #Right Arrow or 6
        if self.Keyboard.isKeyDown(OIS.KC_RIGHT) or self.Keyboard.isKeyDown(OIS.KC_6):
           entVector.x += 8
        #PG Up       
        if self.Keyboard.isKeyDown(OIS.KC_PGUP):
            entVector.y += 8
        #PG Down
        if self.Keyboard.isKeyDown(OIS.KC_PGDOWN):
            entVector.y -= 8
        #SPACEBAR stops all entities
        if self.Keyboard.isKeyDown(OIS.KC_SPACE):
            entVector.y = 0
            entVector.x = 0
            entVector.z = 0
        # Translate the camera based on time.
        self.camNode.translate(self.camNode.orientation
                              * transVector
                              * frameEvent.timeSinceLastFrame)
 
        # Rotate the camera when the Right mouse button is down.
        if currMouse.buttonDown(OIS.MB_Right):
           self.camNode.yaw(ogre.Degree(-self.rotate * currMouse.X.rel).valueRadians())
           self.camNode.getChild(0).pitch(ogre.Degree(-self.rotate * currMouse.Y.rel).valueRadians())
        #call tick on all aspects
        for e in entities:
            e.vel = e.vel + entVector
            if self.Keyboard.isKeyDown(OIS.KC_SPACE):
                e.vel = entVector
            e.tick(frameEvent.timeSinceLastFrame)
        return not self.Keyboard.isKeyDown(OIS.KC_ESCAPE)
        
class TutorialApplication(sf.Application):
    """The Application class."""
    def _createScene(self):
        sceneManager = self.sceneManager
        sceneManager.ambientLight = (0, 0, 0)
        sceneManager.shadowTechnique = ogre.SHADOWTYPE_STENCIL_ADDITIVE
 
        # Setup a mesh object.
    	for i in range(0, 1):
            ent = sceneManager.createEntity('Cube', 'cube.mesh')
            ent.castShadows = True
            sceneManager.getRootSceneNode().createChildSceneNode().attachObject(ent)
            entityScene = sceneManager.getEntity('Cube').getParentNode()
            entities.append(MyEntity('Cube', entityScene, mesh = 'cube.mesh'))
 
        # Setup a ground plane.
        plane = ogre.Plane ((0, 1, 0), surfaceHeight)
        meshManager = ogre.MeshManager.getSingleton ()
        meshManager.createPlane ('Ground', 'General', plane,
                                     10000, 10000, 20, 20, True, 1, 5, 5, (0, 0, 1))
        ent = sceneManager.createEntity('GroundEntity', 'Ground')
        sceneManager.getRootSceneNode().createChildSceneNode ().attachObject (ent)
        ent.setMaterialName ('Examples/Rockwall')
        ent.castShadows = False
 
        # Setup a point light.
        light = sceneManager.createLight ('PointLight')
        light.type = ogre.Light.LT_POINT
        light.position = (150, 300, 150)
        light.diffuseColour = (.5, .0, .0)    # Red
        light.specularColour = (.5, .0, .0)
 
        # Setup a distant directional light.
        light = sceneManager.createLight ('DirectionalLight')
        light.type = ogre.Light.LT_DIRECTIONAL
        light.diffuseColour = (.5, .5, .0)    # yellow
        light.specularColour = (.75, .75, .75)
        light.direction = (0, -1, 1)
 
        # Setup a spot light.
        light = sceneManager.createLight ('SpotLight')
        light.type = ogre.Light.LT_SPOTLIGHT
        light.diffuseColour = (0, 0, .5)    # Blue
        light.specularColour = (0, 0, .5)
        light.direction = (-1, -1, 0)
        light.position = (300, 300, 0)
        light.setSpotlightRange (ogre.Degree (35), ogre.Degree (50))

        # Setup the first camera node and pitch node and aim it.
        node = sceneManager.getRootSceneNode().createChildSceneNode('CamNode1',
                                                               (-400, 200, 400))
        node.yaw(ogre.Degree(-45))
        node = node.createChildSceneNode('PitchNode1')
        node.attachObject(self.camera)
        # Setup a sky plane.
        plane = ogre.Plane ((0, -1, 0), -10)
        self.sceneManager.setSkyPlane (True, plane, "Examples/CloudySky",
                                      100, 45, True, 0.5, 150, 150)

        # Setup the second camera node and pitch node.
        node = sceneManager.getRootSceneNode().createChildSceneNode('CamNode2',
                                                              (0, 200, 400))
        node.createChildSceneNode('PitchNode2')       
 
    def _createCamera(self):
        self.camera =  self.sceneManager.createCamera ('PlayerCam')
        self.camera.nearClipDistance = 5
 
    def _createViewports(self):
        viewport = self.renderWindow.addViewport (self.camera)
        viewport.backGroundColor = (0, 150, 0)
        self.camera.aspectRatio = float (viewport.actualWidth) / float (viewport.actualHeight)
    def _createFrameListener(self):
        self.frameListener = TutorialFrameListener(self.renderWindow,
                                                   self.camera,
                                                   self.sceneManager)
        self.root.addFrameListener(self.frameListener)
        self.frameListener.showDebugOverlay(True)
 
if __name__ == '__main__':
    try:
        ta = TutorialApplication()
        ta.go()
    except ogre.OgreException, e:
        print e
