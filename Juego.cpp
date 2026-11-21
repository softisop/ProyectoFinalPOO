//
// Created by Valentyna on 11/15/2026.
//

#include "Juego.h"
#include <iostream>

Juego::Juego() {
    this->jugador = new Jugador("Phantom", 100, 25);
    crearMapa();
}

Juego::~Juego() {
    delete this->jugador;
    for (Habitacion* h : mapa) {
        delete h;
    }
}

void Juego::crearMapa() {
    // 1. Crear las 4 habitaciones requeridas
    Habitacion* h1 = new Habitacion("Sector de Mantenimiento", "Una sala con servidores parpadeantes. Hay una puerta al norte.");
    Habitacion* h2 = new Habitacion("Sala de Monitoreo", "Pantallas gigantes iluminan la sala de verde.");
    Habitacion* h3 = new Habitacion("Laboratorio de Cibernetica", "Tubos de estasis brillan en tono cian.");
    Habitacion* h4 = new Habitacion("Vestibulo Principal", "Las enormes puertas de cristal de NovaCorp estan aqui. Es la salida.");

    mapa.push_back(h1); mapa.push_back(h2); mapa.push_back(h3); mapa.push_back(h4);

    // 2. Conectar las habitaciones (Navegacion)
    h1->conectar(h2, "norte");
    h2->conectar(h1, "sur");
    h2->conectar(h3, "este");
    h3->conectar(h2, "oeste");
    h3->conectar(h4, "norte");
    h4->conectar(h3, "sur");

    // 3. Crear objetos y agregarlos a las salas
    h1->agregarObjeto(Objeto("Paquete de Datos", "Mejora permanente de hackeo (+15 ataque)", 15, "ataque"));
    h2->agregarObjeto(Objeto("Bateria de Nanobots", "Restaura 50 puntos de salud", 50, "curacion"));
    h3->agregarObjeto(Objeto("Bateria de Nanobots Max", "Restaura 100 puntos de salud", 100, "curacion"));

    // 4. Crear enemigos y asignarlos a las salas (Polimorfismo en accion)
    h2->agregarEnemigo(new DronSeguridad("Dron Ojo-Rojo", 40, 10));
    h3->agregarEnemigo(new DronSeguridad("Dron Patrulla", 50, 15));
    h4->agregarEnemigo(new CyborgCombate("Cyborg Guardian", 150, 25)); // Jefe Final

    // 5. Ubicar al jugador al inicio del juego
    this->habitacionActual = h1;
}

void Juego::bucleCombate() {
    std::vector<Entidad*> enemigos = habitacionActual->obtenerEnemigos();
    if (enemigos.empty()) return;

    Entidad* enemigo = enemigos[0]; // Combate simple 1vs1
    std::cout << "\n=========================================\n";
    std::cout << "¡ALERTA! Combate iniciado contra " << enemigo->getNombre() << "!\n";

    while (jugador->estaVivo() && enemigo->estaVivo()) {
        std::cout << "\nTu salud: " << jugador->getSalud() << " | Salud enemigo: " << enemigo->getSalud() << "\n";
        std::cout << "1. Atacar\n2. Usar Objeto\nElige una accion: ";
        int accion;
        std::cin >> accion;

        if (accion == 1) {
            jugador->atacar(enemigo);
        } else if (accion == 2) {
            std::cout << "Indice de objeto a usar (0 en adelante): ";
            int ind; std::cin >> ind;
            jugador->usarObjeto(ind);
        }

        if (enemigo->estaVivo()) {
            enemigo->atacar(jugador);
        }
    }

    if (jugador->estaVivo()) {
        std::cout << "\n¡Has derrotado a " << enemigo->getNombre() << "!\n";
        habitacionActual->removerEnemigo(enemigo);
        delete enemigo; // Liberamos la memoria del enemigo muerto
    }
}

void Juego::iniciar() {
    std::cout << "Iniciando PROTOCOLO DE FUGA: NOVACORP...\n";
    bool jugando = true;

    while (jugando && jugador->estaVivo()) {
        std::cout << "\n-----------------------------------------\n";
        std::cout << "[" << habitacionActual->getNombre() << "]\n";
        std::cout << habitacionActual->obtenerDescripcion() << "\n";

        // Revisar si hay combates pendientes
        if (!habitacionActual->obtenerEnemigos().empty()) {
            bucleCombate();
            if (!jugador->estaVivo()) {
                std::cout << "\nHas sido eliminado. Fin de la transmision.\n";
                break;
            }
            // Si el jugador gana en la habitación 4, termina el juego
            if (habitacionActual->getNombre() == "Vestibulo Principal") {
                std::cout << "\n¡VICTORIA! Las puertas se abren. Has escapado de NovaCorp.\n";
                break;
            }
        }

        // Revisar objetos locales
        if (habitacionActual->tieneObjetos()) {
            std::cout << "Ves un objeto en el suelo. 1 para recogerlo, 0 para ignorar: ";
            int op; std::cin >> op;
            if (op == 1) {
                jugador->recogerObjeto(habitacionActual->tomarObjeto(0));
            }
        }

        // Navegación
        std::cout << "\n¿Hacia donde quieres ir? (norte, sur, este, oeste) o 'salir' para terminar: ";
        std::string dir;
        std::cin >> dir;

        if (dir == "salir") {
            jugando = false;
        } else {
            Habitacion* siguiente = habitacionActual->obtenerSalida(dir);
            if (siguiente != nullptr) {
                habitacionActual = siguiente;
            } else {
                std::cout << "No puedes ir en esa direccion. Hay una pared.\n";
            }
        }
    }
}
