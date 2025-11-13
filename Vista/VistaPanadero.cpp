#include "VistaPanadero.h"

void VistaPanadero::mostrarMenuPanadero() {
    cout << "\n--- Menú Panadero ---\n";
    cout << "1. Registrar Receta\n";
    cout << "2. Registrar Producción\n";
    cout << "3. Consultar Stock\n";
    cout << "4. Salir\n";
}

string VistaPanadero::obtenerNombreReceta() {
    string nombre;
    cout << "Ingrese el nombre de la receta: ";
    cin >> nombre;
    return nombre;
}

void VistaPanadero::obtenerDatosRegistroReceta() {
    cout << "\n[VistaPanadero] Solicitando datos de la nueva receta...\n";
}

int VistaPanadero::obtenerCantidadProduccion() {
    int cantidad;
    cout << "Ingrese cantidad a producir: ";
    cin >> cantidad;
    return cantidad;
}

void VistaPanadero::mostrarInventarioPanes() {
    cout << "\n[VistaPanadero] Mostrando stock de panes...\n";
}

void VistaPanadero::mostrarInventarioRecetas() {
    cout << "\n[VistaPanadero] Mostrando recetas disponibles...\n";
}

void VistaPanadero::mostrarAdvertenciasProduccion() {
    cout << "\n¡Advertencia!  Algunos ingredientes se encuentran por debajo de su límite mínimo.\n";
}
