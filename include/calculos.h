#ifndef OPERACIONES_H
#define OPERACIONES_H
#include "cuerpo.h"
#include <random>

class Calculos
{
public:
    static void fuerzaGravitacional(Cuerpo &fuente, vector<Cuerpo> cuerpos); //pasar un puntero
    static void velocidadOrbital(Cuerpo &cuerpo, const double &rp);
    static void calcularVectores(Cuerpo &cuerpo, const double &rp); //pasar const
    static void generarDiscoAsteroides(vector<Cuerpo> &cuerpos, const int &na, const double &rd);
    static void resultanteColision(Cuerpo &cuerpo_1, Cuerpo &cuerpo_2);
};

#endif
