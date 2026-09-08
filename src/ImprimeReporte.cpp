#include "ImprimeReporte.h"
#include <iostream>
#include <iomanip>

using namespace std;

void mostrarEstado(const vector<Lugar>& estacionamiento) {

    int compactos = 0;
    int sedanes = 0;
    int suvs = 0;
    int totalOcupados = 0;

    for (const Lugar& lugar : estacionamiento) {

        if (lugar.ocupado) {

            totalOcupados++;

            if (lugar.tipo == "COMPACTO") {
                compactos++;
            }
            else if (lugar.tipo == "SEDAN") {
                sedanes++;
            }
            else if (lugar.tipo == "SUV") {
                suvs++;
            }
        }
    }

    cout << "--- ESTADO DEL ESTACIONAMIENTO ---" << endl;

    cout << "COMPACTO: "
         << compactos << "/10 ocupados" << endl;

    cout << "SEDAN: "
         << sedanes << "/8 ocupados" << endl;

    cout << "SUV: "
         << suvs << "/5 ocupados" << endl;

    double porcentaje = (totalOcupados * 100.0) / 23;

    cout << fixed << setprecision(1);

    cout << "Ocupacion total: "
         << porcentaje << "% ("
         << totalOcupados << "/23)"
         << endl;

    cout << "-----------------------------------" << endl;
}