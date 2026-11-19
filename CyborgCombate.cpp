//
// Created by Valentyna on 11/15/2026.
//

#include "CyborgCombate.h"
#include <iostream>

CyborgCombate::CyborgCombate(std::string n, int s, int p) : Entidad(n, s, p) {
    this->cargaEnergia = 100; // Inicia con energía máxima
}

void CyborgCombate::atacar(Entidad* objetivo) {
    // Lógica interna: decide qué ataque usar según su energía
    if (this->cargaEnergia >= 50) {
        this->ataqueEspecialPlasma(objetivo);
    } else {
        std::cout << "\n[!!] " << this->nombre << " golpea a " << objetivo->getNombre()
                  << " con su brazo metalico por " << this->poderAtaque << " de dano.\n";

        objetivo->recibirDano(this->poderAtaque);
        this->cargaEnergia += 25; // Recarga energía con ataques básicos
    }
}

void CyborgCombate::ataqueEspecialPlasma(Entidad* objetivo) {
    int danoEspecial = this->poderAtaque * 2;
    std::cout << "\n[!!!] ALERTA: " << this->nombre << " desenfunda su espada de plasma y ejecuta un corte critico sobre "
              << objetivo->getNombre() << " por " << danoEspecial << " de dano!\n";

    objetivo->recibirDano(danoEspecial);
    this->cargaEnergia -= 50; // Consume su energía especial
}

