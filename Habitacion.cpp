//
// Created by Valentyna on 11/15/2026.
//

#include "Habitacion.h"
#include <iostream>

Habitacion::Habitacion(std::string n, std::string d) {
    this->nombre = n;
    this->descripcion = d;

    // Inicializar punteros en nullptr es una práctica crucial en C++
    this->norte = nullptr;
    this->sur = nullptr;
    this->este = nullptr;
    this->oeste = nullptr;
}

// Asigna el puntero de la habitación vecina a la dirección correspondiente
void Habitacion::conectar(Habitacion* otra, std::string direccion) {
    if (direccion == "norte") this->norte = otra;
    else if (direccion == "sur") this->sur = otra;
    else if (direccion == "este") this->este = otra;
    else if (direccion == "oeste") this->oeste = otra;
}

// Devuelve el puntero hacia la siguiente habitación, o nullptr si es pared
Habitacion* Habitacion::obtenerSalida(std::string direccion) {
    if (direccion == "norte") return this->norte;
    if (direccion == "sur") return this->sur;
    if (direccion == "este") return this->este;
    if (direccion == "oeste") return this->oeste;
    return nullptr;
}

void Habitacion::agregarEnemigo(Entidad* enemigo) {
    this->enemigos.push_back(enemigo);
}

// Utilizamos un iterador para buscar y borrar de forma segura el puntero del enemigo muerto
void Habitacion::removerEnemigo(Entidad* enemigo) {
    for (auto it = this->enemigos.begin(); it != this->enemigos.end(); ++it) {
        if (*it == enemigo) {
            this->enemigos.erase(it);
            break;
        }
    }
}

std::vector<Entidad*> Habitacion::obtenerEnemigos() {
    return this->enemigos;
}

void Habitacion::agregarObjeto(Objeto obj) {
    this->objetosLocales.push_back(obj);
}

// Extrae un objeto de la sala (para pasarlo al inventario del jugador)
Objeto Habitacion::tomarObjeto(int indice) {
    Objeto obj = this->objetosLocales[indice];
    this->objetosLocales.erase(this->objetosLocales.begin() + indice);
    return obj;
}

bool Habitacion::tieneObjetos() {
    return !this->objetosLocales.empty();
}

std::string Habitacion::obtenerDescripcion() {
    return this->descripcion;
}

std::string Habitacion::getNombre() {
    return this->nombre;
}
