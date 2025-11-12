/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       Recetas
Responsabilidades:        

  - Representar las recetas de cada pan de la panaderia. Debe tener un nombre,
    cantidad de ingredientes, ingredientes de la receta y cantidad a gastar de 
    cada ingrediente.

Colaboradores:   

    - Usa objetos de la clase Ingredientes.

===============================================================================
*/

#ifndef RECETAS_H
#define RECETAS_H

#include "Ingredientes.h"
#include <string>
#include <vector>


class Recetas{

    private:
        std::string nombre;
        int numeroIngredientes;
        std::vector<Ingredientes> ingredientesReceta;
        std::vector<double> cantidadIngredientes;

    public:
        Recetas();  //Constructor de la clase

        //Getters de la clase
        std::string getNombre() const;
        int getNumeroIngredientes() const;
        std::vector<Ingredientes>& getIngredientesReceta();
        std::vector<double>& getCantidadIngredientes();

        //Setters de la clase
        void setNombre(const std::string& nombre);
        void setNumeroIngredientes(const int numeroIngredientes);
        
        //Métodos para manipular los vectores en los atributos
        void agregarIngredienteReceta(const Ingredientes& nuevoIngrediente);
        void agregarCantidadIngrediente(const double cantidadIngrediente);
};

#endif RECETAS_H