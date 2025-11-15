/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       Panadero
Responsabilidades:        
    ...
Colaboradores:            
    ...
===============================================================================
*/
#ifndef PANADERO_H
#define PANADERO_H

#include "Inventario.h"
#include "Recetas.h"
#include "Stock.h"
#include "Panes.h"
#include "VistaPanadero.h"
#include "BaseDeDatos.h"
#include <vector>
#include <string>
#include <iostream>

class Panadero {
private:
    BaseDeDatos* bd;
public:
    Panadero();

    // Registra una nueva receta
    void registrarReceta(std::vector<Recetas>& recetas, const Recetas& nuevaReceta);

    // Modifica una receta existente (según el índice)
    void modificarReceta(std::vector<Recetas>& recetas, const Recetas& recetaModificada);

    // Produce pan con base en una receta existente
    void producirPan(const std::string& nombreReceta, Inventario& inventario, Stock& stockDePanes, const std::vector<Recetas>& recetas);

    void setBaseDatos(BaseDeDatos& bd);
};

#endif // PANADERO_H
