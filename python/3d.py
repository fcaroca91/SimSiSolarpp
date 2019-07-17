from mpl_toolkits.mplot3d import Axes3D
import matplotlib.pyplot as plt
import numpy as np
import time, math

np.random.seed(int(time.time()))


r = 2
puntos = 500
x = [].append(5)
y = [].append(5)
z = [].append(5)
angle = []
for i in range(0, puntos):
    angle.append(i*(puntos/pow(puntos,2))*(math.pi*2))
angle.sort()
for i in angle:
    x.append(r*math.cos(i))
    y.append(r*math.sin(i))
    z.append(5)


""" 
n = 500

rx = (100 - 0)*np.random.rand(n) + 0
ry = (100 - 0)*np.random.rand(n) + 0
rz = (100 - 0)*np.random.rand(n) + 0 """


fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

""" x =[1,2,3,4,5,6,7,8,9,10]
y =[5,6,2,3,13,4,1,2,4,8]
z =[2,3,3,3,5,7,9,11,9,10] """



ax.scatter(x, y, z, c='r', marker='o')

ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

plt.show()


""" # This import registers the 3D projection, but is otherwise unused.
from mpl_toolkits.mplot3d import Axes3D  # noqa: F401 unused import

import matplotlib.pyplot as plt
import numpy as np

# Fixing random state for reproducibility
np.random.seed(19680801)


def randrange(n, vmin, vmax):
    '''
    Helper function to make an array of random numbers having shape (n, )
    with each number distributed Uniform(vmin, vmax).
    '''
    return (vmax - vmin)*np.random.rand(n) + vmin

fig = plt.figure()
ax = fig.add_subplot(111, projection='3d')

n = 500

# For each set of style and range settings, plot n random points in the box
# defined by x in [23, 32], y in [0, 100], z in [zlow, zhigh].
for m, zlow, zhigh in [('o', -50, -25), ('^', -30, -5)]:
    xs = randrange(n, 23, 32)
    ys = randrange(n, 0, 100)
    zs = randrange(n, zlow, zhigh)
    ax.scatter(xs, ys, zs, marker=m)

ax.set_xlabel('X Label')
ax.set_ylabel('Y Label')
ax.set_zlabel('Z Label')

plt.show() """