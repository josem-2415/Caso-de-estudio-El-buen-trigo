#include "Recetas.h"

Recetas::Recetas(std::string nombre, int numeroIngredientes, std::map<Ingredientes, double> ingredientesReceta) 
                : nombre(nombre), numeroIngredientes(numeroIngredientes), ingredientesReceta(ingredientesReceta) {}

Recetas::Recetas() : nombre(""), numeroIngredientes(0), ingredientesReceta() {}

//Implementación de getters de la clase
std::string Recetas::getNombre() const { 
    return nombre;
}
int Recetas::getNumeroIngredientes() const {
    return numeroIngredientes; 
}
const std::map<Ingredientes, double>& Recetas::getIngredientesReceta() const {
    return ingredientesReceta;
}

//Implementación de setters de la clase
void Recetas::setNombre(const std::string& nombre) {
    this -> nombre = nombre; 
}