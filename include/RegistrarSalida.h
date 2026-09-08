#ifndef REGISTRAR_SALIDA_H
#define REGISTRAR_SALIDA_H

#include <vector>
#include <string>

using namespace std;

struct Lugar;

bool registrarSalida(vector<Lugar>& estacionamiento,
                     const string& entrada);

#endif