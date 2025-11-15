#ifndef BASEDEDATOS_H
#define BASEDEDATOS_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <filesystem>

class BaseDeDatos {
private:
    std::string rutaBD;

    // Almacena todas las líneas crudas de cada archivo .txt
    std::map<std::string, std::vector<std::string>> datos;

    // Carga el contenido de un archivo dentro del map "datos"
    void cargarArchivo(const std::string& nombreArchivo);

    // Crea un archivo si no existe
    void crearSiNoExiste(const std::string& nombreArchivo);

public:
    BaseDeDatos();

    // Conecta y carga TODOS los .txt en la carpeta Datos/
    void conectar(const std::string& ruta);

    // Limpia el map interno
    void desconectar();

    // Agrega una línea cruda al final del archivo
    void agregarLinea(const std::string& nombreArchivo, const std::string& linea);

    // Sobrescribe un archivo completo con nuevas líneas crudas
    void sobrescribirArchivo(const std::string& nombreArchivo, const std::vector<std::string>& lineas);

    // Obtiene todas las líneas crudas de un archivo
    std::vector<std::string> obtenerDatos(const std::string& nombreArchivo);
};

#endif
