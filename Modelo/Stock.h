/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       Stock
Responsabilidades:      
    
  - Gestionar los panes de la panaderia proporcionando métodos como "agregarPan()",
    "eliminarPan()", etc.

Colaboradores:            

  - Contiene objetos de la clase panes
  - Conoce a la clase InventarioIngredientes

===============================================================================
*/

#ifndef STOCK_H
#define STOCK_H

#include "Panes.h"
#include "Inventario.h"
#include <vector>

class Stock{

    private:  //Atributo de la clase 
        std::vector<Panes> panes;

    public:  //Métodos de la clase
        Stock();  //Constructor de la clase

        //Getter de la clase
        std::vector<Panes> getVectorPanes() const;

        //Métodos para gestionar los panes de la panaderia
        void agregarPan(const Panes& nuevoPan, Inventario& inventario);
        void eliminarPanes(std::string& nombrePan, int cantidadEliminar);
        Panes& buscarPan(std::string& nombrePan);
};


#endif // STOCK_H
