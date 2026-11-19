//
// Created by Valentyna on 11/15/2026.
//

#include "DronSeguridad.h"
#include <iostream>

DronSeguridad::DronSeguridad(std::string n, int s, int p) : Entidad(n, s, p) {}

void DronSeguridad::atacar(Entidad* objetivo) {
    std::cout << "\n[!] " << this->nombre << " dispara un laser de seguridad contra "
              << objetivo->getNombre() << " causando " << this->poderAtaque << " de dano.\n";

    // Utilizamos el puntero del objetivo para reducir su salud
    objetivo->recibirDano(this->poderAtaque);
}

