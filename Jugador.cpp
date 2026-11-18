#include "Jugador.h"
#include <iostream>

Jugador::Jugador(std::string n, int s, int p) : Entidad(n, s, p) {}
void Jugador::atacar(Entidad* objetivo) {
    std::cout << "\n>>> " << this->nombre << " ejecuta un hackeo ofensivo contra "
              << objetivo->getNombre() << " por " << this->poderAtaque << " de dano!\n";

    objetivo->recibirDano(this->poderAtaque);
}

void Jugador::recogerObjeto(Objeto obj) {
    this->inventario.push_back(obj);
    std::cout << "Has recogido: " << obj.getNombre() << "\n";
}

void Jugador::usarObjeto(int indice) {

    if (indice >= 0 && indice < this->inventario.size()) { // Validar que el índice esté dentro del rango del vector
        Objeto item = this->inventario[indice];
        std::cout << "Usando " << item.getNombre() << "... " << item.getDescripcion() << std::endl;

        if (item.getTipoEfecto() == "curacion") {
            this->sanar(item.getValorEfecto());
        } else if (item.getTipoEfecto() == "ataque") {
            this->aumentarAtaque(item.getValorEfecto());
        }

        this->inventario.erase(this->inventario.begin() + indice);//para eliminar el objeto despues de usarlo
    } else {
        std::cout << "Indice de inventario invalido."<<std::endl;
    }
}

void Jugador::sanar(int cantidad) {
    this->salud += cantidad;
    std::cout << this->nombre << " recupera " << cantidad << " puntos de salud. Salud actual: " << this->salud << std::endl;
}

void Jugador::aumentarAtaque(int cantidad) {
    this->poderAtaque += cantidad;
    std::cout << "Poder de ataque de " << this->nombre << " incrementado en " << cantidad << ". Nuevo ataque: " << this->poderAtaque << std::endl;
}
