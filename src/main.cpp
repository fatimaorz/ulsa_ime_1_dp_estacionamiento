#include <iostream>
#include <string>
#include <vector>
#include <iomanip>


using namespace std;


struct Lugar {
    string tipo;
    int numero;
    bool ocupado;
};


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


    cout << "Ingrese el tamano del vehiculo para entrada"
         << endl;


    cout << "(COMPACTO, SEDAN, SUV)"
         << endl;


    cout << "o el numero de lugar para la salida (ej. SUV01)"
         << endl;


    cout << "Escriba SALIR para terminar"
         << endl;




    string entrada;




    while (true) {


        cout << "> ";
        cin >> entrada;




        // =========================
        // COMANDO SALIR
        // =========================


        if (entrada == "SALIR") {


            cout << "Simulacion finalizada." << endl;


            break;
        }




        // =========================
        // ENTRADA DE VEHICULO
        // =========================


        if (entrada == "SUV" ||
            entrada == "SEDAN" ||
            entrada == "COMPACTO") {


            bool encontrado = false;




            for (Lugar& lugar : estacionamiento) {


                if (lugar.tipo == entrada &&
                    !lugar.ocupado) {


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




                    mostrarEstado(estacionamiento);


                    encontrado = true;


                    break;
                }
            }




            // Si no hay lugar disponible
            if (!encontrado) {


                cout << "Estacionamiento lleno para "
                     << entrada
                     << "." << endl;
            }
        }




        // =========================
        // SALIDA DE VEHICULO
        // =========================


        else {


            string tipo;
            string numeroTexto;




            // Determinar el tipo de lugar


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


                continue;
            }




            // Verificar que sean exactamente dos digitos


            if (numeroTexto.length() != 2 ||
                !isdigit(numeroTexto[0]) ||
                !isdigit(numeroTexto[1])) {


                cout << "Salida invalida: el lugar "
                     << entrada
                     << " no existe."
                     << endl;


                continue;
            }




            int numeroLugar = stoi(numeroTexto);




            // Buscar el lugar


            int indice = -1;




            for (int i = 0; i < estacionamiento.size(); i++) {


                if (estacionamiento[i].tipo == tipo &&
                    estacionamiento[i].numero == numeroLugar) {


                    indice = i;


                    break;
                }
            }




            // El lugar no existe


            if (indice == -1) {


                cout << "Salida invalida: el lugar "
                     << entrada
                     << " no existe."
                     << endl;


                continue;
            }




            // El lugar existe pero está libre


            if (!estacionamiento[indice].ocupado) {


                cout << "Salida invalida: el lugar "
                     << entrada
                     << " ya esta libre."
                     << endl;


                continue;
            }




            // Liberar lugar


            estacionamiento[indice].ocupado = false;




            cout << "Vehiculo de lugar "
                 << entrada
                 << " ha salido."
                 << endl;




            mostrarEstado(estacionamiento);
        }
    }




    return 0;
}
