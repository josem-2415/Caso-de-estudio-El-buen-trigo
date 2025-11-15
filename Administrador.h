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
#ifndef ADMINISTRADOR_H
#define ADMINISTRADOR_H

#include "Inventario.h"
#include "BaseDeDatos.h"
#include "Stock.h"
#include "VistaAdministrador.h"
#include "EncargadoInventario.h"
#include <fstream>
#include <iostream>
using namespace std;

class Administrador {
public:
    Administrador();

    void generarReporte(const Inventario& inv, const Stock& stockDePanes, const VistaAdministrador& vadm);
    void exportarReporteTxt(const Inventario& inv, const Stock& stockDePanes);
};

#endif
