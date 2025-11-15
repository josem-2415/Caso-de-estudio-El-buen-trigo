#include "VistaAdministrador.h"

void VistaAdministrador::mostrarMenuAdministrador() {
    std::cout << "\n--- Menú Administrador ---\n";
    std::cout << "1. Generar Reporte de Inventario\n";
    std::cout << "2. Exportar Reporte a TXT\n";
    std::cout << "3. Ver Resumen General\n";
    std::cout << "4. Salir\n";
                int opcion;
                std::cin >> opcion;
}

void VistaAdministrador::mostrarReporteInventario() {
    std::cout << "\n[VistaAdministrador] Mostrando reporte de inventario...\n";
}

void VistaAdministrador::mostrarReporteStock() {
    std::cout << "\n[VistaAdministrador] Mostrando reporte de stock de productos...\n";
}

void VistaAdministrador::advertenciaExportacion() {
    std::cout << "\n¡Advertencia! Recuerde guardar los cambios antes de exportar el reporte.\n";
}

int VistaAdministrador::obtenerOpcionMenu() {
    int opcion;
    std::cout << "\nSeleccione una opción: ";
    std::cin >> opcion;
    return opcion;
}

void VistaAdministrador::mostrarResumenGeneral() {
    std::cout << "\n[VistaAdministrador] Mostrando resumen general del sistema...\n";
}

void VistaAdministrador::mostrarReporteGeneral() {
    std::cout << "\n[VistaAdministrador] Mostrando reporte general completo...\n";
}
