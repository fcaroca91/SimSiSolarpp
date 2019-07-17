#include "sim.h"
#include "calculos.h"

Sim::Sim(const double &_ms, const double &_mp, const double &_rp, const int &_na, const double &_rd)
{
    ms = _ms;
    mp = _mp;
    rp = _rp;
    na = _na;
    rd = _rd;
}

vector<Cuerpo> Sim::run(const int &_ns)
{
    ns = _ns;
    vector<Cuerpo> cuerpos;

    cuerpos.push_back({"Sol", 0, 0, 0, 7e8, ms}); //podria llamar a velocidadOrbital
    cuerpos.push_back({"Planeta", rp, 0, rp, 7e7, mp}); //podria llamar a velocidadOrbital

    Calculos::generarDiscoAsteroides(cuerpos, na, rd);

    for(int i=1; i<=ns; i++) // Emular dias en la simulacion
    {
        Calculos::fuerzaGravitacional(cuerpos[0], cuerpos);
        Calculos::fuerzaGravitacional(cuerpos[1], cuerpos);
        Calculos::calcularVectores(cuerpos[1], rp);

        //cuerpos.push_back(cuerpos[1]);
    }

    cuerpos.push_back(cuerpos[1]);
    return cuerpos;
}

Sim::~Sim()
{
    cout << "guardar en un archivo para persistir el vector" <<endl;
}