#ifndef INGREDIENTES_H
#define INGREDIENTES_H

#include <string>

class Ingredientes {

private:
    std::string nombre;
    std::string unidadMedida;

public:
    Ingredientes(std::string n, std::string um);
    Ingredientes();

    // Getters
    std::string getNombre() const;
    std::string getUnidadMedida() const;


    // operator para usar Ingredientes como clave en std::map
    bool operator<(const Ingredientes& other) const {
        return nombre < other.nombre;   // ordenar por nombre
    }
};

#endif // INGREDIENTES_H
