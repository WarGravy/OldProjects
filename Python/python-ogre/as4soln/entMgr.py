
from vector import MyVector
import ent

class EntMgr:
    def __init__(self, gfx):
        print "starting ent mgr"
        self.gfx = gfx
        self.ents = {}
        self.nEnts = 0
        self.selectedEntIndex = 0
        self.selectedEnt = None
        self.entTypes = [ent.CIGARETTE, ent.CVN68, ent.DDG51, ent.BOAT, ent.BOAT2, ent.SLEEK, ent.MONTEREY, ent.JETSKI, ent.ALIENSHIP, ent.SAILBOAT]
        

    def createEnt(self, entType, pos = MyVector(0,0,0), yaw = 0):
        ent = entType(self.nEnts, pos = pos, yaw = yaw)

        self.ents[self.nEnts] = ent;
        self.selectedEnt = ent
        self.selectedEntIndex = self.nEnts;

        self.nEnts = self.nEnts + 1
        return ent

    def selectNextEnt(self):
        if self.selectedEntIndex >= self.nEnts - 1:
            self.selectedEntIndex = 0
        else:
            self.selectedEntIndex += 1
        self.selectedEnt = self.ents[self.selectedEntIndex]
        print "EntMgr selected: ", str(self.selectedEnt)
        return self.selectedEnt

    def getSelected(self):
        return self.selectedEnt



        





