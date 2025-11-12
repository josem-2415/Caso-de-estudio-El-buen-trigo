#include "InventarioIngredientes.h"
#include <algorithm>

InventarioIngredientes::InventarioIngredientes(){
    ingredientes = {};
}

//Implementación de los métodos de gestion de ingredientes de la panaderia
<<<<<<< HEAD
void InventarioIngredientes::agregarIngrediente(const Ingrediente& nuevoIngrediente)
=======
void InventarioIngredientes::agregarIngrediente(const Ingredientes& nuevoIngrediente)
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088
    { ingredientes.push_back(nuevoIngrediente); }

void InventarioIngredientes::eliminarIngrediente(const std::string& nombreIngrediente){
    for(int i = 0; i <= ingredientes.size(); i++){
        if(ingredientes.at(i).getNombre() == nombreIngrediente){
            ingredientes.erase(ingredientes.begin() + i);  // Revisar esta linea de codigo luego
        }
    }
}

void InventarioIngredientes::modificarStockIngrediente(const std::string& nombreIngrediente, double nuevoStock)
    { buscarIngrediente(nombreIngrediente).setStock(nuevoStock); }

void InventarioIngredientes::restarIngrediente(const std::string& nombreIngrediente, double cantidadRestar){
    buscarIngrediente(nombreIngrediente).setStock(buscarIngrediente(nombreIngrediente).getStock() - cantidadRestar);
}

<<<<<<< HEAD
void InventarioIngredientes::restarIngredientesReceta(const Receta& receta){  // Método pendiente por terminar
    /*for(Ingrediente ingrediente : receta.getIngredientesReceta()){
        for(Ingrediente ingredientesInventario : ingredientes){
=======
void InventarioIngredientes::restarIngredientesReceta(const Recetas& receta){  // Método pendiente por terminar
    /*for(Ingredientes ingrediente : receta.getIngredientesReceta()){
        for(Ingredientes ingredientesInventario : ingredientes){
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088
            if(ingredientesInventario.getNombre() == ingrediente.getNombre()){

            }
        }
    }*/
}

<<<<<<< HEAD
Ingrediente& InventarioIngredientes::buscarIngrediente(const std::string& nombreIngrediente){
=======
Ingredientes& InventarioIngredientes::buscarIngrediente(const std::string& nombreIngrediente){
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088
    for(int i = 0; i <= ingredientes.size(); i++){
        if(ingredientes.at(i).getNombre() == nombreIngrediente){
            return ingredientes[i];
            break;
        }
    }
}

<<<<<<< HEAD
bool InventarioIngredientes::verificarNivelMinimo(const Ingrediente& ingrediente) const{
    if(ingrediente.getStock() < ingrediente.getNivelMinimo()) return true;
    else false;
}

std::vector<Ingrediente> InventarioIngredientes::getIngredientes() const {
    return ingredientes;
}
=======
bool InventarioIngredientes::verificarNivelMinimo(const Ingredientes& ingrediente) const{
    if(ingrediente.getStock() < ingrediente.getNivelMinimo()) return true;
    else false;
}
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088
