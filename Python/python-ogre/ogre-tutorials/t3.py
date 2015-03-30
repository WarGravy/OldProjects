#!/usr/bin/env python
# This code is Public Domain and was written for Python-Ogre 1.0.
"""Python-Ogre Basic Tutorial 03: Terrain, Sky, Fog, and the Root Object."""
 
import ogre.renderer.OGRE as ogre
import SampleFramework as sf
 
 
class TutorialApplication (sf.Application):
    """Application class."""
 
    def _createScene (self):
        # Create a scene with terrain, sky and fog.
 
        # Setup the fog.
        fadeColour = (0.9, 0.9, 0.9)
        self.renderWindow.getViewport (0).backgroundColour = fadeColour
        self.sceneManager.setFog (ogre.FOG_LINEAR, fadeColour, 0.0, 50, 500)
 
        # Create the terrain
        self.sceneManager.setWorldGeometry ("terrain.cfg")
 
        # Setup a sky plane.
        plane = ogre.Plane ((0, -1, 0), -10)
        self.sceneManager.setSkyPlane (True, plane, "Examples/CloudySky",
                                      100, 45, True, 0.5, 150, 150)
 
    def _chooseSceneManager (self):
        # Select the terrain scene manager.
        self.sceneManager = self.root.createSceneManager (ogre.ST_EXTERIOR_CLOSE,
                                                         'TerrainSM')
 
if __name__ == '__main__':
    ta = TutorialApplication ()
    ta.go ()
