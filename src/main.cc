#include "calculos.h"
#include "cuerpo.h"
#include "sim.h"

int main(int, char **argv)
{
    int n = atoi(argv[1]);
    int dt = atoi(argv[2]);
    vector<Cuerpo> cuerpos;
    

    //Calculos::generarDiscoAsteroides(cuerpos, n, 1e12);


    Sim sim =  Sim(1.988e30, 1.898e27, 7.78e11, n, 1e12);
    cuerpos = sim.run(dt);

    cout << "X: " << cuerpos[0].getX() << " Y: " << cuerpos[0].getY() << " FG: " << cuerpos[0].getFuerza() <<endl;
    cout << "X: " << cuerpos[1].getX() << " Y: " << cuerpos[1].getY() << " FG: " << cuerpos[1].getFuerza() <<endl;

    /* for(auto &i: cuerpos)
    {
        cout << "X: " << i.getX() << " Y: " << i.getY() << " FG: " << i.getFuerza() <<endl;
    } */

    return 0;
}