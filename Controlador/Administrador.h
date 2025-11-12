<<<<<<< HEAD
#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Modelo/InventarioIngredientes.h"
#include "BaseDeDatos.h"
#include <fstream>
#include <iostream>
using namespace std;

class Administrador {
public:
    Administrador();

    void generarReporte(const InventarioIngredientes& inv);
    void exportarReporteTxt(const InventarioIngredientes& inv);
};

#endif
=======
/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       Administrador
Responsabilidades:        
    ...
Colaboradores:            
    ...
===============================================================================
*/
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088
