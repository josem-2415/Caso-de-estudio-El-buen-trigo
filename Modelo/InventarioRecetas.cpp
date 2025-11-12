#include "InventarioRecetas.h"

InventarioRecetas::InventarioRecetas(){
    recetas = {};
}

//Implementación del getter de la clase
std::vector<Recetas> InventarioRecetas::getRecetas() const { return recetas; }

//Implementación de los métodos para la gestion de las recetas de la panaderia
void InventarioRecetas::agregarReceta(const Recetas& recetaNueva)
    {recetas.push_back(recetaNueva);}

void InventarioRecetas::eliminarReceta(const std::string& nombreReceta){
    // Método pendiente
}

Recetas& InventarioRecetas::buscarReceta(const std::string& nombreReceta){
    for(int i = 0; i <= recetas.size(); i++){
        if(recetas.at(i).getNombre() == nombreReceta){
            return recetas[i];
            break;
        }
    }
} 