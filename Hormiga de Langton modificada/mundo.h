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
#include "matriz_T.h"

#include <exception>
#include <iostream>
#include <vector>

class Mundo {

  public:
    Mundo (int min_x = -10, int max_x = 10, int min_y = -10, int max_y = 10);
    virtual ~Mundo ();

    void set_Casilla(int fila, int columna);
    unsigned get_Casilla (int fila, int columna);
    int get_MaxX ();
    int get_MinX ();
    int get_MaxY ();
    int get_MinY ();

    virtual int operator()(int fila, int columna);

    void Resize (int min_x = -10, int max_x = 10, int min_y = -10, int max_y = 10);
    virtual void Actualizar (Hormiga* Hormiga) = 0;

  protected:
    int max_x_;
    int max_y_;
    int min_x_;
    int min_y_;
    matriz_T<unsigned> matriz_;
};



class MundoFinito : public Mundo {

  public:
    MundoFinito (int min_x = -10, int max_x = 10, int min_y = -10, int max_y = 10);
    void Actualizar (Hormiga* Hormiga);
};



class MundoInfinito : public Mundo {

  public:
    MundoInfinito (int min_x = -10, int max_x = 10, int min_y = -10, int max_y = 10);
    void Actualizar (Hormiga* hormiga);
};