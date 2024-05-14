#ifndef PAQUETE_H
#define PAQUETE_H

#include <string>

class Paquete {
 private:
    std::string m_nombre;
    int m_peso;
 public:
    Paquete(std::string nombre = "", int peso = 0);
    std::string getNombre() const;
    int getPeso() const;
};

#endif //PAQUETE_H
