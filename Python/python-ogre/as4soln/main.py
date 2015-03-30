import ogre.renderer.OGRE as ogre
import ogre.io.OIS as OIS
import SampleFramework as sf

 
class PhysicsFrameListener(ogre.FrameListener):
    def __init__(self, entMgr):
        ogre.FrameListener.__init__(self)
        self.entityMgr = entMgr

    def frameStarted(self, frameEvent):
        for uid, ent in self.entityMgr.ents.iteritems():
            ent.tick(frameEvent.timeSinceLastFrame)
        return True


 
class TutorialFrameListener(sf.FrameListener):
    """A FrameListener class that handles basic user input."""
 
    def __init__(self, renderWindow, camera, sceneManager, entmgr):
        # Subclass any Python-Ogre class and you must call its constructor.
        sf.FrameListener.__init__(self, renderWindow, camera)
        self.entityMgr = entmgr
 
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
 
        # Handle Tab selection
        if self.toggle < 0 and self.Keyboard.isKeyDown(OIS.KC_TAB):
            # Update the toggle timer.
            self.toggle = 0.1
            ent = self.entityMgr.selectedEnt
            ent.node.showBoundingBox(False)
            ent = self.entityMgr.selectNextEnt()

            print "FrameListener: Selected: ", str(ent)
            ent.node.showBoundingBox(True)
 
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
        if  self.Keyboard.isKeyDown(OIS.KC_D):
           transVector.x += self.move
        # Move Up.        
        if self.Keyboard.isKeyDown(OIS.KC_PGUP):
            transVector.y += self.move
        # Move Down.
        if self.Keyboard.isKeyDown(OIS.KC_PGDOWN):
            transVector.y -= self.move

#--------------------------------------------------------------------------------------
        
        #print str(self.selectedEntIndex), selectedEnt.id
        import utils
        selectedEnt = self.entityMgr.selectedEnt
        # Speed Up
        if  self.toggle < 0 and self.Keyboard.isKeyDown(OIS.KC_UP):
            self.toggle = 0.1
            selectedEnt.desiredSpeed = utils.clamp(selectedEnt.desiredSpeed + selectedEnt.deltaSpeed, 0, selectedEnt.maxSpeed)
            print "Speeding UP", selectedEnt.desiredSpeed

        # Slow down
        if  self.toggle < 0 and self.Keyboard.isKeyDown(OIS.KC_DOWN):
            self.toggle = 0.1
            selectedEnt.desiredSpeed = utils.clamp(selectedEnt.desiredSpeed - selectedEnt.deltaSpeed, 0, selectedEnt.maxSpeed)
            print "Slowing down", selectedEnt.desiredSpeed


        # Turn Left.
        if  self.toggle < 0 and self.Keyboard.isKeyDown(OIS.KC_LEFT):
            self.toggle = 0.1
            selectedEnt.desiredHeading += selectedEnt.deltaYaw
            selectedEnt.desiredHeading = utils.fixAngle(selectedEnt.desiredHeading)
            print "Turn left", selectedEnt.desiredHeading

            
        # Turn Right.
        if  self.toggle < 0 and self.Keyboard.isKeyDown(OIS.KC_RIGHT):
            self.toggle = 0.1
            selectedEnt.desiredHeading -= selectedEnt.deltaYaw
            selectedEnt.desiredHeading = utils.fixAngle(selectedEnt.desiredHeading)
            print "Turn right", selectedEnt.desiredHeading

        #print self.selectedEnt.uiname, selectedEnt.id, str(selectedEnt.vel)

 #--------------------------------------------------------------------------------------

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

    def frameEnded(self, evt):
        pass
        return True;

    def frameRenderingQueued(self, evt):
        pass
        return True;





class TutorialApplication(sf.Application):
    """The Application class."""

    def createGent(self, mid, mmesh, mpos, myaw):
        e = self.sceneManager.createEntity(mid, mmesh)
        fileRoot = mmesh.split('.')
        materialName = fileRoot[0]+".material"
        node = self.sceneManager.getRootSceneNode().createChildSceneNode(mid + 'node', mpos)
        node.attachObject(e)
        return node

 
    def _createScene(self):
        # Setup a scene with a low level of ambient light.
        sceneManager = self.sceneManager
        sceneManager.ambientLight = 1, 1, 1
 
        # Setup a ground plane.
        plane = ogre.Plane ((0, 1, 0), 0)
        meshManager = ogre.MeshManager.getSingleton ()
        meshManager.createPlane ('Ground', 'General', plane,
                                     10000, 10000, 20, 20, True, 1, 5, 5, (0, 0, 1))
        ent = sceneManager.createEntity('GroundEntity', 'Ground')
        sceneManager.getRootSceneNode().createChildSceneNode ().attachObject (ent)
        ent.setMaterialName ('OceanCg')
        ent.castShadows = False
 
        #self.sceneManager.setSkyBox (True, "Examples/MorningSkyBox", 5000, False)
        self.sceneManager.setSkyDome (True, "Examples/CloudySky", 5, 8)

        #---------------------------------------------------------------------------
        from entMgr import EntMgr
        from vector import MyVector
        self.entityMgr = EntMgr(self);
        x = 0;
        i = 0;
        for entType in self.entityMgr.entTypes:
            ent = self.entityMgr.createEnt(entType, pos = MyVector(x, 0, 0))
            gfxNode = self.createGent(ent.uiname + str(i), ent.mesh, ent.pos, ent.heading)
            ent.node = gfxNode
            x += 300
            i += 1
        #---------------------------------------------------------------------------
        # Setting up only one scene node for camera movement. As5 solution has yaw/pitch
        # Setup the first camera node and pitch node and aim it.
        node = sceneManager.getRootSceneNode().createChildSceneNode('CamNode1',
                                                               (-400, 200, 400))
        node.yaw(ogre.Degree(-45))
        node = node.createChildSceneNode('PitchNode1')
        node.attachObject(self.camera)

    def _createCamera(self):
        self.camera = self.sceneManager.createCamera('PlayerCam')
        self.camera.nearClipDistance = 5
 
    def _createFrameListener(self):
        self.frameListener = TutorialFrameListener(self.renderWindow,
                                                   self.camera,
                                                   self.sceneManager, self.entityMgr)
        self.root.addFrameListener(self.frameListener)
        self.frameListener.showDebugOverlay(False)

        self.physicsFrameListener = PhysicsFrameListener(self.entityMgr)
        self.root.addFrameListener(self.physicsFrameListener)
 
 
if __name__ == '__main__':
    try:
        ta = TutorialApplication()
        ta.go()
    except ogre.OgreException, e:
        print e
