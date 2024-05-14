#include <iostream>
#include <string>
#include <limits>
#include "paquete.h"
#include "centro_logistico.h"

using namespace std;



//Páctica realizada por Juan Manuel Muñoz del Cerro 


int obtenerEntero() {
    int num;
    bool valid_input = false;

    do {
        cout << "Ingrese una cantidad de paquetes: ";
        if (cin >> num) {
            valid_input = true;
        } else {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Entrada no valida. Por favor, ingrese un entero." << endl;
        }
        cin.ignore();  // Ignorar el salto de linea que queda en el buffer
    } while (!valid_input);


    cout << "La cantidad de paquetes sera: " << num << endl;

    return num;
}



int main(int argc, char const *argv[]) {
    CentroLogistico centro;
    int numPaquetes = 7;
    if (argc > 1) {
        centro.agregaAuto(numPaquetes);
    } else {
        numPaquetes = obtenerEntero();
        centro.agregaManual(numPaquetes);
    }

    cout << endl << endl;

    centro.imprimePila();
    cout << endl;

    centro.borraDeLaCola(numPaquetes/2);
    cout << endl;

    centro.imprimeCola();
    cout << endl;

    return 0;


}
