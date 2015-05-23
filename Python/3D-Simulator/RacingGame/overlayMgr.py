#######
#Team Purple Flower
#Producer: Britanny McGarr
#Member: Zachary Carlson
#Member: Sara Garic
#######
# 381 Overlay Manager
from pygame import mixer
import ogre.renderer.OGRE as ogre
import time


class OverlayMgr:
    def __init__(self, engine):
        self.engine = engine
        print "OverlayMgr Constructor"

    def init(self):
        # Get the ogre base overlay manager
        self.overlayManager = ogre.OverlayManager.getSingleton()

        # Initialize the sound mixer and controls screen boolean
        mixer.init()

        # Initialize the controls screen boolean and selection
        self.selection = 1
        self.showControls = False
        self.count = 6

        # Maintain a listing of the race time
        self.playerTime = 0

        # Create a list of overlays and populate (Only StatusOverlay for demo)
        self.overlayList = []
        self.loadOverlay()
        self.currentSelected = ""
        self.setDisplay("Start")

    def loadOverlay(self):
        # Add each overlay to the list as created (One for demo)
        self.overlayList.append(StartOverlay(self.engine, self.overlayManager))
        self.overlayList.append(StatusOverlay(self.engine, self.overlayManager))
        self.overlayList.append(LevelOverlay(self.engine, self.overlayManager))

    def setDisplay(self, name):
        # Toggle display of overlays as selected (One for demo)
        self.currentSelected = name
        for overlay in self.overlayList:
            overlay.setVisible(overlay.name == name)

    def countDown(self):
        # Calls the countdown function of the entity
        for overlay in self.overlayList:
            if overlay.name == self.currentSelected:
                overlay.countDown(self.count)

    def tick(self, dtime):
        # To be implemented as more overlays are required (Only status display for now)
        for overlay in self.overlayList:
            if overlay.name == self.currentSelected:
                overlay.tick(dtime)


class Overlay:
    def __init__(self, engine, overlayManager, name):
        self.engine = engine

        # Overlay initialization for CS381 engine
        self.name = name
        self.startTime = time.time()
        self.overlayManager = overlayManager
        self.musicPath = ""
        self.overlay = self.overlayManager.create(self.name + "Overlay")

    def setVisible(self, visible):
        # Response to toggle between overlays
        if visible:
            self.startTime = time.time()
            mixer.music.load(self.musicPath)
            mixer.music.play()
            mixer.music.set_volume(.2)
            self.overlay.show()
        else:
            self.startTime = time.time()
            mixer.stop()
            self.overlay.hide()


class StartOverlay(Overlay):
    name = "Start"

    def __init__(self, engine, overlayManager):
        Overlay.__init__(self, engine, overlayManager, self.name)
        self.loadOverlay()

    def loadOverlay(self):
        self.musicPath = "data/music/TopGearTheme.mp3"
        # Sets the specifications of the Start Screen Overlay - Entry point for the game
        self.background = self.overlayManager.createOverlayElement("Panel", self.name+"_Background")
        self.background.setPosition(0.0, 0.0)
        self.background.setDimensions(1.0, 1.0)
        self.background.setMaterialName("GUI_StartBackground")
        self.overlay.add2D(self.background)

        # Add a Start Game button
        button = self.overlayManager.createOverlayElement("BorderPanel", self.name+"_Start_Button")
        button.setPosition(0.35, 0.60)
        button.setDimensions(0.12, 0.08)
        button.setMaterialName("Splash_Start_Button")
        button.setBorderMaterialName("GUI_Gray_Border")
        button.setBorderSize(0.005)

        # Add a Controls Button
        controlsButton = self.overlayManager.createOverlayElement("BorderPanel", self.name+"_Controls_Button")
        controlsButton.setPosition(0.55, 0.60)
        controlsButton.setDimensions(0.12, 0.08)
        controlsButton.setMaterialName("Splash_Controls_Button")
        controlsButton.setBorderMaterialName("GUI_Gray_Border")
        controlsButton.setBorderSize(0.005)

        # Add a Controls panel for player
        panel = self.overlayManager.createOverlayElement("Panel", self.name + "_Controls_Panel")
        panel.setPosition(0.0, 0.0)
        panel.setDimensions(1, 1)
        panel.setMaterialName("GUI_ControlsBackground")

        self.startButton = button
        self.controlsButton = controlsButton
        self.controlsPanel = panel
        self.overlay.add2D(self.startButton)
        self.overlay.add2D(self.controlsButton)
        self.overlay.add2D(self.controlsPanel)

    def countDown(self, count):
        # Unable to solve - empty method
        pass

    def tick(self, dtime):
        # Check if the menu selection has changed and highlight the selection
        if self.engine.overlayMgr.selection == 1:
            self.startButton.setBorderMaterialName("GUI_Red_Border")
            self.controlsButton.setBorderMaterialName("GUI_Gray_Border")
        elif self.engine.overlayMgr.selection == 0:
            self.startButton.setBorderMaterialName("GUI_Gray_Border")
            self.controlsButton.setBorderMaterialName("GUI_Red_Border")

        # Check for Controls page selection and toggle on
        if self.engine.overlayMgr.showControls:
            self.controlsPanel.show()
            self.startButton.hide()
            self.controlsButton.hide()
            self.background.hide()
        else:
            self.controlsPanel.hide()
            self.controlsButton.show()
            self.startButton.show()
            self.background.show()


