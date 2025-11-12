/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       InventarioIngredientes
Responsabilidades:        
    
  - Gestionar los Ingredientes de la panaderia proporcionando métodos como
    "agregarIngrediente()", "eliminarIngredientes()", etc.
      

Colaboradores:            
    
  - Contiene objetos de la clase Ingredientes.
  - Conoce objetos de la clase Recetas.

===============================================================================
*/

#ifndef INVENTARIOINGREDIENTES_H
#define INVENTARIOINGREDIENTES_H

<<<<<<< HEAD
#include "Ingrediente.h"
#include "Receta.h"
=======
#include "Ingredientes.h"
#include "Recetas.h"
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088
#include <vector>

class InventarioIngredientes{

    private:  //Atributo de la clase
<<<<<<< HEAD
        std::vector<Ingrediente> ingredientes;
=======
        std::vector<Ingredientes> ingredientes;
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088

    public:  //Métodos de la clase
        InventarioIngredientes();  // Constructor de la clase

        //Métodos para gestionar los ingredientes de la panaderia
<<<<<<< HEAD
        void agregarIngrediente(const Ingrediente& nuevoIngrediente);
        void eliminarIngrediente(const std::string& nombreIngrediente);
        void modificarStockIngrediente(const std::string& nombreIngrediente, double nuevaCantidad);
        void restarIngrediente(const std::string& nombreIngrediente, double cantidadRestar);
        void restarIngredientesReceta(const Receta& receta);
        Ingrediente& buscarIngrediente(const std::string& nombreIngrediente);
        bool verificarNivelMinimo(const Ingrediente& ingrediente) const;

        std::vector<Ingrediente> getIngredientes() const;
};

#endif INVENTARIOINGREDIENTES_H

=======
        void agregarIngrediente(const Ingredientes& nuevoIngrediente);
        void eliminarIngrediente(const std::string& nombreIngrediente);
        void modificarStockIngrediente(const std::string& nombreIngrediente, double nuevaCantidad);
        void restarIngrediente(const std::string& nombreIngrediente, double cantidadRestar);
        void restarIngredientesReceta(const Recetas& receta);
        Ingredientes& buscarIngrediente(const std::string& nombreIngrediente);
        bool verificarNivelMinimo(const Ingredientes& ingrediente) const;
};

#endif INVENTARIOINGREDIENTES_H
>>>>>>> 30f205684ecc2689dc0c56a3dd44bd4c690b4088
