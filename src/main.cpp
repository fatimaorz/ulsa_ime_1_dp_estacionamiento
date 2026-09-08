#include <iostream>
#include <string>
#include <vector>

#include "Lugar.h"
#include "RegistrarEntrada.h"
#include "RegistrarSalida.h"
#include "ImprimeReporte.h"

using namespace std;

int main() {

    vector<Lugar> estacionamiento;

    // Crear 5 lugares SUV
    for (int i = 1; i <= 5; i++) {
        estacionamiento.push_back({"SUV", i, false});
    }

    // Crear 8 lugares SEDAN
    for (int i = 1; i <= 8; i++) {
        estacionamiento.push_back({"SEDAN", i, false});
    }

    // Crear 10 lugares COMPACTO
    for (int i = 1; i <= 10; i++) {
        estacionamiento.push_back({"COMPACTO", i, false});
    }

    cout << "Bienvenido al Simulador de Acceso a Estacionamiento"
         << endl;

    cout << "Ingrese el tamano del vehiculo para entrada" << endl;
    cout << "(COMPACTO, SEDAN, SUV)" << endl;
    cout << "o el numero de lugar para la salida (ej. SUV01)" << endl;
    cout << "Escriba SALIR para terminar" << endl;

    string entrada;

    while (true) {

        cout << "> ";
        cin >> entrada;

        // Comando para terminar
        if (entrada == "SALIR") {

            cout << "Simulacion finalizada." << endl;

            break;
        }

        // Entrada de vehiculo
        if (entrada == "SUV" ||
            entrada == "SEDAN" ||
            entrada == "COMPACTO") {

            registrarEntrada(estacionamiento, entrada);

            mostrarEstado(estacionamiento);
        }

        // Salida de vehiculo
        else {

            bool salidaRealizada =
                registrarSalida(estacionamiento, entrada);

            if (salidaRealizada) {
                mostrarEstado(estacionamiento);
            }
        }
    }

    return 0;
}