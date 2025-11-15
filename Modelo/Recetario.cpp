#include "Recetario.h"

Recetario::Recetario(){
    recetas = {};
}

//Implementación del getter de la clase
std::vector<Recetas> Recetario::getRecetas() const { return recetas; }

//Implementación de los métodos para la gestion de las recetas de la panaderia
void Recetario::agregarReceta(const Recetas& recetaNueva)
    {recetas.push_back(recetaNueva);}

void Recetario::eliminarReceta(const std::string& nombreReceta){
    // Método pendiente
}

Recetas* Recetario::buscarReceta(const std::string& nombreReceta){
    for(int i = 0; i <= recetas.size(); i++){
        if(recetas.at(i).getNombre() == nombreReceta){
            return &recetas[i];
            break;
        }
    }
    return nullptr;
} 