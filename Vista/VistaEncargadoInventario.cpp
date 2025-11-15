#include "VistaEncargadoInventario.h"

void VistaEncargadoInventario::mostrarMenuEncargadoInventario() {
    std::cout << "\n--- Menú Encargado de Inventario ---\n";
    std::cout << "1. Registrar Ingrediente\n";
    std::cout << "2. Consultar Inventario\n";
    std::cout << "3. Ver Alertas de Reposición\n";
    std::cout << "4. Salir\n";
                int opcion;
                std::cin >> opcion;
}

void VistaEncargadoInventario::mostrarInventarioIngredientes() {
    std::cout << "\n[VistaEncargadoInventario] Mostrando ingredientes registrados...\n";
}

void VistaEncargadoInventario::mostrarAlertasReposicion() {
    std::cout << "\n[VistaEncargadoInventario] Mostrando alertas de reposición...\n";
}

bool VistaEncargadoInventario::advertenciaEliminacionIngrediente() {
    char respuesta;
    std::cout << "\n¿Está seguro que desea eliminar este ingrediente? (s/n): ";
    std::cin >> respuesta;
    return (respuesta == 's' || respuesta == 'S');
}

void VistaEncargadoInventario::ingredienteNegativo() {
    std::cout << "\n¡Advertencia! No se permite registrar stock negativo.\n";
}
