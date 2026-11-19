//
// Created by Valentyna on 11/15/2026.
//
#ifndef DRONSEGURIDAD_H
#define DRONSEGURIDAD_H

#include "Entidad.h"

class DronSeguridad : public Entidad {
public:
    // Constructor
    DronSeguridad(std::string n, int s, int p);

    // Sobrescritura obligatoria del método puro
    void atacar(Entidad* objetivo) override;
};

#endif
