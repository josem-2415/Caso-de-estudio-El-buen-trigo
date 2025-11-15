#include <iostream>
#include "Controlador/Controlador.h"
#include "Modelo/Panadero.h"
#include "Modelo/EncargadoInventario.h"
#include "Modelo/Administrador.h"
using namespace std;

int main() {
    Controlador app;
    bool salir = false;

    while (!salir) {
        cout << "\n===== PANADERÍA EL BUEN TRIGO =====\n";
        cout << "Seleccione tipo de usuario:\n";
        cout << "1. Panadero\n";
        cout << "2. Encargado de Inventario\n";
        cout << "3. Administrador\n";
        cout << "4. Salir del sistema\n> ";

        int opcion;
        cin >> opcion;

        Usuario* user = nullptr;

        switch (opcion) {
            case 1: user = new Panadero("Carlos"); break;
            case 2: user = new EncargadoInventario("Marta"); break;
            case 3: user = new Administrador("Luis"); break;
            case 4: salir = true; break;
            default:
                cout << "Opción inválida.\n";
                continue;
        }

        if (user) {
            app.ejecutar(user);
            delete user;
            cout << "\nHas cerrado sesión. Volviendo al menú principal...\n";
        }
    }

    cout << "\nGracias por usar El Buen Trigo. ¡Hasta pronto!\n";
    return 0;
}
