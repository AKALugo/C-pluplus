/* Univerdidad: Universidad de La Laguna.
   Grado:       Grado de ingeniería informática.
   Asignatura:  Computablilidad y algoritmia.
   Autor:       Alejandro Lugo Fumero.
   Correo:      alu0101329185@ull.edu.es
   Práctica nº: 2
   Comentario:  Realizar un programa en c++ que sea capaz de realizar 
                el metodo de La criba de Eratóstenes.
   Compilar:    g++ -std=c++14 -g -Wall -o erathostenes erathostenes.cc
   Ejecución:   ./erathostenes 1000
*/

#include "erathostenes.h"

#include <iostream>
#include <cassert>

using namespace std;

int main(int argc, char* argv[]){

    if (argc != 2){
        cout << "INTRODUZCA UNICAMENTE 1 PARAMETRO" << endl;

        return 0;
    }

    int kArgumento = atoi(argv[1]);

    Erathostenes A(kArgumento);
    A.Sieves();
    cout << A ;

    
    return 0;
}