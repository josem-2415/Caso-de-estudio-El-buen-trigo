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
#define PANES_h

<<<<<<< HEAD
#include "Receta.h"
=======
#include "Recetas.h"
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088
#include <string>

class Panes{

    private:  // Atributos de la clase
        std::string nombre;
        int stock;
<<<<<<< HEAD
        Receta receta;
=======
        Recetas receta;
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088

    public:
        Panes();  //Constructor de la clase

        //Getters de la clase
        std::string getNombre() const;
        int getStock() const;
<<<<<<< HEAD
        Receta getReceta() const; 
=======
        Recetas getReceta() const; 
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088

        //Setters de la clase
        void setNombre(const std::string& nombre);
        void setStock(const int stock);
<<<<<<< HEAD
        void setReceta(const Receta& recetaPan);
};

#endif //PANES_H
=======
        void setReceta(const Recetas& recetaPan);
};

#endif PANES_H
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088
