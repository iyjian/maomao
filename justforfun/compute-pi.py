import random


def rand2DPoint():
    return [random.random(), random.random()]

def isInCircle(x1, y1):
    return (.5 - x1) ** 2 + (.5 - y1) ** 2 <= .5 ** 2

def pi_computing(Precision : int):

    totalRolls = 0
    inCircleTimes = 0

    while totalRolls < Precision:
        point = rand2DPoint()
        if isInCircle(*point):
            inCircleTimes += 1
        totalRolls += 1

    return ((4 * inCircleTimes) / totalRolls)

print(pi_computing(100))
