#include "Stock.h"

Stock::Stock(){
    panes = {};
}

//Implementación de getter de la clase
std::vector<Panes> Stock::getVectorPanes() const {return panes; }


//Implementación de métodos para gestionar los panes de la panaderia
void Stock::agregarPan(const Panes& nuevoPan, Inventario& inventario) {
    panes.push_back(nuevoPan);
    inventario.eliminarIngrediente(nuevoPan.getReceta().getNombre());
}

void Stock::eliminarPanes(std::string& nombrePan, int cantidadEliminar)
    {buscarPan(nombrePan).setStock(buscarPan(nombrePan).getStock() - cantidadEliminar); }

Panes& Stock::buscarPan(std::string& nombrePan) {
    for (size_t i = 0; i < panes.size(); i++) {   // < en vez de <=
        if (panes[i].getNombre() == nombrePan) {  // no hace falta .at()
            return panes[i];
        }
    }

    // Si no lo encuentra:
    throw std::runtime_error("Pan no encontrado en Stock::buscarPan");
}

void Stock::setBaseDatos(BaseDeDatos& bd) {
    this->bd = &bd;
}

void Stock::cargarDesdeBD(BaseDeDatos& bd, const std::vector<Recetas>& recetas) {

    for (const std::string& linea : bd.obtenerDatos("stock.txt")) {

        // Formato: PanBlanco;20;

        size_t p = linea.find(';');
        if (p == std::string::npos) continue;

        std::string nombre = linea.substr(0, p);
        int cantidad = std::stoi(linea.substr(p + 1));

        // Buscar la receta asociada
        const Recetas* recPtr = nullptr;
        for (const auto& r : recetas) {
            if (r.getNombre() == nombre) {
                recPtr = &r;
                break;
            }
        }
        if (!recPtr) continue;

        panes.push_back( Panes(nombre, cantidad, *recPtr) );
    }
}
