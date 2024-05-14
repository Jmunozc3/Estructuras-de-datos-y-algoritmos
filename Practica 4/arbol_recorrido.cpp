//
// Created by cmestre on 17/04/2023.
//
//Práctica realizada por Francisco González Prieto y Juan Manuel Muñoz del Cerro

#include "arbol_recorrido.h"

void recorridoPreorden(std::unique_ptr<Nodo>& nodo) {
   /* std::cout << "SALIDA PARA seed=0" << std::endl;
    std::cout << "39->20->26->12->51->1->81->91->38->12->88->68->98->58->5->22->" << std::endl;
    */

    if (nodo != nullptr) {
    std::cout << nodo->key << std::endl;
    recorridoPreorden(nodo->izquierda);
    recorridoPreorden(nodo->derecha);
    }
}

void recorridoPostorden(std::unique_ptr<Nodo>& nodo) {
    /*std::cout << "SALIDA PARA seed=0" << std::endl;
    std::cout << "12->26->81->91->1->51->20->88->68->12->5->58->22->98->38->39->" << std::endl;*/

    if (nodo != nullptr) {
    recorridoPostorden(nodo->izquierda);
    recorridoPostorden(nodo->derecha);
    std::cout << nodo->key << std::endl;
    }
}

void recorridoEnOrden(std::unique_ptr<Nodo>& nodo) {
   /* std::cout << "SALIDA PARA seed=0" << std::endl;
    std::cout << "26->12->20->51->81->1->91->39->88->12->68->38->58->5->98->22->" << std::endl;*/

    if (nodo != nullptr) {
    recorridoPostorden(nodo->izquierda);
    std::cout << nodo->key << std::endl;
    recorridoPostorden(nodo->derecha);

    }
}
