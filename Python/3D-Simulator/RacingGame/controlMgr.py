#######
#Team Purple Flower
#Producer: Britanny McGarr
#Member: Zachary Carlson
#Member: Sara Garic
#######
# Control manager.
#    handle entity control through the arrow keys on the keyboard. The
#    arrow keys on your keyboard control all selected entities. Up/Down 
#    will increase and decrease desiredSpeed in the current direction of 
#    motion. Left/Right arrow keys turn the entity, they change the entity's
#    desiredHeading.
import ogre.io.OIS as OIS
import ogre.renderer.OGRE as ogre
import pygame
from vector import Vector3

class ControlMgr:
    def __init__(self, engine):
        self.engine = engine
        pass

    def init(self):
        self.entMgr = self.engine.entityMgr
        self.selMgr = self.engine.selectionMgr
        self.keyboard = self.engine.inputMgr.keyboard
        self.toggle = 0.0

        # Init joystick
        pygame.init()
        pygame.joystick.init()
        if (pygame.joystick.get_count() > 0):
            self.isJoystick = True
            self.joystick = pygame.joystick.Joystick(0)
            self.joystick.init()
            print "Joystick detected"
        else:
            self.isJoystick = False
            print "No joy detected. Use keyboard commands."

    def tick(self, dt):
        # Update the toggle timer.
        if self.toggle >= 0:
            self.toggle -= dt
        self.isJoystick = self.engine.inputMgr.isJoystick
        import utils
        entList = self.selMgr.getSelected()
        entList.extend(self.engine.aiMgr.ai)
        if entList:
            for selectedEnt in entList:
                #change desired speed and current direction
                #------------------------------------------

                if self.isJoystick and selectedEnt.isAI == False: # if gamepad is attached
                    pygame.event.get() # For joystick control

                    # Speed Up
                    if self.joystick.get_button(0): # If A button is pressed
                        selectedEnt.desiredSpeed = utils.clamp(selectedEnt.desiredSpeed + selectedEnt.deltaSpeed, 0, selectedEnt.maxSpeed)

                    # Slow down # Changed by Sara 
                    elif self.joystick.get_button(1): # If B button is pressed
                        selectedEnt.desiredSpeed = utils.clamp(selectedEnt.desiredSpeed - selectedEnt.deltaSpeed, -90, selectedEnt.maxSpeed) 
 
                    # Drift # Added by Sara to make Ents drift to a stop
                    elif selectedEnt.speed != 0:
                        if selectedEnt.speed > 0:
                            selectedEnt.desiredSpeed = utils.clamp(selectedEnt.desiredSpeed - selectedEnt.drift, 0, selectedEnt.maxSpeed)
                            if selectedEnt.speed < 0:
                                selectedEnt.desiredSpeed = 0
                        elif selectedEnt.speed < 0:
                            selectedEnt.desiredSpeed = utils.clamp(selectedEnt.desiredSpeed + selectedEnt.drift, -90, 0)
                            if selectedEnt.speed > 0:
                                selectedEnt.desiredSpeed = 0

                    # Turn Left.
                    if self.joystick.get_axis(0) < -.25:
                        selectedEnt.heading += selectedEnt.turningRate * (selectedEnt.speed / 3 ) * (self.joystick.get_axis(0) * -1)

                    # Turn Right.
                    if self.joystick.get_axis(0) > .25:
                        selectedEnt.heading -= selectedEnt.turningRate * (selectedEnt.speed / 3 ) * self.joystick.get_axis(0)

                    # Fly up. Added by Sara
                    if self.joystick.get_axis(1) < -.25:
                        if selectedEnt.height < 900: # Keep it from going too high
                            selectedEnt.height += selectedEnt.climbingSpeed * (selectedEnt.speed / 2 ) * (self.joystick.get_axis(1) * -1) # Can't fly up if not moving.
                            selectedEnt.pos.y = selectedEnt.height
           
                    # Fly down. Added by Sara
                    if self.joystick.get_axis(1) > .25 and selectedEnt.speed > 0:
                        if selectedEnt.height > 10: # Keep it from going too low
                            selectedEnt.height -= selectedEnt.climbingSpeed * selectedEnt.speed * self.joystick.get_axis(1)# Can't fly down if not moving.
                            selectedEnt.pos.y = selectedEnt.height

                elif self.isJoystick == False or selectedEnt.isAI == True:
                    # Speed Up
                    if (self.keyboard.isKeyDown(OIS.KC_UP) and selectedEnt.isAI == False) or selectedEnt.AI_FORWARD:
                        selectedEnt.desiredSpeed = utils.clamp(selectedEnt.desiredSpeed + selectedEnt.deltaSpeed, 0, selectedEnt.maxSpeed)

                    # Slow down
                    elif (self.keyboard.isKeyDown(OIS.KC_DOWN)  and selectedEnt.isAI == False) or selectedEnt.AI_REVERSE:
                        selectedEnt.desiredSpeed = utils.clamp(selectedEnt.desiredSpeed - selectedEnt.deltaSpeed, -90, selectedEnt.maxSpeed) #Sara added a reverse

                    # Drift # Added by Sara to make Ents drift to a stop
                    elif selectedEnt.speed != 0:
                        if selectedEnt.speed > 0:
                            selectedEnt.desiredSpeed = utils.clamp(selectedEnt.desiredSpeed - selectedEnt.drift, 0, selectedEnt.maxSpeed)
                            if selectedEnt.speed < 0:
                                selectedEnt.desiredSpeed = 0
                        elif selectedEnt.speed < 0:
                            selectedEnt.desiredSpeed = utils.clamp(selectedEnt.desiredSpeed + selectedEnt.drift, -90, 0)
                            if selectedEnt.speed > 0:
                                selectedEnt.desiredSpeed = 0

                    # Turn Left.
                    if  (self.keyboard.isKeyDown(OIS.KC_LEFT)  and selectedEnt.isAI == False) or selectedEnt.AI_LEFT:
                        selectedEnt.heading += selectedEnt.turningRate * (selectedEnt.speed / 3 )

                    # Turn Right.
                    if (self.keyboard.isKeyDown(OIS.KC_RIGHT) and selectedEnt.isAI == False) or selectedEnt.AI_RIGHT:
                        selectedEnt.heading -= selectedEnt.turningRate * (selectedEnt.speed / 3 )

                    # Fly up. Added by Sara
                    if (selectedEnt.isAI == False and self.keyboard.isKeyDown(OIS.KC_R) and selectedEnt.speed > 0) or (selectedEnt.AI_UP and selectedEnt.speed > 0):
                        if selectedEnt.height < 900: # Keep it from going too high
                            selectedEnt.height += selectedEnt.climbingSpeed * (selectedEnt.speed / 2 ) # Can't fly up if not moving.
                            selectedEnt.pos.y = selectedEnt.height

                    # Fly down. Added by Sara
                    if (selectedEnt.isAI == False and self.keyboard.isKeyDown(OIS.KC_F) and selectedEnt.speed > 0) or (selectedEnt.AI_DOWN and selectedEnt.speed > 0):
                        if selectedEnt.height > 10: # Keep it from going too low
                            selectedEnt.height -= selectedEnt.climbingSpeed * selectedEnt.speed # Can't fly down if not moving.
                            selectedEnt.pos.y = selectedEnt.height

                if self.toggle < 0:
                    toggle = 0.2

    def stop(self):
        pygame.joystick.quit()
        pass
