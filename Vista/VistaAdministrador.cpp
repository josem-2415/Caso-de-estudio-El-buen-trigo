#include "VistaAdministrador.h"

void VistaAdministrador::mostrarMenuAdministrador() {
    cout << "\n--- Menú Administrador ---\n";
    cout << "1. Generar Reporte de Inventario\n";
    cout << "2. Exportar Reporte a TXT\n";
    cout << "3. Ver Resumen General\n";
    cout << "4. Salir\n";
}

void VistaAdministrador::mostrarReporteInventario() {
    cout << "\n[VistaAdministrador] Mostrando reporte de inventario...\n";
}

void VistaAdministrador::mostrarReporteStock() {
    cout << "\n[VistaAdministrador] Mostrando reporte de stock de productos...\n";
}

void VistaAdministrador::advertenciaExportacion() {
    cout << "\n¡Advertencia! Recuerde guardar los cambios antes de exportar el reporte.\n";
}

int VistaAdministrador::obtenerOpcionMenu() {
    int opcion;
    cout << "\nSeleccione una opción: ";
    cin >> opcion;
    return opcion;
}

void VistaAdministrador::mostrarResumenGeneral() {
    cout << "\n[VistaAdministrador] Mostrando resumen general del sistema...\n";
}

void VistaAdministrador::mostrarReporteGeneral() {
    cout << "\n[VistaAdministrador] Mostrando reporte general completo...\n";
}