class StatusOverlay(Overlay):
    name = "Status"

    def __init__(self, engine, overlayManager):
        # Base constructor for Overlay parent class must be called for each new child overlay
        # Demo uses only StatusOverlay
        Overlay.__init__(self, engine, overlayManager, self.name)
        self.loadOverlay()

    def loadOverlay(self):
        self.musicPath = "data/music/DangerZone.mp3"
        # Sets the specifications of the Status Overlay - a display of the currently selected
        # drone's properties
        background = self.overlayManager.createOverlayElement("Panel", self.name+"_Background")
        background.setPosition(0.0, 0.0)
        background.setDimensions(1.0, 1.0)
        background.setMaterialName("GUI_Background")

        self.background = background
        self.overlay.add2D(background)

        # Create a text area for testing
        speedPanel = self.overlayManager.createOverlayElement("Panel", self.name+"_SpeedPanel")
        speedPanel.setPosition(0.04, 0.05)
        speedPanel.setDimensions(0.07, 0.04)

        speedText = self.overlayManager.createOverlayElement("TextArea", self.name+"_SpeedText")
        speedText.setMetricsMode(ogre.GMM_PIXELS)
        speedText.setFontName("BlueHighway")
        speedText.setCharHeight(25)
        speedText.setColour(ogre.ColourValue(1, 1, 1))
        speedPanel.addChild(speedText)

        self.speedPanel = speedPanel
        self.speedPanel.textArea = speedText
        self.overlay.add2D(speedPanel)

        # Create a time text area
        timePanel = self.overlayManager.createOverlayElement("Panel", self.name+"_TimePanel")
        timePanel.setPosition(0.2, 0.05)
        timePanel.setDimensions(0.7, 0.04)

        timeText = self.overlayManager.createOverlayElement("TextArea", self.name+"_TimeText")
        timeText.setMetricsMode(ogre.GMM_PIXELS)
        timeText.setFontName("BlueHighway")
        timeText.setCharHeight(25)
        timeText.setColour(ogre.ColourValue(1, 1, 1))
        timePanel.addChild(timeText)

        self.timePanel = timePanel
        self.timePanel.textArea = timeText
        self.overlay.add2D(timePanel)

        # Create and hide the Warning panel for player moving out of bounds
        warningPanel = self.overlayManager.createOverlayElement("Panel", self.name+"_WarningPanel")
        warningPanel.setPosition(0.15, 0.15)
        warningPanel.setDimensions(0.7, 0.7)
        warningPanel.setMaterialName("Game_Warning_Screen")

        self.warningPanel = warningPanel
        self.overlay.add2D(warningPanel)

        # Create and hide the winner and loser panels
        winPanel = self.overlayManager.createOverlayElement("Panel", self.name+"_WinnerPanel")
        winPanel.setPosition(0.15, 0.15)
        winPanel.setDimensions(0.7, 0.7)
        winPanel.setMaterialName("Game_Winner_Screen")

        self.winPanel = winPanel
        self.overlay.add2D(winPanel)

        losePanel = self.overlayManager.createOverlayElement("Panel", self.name+"_LoserPanel")
        losePanel.setPosition(0.15, 0.15)
        losePanel.setDimensions(0.7, 0.7)
        losePanel.setMaterialName("Game_Loser_Screen")

        self.losePanel = losePanel
        self.overlay.add2D(losePanel)

        # Create Flags for initial demo (Will work on game logic as this progresses)
        self.flagPanelList = []

        for i in range(0,7):
            flagPanel = self.overlayManager.createOverlayElement("Panel", self.name+"_FlagPanel"+str(i))
            flagPanel.setPosition(0.5+0.06*i, 0.90)
            flagPanel.setDimensions(0.06, 0.06)
            flagPanel.setMaterialName("GUI_FlagTransparent")
            self.flagPanelList.append(flagPanel)
            self.overlay.add2D(flagPanel)
            self.test = True

    def markFlag(self, iFlag):
        if iFlag > 0 and iFlag <= len(self.flagPanelList):
            self.flagPanelList[iFlag - 1].setMaterialName("GUI_FlagCollected")

    def countDown(self, count):
        # Empty method for testing until countdown fixed
        pass

    def tick(self, dtime):
        # Update information on player drone with each tick and display
        playerEntity = self.engine.selectionMgr.getSelected()
        playerEntity = playerEntity[0]
        endTime = time.time()
        self.engine.overlayMgr.playerTime = (endTime - self.startTime)
        reportTime = str(round(self.engine.overlayMgr.playerTime, 2))
        speed = str(round(playerEntity.speed, 1) / 10)
        self.speedPanel.textArea.setCaption(speed + " m/h")
        if self.engine.gameMgr.currentState != self.engine.gameMgr.states[2]:
            self.timePanel.textArea.setCaption("TIME: " + reportTime)
        self.markFlag(self.engine.gameMgr.completed)

        # Handle player approaching out of bounds
        if self.engine.gameMgr.outOfBounds:
            self.warningPanel.show()
        else:
            self.warningPanel.hide()

        # Handle win/loss conditions
        if self.engine.gameMgr.player.place == 1 and self.engine.gameMgr.gameFinished:
            self.winPanel.show()
        elif self.engine.gameMgr.player.place != 1 and self.engine.gameMgr.gameFinished:
            self.losePanel.show()
        else:
            self.winPanel.hide()
            self.losePanel.hide()


