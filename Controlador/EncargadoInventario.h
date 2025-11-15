

/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       EncargadoInventario
Responsabilidades:        
    ...
Colaboradores:            
    ...
===============================================================================
*/

#ifndef ENCARGADOINVENTARIO_H
#define ENCARGADOINVENTARIO_H

#include "Modelo/Stock.h"
#include "Modelo/Inventario.h"
#include "Vista/VistaEncargadoInventario.h"
#include <iostream>

class EncargadoInventario {
public:
    EncargadoInventario();

    void registrarIngrediente(Inventario& inv);
    void editarIngrediente(Inventario& inv);
    void eliminarIngrediente(Inventario& inv);
    void consultarInventario(const Inventario& inv);
    void verificarNivelMinimo(VistaEncargadoInventario& inv);
};

#endif

/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       EncargadoInventario
Responsabilidades:  
    Agrega ingredientes al inventario
    Edita los ingredientes de inventario
    Elimina ingredientes
    verifica los niveles de los ingredientes
Colaboradores:            
    Inventario
    VistaInventario
    ControladorGeneral
===============================================================================
*/


