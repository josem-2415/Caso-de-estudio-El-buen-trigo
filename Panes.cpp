#include "Panes.h"

Panes::Panes(const std::string& nombre, int stock, const Recetas& receta) : nombre(nombre), stock(stock), receta(receta) {}

//Implementación de getters de la clase
std::string Panes::getNombre() const {
    return nombre; 
}
int Panes::getStock() const {
    return stock; 
}
Recetas Panes::getReceta() const { 
    return receta;
}

//Implementación de setters de la clase
void Panes::setNombre(const std::string& nombre) { this -> nombre = nombre; }
void Panes::setStock(const int stock) { this -> stock = stock; }
void Panes::setReceta(const Recetas& receraPan) { this -> receta = receta; }
