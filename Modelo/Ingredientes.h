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
        double stock;
        double nivelMinimo;

    public:  //Métodos de la clase
        Ingredientes();  //Constructor de la clase

        //Getters 
        std::string getNombre() const;
        std::string getUnidadMedida() const;
        double getStock() const;
        double getNivelMinimo() const;

        //setters
        void setNombre(const std::string& nombre);
        void setUnidadMedida(const std::string& UnidadMedida);
        void setStock(const double stock);
        void setNivelMinimo(const double nivelMinimo);
};

#endif //INGREDIENTES