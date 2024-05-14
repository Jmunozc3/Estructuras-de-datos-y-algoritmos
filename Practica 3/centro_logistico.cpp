#include <iostream>
#include <string>
#include "centro_logistico.h"

using namespace std;

void CentroLogistico::agregaAuto(int numPaquetes) {
    for (int i = 0; i < numPaquetes; ++i)
    {
        // Agregar paquetes a la pila
        pila.push(Paquete("Paquete " + std::to_string(i), i*5));
        // Agregar paquetes a la cola
        cola.enqueue(Paquete("Paquete " + std::to_string(i), i*5));
    }
}

void CentroLogistico::agregaManual(int numPaquetes) {
    cout << "Agregando paquetes a la pila y a la cola..." << endl;
    for (int i = 0; i < numPaquetes; i++) {
       cout << "Ingrese el nombre del paquete #" << i + 1 << ": ";
       string nombre;
       getline(cin, nombre);
       cout << "Ingrese el peso del paquete #" << i + 1 << ": ";
       int peso;
       cin >> peso;
       cin.ignore();  // Ignorar el salto de linea que queda en el buffer
       Paquete paquete(nombre, peso);
       pila.push(paquete);
       cola.enqueue(paquete);
    }
}

void CentroLogistico::imprimeCola() {
    int cantPaquetes = cola.size();
    cout << "Hay " << to_string(cantPaquetes) << " paquetes en la cola: " << endl;
    while (!cola.empty()) {
        Paquete paquete = cola.front();
        cout << "- " << paquete.getNombre() << " (Peso: " << paquete.getPeso() << ")" << endl;
        cola.dequeue();
    }
}

void CentroLogistico::imprimePila() {
    int cantPaquetes = pila.size();
    cout << "Hay " << to_string(cantPaquetes) << " paquetes en la pila: " << endl;
    while (!pila.empty()) {
       Paquete paquete = pila.top();
       cout << "Nombre: " << paquete.getNombre() << ", Peso: " << paquete.getPeso() << endl;
       pila.pop();
    }
}

void CentroLogistico::borraDeLaCola(int numEliminar) {
    cout << "Eliminando " << numEliminar << " paquete";
    if (numEliminar > 1)
    {
       cout << "s";
    }
    cout << " de la cola..." << endl;
    for (int i = 0; i < numEliminar; i++) {
       cola.dequeue();
    }
}
