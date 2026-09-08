#ifndef REGISTRAR_ENTRADA_H
#define REGISTRAR_ENTRADA_H

#include <vector>
#include <string>
#include "Lugar.h"

using namespace std;

bool registrarEntrada(vector<Lugar>& estacionamiento,
                      const string& tipo);

#endif