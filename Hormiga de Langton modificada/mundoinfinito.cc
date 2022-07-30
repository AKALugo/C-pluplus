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

MundoInfinito::MundoInfinito (int min_x, int max_x, int min_y, int max_y): Mundo(min_x, max_x, min_y, max_y) {}



void
MundoInfinito::Actualizar (Hormiga* hormiga) {

  int sumar_x = 0;
  int sumar_y = 0;
  int restar_x = 0;
  int restar_y = 0;
  int x = hormiga->get_X();
  int y = hormiga->get_Y();

  try {
    matriz_.Limites(x, y);
  }
  
  catch(const matriz_segmentation_fault& e) {
    if (x >= matriz_.get_MaxX())
      sumar_x = sumar_x + 10;

    if (x < matriz_.get_MinX())
      restar_x = restar_x - 10;

    if (y >= matriz_.get_MaxY())
      sumar_y = sumar_y + 10;

    if (y < matriz_.get_MinY())
      restar_y = restar_y - 10;

    matriz_T<unsigned> aux (matriz_);
    unsigned a = 0;
    matriz_.Resize(a, aux, aux.get_MinX() + restar_x, aux.get_MaxX() + sumar_x,
                   aux.get_MinY() + restar_y, aux.get_MaxY() + sumar_y);

    max_x_ = matriz_.get_MaxX();
    max_y_ = matriz_.get_MaxY();
    min_x_ = matriz_.get_MinX();
    min_y_ = matriz_.get_MinY();
  }
}