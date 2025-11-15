#include "Administrador.h"

Administrador::Administrador() {}

void Administrador::generarReporte(const Inventario& inv, const Stock& stockDePanes, const VistaAdministrador& vadm) {
    std::cout<< "===== REPORTE DE INVENTARIO Y STOCK =====\n\n";

    std::cout << "[Ingredientes]\n";
    for (const auto& i : inv.getIngredientes()) {
        std::cout << "- " << i.first.getNombre() << "---" << i.first.getUnidadMedida() << "---" << i.second << "\n";
        if (inv.getCantidadIngrediente(i.first.getNombre()) < 5.0) {
            std::cout << "  ¡Alerta! Nivel bajo";
        }
        std::cout << "\n";
    }

    std::cout << "\n[Productos]\n";
    for (const auto& p : stockDePanes.getVectorPanes())
        std::cout << "- " << p.getNombre() << ": " << p.getStock() << " unidades\n";

    std::cout << "Reporte impreso exitosamente.\n";
}

/*void Administrador::exportarReporteTxt(const VistaAdministrador& vadm) {
    ofstream file("reporte_inventario.txt");
    if (!file.is_open()) {
        cout << "Error al crear el archivo.\n";
        return;
    }

    VistaAdministrador vista;

    file << "===== REPORTE DE INVENTARIO Y STOCK =====\n\n";
    
    file << "[Ingredientes]\n";
    vista.mostrarReporteInventario(std::map<Ingredientes, double>());

    file << "\n[Stock]\n";
    vista.mostrarReporteStock(std::vector<Panes>());

    file.close();
    cout << "Reporte exportado exitosamente como 'reporte_inventario.txt'.\n";
}*/
void Administrador::exportarReporteTxt(const Inventario& inv, const Stock& stockDePanes) {
    ofstream file("reporte_inventario.txt");
    if (!file.is_open()) {
        cout << "Error al crear el archivo.\n";
        return;
    }

    file << "===== REPORTE DE INVENTARIO Y STOCK =====\n\n";

    file << "[Ingredientes]\n";
    for (const auto& i : inv.getIngredientes()) {
        file << "- " << i.first.getNombre() << "---" << i.first.getUnidadMedida() << "---" << i.second << "\n";
        if (inv.getCantidadIngrediente(i.first.getNombre()) < 5.0) {
            file << "  ¡Alerta! Nivel bajo";
        }
        file << "\n";
    }

    file << "\n[Productos]\n";
    for (const auto& p : stockDePanes.getVectorPanes())
        file << "- " << p.getNombre() << ": " << p.getStock() << " unidades\n";

    file.close();
    cout << "Reporte exportado exitosamente como 'reporte_inventario.txt'.\n";
}