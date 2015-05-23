#######
#Team Purple Flower
#Producer: Britanny McGarr
#Member: Zachary Carlson
#Member: Sara Garic
#######

def clamp(val, min, max):
    if val <= min:
        return min
    elif val >= max:
        return max

    return val

import math

twopi  = 2.0 * math.pi
pi     = math.pi
halfpi = math.pi/2.0

def fixAngle(angle):
    while angle > pi:
        angle -= twopi
    while angle < -pi:
        angle += twopi

    return angle

def diffAngle(angle1, angle2):
    return fixAngle(angle1 - angle2)

def getDistance(pos1, pos2):
    x = (pos1.x - pos2.x) * (pos1.x - pos2.x)
    y = (pos1.y - pos2.y) * (pos1.y - pos2.y)
    z = (pos1.z - pos2.z) * (pos1.z - pos2.z)
    dist = math.sqrt(x + y + z)
    return dist