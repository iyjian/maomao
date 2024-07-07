import math

def isInCircle(x1, y1):
    return (.5 - x1) ** 2 + (.5 - y1) ** 2 <= .5 ** 2


def pi_computing(Precision : int):
    grids = Precision
    totalRolls = 0
    inCircleTimes = 0
    counter = 0
    while counter < grids * grids:
        x = (counter % grids) / grids
        y = math.floor(counter / grids) / grids
        if isInCircle(x, y):
            inCircleTimes += 1
        totalRolls += 1
        counter += 1
    return (4 * inCircleTimes) / totalRolls