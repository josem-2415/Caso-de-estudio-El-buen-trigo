#include "Inventario.h"
#include <algorithm>

Inventario::Inventario(){
    ingredientes = {};
}

//Implementación de los métodos de gestion de ingredientes de la panaderia
void Inventario::agregarIngrediente(const Ingredientes& nuevoIngrediente, double cantidad) {
    VistaEncargadoInventario vista;
    if (ingredientes.find(nuevoIngrediente) != ingredientes.end()) {
        vista.ingredienteNegativo();
        return;
    }
    ingredientes.insert({nuevoIngrediente, cantidad});

}

void Inventario::eliminarIngrediente(const std::string& nombreIngrediente){
    for(auto it = ingredientes.begin(); it != ingredientes.end(); ++it){
        if(it->first.getNombre() == nombreIngrediente){
            ingredientes.erase(it);
            break;
        }
    }
}

void Inventario::editarIngrediente(const std::string& nombreIngrediente, double nuevoStock) { 
    buscarIngrediente(nombreIngrediente).setStock(nuevoStock);
}

Ingredientes Inventario::buscarIngrediente(const std::string& nombreIngrediente){
    for(auto it = ingredientes.begin(); it != ingredientes.end(); ++it){
        if(it->first.getNombre() == nombreIngrediente){
            return it->first;
        }
    }
    return Ingredientes(); // o lanzar una excepción si el ingrediente no se encuentra
}

void Inventario::verificarCantIngredientes() const {
    for (const auto& it : ingredientes) {
        if (it.second < 5.0) { // Suponiendo que 5.0 es el nivel mínimo
            std::cout << "Alerta: El ingrediente " << it.first.getNombre() << " está por debajo del nivel mínimo.\n";
        }
    }
}

void Inventario::restarCantidadIngrediente(const std::string& nombreIngrediente, double cantidad) {
    for (auto& it : ingredientes) {
        if (it.first.getNombre() == nombreIngrediente) {
            it.second -= cantidad;
            break;
        }
    }
}

const std::map<Ingredientes, double>& Inventario::getIngredientes() const {
    return ingredientes;
}

const double Inventario::getCantidadIngrediente(const std::string& nombreIngrediente) const {
    for (const auto& it : ingredientes) {
        if (it.first.getNombre() == nombreIngrediente) {
            return it.second;
        }
    }
    return 0.0; // o lanzar una excepción si el ingrediente no se encuentra
}