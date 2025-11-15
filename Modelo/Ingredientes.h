/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       Ingredientes
Responsabilidades:        

  - Representar los ingredientes de la panaderia. Debe tener un nombre,
    cantidad, unidad de medida y nivel minimo.

Colaboradores:            
    ...
===============================================================================
*/

#ifndef INGREDIENTES_H
#define INGREDIENTES_H

#include <string>

class Ingredientes{

    private:  // Atributos de la clase
        std::string nombre;
        std::string unidadMedida;


    public:  //Métodos de la clase
        Ingredientes(std::string n, std::string um);  //Constructor de la clase
        Ingredientes();

        //Getters 
        std::string getNombre() const;
        std::string getUnidadMedida() const;

        //setters
        void setStock(const double stock);
};

#endif //INGREDIENTES