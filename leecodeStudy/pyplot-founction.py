import matplotlib.pyplot as plt

xpoints = []
ypoints = []
for x in range(-1000000000, 1000000000, 5000):
    xpoints.append(x)
    ypoints.append((2 * x - 1) * (3 * x - 2) * (3 * x - 4))

plt.plot(xpoints, ypoints)
plt.show()

