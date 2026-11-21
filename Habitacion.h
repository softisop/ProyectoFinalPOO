//
// Created by Valentyna on 11/15/2026.
//
#ifndef HABITACION_H
#define HABITACION_H

#include <string>
#include <vector>
#include "Entidad.h"
#include "Objeto.h"

class Habitacion {
private:
    std::string nombre;
    std::string descripcion;

    // Contenedores de la STL para agregación y composición requeridas
    std::vector<Entidad*> enemigos; // Agregación: La habitación conoce a los enemigos, pero no los destruye
    std::vector<Objeto> objetosLocales; // Composición: Objetos listos para ser recogidos

    // Punteros para conectar el mapa (Asociación)
    Habitacion* norte;
    Habitacion* sur;
    Habitacion* este;
    Habitacion* oeste;

public:
    // Constructor
    Habitacion(std::string n, std::string d);

    // Métodos de navegación
    void conectar(Habitacion* otra, std::string direccion);
    Habitacion* obtenerSalida(std::string direccion);

    // Gestión de Enemigos
    void agregarEnemigo(Entidad* enemigo);
    void removerEnemigo(Entidad* enemigo);
    std::vector<Entidad*> obtenerEnemigos();

    // Gestión de Botín (Loot)
    void agregarObjeto(Objeto obj);
    Objeto tomarObjeto(int indice);
    bool tieneObjetos();

    // Información
    std::string obtenerDescripcion();
    std::string getNombre();
};

#endif

