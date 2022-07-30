/** Univerdidad:Universidad de La Laguna.
*  Grado:       Grado de ingeniería informática.
*  Asignatura:  Algoritmos y Estructura de Datos Avanzados
*  Autor:       Alejandro Lugo Fumero.
*  Correo:      alu0101329185@ull.edu.es
*  Práctica nº: 4
*  Comentario:  Este programa simula a la Hormiga de Langton modificada.
*  Compilar:    make
*               ./hormiga
*/

#pragma once

#include "hormiga.h"
#include "mundo.h"

#include <iostream>
#include <string>
#include <vector>

class Universo {

  public:
    Universo (std::vector<Hormiga *>& lista_hormigas, Mundo* mundo);
    ~Universo ();

    void Imprimir (std::vector<Hormiga *>& lista_hormigas, Mundo* mundo);

  private:
    void OrdenarHormigas (std::vector<Hormiga *>& lista_hormigas);
};