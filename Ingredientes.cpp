#include "Ingredientes.h"

Ingredientes::Ingredientes(std::string n, std::string um) : nombre(n), unidadMedida(um) {}
Ingredientes::Ingredientes(){}

//Implementación de getters de la clase
std::string Ingredientes::getNombre() const {
    return nombre; 
}
std::string Ingredientes::getUnidadMedida() const {
    return unidadMedida; 
}