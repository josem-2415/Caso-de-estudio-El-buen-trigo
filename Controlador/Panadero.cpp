#include "Panadero.h"

Panadero::Panadero() {}

// Registra una receta (solo agrega al vector recibido)
void Panadero::registrarReceta(std::vector<Recetas>& recetas, const Recetas& nuevaReceta) {
    VistaPanadero vista;
    vista.obtenerDatosRegistroReceta();
    
    Recetas receta(vista.obtenerNombreReceta(), vista.obtenerCantidadProduccion(), vista.obtenerIngredientesReceta());

    // Formatear línea para guardar en archivo
    std::string linea;
    linea = receta.getNombre() + ";";

    for (auto& ing : receta.getIngredientesReceta()) {
        linea += ing.first.getNombre() + ":" + ing.first.getUnidadMedida() + ":" + std::to_string(ing.second) + ";";
    }

    recetas.push_back(receta);
    std::cout << "[Panadero] Receta registrada con éxito.\n";
    bd.agregarLinea("recetario.txt", linea);
}

// Modifica una receta existente (reemplaza el objeto)
void Panadero::modificarReceta(std::vector<Recetas>& recetas, const Recetas& recetaModificada) {
    VistaPanadero vista;
    std::cout << "\n[Panadero] Modificando receta...\n";
    Recetas recetaModificada(vista.obtenerNombreReceta(), vista.obtenerCantidadProduccion(), vista.obtenerIngredientesReceta());

    


    std::vector<std::string> nuevasLineas;
    for (const auto& r : recetas) {
        std::string linea = r.getNombre() + ";";
        for (const auto& ing : r.getIngredientesReceta()) {
            linea += ing.first.getNombre() + ":" + ing.first.getUnidadMedida() + ":" + std::to_string(ing.second) + ";";
        }
        nuevasLineas.push_back(linea);
    }
    for (auto& receta : recetas) {
        if (receta.getNombre() == recetaModificada.getNombre()) {
            receta = recetaModificada;
            break;
        }
    }
    bd.sobrescribirArchivo("recetario.txt", nuevasLineas);

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
    std::cout << "[Panadero] Producción completada. Se han producido " << cantidadProduccion << " unidades de " << nombreReceta << ".\n";
    bd.agregarLinea("stock.txt", nombreReceta + ";" + std::to_string(cantidadProduccion) + ";");
}

// Devuelve el stock actual de panes (sin imprimir nada)
std::vector<Panes> Panadero::consultarStock(const Stock& stockDePanes) const {
    return stockDePanes.getVectorPanes();
}
