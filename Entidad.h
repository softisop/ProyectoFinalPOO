#ifndef ENTIDAD_H
#define ENTIDAD_H
#include <iostream>
#include <string>

class Entidad {
protected:
    std::string nombre;
    int salud;
    int poderAtaque;

public:
    Entidad(std::string n, int s, int p);
    virtual ~Entidad() {}
    virtual void atacar(Entidad* objetivo) = 0; //convierte a Entidad en una clase abs
    void recibirDano(int dano);
    bool estaVivo();
    std::string getNombre();
    int getSalud();
};
#endif