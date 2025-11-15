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
    bd->agregarLinea("ingredientes.txt", linea);
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
    VistaEncargadoInventario vista;

    std::cout << "Nombre del ingrediente a eliminar: ";
    std::cin >> nombre;
    
    inv.eliminarIngrediente(nombre);
    vista.advertenciaEliminacionIngrediente();
    std::cout << " Ingrediente eliminado con éxito.\n";
}

void EncargadoInventario::consultarInventario(const Inventario& inv) {
    std::cout << "[Ingredientes]\n";
    for (const auto& i : inv.getIngredientes()) {
        std::cout << "- " << i.first.getNombre() << "---" << i.first.getUnidadMedida() << "---" << i.second << "\n";
        if (inv.getCantidadIngrediente(i.first.getNombre()) < 50.0) {
            std::cout << "  ¡Alerta! Nivel bajo";
        }
        std::cout << "\n";
    }
}

void EncargadoInventario::verificarNivelMinimo(const Inventario& inv) {
    std::cout << "\n--- Alertas de Reposición ---\n";
    for (const auto& i : inv.getIngredientes()) {
        if (inv.getCantidadIngrediente(i.first.getNombre()) < 5.0) {
            
            std::cout << i.first.getNombre() <<" ¡Alerta! Nivel bajo";
        }
        std::cout << "\n";
    }
}

void EncargadoInventario::consultarStock(VistaAdministrador& inv, const Stock& stockPanes) const {
    for (const auto& p : stockPanes.getVectorPanes()){
        std::cout << "- " << p.getNombre() << ": " << p.getStock() << " unidades\n";
    }
}

void EncargadoInventario::setBaseDatos(BaseDeDatos& bd) {
    this->bd = &bd;
}