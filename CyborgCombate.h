//
// Created by Valentyna on 11/15/2026.
//

#ifndef CYBORGCOMBATE_H
#define CYBORGCOMBATE_H

#include "Entidad.h"

class CyborgCombate : public Entidad {
private:
    int cargaEnergia; // Atributo exclusivo para gestionar su habilidad única

public:
    CyborgCombate(std::string n, int s, int p);

    void atacar(Entidad* objetivo) override;

    // Método exclusivo del jefe
    void ataqueEspecialPlasma(Entidad* objetivo);
};

#endif
