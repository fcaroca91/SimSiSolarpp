#ifndef CUERPO_H
#define CUERPO_H
#include "librerias.h" 

class Cuerpo
{
    string nombre;
    double x;
    double y;
    double vx;
    double vy;
    double radio;
    double fuerza;
    double masa;
    double vt;
    double xt;

public:
    Cuerpo();
    Cuerpo(const string &nombre, const double &_x, const double &_y, const double &_vt, const double &_radio, const double &_masa);
    const string &getNombre() const;
    const double &getX() const;
    const double &getY() const;
    const double &getVx() const;
    const double &getVy() const;
    const double &getRadio() const;
    const double &getFuerza() const;
    const double &getMasa() const;
    const double &getVt() const;
    const double &getXt() const;
    void setNombre(const string &_nombre);
    void setX(const double &_x);
    void setY(const double &_y);
    void setVx(const double &_vx);
    void setVy(const double &_vy);
    void setRadio(const double &_masa);
    void setFuerza(const double &_fuerza);
    void setMasa(const double &_masa);
    void setVt(const double &_vt);
    void setXt(const double &_xt);
    ~Cuerpo();
};

#endif