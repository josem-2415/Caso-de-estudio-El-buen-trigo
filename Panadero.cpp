#include "Panadero.h"

Panadero::Panadero() {}

// Registra una receta (solo agrega al vector recibido)
void Panadero::registrarReceta(std::vector<Recetas>& recetas, const Recetas& nuevaReceta) {
    VistaPanadero vista;
    vista.obtenerDatosRegistroReceta();
 
    std::string nombre = vista.obtenerNombreReceta();
    int cantidadProduccion = vista.obtenerCantidadIngredientes();
    std::map<Ingredientes, double> ingredientesReceta = vista.obtenerIngredientesReceta();

    Recetas receta(nombre, cantidadProduccion, ingredientesReceta);

    // Formatear línea para guardar en archivo
    std::string linea;
    linea = receta.getNombre() + ";";

    for (auto& ing : receta.getIngredientesReceta()) {
        linea += ing.first.getNombre() + ":" + ing.first.getUnidadMedida() + ":" + std::to_string(ing.second) + ";";
    }

    recetas.push_back(receta);
    std::cout << "[Panadero] Receta registrada con éxito.\n";
    bd->agregarLinea("recetas.txt", linea);
}

// Modifica una receta existente (reemplaza el objeto)
void Panadero::modificarReceta(std::vector<Recetas>& recetas, const Recetas& recetaModificada) {
    VistaPanadero vista;
    std::cout << "\n[Panadero] Modificando receta...\n";
    Recetas recetaModifica(vista.obtenerNombreReceta(), vista.obtenerCantidadProduccion(), vista.obtenerIngredientesReceta());

    std::vector<std::string> nuevasLineas;
    for (const auto& r : recetas) {
        std::string linea = r.getNombre() + ";";
        for (const auto& ing : r.getIngredientesReceta()) {
            linea += ing.first.getNombre() + ":" + ing.first.getUnidadMedida() + ":" + std::to_string(ing.second) + ";";
        }
        nuevasLineas.push_back(linea);
    }
    for (auto& receta : recetas) {
        if (receta.getNombre() == recetaModifica.getNombre()) {
            receta = recetaModifica;
            break;
        }
    }
    bd->sobrescribirArchivo("recetario.txt", nuevasLineas);

    std::cout << "[Panadero] Receta modificada con éxito.\n";
}

// Produce pan (actualiza el inventario de panes e ingredientes)
void Panadero::producirPan(const std::string& nombreReceta, Inventario& inventario, Stock& stockDePanes, const std::vector<Recetas>& recetas) {
    VistaPanadero vista;
    std::string nombreDeReceta;
    nombreDeReceta = vista.obtenerNombreReceta();
    int cantidadProduccion = vista.obtenerCantidadProduccion();
    
    VistaEncargadoInventario veinv;
    if (cantidadProduccion<0){
        veinv.ingredienteNegativo();
    }
    
    const Recetas* recetaSeleccionada = nullptr;
    for (const auto& receta : recetas) {
        if (receta.getNombre() == nombreDeReceta) {
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
    bd->agregarLinea("stock.txt", nombreReceta + ";" + std::to_string(cantidadProduccion) + ";");
}

void Panadero::setBaseDatos(BaseDeDatos& bd) {
    this->bd = &bd;
}