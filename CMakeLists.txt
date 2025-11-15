cmake_minimum_required(VERSION 4.0)
project(Taller5C__)

set(CMAKE_CXX_STANDARD 14)

include_directories(Controlador)
include_directories(Modelo)
include_directories(Vista)

add_executable(Taller5C__
        Controlador/Administrador.cpp
        Controlador/Administrador.h
        Controlador/BaseDeDatos.cpp
        Controlador/BaseDeDatos.h
        Controlador/ControladorGeneral.cpp
        Controlador/ControladorGeneral.h
        Controlador/EncargadoInventario.cpp
        Controlador/EncargadoInventario.h
        Controlador/Panadero.cpp
        Controlador/Panadero.h
        Modelo/Ingredientes.cpp
        Modelo/Ingredientes.h
        Modelo/Inventario.cpp
        Modelo/Inventario.h
        Modelo/Panes.cpp
        Modelo/Panes.h
        Modelo/Recetario.cpp
        Modelo/Recetario.h
        Modelo/Recetas.cpp
        Modelo/Recetas.h
        Modelo/Stock.cpp
        Modelo/Stock.h
        Vista/Vista.cpp
        Vista/Vista.h
        main.cpp)
