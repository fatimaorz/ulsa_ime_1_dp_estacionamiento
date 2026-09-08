#ifndef REGISTRAR_ENTRADA_H
#define REGISTRAR_ENTRADA_H

#include <vector>
#include <string>

using namespace std;

struct Lugar;

bool registrarEntrada(vector<Lugar>& estacionamiento,
                      const string& tipo);

#endif