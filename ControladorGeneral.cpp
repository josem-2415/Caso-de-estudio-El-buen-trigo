#include "ControladorGeneral.h"

ControladorGeneral::ControladorGeneral() {}

void ControladorGeneral::inicializarBaseDeDatos(const std::string& ruta) {
    baseDatos.conectar(ruta);
}

void ControladorGeneral::ejecutarMenuPanadero(int opcion) {
    int opcionMenu = 0;
    do{
        vp.mostrarMenuPanadero();
        opcionMenu = vp.obtenerOpcionMenu();
        switch (opcionMenu) {
            case 1:
                panadero.registrarReceta(recetas, receta);
                break;
            case 2:
                panadero.modificarReceta(recetas, receta);
                break;
            case 3:
                panadero.producirPan(receta.getNombre(), inventarioIngredientes, inventarioPanes, recetas);
                break;
            case 4:
                std::cout << "Saliendo del menú de Panadero...\n";
                break;
            default:
                break;
        }
    }while(opcionMenu != 4);
}

void ControladorGeneral::ejecutarMenuEncargado(int opcion) {
    int opcionMenu = 0;
    do{
        vinv.mostrarMenuEncargadoInventario();
        opcionMenu = vinv.obtenerOpcionMenu();
        switch (opcionMenu) {
            case 1: {
                encargadoInventario.registrarIngrediente(inventarioIngredientes);
                break;
            }
            case 2:{
                encargadoInventario.consultarInventario(inventarioIngredientes);
                break;
            }
            case 3:{
                encargadoInventario.consultarStock(vadm, inventarioPanes);
                break;
            }
            case 4:{
                encargadoInventario.verificarNivelMinimo(vinv);
                break;
            }
            case 5:
                std::cout << "Saliendo del menú de Encargado de Inventario...\n";
                break;
            default:
                break;
        }
    } while(opcionMenu != 5);
}

void ControladorGeneral::ejecutarMenuAdministrador(int opcion) {
    int opcionMenu = 0;
    do{
        vadm.mostrarMenuAdministrador();
        opcionMenu = vadm.obtenerOpcionMenu();
        switch (opcionMenu) {
            case 1:{
                administrador.generarReporte(inventarioIngredientes, inventarioPanes, vadm);
                break;
            }
            case 2: {
                administrador.exportarReporteTxt(inventarioIngredientes, inventarioPanes);
                break;
            }
            case 3:
                std::cout << "Saliendo del menú de Administrador...\n";
                break;
            default:
                break;
        }
    }while(opcionMenu != 3);
}
