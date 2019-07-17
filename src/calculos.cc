#include "calculos.h"

void Calculos::fuerzaGravitacional(Cuerpo &fuente, vector<Cuerpo> cuerpos)
{
    double x, y, distancia;
    double fuerza = 0.0;
    double G = 6.674e-11;
    size_t n = cuerpos.size();

    cout << "\t\t" << fuente.getNombre() << endl;
    for (size_t i = 0; i < n; i++) //se sumaran la estrella y el planeta, no es correcto
    {
        x = fuente.getX() - cuerpos[i].getX();
        y = fuente.getY() - cuerpos[i].getY();

        cout << "DX: " << x << " DY: " << y << endl;

        if (x != 0.0 || y != 0.0)
        {
            distancia = pow(x, 2) + pow(y, 2);

            if(cuerpos[i].getVt() >= sqrt(2 * G * (1.988e30 / sqrt(distancia))))
            {
                cuerpos.erase(cuerpos.begin()+i);
                n--;
                i--;
            }
            else if(sqrt(distancia) < fuente.getRadio()) //rumbo colision, cuando ocurre se deberia recalcular la fuerza denuevo con todos los asteroides
            {
                resultanteColision(fuente, cuerpos[i]);
                cuerpos.erase(cuerpos.begin()+i);
                n--;
                i--;
            }
            else
            {
                cout << "DISTANCIA: " << distancia << endl;
                fuerza += G * ((fuente.getMasa() * cuerpos[i].getMasa()) / distancia); // distancia = raiz(x^2 + y^2) y en fuerza la distancia es al cuadrado
                cuerpos[i].setFuerza(fuerza);
                velocidadOrbital(cuerpos[i], sqrt(distancia)); //recalcular velocidad orbital para cada elemento
            }
        }
    }
    cout << "FG: " << fuerza << endl;
    fuente.setFuerza(fuerza);
}

void Calculos::velocidadOrbital(Cuerpo &cuerpo, const double &rp)
{
    double aceleracionOrbital = cuerpo.getFuerza() / cuerpo.getMasa();
    double velocidadOrbital = sqrt(aceleracionOrbital * rp);
    cuerpo.setVt(velocidadOrbital);
    cout << "AO: " << aceleracionOrbital << " VO: " << velocidadOrbital << endl;
}

void Calculos::calcularVectores(Cuerpo &cuerpo, const double &rp) //hay que actualizar rp, cambiara debido a F, el radio orbital disminuira o crecera
{
    velocidadOrbital(cuerpo, rp);

    double distanciaRecorrida = cuerpo.getXt() + (86400.0 * cuerpo.getVt()); //setXt
    cuerpo.setXt(distanciaRecorrida);

    double anguloAcumulado = (distanciaRecorrida / rp); //rp radio orbital del cuerpo

    cout << "AACUMULADO: " << 360.0 - anguloAcumulado * 180.0 / M_PI << endl;

    cuerpo.setX(rp * cos((2 * M_PI - anguloAcumulado)));
    cuerpo.setY(rp * sin((2 * M_PI - anguloAcumulado))); // (M_PI/180) se cancela con el 180/pi del anguloAcumulado

    cuerpo.setVx(cuerpo.getVt() * sin((2.0 * M_PI - anguloAcumulado)));
    cuerpo.setVy(cuerpo.getVt() * cos((2.0 * M_PI - anguloAcumulado)));

    cout << "Vx: " << cuerpo.getVx() << " Vy: " << cuerpo.getVy() << endl;
}

void Calculos::generarDiscoAsteroides(vector<Cuerpo> &cuerpos, const int &na, const double &rd)
{
    double velocidadOrbitalInicial;
    double anguloPosicion;
    double radioPosicion;
    double coorX, coorY;
    int i = 0;
    double anguloSeccion = 360.0 / na;
    double anguloAcumulado = anguloSeccion;

    std::random_device r;
    std::default_random_engine generador(r());
    std::uniform_real_distribution<double> radioAleatorio(cuerpos[0].getRadio(), rd);

    vector<Cuerpo> asteroides;

    while (i++ < na)
    {
        std::uniform_real_distribution<double> anguloAleatorio(anguloAcumulado - anguloSeccion, anguloAcumulado); //problema aca

        anguloPosicion = anguloAleatorio(generador);
        radioPosicion = radioAleatorio(generador);
        coorX = radioPosicion * cos((anguloPosicion));
        coorY = radioPosicion * sin((anguloPosicion));
        velocidadOrbitalInicial = sqrt(6.674e-11 * (1.988e30 / radioPosicion));

        cuerpos.push_back({to_string(i), coorX, coorY, velocidadOrbitalInicial, radioPosicion, 1e18}); // Agregar velocidaadOrbital, como recalcular el radio?

        anguloAcumulado += anguloSeccion;
    }
}

void Calculos::resultanteColision(Cuerpo &cuerpo_1, Cuerpo &cuerpo_2)
{   
    double masaResultante = cuerpo_1.getMasa() + cuerpo_2.getMasa();
    double momentoCuerpo_1 = cuerpo_1.getMasa() * cuerpo_1.getVt();
    double momentoCuerpo_2 = cuerpo_2.getMasa() * cuerpo_2.getVt();
    double velocidadResultante = (momentoCuerpo_1 + momentoCuerpo_2) / masaResultante;

    //el cuerpo_1 siempre es el mas grande
    cuerpo_1.setMasa(masaResultante);
    cuerpo_1.setVt(velocidadResultante);
}