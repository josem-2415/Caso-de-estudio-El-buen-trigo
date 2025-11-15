#include "Vista.h"

void Vista::mostrarMenu() {
    std::cout << "\n--- Menú Principal ---\n";
    std::cout << "1. Iniciar sesión como Panadero\n";
    std::cout << "2. Iniciar sesión como Encargado de Inventario\n";
    std::cout << "3. Iniciar sesión como Administrador\n";
    std::cout << "4. Salir\n";
}

int Vista::obtenerOpcionMenu() {
    int opcion;
    std::cout << "Seleccione una opción: ";
    std::cin >> opcion;
    return opcion;
}