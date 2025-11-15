
/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       ControladorGeneral
Responsabilidades:        
    ...
Colaboradores:            
    ...
===============================================================================
*/

#ifndef CONTROLADORGENERAL_H
#define CONTROLADORGENERAL_H

#include "Panadero.h"
#include "EncargadoInventario.h"
#include "Administrador.h"
#include "BaseDeDatos.h"
#include "../Modelo/Inventario.h"
#include "../Modelo/Stock.h"
#include "../Modelo/Recetas.h"
#include <vector>

class ControladorGeneral {
private:
    Panadero panadero;
    EncargadoInventario encargadoInventario;
    Administrador administrador;
    BaseDeDatos baseDatos;

    Inventario inventarioIngredientes;
    Stock inventarioPanes;
    std::vector<Recetas> recetas;

public:
    ControladorGeneral();

    // Sólo estas tres funciones públicas: la Vista llamará a una de ellas
    void ejecutarMenuPanadero(int opcion);
    void ejecutarMenuEncargado(int opcion);
    void ejecutarMenuAdministrador(int opcion);
};

#endif // CONTROLADORGENERAL_H


/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       ControladorGeneral
Responsabilidades:        
    Se encarga de ejecutar los menus para los diferentes usuarios
Colaboradores:            
    Adminitrador
    Panadero
    BaseDeDatos
===============================================================================
*/

