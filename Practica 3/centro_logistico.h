#ifndef CENTROLOGISTICO_H
#define CENTROLOGISTICO_H
#include<iostream>
#include "pila_paquetes.h"
#include "cola_paquetes.h"

class CentroLogistico {
 private:
    PilaPaquetes pila;
    ColaPaquetes cola;
 public:
    void agregaAuto(int numPaquetes);
    void agregaManual(int numPaquetes);
    void imprimeCola();
    void imprimePila();
    void borraDeLaCola(int numEliminar = 1);
};

#endif //CENTROLOGISTICO_H

