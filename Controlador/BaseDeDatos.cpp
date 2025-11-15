#include "BaseDeDatos.h"
#include <filesystem>

BaseDeDatos::BaseDeDatos() : jsonCargado(false) {}

void BaseDeDatos::conectar(const std::string& ruta) {
    std::ifstream archivo(ruta);
    if (!archivo.is_open()) {
        std::cerr << "No se pudo abrir JSON: " << ruta << std::endl;
        return;
    }
    
    try {
        archivo >> datosJSON;
        jsonCargado = true;
        archivo.close();
        std::cout << "JSON cargado exitosamente" << std::endl;
    } catch (json::parse_error& e) {
        std::cerr << "Error al parsear JSON: " << e.what() << std::endl;
        jsonCargado = false;
        archivo.close();
    }
}

void BaseDeDatos::desconectar() {
    datosJSON.clear();
    jsonCargado = false;
}

bool BaseDeDatos::tieneJSON() const {
    return jsonCargado;
}

// Guardar panes y ingredientes en JSON
void BaseDeDatos::guardarDatos(const std::string& rutaArchivo,
                               const std::vector<Ingredientes>& ingredientes,
                               const std::vector<Panes>& panes) {
    json datos;
    
    // Guardar ingredientes
    datos["ingredientes"] = json::array();
    for (const auto& ing : ingredientes) {
        json ingredienteJSON;
        ingredienteJSON["nombre"] = ing.getNombre();
        ingredienteJSON["unidadMedida"] = ing.getUnidadMedida();
        datos["ingredientes"].push_back(ingredienteJSON);
    }
    
    // Guardar panes
    datos["panes"] = json::array();
    for (const auto& pan : panes) {
        json panJSON;
        panJSON["nombre"] = pan.getNombre();
        panJSON["stock"] = pan.getStock();
        datos["panes"].push_back(panJSON);
    }
    
    std::ofstream archivo(rutaArchivo);
    if (archivo.is_open()) {
        archivo << datos.dump(4);
        archivo.close();
        std::cout << "Datos guardados correctamente" << std::endl;
    } else {
        std::cerr << "Error al guardar datos" << std::endl;
    }
}

// Cargar ingredientes desde JSON
std::vector<Ingredientes> BaseDeDatos::cargarIngredientes() {
    std::vector<Ingredientes> ingredientes;
    
    if (!jsonCargado || !datosJSON.contains("ingredientes")) {
        std::cerr << "No se pueden cargar ingredientes" << std::endl;
        return ingredientes;
    }
    
    for (const auto& ingJSON : datosJSON["ingredientes"]) {
        Ingredientes ing;
        ing.setNombre(ingJSON["nombre"]);
        ing.setUnidadMedida(ingJSON["unidadMedida"]);
        ingredientes.push_back(ing);
    }
    
    std::cout << ingredientes.size() << " ingredientes cargados" << std::endl;
    return ingredientes;
}

// Cargar panes desde JSON
std::vector<Panes> BaseDeDatos::cargarPanes() {
    std::vector<Panes> panes;
    
    if (!jsonCargado || !datosJSON.contains("panes")) {
        std::cerr << "No se pueden cargar panes" << std::endl;
        return panes;
    }
    
    for (const auto& panJSON : datosJSON["panes"]) {
        Panes pan;
        pan.setNombre(panJSON["nombre"]);
        pan.setStock(panJSON["stock"]);
        panes.push_back(pan);
    }
    
    std::cout << panes.size() << " panes cargados" << std::endl;
    return panes;
}
