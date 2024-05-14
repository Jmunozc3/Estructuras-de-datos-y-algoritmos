#ifndef PILAPAQUETES_H
#define PILAPAQUETES_H
#include "paquete.h"

const int PILA_MAX_SIZE = 100;

class PilaPaquetes {
public:
    // Constructor
    PilaPaquetes();

    // Agregar un paquete a la pila
    void push(const Paquete& paquete);

    // Sacar un paquete de la pila
    void pop();

    // Obtener el paquete en la cima de la pila
    Paquete top() const;

    // Obtener el tamaño de la pila
    int size() const;

   // Verificar si la pila está vacía
    bool empty() const;

private:
    Paquete data_[PILA_MAX_SIZE];
    int top_ = 0;
};

#endif // PILAPAQUETES_H
