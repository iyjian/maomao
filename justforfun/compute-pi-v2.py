import random

# def rand2DPoint():
#     return [random.random(), random.random()]

def isInCircle(x1, y1):
    return (.5 - x1) ** 2 + (.5 - y1) ** 2 <= .5 ** 2

# print(rand2DPoint())

totalRolls = 0
inCircleTimes = 0

while totalRolls < 10000000:
    # point = rand2DPoint()
    rand = random.random()
    if isInCircle(rand, rand):
        inCircleTimes += 1
    totalRolls += 1

print((4 * inCircleTimes) / totalRolls)
