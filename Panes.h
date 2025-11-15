/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       Panes
Responsabilidades:        

  - Representar los panes de la panaderia. Deben tener un nombre y un stock

Colaboradores:            
    
    - Depende de la clase recetas

===============================================================================
*/

#ifndef PANES_H
#define PANES_H

#include "Recetas.h"
#include <string>

class Panes{

    private:  // Atributos de la clase
        std::string nombre;
        int stock;
        Recetas receta;

    public:
        Panes(const std::string& nombre, int stock, const Recetas& receta);  //Constructor de la clase

        //Getters de la clase
        std::string getNombre() const;
        int getStock() const;
        Recetas getReceta() const; 

        //Setters de la clase
        void setNombre(const std::string& nombre);
        void setStock(const int stock);
        void setReceta(const Recetas& recetaPan);
};

#endif // PANES_H
