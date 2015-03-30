#!/usr/bin/env python 
# This code is Public Domain. 
"""Python-Ogre Basic Tutorial 01: The SceneNode, Entity, and SceneManager constructs.""" 
 
import ogre.renderer.OGRE as ogre 
import SampleFramework as sf 
 
class TutorialApplication (sf.Application): 
   """Application class.""" 
 
   def _createScene (self):        
       # Setup the ambient light. 
       sceneManager = self.sceneManager 
       sceneManager.ambientLight = (1.0, 1.0, 1.0) 
 
       # Setup a mesh entity and attach it to the root scene node. 
       ent1 = sceneManager.createEntity ('Robot', 'robot.mesh') 
       node1 = sceneManager.getRootSceneNode().createChildSceneNode ('RobotNode') 
       node1.attachObject (ent1) 

       a = 0
       b = 0
       c = 0
 
       # Setup a second mesh entity as a child node. 
       #ent2 = sceneManager.createEntity ('Robot2', 'robot.mesh') 
       #node2 = node1.createChildSceneNode ('RobotNode2', (a, b, c)) 
       #node2.attachObject (ent2) 

       # Set up third
       #ent3 = sceneManager.createEntity ('Robot3', 'robot.mesh')
       #node3 = node1.createChildSceneNode ('RobotNode3', (0, 100, 0))
       #node3.attachObject (ent3)

       for i in range(1,10):
           a = a + 50
           ent2 = sceneManager.createEntity ('Robot' + str(i), 'robot.mesh')
           node2 = node1.createChildSceneNode ('RobotNode' + str(i), (a, 0, 0))
           node2.attachObject(ent2)

if __name__ == '__main__': 
   ta = TutorialApplication () 
   ta.go ()
