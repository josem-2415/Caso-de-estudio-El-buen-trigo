/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       InventarioPanes
Responsabilidades:      
    
  - Gestionar los panes de la panaderia proporcionando métodos como "agregarPan()",
    "eliminarPan()", etc.

Colaboradores:            

  - Contiene objetos de la clase panes
  - Conoce a la clase InventarioIngredientes

===============================================================================
*/

#ifndef INVENTARIOPANES
#define INVENTARIOPANES

#include "Panes.h"
#include "InventarioIngredientes.h"
#include <vector>

class InventarioPanes{

    private:  //Atributo de la clase 
        std::vector<Panes> panes;

    public:  //Métodos de la clase
        InventarioPanes();  //Constructor de la clase

        //Getter de la clase
        std::vector<Panes> getVectorPanes() const;

        //Métodos para gestionar los panes de la panaderia
        void agregarPan(const Panes& nuevoPan, InventarioIngredientes& inventario);
        void eliminarPanes(std::string& nombrePan, int cantidadEliminar);
        Panes& buscarPan(std::string& nombrePan);
};


<<<<<<< HEAD
#endif // INVENTARIOPANES_H
=======
#endif INVENTARIOPANES_H
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088
