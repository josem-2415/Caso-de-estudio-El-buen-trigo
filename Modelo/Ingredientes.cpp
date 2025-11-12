#include <Ingredientes.h>

Ingredientes::Ingredientes(){
    nombre = " ";
    unidadMedida = " ";
    stock = 0;
    nivelMinimo = 0;
}

//Implementación de getters de la clase
std::string Ingredientes::getNombre() const { return nombre; }
std::string Ingredientes::getUnidadMedida() const {return unidadMedida; }
double Ingredientes::getStock() const {return stock; }
double Ingredientes::getNivelMinimo() const {return nivelMinimo; }

//Implementación de setters de la clase
void Ingredientes::setNombre(const std::string& nombre) { this -> nombre = nombre; }
void Ingredientes::setUnidadMedida(const std::string& unidadMedida) 
    { this -> unidadMedida = unidadMedida; }
void Ingredientes::setStock(const double stock) { this -> stock = stock; }
void Ingredientes::setNivelMinimo(const double nivelMinimo) 
    {this -> nivelMinimo = nivelMinimo; }