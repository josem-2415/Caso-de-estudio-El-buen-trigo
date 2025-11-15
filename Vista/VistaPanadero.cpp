#include "VistaPanadero.h"

void VistaPanadero::mostrarMenuPanadero() {
    std::cout << "\n--- Menú Panadero ---\n";
    std::cout << "1. Registrar Receta\n";
    std::cout << "2. Registrar Producción\n";
    std::cout << "3. Consultar Stock\n";
    std::cout << "4. Salir\n";
                int opcion;
                std::cin >> opcion;
}

std::string VistaPanadero::obtenerNombreReceta() {
    std::string nombre;
    std::cout << "Ingrese el nombre de la receta: ";
    std::cin >> nombre;
    return nombre;
}

int VistaPanadero::obtenerCantidadIngredientes() {
    int ingredientes;
    std::cout << "Ingrese la cantidad de ingredientes: ";
    std::cin >> ingredientes;
    return ingredientes;
}

std::map<Ingredientes, double> VistaPanadero::obtenerIngredientesReceta() {
    std::map<Ingredientes, double> ingredientesReceta;
    int cantidadIngredientes = obtenerCantidadIngredientes();

    for (int i = 0; i < cantidadIngredientes; ++i) {
        std::string nombreIngrediente;
        double cantidad;

        std::cout << "Ingrese el nombre del ingrediente " << (i + 1) << ": ";
        std::cin >> nombreIngrediente;
        std::cout << "Ingrese la cantidad de " << nombreIngrediente << ": ";
        std::cin >> cantidad;

        ingredientesReceta[Ingredientes(nombreIngrediente, "unidad")] = cantidad; // Asumiendo unidad genérica
    }

    return ingredientesReceta;
}

void VistaPanadero::obtenerDatosRegistroReceta() {
    std::cout << "\n[VistaPanadero] Solicitando datos de la nueva receta...\n";

}

int VistaPanadero::obtenerCantidadProduccion() {
    int cantidad;
    std::cout << "Ingrese cantidad a producir: ";
    std::cin >> cantidad;
    return cantidad;
}

void VistaPanadero::mostrarInventarioPanes() {
    std::cout << "\n[VistaPanadero] Mostrando stock de panes...\n";
}

void VistaPanadero::mostrarInventarioRecetas() {
    std::cout << "\n[VistaPanadero] Mostrando recetas disponibles...\n";
}

void VistaPanadero::mostrarAdvertenciasProduccion() {
    std::cout << "\n¡Advertencia!  Algunos ingredientes se encuentran por debajo de su límite mínimo.\n";
}
