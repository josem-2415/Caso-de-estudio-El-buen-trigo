#include "Panadero.h"

Panadero::Panadero() {}

// Registra una receta (solo agrega al vector recibido)
void Panadero::registrarReceta(std::vector<Recetas>& recetas, const Recetas& nuevaReceta) {
    VistaPanadero vista;
    vista.obtenerDatosRegistroReceta();
    
    Recetas receta(vista.obtenerNombreReceta(), vista.obtenerCantidadProduccion(), vista.obtenerIngredientesReceta());
    recetas.push_back(receta);
}

// Modifica una receta existente (reemplaza el objeto)
void Panadero::modificarReceta(std::vector<Recetas>& recetas, int indice, const Recetas& recetaModificada) {
    VistaPanadero vista;
    std::cout << "\n[Panadero] Modificando receta...\n";
    Recetas recetaModificada(vista.obtenerNombreReceta(), vista.obtenerCantidadProduccion(), vista.obtenerIngredientesReceta());

    for (auto& receta : recetas) {
        if (receta.getNombre() == recetaModificada.getNombre()) {
            receta = recetaModificada;
            break;
        }
    }
    std::cout << "[Panadero] Receta modificada con éxito.\n";
}

// Produce pan (actualiza el inventario de panes e ingredientes)
void Panadero::producirPan(const std::string& nombreReceta, Inventario& inventario, Stock& stockDePanes, const std::vector<Recetas>& recetas) {
    std::cout << "\n[Panadero] Produciendo pan con la receta: " << nombreReceta << "...\n";
    VistaPanadero vista;
    int cantidadProduccion = vista.obtenerCantidadProduccion();
    
    const Recetas* recetaSeleccionada = nullptr;
    for (const auto& receta : recetas) {
        if (receta.getNombre() == nombreReceta) {
            recetaSeleccionada = &receta;
            break;
        }
    }
    if (!recetaSeleccionada) {
        std::cout << "[Panadero] Receta no encontrada.\n";
        return;
    }
    // Verificar si hay suficientes ingredientes
    inventario.verificarCantIngredientes();

    // restar ingredientes del inventario
    for (const auto& ingrediente : recetaSeleccionada->getIngredientesReceta()) {
        inventario.restarCantidadIngrediente(ingrediente.first.getNombre(), ingrediente.second * cantidadProduccion);
    }
    // Añadir pan producido al stock
    Panes nuevoPan(nombreReceta, cantidadProduccion, *recetaSeleccionada);
    stockDePanes.agregarPan(nuevoPan, inventario);
}

// Devuelve el stock actual de panes (sin imprimir nada)
std::vector<Panes> Panadero::consultarStock(const Stock& stockDePanes) const {
    return stockDePanes.getVectorPanes();
}
