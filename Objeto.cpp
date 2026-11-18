#include "Objeto.h"
#include <iostream>
#include <string>

Objeto::Objeto(std::string n, std::string d, int v, std::string t) {
    this->nombre = n;
    this->descripcion = d;
    this->valorEfecto = v;
    this->tipoEfecto = t;
}
std::string Objeto::getNombre() {
    return this->nombre;
}
std::string Objeto::getDescripcion() {
    return this->descripcion;
}
int Objeto::getValorEfecto() {
    return this->valorEfecto;
}
std::string Objeto::getTipoEfecto() {
    return this->tipoEfecto;
}
