#include "Entidad.h"
#include <iostream>
#include <string>
Entidad::Entidad(std::string n, int s, int p) {
    this->nombre = n;
    this->salud = s;
    this->poderAtaque = p;
}
void Entidad::recibirDano(int dano) {
    this->salud -= dano;
    if (this->salud < 0) {
        this->salud = 0; //Evitar que salud sea negativa
    }
    std::cout << this->nombre << " recibe " << dano << " puntos de dano. Salud restante: "
              << this->salud << "\n";
}

//Verificar que la entidad sigue viva
bool Entidad::estaVivo() {
    return this->salud > 0;
}
std::string Entidad::getNombre() {
    return this->nombre;
}
int Entidad::getSalud() {
    return this->salud;
}
