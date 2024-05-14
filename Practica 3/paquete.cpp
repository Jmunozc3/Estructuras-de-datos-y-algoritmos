#include "paquete.h"

Paquete::Paquete(std::string nombre , int peso )
{
    m_nombre = nombre;
    m_peso = peso;
}

std::string Paquete::getNombre() const{
    return m_nombre;
}

int Paquete::getPeso() const{
    return m_peso;
}
