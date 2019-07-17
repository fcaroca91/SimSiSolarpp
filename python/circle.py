import random
import math
import matplotlib.animation as anim
import matplotlib.pyplot as plt
import gravitacion as g

fig = plt.figure()

r = 1e12
dt = 2000
ast = 200
puntos = dt+ast+1

c = g.Sim(1.988e30, 1.898e27, 7.78e11, ast, 1e12)  #Cuerpo("felipe",2,3,4,5,6,7)
v = c.run(dt) #-2415

x = []
y = []

for a in v:
    x.append(a.getX())
    y.append(a.getY())


t = []
for i in range(puntos):
    t.append(1)

frame_t = []
for i, item in enumerate(t):
    frame_t.extend([i] * item)


def init():
    fig.clear()
    plt.axes().set_aspect('equal', 'datalim')


def animate(i):
    ejes = r+1
    plt.xlim(-ejes, ejes)
    plt.ylim(-ejes, ejes)
    if v[i].getNombre() == "Sol":
        plt.scatter(v[i].getX(), v[i].getY(), s=500, color="r")
    elif v[i].getNombre() == "Planeta":
        plt.scatter(v[i].getX(), v[i].getY(), s=20, color="k")
    else:
        plt.scatter(v[i].getX(), v[i].getY(), c="b")


ani = anim.FuncAnimation(fig, animate, init_func=init,
                         frames=frame_t, interval=10, repeat=False)

plt.show()

