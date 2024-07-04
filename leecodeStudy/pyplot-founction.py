import matplotlib.pyplot as plt
import numpy as np

xpoints = np.array([])
ypoints = np.array([])
for i in range(-100000000, 100000000):
    xpoints = np.append(xpoints, i)
    ypoints = np.append(ypoints, (2 * i - 1) * (3 * i - 2) * (4 * i - 3))


plt.plot(xpoints, ypoints)
plt.show()

