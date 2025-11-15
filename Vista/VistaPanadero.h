#ifndef VISTA_PANADERO_H
#define VISTA_PANADERO_H

#include <iostream>
#include <string>
#include <map>
#include "../Modelo/Ingredientes.h"

class VistaPanadero {
public:
    void mostrarMenuPanadero();
    std::string obtenerNombreReceta();
    int obtenerCantidadIngredientes();
    std::map<Ingredientes, double> obtenerIngredientesReceta();
    void obtenerDatosRegistroReceta();
    int obtenerCantidadProduccion();
    void mostrarInventarioPanes();
    void mostrarInventarioRecetas();
    void mostrarAdvertenciasProduccion();
};

#endif // VISTA_PANADERO_H 
