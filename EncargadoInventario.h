#ifndef ENCARGADOINVENTARIO_H
#define ENCARGADOINVENTARIO_H

#include "Stock.h"
#include "Inventario.h"
#include "VistaEncargadoInventario.h"
#include "VistaAdministrador.h"
#include "BaseDeDatos.h"
#include <iostream>

class EncargadoInventario {
private:
    BaseDeDatos* bd;
public:
    EncargadoInventario();

    void registrarIngrediente(Inventario& inv);
    void editarIngrediente(Inventario& inv);
    void eliminarIngrediente(Inventario& inv);
    void consultarInventario(const Inventario& inv);
    void verificarNivelMinimo(const Inventario& inv);
    void consultarStock(VistaAdministrador& inv, const Stock& stock) const;
    void setBaseDatos(BaseDeDatos& bd);
};

#endif // ENCARGADOINVENTARIO_H