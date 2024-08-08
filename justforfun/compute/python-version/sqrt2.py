import math
import random

def isInLine(x1):
    return ((.5 - x1) ** 2) * 2<= .5 ** 2


        

def sqrt2_computing(Precision : int):
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
