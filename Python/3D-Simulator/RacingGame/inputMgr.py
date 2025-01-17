#######
#Team Purple Flower
#Producer: Britanny McGarr
#Member: Zachary Carlson
#Member: Sara Garic
#######
# Input manager.
#    initialize the keyboard and mouse and setup buffered input.
#    Handle mouse selection and, for now, handle camera movemement
import ogre.renderer.OGRE as ogre
import ogre.io.OIS as OIS
import platform
from vector import Vector3
import pygame
import time

class InputMgr():
    def __init__(self, engine):
        self.engine = engine
        self.windowHandle = 0
        self.move = 250
        self.rotate = 0.13
        self.renderWindow = engine.gfxMgr.root.getAutoCreatedWindow()
        self.toggle = 0.0
        # Init joystick
        pygame.init()
        pygame.joystick.init()
        if pygame.joystick.get_count() > 0:
            self.isJoystick = True
            self.joystick = pygame.joystick.Joystick(0)
            self.joystick.init()
        else:
            self.isJoystick = False
        self.buttonPress = False

    def initKeyStates(self):
        #selection manager
        self.CURRENT_TAB = False
        self.PRIOR_TAB = False
        self.CURRENT_LClick = False
        self.PRIOR_LClick = False
        #CAMERA
        self.CURRENT_W = False
        self.PRIOR_W = False
        self.CURRENT_A = False
        self.PRIOR_A = False
        self.CURRENT_S = False
        self.PRIOR_S = False
        self.CURRENT_D = False
        self.PRIOR_D = False
        self.CURRENT_PGUP = False
        self.PRIOR_PGUP = False
        self.CURRENT_PGDN = False
        self.PRIOR_PGDN = False
        
    def updateCamNode(self):
        self.camNode = self.engine.gfxMgr.camera.parentSceneNode.parentSceneNode
    def init(self):
        self.initKeyStates()
        self.updateCamNode()
        int64 = False
        for bit in platform.architecture():
            if '64' in bit:
                int64 = True
        if int64:
            self.windowHandle = self.renderWindow.getCustomAttributeUnsignedLong("WINDOW")
        else:
            self.windowHandle = self.renderWindow.getCustomAttributeInt("WINDOW")
        paramList = [("WINDOW", str(self.windowHandle))]
        t = [("x11_mouse_grab", "false"), ("x11_mouse_hide", "false")]
        paramList.extend(t)
        self.inputManager = OIS.createPythonInputSystem(paramList)
 
        # Now InputManager is initialized for use. Keyboard and Mouse objects
        # must still be initialized separately
        try:
            self.keyboard = self.inputManager.createInputObjectKeyboard(OIS.OISKeyboard, False)
            self.mouse = self.inputManager.createInputObjectMouse(OIS.OISMouse, False)
        except Exception, e:
            raise e

    def wait(self, seconds):
        end_time = time.time() + seconds
        while time.time() < end_time:
            something = "it's doing something"

    def countDown(self):
        #Countdown Sequence
        self.engine.overlayMgr.count = 5
        self.engine.overlayMgr.countDown()
        print("5")
        self.wait(1)
        #time.sleep(1)
        self.engine.overlayMgr.count = 4
        self.engine.overlayMgr.countDown()
        print("4")
        self.wait(1)
        #time.sleep(1)
        self.engine.overlayMgr.count = 3
        self.engine.overlayMgr.countDown()
        print("3")
        self.wait(1)
        #time.sleep(1)
        self.engine.overlayMgr.count = 2
        self.engine.overlayMgr.countDown()
        print("2")
        self.wait(1)
        #time.sleep(1)
        self.engine.overlayMgr.count = 1
        self.engine.overlayMgr.countDown()
        print("1")
        self.wait(1)
        #time.sleep(1)
        self.engine.overlayMgr.count = 0
        self.engine.overlayMgr.countDown()
        print("GO!")
        self.wait(0.5)
        self.engine.overlayMgr.count = -1
        self.engine.overlayMgr.countDown()

    def tick(self, dt):
        self.keyboard.capture()
        self.mouse.capture()
        currMouse = self.mouse.getMouseState()
        self.currMouse = currMouse
        #TAB KEY
        self.PRIOR_TAB = self.CURRENT_TAB
        self.toggle -= dt
        #DEBUGGING
        if self.keyboard.isKeyDown(OIS.KC_1):
            self.engine.overlayMgr.count = 1
            self.engine.overlayMgr.countDown()
        if self.keyboard.isKeyDown(OIS.KC_2):
            self.engine.overlayMgr.count = 2
            self.engine.overlayMgr.countDown()
        if self.keyboard.isKeyDown(OIS.KC_3):
            self.engine.overlayMgr.count = 3
            self.engine.overlayMgr.countDown()
        if self.keyboard.isKeyDown(OIS.KC_4):
            self.engine.overlayMgr.count = 4
            self.engine.overlayMgr.countDown()
        if self.keyboard.isKeyDown(OIS.KC_5):
            self.engine.overlayMgr.count = 5
            self.engine.overlayMgr.countDown()
        #JOYSTICK
        if self.isJoystick:
            for event in pygame.event.get():
                if event.type == pygame.JOYBUTTONDOWN: #if any button is pressed
                    self.buttonPress = True

        # Start Screen selection logic
        if self.engine.overlayMgr.currentSelected == "Start":
            if not self.engine.overlayMgr.showControls:
                if (self.keyboard.isKeyDown(OIS.KC_RETURN) or self.buttonPress) and self.engine.overlayMgr.selection == 1 and self.toggle <= 0:
                    # Bring up the level selection menu and choose based on input
                    self.toggle = 0.25
                    self.engine.overlayMgr.selection = 0
                    self.engine.overlayMgr.setDisplay("Level")
                if (self.keyboard.isKeyDown(OIS.KC_RETURN) or self.buttonPress) and self.engine.overlayMgr.selection == 0 and self.toggle <= 0:
                    self.toggle = 0.25
                    self.engine.overlayMgr.showControls = True
                    self.buttonPress = False
                if (self.keyboard.isKeyDown(OIS.KC_RIGHT) or self.isJoystickRight()) and self.toggle <= 0:
                    self.toggle = 0.25
                    self.engine.overlayMgr.selection = (self.engine.overlayMgr.selection + 1) % 2
                if (self.keyboard.isKeyDown(OIS.KC_LEFT) or self.isJoystickLeft()) and self.toggle <= 0:
                    self.toggle = 0.25
                    self.engine.overlayMgr.selection = (self.engine.overlayMgr.selection + 1) % 2
            elif (self.keyboard.isKeyDown(OIS.KC_RETURN) or self.buttonPress) and self.toggle <= 0:
                self.toggle = 0.25
                self.engine.overlayMgr.showControls = False
                self.buttonPress = False

        if self.engine.overlayMgr.currentSelected == "Level":
            self.engine.gameMgr.loadWaypoints = True
            if(self.keyboard.isKeyDown(OIS.KC_RETURN) or self.buttonPress) and self.engine.overlayMgr.selection == 1 and self.toggle <= 0:
                self.toggle = 0.25
                self.countDown()
                self.engine.gameMgr.secondLevel = True
                self.engine.overlayMgr.setDisplay("Status")
                self.engine.gameMgr.startGame()
                self.buttonPress = False
            if(self.keyboard.isKeyDown(OIS.KC_RETURN) or self.buttonPress) and self.engine.overlayMgr.selection == 0 and self.toggle <= 0:
                self.toggle = 0.25
                self.countDown()
                self.engine.gameMgr.secondLevel = False
                self.engine.overlayMgr.setDisplay("Status")
                self.engine.gameMgr.startGame()
                self.buttonPress = False
            if(self.keyboard.isKeyDown(OIS.KC_RIGHT) or self.isJoystickRight()) and self.toggle <= 0:
                self.toggle = 0.25
                self.engine.overlayMgr.selection = (self.engine.overlayMgr.selection + 1) % 2
            if(self.keyboard.isKeyDown(OIS.KC_LEFT) or self.isJoystickLeft()) and self.toggle <= 0:
                self.toggle = 0.25
                self.engine.overlayMgr.selection = (self.engine.overlayMgr.selection + 1) % 2
            if self.engine.overlayMgr.selection == 1:
                self.engine.gfxMgr.sceneManager.setSkyDome(True, "Examples/CitySkyBox", 5, 8)
            if self.engine.overlayMgr.selection == 0:
                self.engine.gfxMgr.sceneManager.setSkyDome(True, "Examples/MountainSkyBox", 5, 8)

        if self.keyboard.isKeyDown(OIS.KC_TAB):
            self.CURRENT_TAB = True
        else:
            self.CURRENT_TAB = False
        #Left Mouse Click
        self.PRIOR_LClick = self.CURRENT_LClick
        if currMouse.buttonDown(OIS.MB_Left):
            self.CURRENT_LClick = True
        else:
            self.CURRENT_LClick = False

        # Move the camera using keyboard input.
        transVector = Vector3(0.0,0.0,0.0)
        # Move Forward.
        if self.keyboard.isKeyDown(OIS.KC_W):
           transVector.z -= self.move
        # Move Backward.
        if self.keyboard.isKeyDown(OIS.KC_S):
            transVector.z += self.move
        # Strafe Left.
        if self.keyboard.isKeyDown(OIS.KC_A):
            transVector.x -= self.move
        # Strafe Right.
        if self.keyboard.isKeyDown(OIS.KC_D):
           transVector.x += self.move
        #YAW Q - Counter-clockwise
        if self.keyboard.isKeyDown(OIS.KC_Q):
           self.camNode.yaw(ogre.Degree(self.rotate * self.move * dt).valueRadians())
        #YAW E - Clockwise
        if self.keyboard.isKeyDown(OIS.KC_E):
           self.camNode.yaw(ogre.Degree(-self.rotate * self.move * dt).valueRadians())
        #Pitch Z - Up
        if self.keyboard.isKeyDown(OIS.KC_Z):
           self.camNode.getChild(0).pitch(ogre.Degree(self.rotate * self.move * dt).valueRadians())
        #Pitch X - Down
        if self.keyboard.isKeyDown(OIS.KC_X):
           self.camNode.getChild(0).pitch(ogre.Degree(-self.rotate * self.move * dt).valueRadians())
        # Move Up.        
        if self.keyboard.isKeyDown(OIS.KC_PGUP):
            transVector.y += self.move
        # Move Down.
        if self.keyboard.isKeyDown(OIS.KC_PGDOWN):
            transVector.y -= self.move
        #ESCAPE KEY
        if self.keyboard.isKeyDown(OIS.KC_ESCAPE):
            self.engine.keepRunning = False
        # Translate the camera based on time.
        self.camNode.translate(self.camNode.orientation
                              * transVector
                              * dt)
 
        # Rotate the camera when the Right mouse button is down.
        if currMouse.buttonDown(OIS.MB_Right):
           self.camNode.yaw(ogre.Degree(-self.rotate 
                            * currMouse.X.rel).valueRadians())
           self.camNode.getChild(0).pitch(ogre.Degree(-self.rotate
                                          * currMouse.Y.rel).valueRadians())

    def isJoystickLeft(self):
        if self.isJoystick:
            try:
                if self.joystick.get_axis(0) < -.25:
                    return True
                if self.joystick.get_axis(3) < -.25:
                    return True
                if self.joystick.get_hat(0) < (-.25, 1):
                    return True
            except:
                self.isJoystick = False
        return False

    def isJoystickRight(self):
        if self.isJoystick:
            try:
                if self.joystick.get_axis(0) > .25:
                    return True
                if self.joystick.get_axis(3) > .25:
                    return True
                if self.joystick.get_hat(0) > (.25,-1):
                    return True
            except:
                self.isJoystick = False
        return False

    def stop(self):
        self.inputManager.destroyInputObjectKeyboard(self.keyboard)
        self.inputManager.destroyInputObjectMouse(self.mouse)
        OIS.InputManager.destroyInputSystem(self.inputManager)
        self.inputManager = None
