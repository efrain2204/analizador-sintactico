#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <vector>

using namespace std;
#include "gramatica.h"
#include "gramatica2.h"


int main()
{

        ifstream archivo_entrada("gramatica1.txt");;
        string linea;
        int contador = 0;
        gramatica primero;
        while(getline(archivo_entrada, linea)) {
                primero.insertar(linea);
                contador++;
        }
        primero.actualizar();
        primero.imprimir();
        primero.Primeros();
        primero.imprimirPrimeros();
        return EXIT_SUCCESS;
}
