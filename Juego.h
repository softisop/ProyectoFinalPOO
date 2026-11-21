//
// Created by Valentyna on 11/15/2026.
//

#ifndef JUEGO_H
#define JUEGO_H

#include "Jugador.h"
#include "Habitacion.h"
#include "DronSeguridad.h"
#include "CyborgCombate.h"
#include "Entidad.h"

class Juego {
private:
    Jugador* jugador;
    Habitacion* habitacionActual;

    // Lista de todas las habitaciones para liberar memoria al final
    std::vector<Habitacion*> mapa;

    void crearMapa();
    void mostrarMenu();
    void bucleCombate();

public:
    Juego();
    ~Juego(); // Destructor para liberar la memoria dinámica de los punteros
    void iniciar();
};

#endif