class LevelOverlay(Overlay):
    name = "Level"

    def __init__(self, engine, overlayManager):
        # Base constructor for Overlay parent class must be called for each new child overlay
        # Demo uses only StatusOverlay
        Overlay.__init__(self, engine, overlayManager, self.name)
        self.loadOverlay()

    def loadOverlay(self):
        self.musicPath = "data/music/TopGearTheme.mp3"
        # Sets the specifications of the Start Screen Overlay - Entry point for the game
        self.background = self.overlayManager.createOverlayElement("Panel", self.name+"_Background")
        self.background.setPosition(0.0, 0.0)
        self.background.setDimensions(1.0, 1.0)
        self.background.setMaterialName("GUI_StartBackground")
        self.overlay.add2D(self.background)

        # Add a Ocean level Button
        button = self.overlayManager.createOverlayElement("BorderPanel", self.name+"_Ocean_Button")
        button.setPosition(0.35, 0.60)
        button.setDimensions(0.12, 0.08)
        button.setMaterialName("Level_Ocean_Button")
        button.setBorderMaterialName("GUI_Gray_Border")
        button.setBorderSize(0.005)

        # Add a City level Button
        cityButton = self.overlayManager.createOverlayElement("BorderPanel", self.name+"_City_Button")
        cityButton.setPosition(0.55, 0.60)
        cityButton.setDimensions(0.12, 0.08)
        cityButton.setMaterialName("Level_City_Button")
        cityButton.setBorderMaterialName("GUI_Gray_Border")
        cityButton.setBorderSize(0.005)

        self.oceanButton = button
        self.cityButton = cityButton
        self.overlay.add2D(self.oceanButton)
        self.overlay.add2D(self.cityButton)

    def countDown(self, count):
        # Unable to solve - empty method
        pass

    def tick(self, dtime):
        # Display the level menu
        self.background.show()
        self.cityButton.show()
        self.oceanButton.show()

        # Check if the menu selection has changed and highlight the selection
        if self.engine.overlayMgr.selection == 0:
            self.oceanButton.setBorderMaterialName("GUI_Red_Border")
            self.cityButton.setBorderMaterialName("GUI_Gray_Border")
        elif self.engine.overlayMgr.selection == 1:
            self.oceanButton.setBorderMaterialName("GUI_Gray_Border")
            self.cityButton.setBorderMaterialName("GUI_Red_Border")