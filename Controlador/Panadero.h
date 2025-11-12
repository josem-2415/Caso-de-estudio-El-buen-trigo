<<<<<<< HEAD
#ifndef PANADERO_H
#define PANADERO_H

#include "../Modelo/InventarioIngredientes.h"
#include "../Modelo/Receta.h"
#include "../Modelo/InventarioPanes.h"
#include <vector>
#include <string>

class Panadero {
public:
    Panadero();

    // Registra una nueva receta
    void registrarReceta(std::vector<Receta>& recetas, const Receta& nuevaReceta);

    // Modifica una receta existente (según el índice)
    void modificarReceta(std::vector<Receta>& recetas, int indice, const Receta& recetaModificada);

    // Produce pan con base en una receta existente
    void producirPan(const std::string& nombreReceta);

    // Consulta el stock de panes (devuelve el vector para que la Vista lo muestre)
    std::vector<Panes> consultarStock(const InventarioPanes& inventarioPanes) const;
};

#endif // PANADERO_H
=======
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
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088
