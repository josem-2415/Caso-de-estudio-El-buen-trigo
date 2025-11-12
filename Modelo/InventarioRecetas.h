/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       InventarioRecetas
Responsabilidades:      
    
  - Gestionar las recetas de la panaderia proporcionando métodos como "agregarPan()",
    "eliminarPan()", etc.

Colaboradores:            
    Contiene objetos de la clase panes
===============================================================================
*/

#ifndef INVENTARIORECETAS
#define INVENTARIORECETAS

#include "Recetas.h"
#include <vector>

class InventarioRecetas{

    private:  //Atributos de la clase
        std::vector<Recetas> recetas; 
    
    public:  //Métodos de la clase
        InventarioRecetas();  //Constructor de la clase

        //Getter de la clase
        std::vector<Recetas> getRecetas() const;

        //Métodos para la gestión de las recetas de la panaderia
        void agregarReceta(const Recetas& recetaNueva);
        void eliminarReceta(const std::string& nombreReceta);
        Recetas& buscarReceta(const std::string& nombreReceta);
};

#endif INVENTARIORECETAS