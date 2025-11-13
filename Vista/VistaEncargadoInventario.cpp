#include "VistaEncargadoInventario.h"

void VistaEncargadoInventario::mostrarMenuEncargadoInventario() {
    cout << "\n--- Menú Encargado de Inventario ---\n";
    cout << "1. Registrar Ingrediente\n";
    cout << "2. Consultar Inventario\n";
    cout << "3. Ver Alertas de Reposición\n";
    cout << "4. Salir\n";
}

void VistaEncargadoInventario::mostrarInventarioIngredientes() {
    cout << "\n[VistaEncargadoInventario] Mostrando ingredientes registrados...\n";
}

void VistaEncargadoInventario::mostrarAlertasReposicion() {
    cout << "\n[VistaEncargadoInventario] Mostrando alertas de reposición...\n";
}

bool VistaEncargadoInventario::advertenciaEliminacionIngrediente() {
    char respuesta;
    cout << "\n¿Está seguro que desea eliminar este ingrediente? (s/n): ";
    cin >> respuesta;
    return (respuesta == 's' || respuesta == 'S');
}

void VistaEncargadoInventario::stockNegativo() {
    cout << "\n¡Advertencia! No se permite registrar stock negativo.\n";
}
