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

#include "hormiga.h"
#include "mundo.h"

HormigaOriginal::HormigaOriginal (int x, int y) : Hormiga(x,y) {}



HormigaOriginal::HormigaOriginal (const HormigaOriginal& aux) {

  direccion_actual_ = aux.get_DireccionActual();
  posicion_x_ = aux.get_X();
  posicion_y_ = aux.get_Y();

}



void
HormigaOriginal::MoverCabeza (unsigned casilla) {

  switch (casilla) {

    case 1:
      direccion_actual_ ++;
      if (direccion_actual_ > 7)
        direccion_actual_ = 0;
      direccion_actual_ ++;
      if (direccion_actual_ > 7)
        direccion_actual_ = 0;
      break;
  
    case 0:
      direccion_actual_ --;
      if (direccion_actual_ < 0)
        direccion_actual_ = 7;
      direccion_actual_ --;
      if (direccion_actual_ < 0)
        direccion_actual_ = 7;
      break;
  }
}



void
HormigaOriginal::MoverHormiga () {

  switch (direccion_hormiga_[direccion_actual_]) {
    case '<':
      posicion_x_ --;
      break;
    case '^':
      posicion_y_ --;
      break;
    case '>':
      posicion_x_ ++;
      break;
    case 'v':
      posicion_y_ ++;
      break;
  }
}



HormigaOriginal
HormigaOriginal::operator= (const HormigaOriginal& aux) {

  return HormigaOriginal (aux);
}