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

Panes& Stock::buscarPan(std::string& nombrePan){
    for(int i = 0; i <= panes.size(); i++){
        if(panes.at(i).getNombre() == nombrePan){
            return panes[i];
            break;
        }
    }
}