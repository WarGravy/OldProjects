import ogre.renderer.OGRE as ogre
import SampleFramework as sf

class TutorialApplication(sf.Application):

	def _createScene(self):
		# Setup the ambient light. 
		sceneManager = self.sceneManager
		sceneManager.ambientLight = (1.0, 1.0, 1.0)
		# Setup a mesh entity and attach it to the root scene node.
		ent1 = sceneManager.createEntity('Robot', 'robot.mesh')
		node1 = sceneManager.getRootSceneNode().createChildSceneNode('RobotNode')
		node1.attachObject(ent1)
		key = 0

		for i in range(1,100):
			# Setup a second mesh entity as a child node.
			if(i % 10 == 0):
				key+=1
			ent2 = sceneManager.createEntity('Robot' + str(i), 'robot.mesh')
			node2 = node1.createChildSceneNode('RobotNode' + str(i), (50 * (i%10 +1), 0, key))
			node2.attachObject(ent2)
 
if __name__ == '__main__':
	ta = TutorialApplication()
	ta.go()