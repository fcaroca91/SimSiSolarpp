#ifndef SIM_H
#define SIM_H
#include "cuerpo.h"
//#include "librerias.h"

class Sim
{
    double ms;
    double mp;
    double rp;
    int na;
    double rd;
    int ns;

public:
    Sim(const double &_ms, const double &mp, const double &_rp, const int &_na, const double &_rd);
    vector<Cuerpo> run(const int &_ns);
    //const string &getNombre() const;
    //void setAceleracion(const double &_aceleracion);
    ~Sim();
};

#endif