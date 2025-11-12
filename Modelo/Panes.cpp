#include "Panes.h"

Panes::Panes(){
    nombre = " ";
    stock = 0;
}

//Implementación de getters de la clase
std::string Panes::getNombre() const { return nombre; }
int Panes::getStock() const { return stock; }
<<<<<<< HEAD
Receta Panes::getReceta() const { return receta; }
=======
Recetas Panes::getReceta() const { return receta; }
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088

//Implementación de setters de la clase
void Panes::setNombre(const std::string& nombre) { this -> nombre = nombre; }
void Panes::setStock(const int stock) { this -> stock = stock; }
<<<<<<< HEAD
void Panes::setReceta(const Receta& receraPan) { this -> receta = receta; }
=======
void Panes::setReceta(const Recetas& receraPan) { this -> receta = receta; }
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088
