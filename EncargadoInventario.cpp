#include "EncargadoInventario.h"

EncargadoInventario::EncargadoInventario(){}

void EncargadoInventario::registrarIngrediente(Inventario& inv) {
    std::string nombre, unidad;
    float cantidad;

    std::cout << "Nombre del ingrediente: ";
    std::cin >> nombre;
    std::cout << "Unidad de medida: ";
    std::cin >> unidad;
    std::cout << "Cantidad disponible: ";
    std::cin >> cantidad;

    inv.agregarIngrediente(Ingredientes(nombre, unidad), cantidad);
    std::string linea;
    linea = nombre + " --- " + unidad + " --- " + std::to_string(cantidad) + " ; ";

    std::cout << " Ingrediente registrado con éxito.\n";
    bd.agregarLinea("ingredientes.txt", linea);
}

void EncargadoInventario::editarIngrediente(Inventario& inv) {
    std::string nombre;

    std::cout << "Nombre del ingrediente a editar: ";
    std::cin >> nombre;
    
    inv.buscarIngrediente(nombre);
    
    std::cout << " Ingrediente actualizado con éxito.\n";
}

void EncargadoInventario::eliminarIngrediente(Inventario& inv){
    std::string nombre;

    std::cout << "Nombre del ingrediente a eliminar: ";
    std::cin >> nombre;
    
    inv.eliminarIngrediente(nombre);
    std::cout << " Ingrediente eliminado con éxito.\n";
}

void EncargadoInventario::consultarInventario(const Inventario& inv) {
    const auto& ingredientes = inv.getIngredientes();
    if (ingredientes.empty()) {
        std::cout << " No hay ingredientes registrados.\n";
        return;
    }

    std::cout << "\n--- Inventario de Ingredientes ---\n";
    for (const auto& i : ingredientes)
        std::cout << i.first.getNombre() << " (" << i.second << " " << i.first.getUnidadMedida() << ")\n";
}

void EncargadoInventario::verificarNivelMinimo(VistaEncargadoInventario& vinv) {
    std::cout << "\n--- Alertas de Reposición ---\n";
    vinv.mostrarAlertasReposicion();
}

void EncargadoInventario::consultarStock(VistaAdministrador& inv, const Stock& stockPanes) const {
    for (const auto& p : stockPanes.getVectorPanes())
        std::cout << "- " << p.getNombre() << ": " << p.getStock() << " unidades\n";

    std::cout << "Reporte impreso exitosamente.\n";
}
