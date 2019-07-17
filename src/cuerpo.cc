#include "cuerpo.h"

Cuerpo::Cuerpo()
{
    
}

Cuerpo::Cuerpo(const string &nombre, const double &_x, const double &_y, const double &_vt, const double &_radio, const double &_masa)
{
    this->nombre = nombre;
    x = _x;
    y = _y;
    vt = _vt;
    radio = _radio;
    masa = _masa;
}

const string &Cuerpo::getNombre() const
{
    return nombre;
}

const double &Cuerpo::getX() const
{
    return x;
}

const double &Cuerpo::getY() const
{
    return y;
}

const double &Cuerpo::getVx() const
{
    return vx;
}

const double &Cuerpo::getVy() const
{
    return vy;
}

const double &Cuerpo::getRadio() const
{
    return radio;
}

const double &Cuerpo::getFuerza() const
{
    return fuerza;
}

const double &Cuerpo::getMasa() const
{
    return masa;
}

const double &Cuerpo::getVt() const
{
    return vt;
}

const double &Cuerpo::getXt() const
{
    return xt;
}

void Cuerpo::setNombre(const string &_nombre)
{
    nombre = _nombre;
}

void Cuerpo::setX(const double &_x)
{
    x = _x;
}

void Cuerpo::setY(const double &_y)
{
    y = _y;
}

void Cuerpo::setVx(const double &_vx)
{
    vx = _vx;
}

void Cuerpo::setVy(const double &_vy)
{
    vy = _vy;
}

void Cuerpo::setRadio(const double &_radio)
{
    radio = _radio;
}

void Cuerpo::setFuerza(const double &_fuerza)
{
    fuerza = _fuerza;
}

void Cuerpo::setMasa(const double &_masa)
{
    masa = _masa;
}

void Cuerpo::setVt(const double &_vt)
{
    vt = _vt;
}

void Cuerpo::setXt(const double &_xt)
{
    xt = _xt;
}

Cuerpo::~Cuerpo()
{
    //cout << "Morí" << endl;
}