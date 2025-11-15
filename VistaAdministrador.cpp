#include "VistaAdministrador.h"

void VistaAdministrador::mostrarMenuAdministrador() {
    std::cout << "\n--- Menú Administrador ---\n";
    std::cout << "1. Generar Reporte a TXT\n";
    std::cout << "2. Exportar Reporte de Inventario\n";
    std::cout << "3. Salir\n";
}

int VistaAdministrador::obtenerOpcionMenu() {
    int opcion;
    std::cout << "\nSeleccione una opción: ";
    std::cin >> opcion;
    return opcion;
}