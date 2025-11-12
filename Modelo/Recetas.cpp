#include "Recetas.h"

Recetas::Recetas(){
    nombre = " ";
    numeroIngredientes = 0;
    ingredientesReceta = {};
    cantidadIngredientes = {};
}

//Implementación de getters de la clase
std::string Recetas::getNombre() const { return nombre; }
int Recetas::getNumeroIngredientes() const { return numeroIngredientes; }
std::vector<Ingredientes>& Recetas::getIngredientesReceta()  
    { return ingredientesReceta; }
std::vector<double>& Recetas::getCantidadIngredientes() 
    { return cantidadIngredientes; }

//Implementación de setters de la clase
void Recetas::setNombre(const std::string& nombre)
    { this -> nombre = nombre; }
void Recetas::setNumeroIngredientes(const int numeroIngredientes)
    {this -> numeroIngredientes = numeroIngredientes; }

//Implementación de métodos de manipulación de los vectores
void Recetas::agregarIngredienteReceta(const Ingredientes& nuevoIngrediente)
    { ingredientesReceta.push_back(nuevoIngrediente); }
void Recetas::agregarCantidadIngrediente(const double cantidadIngrediente)
    { cantidadIngredientes.push_back(cantidadIngrediente); }