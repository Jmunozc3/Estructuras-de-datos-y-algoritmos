
#ifndef COLAPAQUETES_H
#define COLAPAQUETES_H
#include<iostream>
#include "paquete.h"

const int COLA_MAX_SIZE = 100;

class ColaPaquetes {
public:
    // Constructor
    ColaPaquetes();

    // Agregar un paquete a la cola
    void enqueue(const Paquete& paquete);

    // Sacar un paquete de la cola
    void dequeue();

    // Obtener el paquete al frente de la cola
    Paquete front() const;

    // Obtener el tamaño de la cola
    int size() const;

    // Verificar si la cola está vacía
    bool empty() const;

private:
    Paquete data_[COLA_MAX_SIZE];
    int head_ = 0;
    int tail_ = 0;
};

#endif // COLAPAQUETES_H
