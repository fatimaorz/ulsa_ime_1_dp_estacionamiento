#include "RegistrarSalida.h"
#include "Lugar.h"

#include <iostream>
#include <vector>
#include <string>
#include <cctype>

using namespace std;

bool registrarSalida(vector<Lugar>& estacionamiento,
                     const string& entrada) {

    string tipo;
    string numeroTexto;

    if (entrada.length() >= 3 &&
        entrada.substr(0, 3) == "SUV") {

        tipo = "SUV";
        numeroTexto = entrada.substr(3);
    }
    else if (entrada.length() >= 5 &&
             entrada.substr(0, 5) == "SEDAN") {

        tipo = "SEDAN";
        numeroTexto = entrada.substr(5);
    }
    else if (entrada.length() >= 8 &&
             entrada.substr(0, 8) == "COMPACTO") {

        tipo = "COMPACTO";
        numeroTexto = entrada.substr(8);
    }
    else {

        cout << "Entrada invalida: tipo de vehiculo no reconocido."
             << endl;

        return false;
    }

    if (numeroTexto.length() != 2 ||
        !isdigit(numeroTexto[0]) ||
        !isdigit(numeroTexto[1])) {

        cout << "Salida invalida: el lugar "
             << entrada << " no existe." << endl;

        return false;
    }

    int numeroLugar = stoi(numeroTexto);

    for (Lugar& lugar : estacionamiento) {

        if (lugar.tipo == tipo &&
            lugar.numero == numeroLugar) {

            if (!lugar.ocupado) {

                cout << "Salida invalida: el lugar "
                     << entrada << " ya esta libre." << endl;

                return false;
            }

            lugar.ocupado = false;

            cout << "Vehiculo de lugar "
                 << entrada << " ha salido." << endl;

            return true;
        }
    }

    cout << "Salida invalida: el lugar "
         << entrada << " no existe." << endl;

    return false;
}