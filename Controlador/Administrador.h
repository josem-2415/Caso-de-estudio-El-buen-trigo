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

#include "Modelo/Inventario.h"
#include "BaseDeDatos.h"
#include "Modelo/Stock.h"
#include "Vista/VistaAdministrador.h"
#include "EncargadoInventario.h"
#include <fstream>
#include <iostream>
using namespace std;

class Administrador : public EncargadoInventario {
public:
    Administrador();

    void exportarReporteTxt(const VistaAdministrador& vadm);
};

#endif
