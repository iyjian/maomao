import math
import random

def isInLine(x1):
    return ((.5 - x1) ** 2) * 2<= .5 ** 2


        

def sqrt2_computing_stable_version(Precision : int):
    counter = 0
    totalRolls = 0
    inLineTimes = 0

    while counter < Precision:
        x = counter / Precision
        if isInLine(x) == True:
            inLineTimes += 1
        totalRolls += 1
        counter += 1
    return totalRolls / inLineTimes
            
        

def sqrt2_computing_random_version(Precision : int):
    totalRolls = 0
    inCircleTimes = 0

    while totalRolls < Precision:
        point = random.random()
        if isInLine(point):
            inCircleTimes += 1
        totalRolls += 1

    return ((4 * inCircleTimes) / totalRolls)