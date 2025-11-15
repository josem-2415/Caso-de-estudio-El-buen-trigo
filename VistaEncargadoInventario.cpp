#include "VistaEncargadoInventario.h"

void VistaEncargadoInventario::mostrarMenuEncargadoInventario() {
    std::cout << "\n--- Menú Encargado de Inventario ---\n";
    std::cout << "1. Registrar Ingrediente\n";
    std::cout << "2. Consultar Inventario\n";
    std::cout << "3. Consultar Stock\n";
    std::cout << "4. Ver Alertas de Reposición\n";
    std::cout << "5. Salir\n";
}

void VistaEncargadoInventario::mostrarInventarioIngredientes(const std::map<Ingredientes, double>& inventario) {
    std::cout << "\n[VistaEncargadoInventario] Mostrando ingredientes registrados...\n";
    for (const auto& item : inventario) {
        std::cout << "Ingrediente: " << item.first.getNombre() << " Unidad de medida: " << item.first.getUnidadMedida() << ", Cantidad: " << item.second << "\n";
    }
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

int VistaEncargadoInventario::obtenerOpcionMenu() {
    int opcion;
    std::cout << "\nSeleccione una opción: ";
    std::cin >> opcion;
    return opcion;
}