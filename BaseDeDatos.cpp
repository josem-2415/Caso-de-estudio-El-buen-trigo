#include "BaseDeDatos.h"

BaseDeDatos::BaseDeDatos() {}

void BaseDeDatos::crearSiNoExiste(const std::string& nombreArchivo) {
    std::string ruta = rutaBD + "/" + nombreArchivo;

    if (!std::filesystem::exists(ruta)) {
        std::ofstream archivo(ruta);
        archivo.close();
    }
}

void BaseDeDatos::cargarArchivo(const std::string& nombreArchivo) {
    std::string ruta = rutaBD + "/" + nombreArchivo;
    std::ifstream archivo(ruta);

    datos[nombreArchivo].clear();

    if (!archivo.is_open()) {
        return;
    }

    std::string linea;
    while (std::getline(archivo, linea)) {
        datos[nombreArchivo].push_back(linea);
    }

    archivo.close();
}

void BaseDeDatos::conectar(const std::string& ruta) {
    rutaBD = ruta;
    datos.clear();

    for (auto& entry : std::filesystem::directory_iterator(rutaBD)) {
        if (entry.is_regular_file()) {
            std::string nombre = entry.path().filename().string();

            if (entry.path().extension() == ".txt") {
                crearSiNoExiste(nombre);
                cargarArchivo(nombre);
            }
        }
    }
}

void BaseDeDatos::desconectar() {
    datos.clear();
}

void BaseDeDatos::agregarLinea(const std::string& nombreArchivo, const std::string& linea) {
    std::string ruta = rutaBD + "/" + nombreArchivo;

    std::ofstream archivo(ruta, std::ios::app);

    if (archivo.is_open()) {
        archivo << linea << "\n";
        archivo.close();
    }

    datos[nombreArchivo].push_back(linea);
}

void BaseDeDatos::sobrescribirArchivo(const std::string& nombreArchivo, const std::vector<std::string>& lineas) {
    std::string ruta = rutaBD + "/" + nombreArchivo;

    std::ofstream archivo(ruta, std::ios::trunc);

    if (!archivo.is_open()) {
        return;
    }

    for (const auto& linea : lineas) {
        archivo << linea << "\n";
    }

    archivo.close();

    datos[nombreArchivo] = lineas;
}

std::vector<std::string> BaseDeDatos::obtenerDatos(const std::string& nombreArchivo) {
    return datos[nombreArchivo];
}