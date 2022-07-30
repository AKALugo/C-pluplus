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

HormigaModificada::HormigaModificada (int x, int y) : Hormiga(x,y) {}



HormigaModificada::HormigaModificada (const HormigaModificada& aux) {

  direccion_actual_ = aux.get_DireccionActual();
  posicion_x_ = aux.get_X();
  posicion_y_ = aux.get_Y();
}



void
HormigaModificada::MoverCabeza (unsigned casilla) {

  switch (casilla) {

    case 1:
      direccion_actual_ ++;
      if (direccion_actual_ > 7)
        direccion_actual_ = 0;
      break;
  
    case 0:
      direccion_actual_ --;
      if (direccion_actual_ < 0)
        direccion_actual_ = 7;
      break;
  }
}



void
HormigaModificada::MoverHormiga () {

  switch (direccion_hormiga_[direccion_actual_]) {
    case '<':
      posicion_x_ --;
      break;
    case 'A':
      posicion_x_ --;
      posicion_y_ --;
      break;
    case '^':
      posicion_y_ --;
      break;
    case 'B':
      posicion_x_ ++;
      posicion_y_ --;
      break;
    case '>':
      posicion_x_ ++;
      break;
    case 'C':
      posicion_x_ ++;
      posicion_y_ ++;
      break;
    case 'v':
      posicion_y_ ++;
      break;
    case 'D':
      posicion_x_ --;
      posicion_y_ ++;
      break;
  }
}



HormigaModificada
HormigaModificada::operator= (const HormigaModificada& aux) {

  return HormigaModificada (aux);
}