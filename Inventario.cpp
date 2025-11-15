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
    std::string linea;
    linea = nuevoIngrediente.getNombre() + ";" + nuevoIngrediente.getUnidadMedida() + ";" + std::to_string(cantidad);
    bd->agregarLinea("ingredientes.txt", linea);
}

void Inventario::eliminarIngrediente(const std::string& nombreIngrediente){
    for(auto it = ingredientes.begin(); it != ingredientes.end(); ++it){
        if(it->first.getNombre() == nombreIngrediente){
            ingredientes.erase(it);
            break;
        }
    }
    std::vector<std::string> nuevasLineas;

    for (const auto& par : ingredientes) {

        const Ingredientes& ing = par.first;
        double cantidad = par.second;

        std::string linea = 
            ing.getNombre() + ";" +
            ing.getUnidadMedida() + ";" +
            std::to_string(cantidad);

        nuevasLineas.push_back(linea);
    }

    // 3. Sobrescribir el archivo completo
    bd->sobrescribirArchivo("ingredientes.txt", nuevasLineas);
}

void Inventario::editarIngrediente(const std::string& nombreIngrediente, double nuevoStock) { 
    buscarIngrediente(nombreIngrediente);
}

Ingredientes Inventario::buscarIngrediente(const std::string& nombreIngrediente){
    for(auto it = ingredientes.begin(); it != ingredientes.end(); ++it){
        if(it->first.getNombre() == nombreIngrediente){
            return it->first;
        }
    }
    std::vector<std::string> nuevasLineas;

    for (const auto& par : ingredientes) {

        const Ingredientes& ing = par.first;
        double cantidad = par.second; // o par.first.getCantidad() si tu clase lo maneja así

        std::string linea = 
            ing.getNombre() + ";" +
            ing.getUnidadMedida() + ";" +
            std::to_string(cantidad);

        nuevasLineas.push_back(linea);
    }

    // 3. Sobrescribir el archivo completo
    bd->sobrescribirArchivo("ingredientes.txt", nuevasLineas);
    return Ingredientes(); // o lanzar una excepción si el ingrediente no se encuentra
}

void Inventario::verificarCantIngredientes() const {
    for (const auto& it : ingredientes) {
        if (it.second < 50.0) { // Suponiendo que 50.0 es el nivel mínimo
            VistaEncargadoInventario vista;
            vista.mostrarAlertasReposicion();
            break;
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

void Inventario::setBaseDatos(BaseDeDatos& bd) {
    this->bd = &bd;
}

void Inventario::cargarDesdeBD(BaseDeDatos& bd) {
    for (const std::string& linea : bd.obtenerDatos("ingredientes.txt")) {

        // Formato esperado: nombre;unidad;cantidad
        size_t p1 = linea.find(';');
        size_t p2 = linea.find(';', p1 + 1);

        if (p1 == std::string::npos || p2 == std::string::npos) continue;

        std::string nombre = linea.substr(0, p1);
        std::string unidad = linea.substr(p1 + 1, p2 - (p1 + 1));
        double cantidad = std::stod(linea.substr(p2 + 1));

        ingredientes[ Ingredientes(nombre, unidad) ] = cantidad;
    }
}