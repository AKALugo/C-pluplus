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

#include "matriz_T_exception.h"
#include "mundo.h"

MundoFinito::MundoFinito (int min_x, int max_x, int min_y, int max_y ):
                          Mundo(min_x, max_x, min_y, max_y) {}



void
MundoFinito::Actualizar (Hormiga* hormiga) {

  int x = hormiga->get_X();
  int y = hormiga->get_Y();

  try {
    matriz_.Limites(x, y);
  }
  
  catch(const matriz_segmentation_fault& e) {

    if (x >= get_MaxX())
      hormiga->set_X(get_MinX());
    if (x < get_MinX())
      hormiga->set_X(get_MaxX() -1);

    if (y >= get_MaxY())
      hormiga->set_Y(get_MinY());
    if (y < get_MinY())
      hormiga->set_Y(get_MaxY() -1);
  }
}