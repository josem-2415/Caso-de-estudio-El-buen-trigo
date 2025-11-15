#include "ControladorGeneral.h"

ControladorGeneral::ControladorGeneral() {}

void ControladorGeneral::inicializarBaseDeDatos(const std::string& ruta) {
    baseDatos.conectar(ruta);

    // Cargar todo
    inventarioIngredientes.cargarDesdeBD(baseDatos);
    cargarRecetas();
    inventarioPanes.cargarDesdeBD(baseDatos, recetas);

    std::cout << "[Sistema] Datos cargados desde TXT.\n";
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
                encargadoInventario.verificarNivelMinimo(inventarioIngredientes);
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

void ControladorGeneral::inicializarDependencias(){
        panadero.setBaseDatos(baseDatos);
        encargadoInventario.setBaseDatos(baseDatos);
        inventarioIngredientes.setBaseDatos(baseDatos);
        inventarioPanes.setBaseDatos(baseDatos);
    }

void ControladorGeneral::cargarRecetas() {
    const auto& lineas = baseDatos.obtenerDatos("recetas.txt");

    for (const std::string& linea : lineas) {

        // Ej: "PanBlanco;Harina:kg:500;Sal:g:10;Agua:ml:300;"

        size_t p = linea.find(';');
        if (p == std::string::npos) continue;

        std::string nombre = linea.substr(0, p);
        std::map<Ingredientes, double> ingMap;

        std::string resto = linea.substr(p + 1);
        size_t ini = 0;

        while (true) {
            size_t fin = resto.find(';', ini);
            if (fin == std::string::npos) break;

            std::string bloque = resto.substr(ini, fin - ini);
            ini = fin + 1;

            // formato: Harina:kg:500
            size_t p1 = bloque.find(':');
            size_t p2 = bloque.find(':', p1 + 1);

            if (p1 == std::string::npos || p2 == std::string::npos) continue;

            std::string ing = bloque.substr(0, p1);
            std::string unidad = bloque.substr(p1 + 1, p2 - (p1 + 1));
            double cantidad = std::stod(bloque.substr(p2 + 1));

            ingMap[ Ingredientes(ing, unidad) ] = cantidad;
        }

        recetas.push_back( Recetas(nombre, ingMap.size(), ingMap) );
    }
}
