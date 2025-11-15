#include "ControladorGeneral.h"

ControladorGeneral::ControladorGeneral() {}

void ControladorGeneral::ejecutarMenuPanadero(int opcion) {
    do{
        vp.mostrarMenuPanadero();
        int opcion = vp.obtenerOpcionMenu();
        switch (opcion) {
            case 1:
                panadero.registrarReceta(recetas, Recetas());
                break;
            case 2:
                panadero.modificarReceta(recetas, Recetas());
                break;
            case 3:
                panadero.consultarStock(inventarioPanes);
                break;
            case 4:
                std::cout << "Saliendo del menú de Panadero...\n";
                break;
            default:
                break;
        }
    }while(opcion != 4);
}

void ControladorGeneral::ejecutarMenuEncargado(int opcion) {
    do{
        vinv.mostrarMenuEncargadoInventario();
        int opcion = vinv.obtenerOpcionMenu();
        switch (opcion) {
            case 1: {
                encargadoInventario.registrarIngrediente(inventarioIngredientes);
                break;
            }
            case 2:{
                encargadoInventario.consultarInventario(inventarioIngredientes);
                break;
            }
            case 3:{
                encargadoInventario.verificarNivelMinimo(vinv);
                break;
            }
            case 4:
                std::cout << "Saliendo del menú de Encargado de Inventario...\n";
                break;
            default:
                break;
        }
    } while(opcion != 4);
}

void ControladorGeneral::ejecutarMenuAdministrador(int opcion) {
    do{
        vadm.mostrarMenuAdministrador();
        int opcion = vadm.obtenerOpcionMenu();
        switch (opcion) {
            case 1:{
                
                administrador.exportarReporteTxt(inventarioIngredientes, inventarioPanes);
                break;
            }
            case 2: {
                administrador.generarReporte(inventarioIngredientes, inventarioPanes, vadm);
                break;
            }
            case 3:
                std::cout << "Saliendo del menú de Administrador...\n";
                break;
            default:
                break;
        }
    }while(opcion != 3);
}
