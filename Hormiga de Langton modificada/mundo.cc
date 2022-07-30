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

#include "mundo.h"

Mundo::Mundo (int min_x, int max_x, int min_y, int max_y) {

  max_x_ = max_x;
  max_y_ = max_y;
  min_x_ = min_x;
  min_y_ = min_y;

  unsigned a = 0;
  matriz_.Resize(a, min_x, max_x, min_y, max_y);
}



Mundo::~Mundo() {}



void 
Mundo::set_Casilla (int fila, int columna) {

  if (matriz_(fila, columna) == 0)
    matriz_(fila, columna) = 1;
  else 
    matriz_(fila, columna) = 0;
}



unsigned
Mundo::get_Casilla (int fila, int columna) {

    return matriz_(fila, columna);
}



int
Mundo::operator() (int fila, int columna) {

    return matriz_(fila, columna);
}



void
Mundo::Resize (int min_x, int max_x, int min_y, int max_y) {

  unsigned a = 0;
  matriz_.Resize(a, min_x, max_x, min_y, max_y);

  max_x_ = max_x;
  max_y_ = max_y;
  min_x_ = min_x;
  min_y_ = min_y;
}



int
Mundo::get_MaxX () {

  return max_x_;
}



int
Mundo::get_MinX () {

  return min_x_;
}



int
Mundo::get_MaxY () {

  return max_y_;
}



int
Mundo::get_MinY () {

  return min_y_;
}