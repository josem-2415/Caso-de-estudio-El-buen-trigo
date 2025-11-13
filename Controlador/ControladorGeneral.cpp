#include "ControladorGeneral.h"

ControladorGeneral::ControladorGeneral() {}

void ControladorGeneral::ejecutarMenuPanadero(int opcion) {
    switch (opcion) {
        case 1:
            panadero.registrarReceta();
            break;
        case 2:
            panadero.editarReceta();
            break;
        case 3:
            panadero.consultarStock();
            break;
        default:
            // Aquí no se imprime nada, solo se podría devolver un código de error
            break;
    }
}

void ControladorGeneral::ejecutarMenuEncargadoInventario(int opcion) {
    switch (opcion) {
        case 1:
            encargadoInventario.registrarIngrediente();
            break;
        case 2:
            encargadoInventario.consultarInventario();
            break;
        case 3:
            encargadoInventario.verificarNivelMinimo();
            break;
        default:
            break;
    }
}

void ControladorGeneral::ejecutarMenuAdministrador(int opcion) {
    switch (opcion) {
        case 1:
            administrador.generarReporte();
            break;
        case 2:
            administrador.exportarReporteTxt();
            break;
        default:
            break;
    }
}
