/*
===============================================================================
                                TARJETA CRC
===============================================================================
Nombre de la clase:       Inventario
Responsabilidades:        
    
  - Gestionar los Ingredientes de la panaderia proporcionando métodos como
    "agregarIngrediente()", "eliminarIngredientes()", etc.
      

Colaboradores:            
    
  - Contiene objetos de la clase Ingredientes.
  - Conoce objetos de la clase Recetas.

===============================================================================
*/

#ifndef INVENTARIO_H
#define INVENTARIO_H

#include "Ingredientes.h"
#include "Recetas.h"
#include "VistaEncargadoInventario.h"
#include "BaseDeDatos.h"
#include <map>

class Inventario{

  private:  //Atributo de la clase
    std::map<Ingredientes, double> ingredientes;
    BaseDeDatos* bd;

  public:  //Métodos de la clase
    Inventario();  // Constructor de la clase
    //Métodos para gestionar los ingredientes de la panaderia
    void agregarIngrediente(const Ingredientes& nuevoIngrediente, double cantidad);
    void eliminarIngrediente(const std::string& nombreIngrediente);
    void editarIngrediente(const std::string& nombreIngrediente, double nuevaCantidad);
    Ingredientes buscarIngrediente(const std::string& nombreIngrediente);
    void verificarCantIngredientes() const;
    void restarCantidadIngrediente(const std::string& nombreIngrediente, double cantidad);
    const std::map<Ingredientes, double>& getIngredientes() const;
    const double getCantidadIngrediente(const std::string& nombreIngrediente) const;

    void setBaseDatos(BaseDeDatos& bd);
    void cargarDesdeBD(BaseDeDatos& bd);
};

#endif // INVENTARIO_H
