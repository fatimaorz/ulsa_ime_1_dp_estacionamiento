#include "RegistrarEntrada.h"
#include "Lugar.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool registrarEntrada(vector<Lugar>& estacionamiento,
                      const string& tipo) {

    for (Lugar& lugar : estacionamiento) {

        if (lugar.tipo == tipo && !lugar.ocupado) {

            lugar.ocupado = true;

            string numero;

            if (lugar.numero < 10) {
                numero = "0" + to_string(lugar.numero);
            }
            else {
                numero = to_string(lugar.numero);
            }

            cout << "Vehiculo aceptado. Lugar asignado: "
                 << lugar.tipo
                 << numero
                 << endl;

            return true;
        }
    }

    cout << "Estacionamiento lleno para "
         << tipo
         << "." << endl;

    return false;
}