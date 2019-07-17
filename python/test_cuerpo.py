#Sim simulador(1.988e30, 1.898e27, 7.78e11, 10, 1e12);
#vector<Cuerpo> resultado = simulador.run(2000);

import gravitacion as g
import matplotlib.pyplot as plt

c = g.Sim(1.988e30, 1.898e27, 7.78e11, 20000, 1e12)  #Cuerpo("felipe",2,3,4,5,6,7)
v = c.run(2000) #-2415 3429 dias y 20 horas

x = []
y = []


for a in v:
    if a.getNombre() == "Sol":
        plt.scatter(a.getX(), a.getY(), s=500, color="r")
    elif a.getNombre() == "Planeta":
        plt.scatter(a.getX(), a.getY(), s=200, color="k")
    else:
        x.append(a.getX())
        y.append(a.getY())


""" x.extend(a.getX() for a in v)
y.extend(a.getY() for a in v) """


""" f = g.Cuerpo("felipe",2,3,4,5,6,7)
v.append(f)
print   ([a.getNombre() for a in v]) """

plt.scatter(x, y, s=5, color="b")
plt.axes().set_aspect('equal', 'datalim')

plt.show()