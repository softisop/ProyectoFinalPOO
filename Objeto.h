#ifndef OBJETO_H
#define OBJETO_H
#include <iostream>
#include <string>


class Objeto {
private:
    std::string nombre;
    std::string descripcion;
    int valorEfecto;
    std::string tipoEfecto; // Puede ser "curacion" o "ataque"

public:
    Objeto(std::string n, std::string d, int v, std::string t);
    std::string getNombre();
    std::string getDescripcion();
    int getValorEfecto();
    std::string getTipoEfecto();
};
#endif