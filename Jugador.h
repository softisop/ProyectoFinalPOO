#ifndef JUGADOR_H
#define JUGADOR_
#include "Entidad.h"
#include "Objeto.h"
#include <vector>
#include <iostream>
#include <string>

class Jugador : public Entidad {
private:
    std::vector<Objeto> inventario; // Contenedor para los ítems

public:
    Jugador(std::string n, int s, int p);
    void atacar(Entidad* objetivo) override;
    void recogerObjeto(Objeto obj);
    void usarObjeto(int indice);
    void sanar(int cantidad);
    void aumentarAtaque(int cantidad);
};

#endif