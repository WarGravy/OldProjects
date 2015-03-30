import ogre.renderer.OGRE as ogre
import ogre.io.OIS as OIS
import SampleFramework as sf
 
 
class TutorialFrameListener(sf.FrameListener):
    """A FrameListener class that handles basic user input."""
 
    def __init__(self, renderWindow, camera, sceneManager):
        # Subclass any Python-Ogre class and you must call its constructor.
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
        # Move Forward.
        if self.Keyboard.isKeyDown(OIS.KC_UP) or self.Keyboard.isKeyDown(OIS.KC_W):
           transVector.z -= self.move
        # Move Backward.
        if self.Keyboard.isKeyDown(OIS.KC_DOWN) or self.Keyboard.isKeyDown(OIS.KC_S):
            transVector.z += self.move
        # Strafe Left.
        if self.Keyboard.isKeyDown(OIS.KC_LEFT) or self.Keyboard.isKeyDown(OIS.KC_A):
            transVector.x -= self.move
        # Strafe Right.
        if self.Keyboard.isKeyDown(OIS.KC_RIGHT) or self.Keyboard.isKeyDown(OIS.KC_D):
           transVector.x += self.move
        # Move Up.        
        if self.Keyboard.isKeyDown(OIS.KC_PGUP) or self.Keyboard.isKeyDown(OIS.KC_Q):
            transVector.y += self.move
        # Move Down.
        if self.Keyboard.isKeyDown(OIS.KC_PGDOWN) or self.Keyboard.isKeyDown(OIS.KC_E):
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
 
        # If the escape key is pressed end the program.
        return not self.Keyboard.isKeyDown(OIS.KC_ESCAPE)
 
class TutorialApplication(sf.Application):
    """The Application class."""
 
    def _createScene(self):
        # Setup a scene with a low level of ambient light.
        sceneManager = self.sceneManager
        sceneManager.ambientLight = 0.25, 0.25, 0.25
 
        # Setup a mesh entity and attach it to a scene node.
        entity = sceneManager.createEntity('Ninja', 'ninja.mesh')
        node = sceneManager.getRootSceneNode().createChildSceneNode('NinjaNode')
        node.attachObject(entity)
 
        # Setup a White point light.
        light = sceneManager.createLight('Light1')
        light.type = ogre.Light.LT_POINT
        light.position = 250, 150, 250
        light.diffuseColour = 1, 1, 1
        light.specularColour = 1, 1, 1
 
        # Setup the first camera node and pitch node and aim it.
        node = sceneManager.getRootSceneNode().createChildSceneNode('CamNode1',
                                                               (-400, 200, 400))
        node.yaw(ogre.Degree(-45))
        node = node.createChildSceneNode('PitchNode1')
        node.attachObject(self.camera)
 
        # Setup the second camera node and pitch node.
        node = sceneManager.getRootSceneNode().createChildSceneNode('CamNode2',
                                                              (0, 200, 400))
        node.createChildSceneNode('PitchNode2')        
 
    def _createCamera(self):
        self.camera = self.sceneManager.createCamera('PlayerCam')
        self.camera.nearClipDistance = 5
 
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
