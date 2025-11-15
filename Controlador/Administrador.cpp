#include "Administrador.h"

Administrador::Administrador() {}

void Administrador::exportarReporteTxt(const VistaAdministrador& vinv) {
    ofstream file("reporte_inventario.txt");
    if (!file.is_open()) {
        cout << "Error al crear el archivo.\n";
        return;
    }

    VistaAdministrador vista;

    file << "===== REPORTE DE INVENTARIO Y STOCK =====\n\n";
    
    file << "[Ingredientes]\n";
    vista.mostrarReporteInventario();

    file << "\n[Stock]\n";
    vista.mostrarReporteStock();

    file.close();
    cout << "Reporte exportado exitosamente como 'reporte_inventario.txt'.\n";
}
