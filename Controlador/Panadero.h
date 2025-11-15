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

#include "../Modelo/Inventario.h"
#include "../Modelo/Recetas.h"
#include "../Modelo/Stock.h"
#include "../Modelo/Panes.h"
#include "../Vista/VistaPanadero.h"
#include "BaseDeDatos.h"
#include <vector>
#include <string>
#include <iostream>

class Panadero {
private:
    BaseDeDatos bd; 
public:
    Panadero();

    // Registra una nueva receta
    void registrarReceta(std::vector<Recetas>& recetas, const Recetas& nuevaReceta);

    // Modifica una receta existente (según el índice)
    void modificarReceta(std::vector<Recetas>& recetas, const Recetas& recetaModificada);

    // Produce pan con base en una receta existente
    void producirPan(const std::string& nombreReceta, Inventario& inventario, Stock& stockDePanes, const std::vector<Recetas>& recetas);

    // Consulta el stock de panes (devuelve el vector para que la Vista lo muestre)
    std::vector<Panes> consultarStock(const Stock& stockDePanes) const;
};

#endif // PANADERO_H
