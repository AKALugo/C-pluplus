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

Hormiga::Hormiga (int x, int y) {

  // Posicionamos a la hormiga en el centro del tablero.
  posicion_y_ = y;
  posicion_x_ = x;
  direccion_actual_ = 0;
}



Hormiga::~Hormiga() {}



void
Hormiga::Resize (int x, int y, int direccion) {

  posicion_y_ = y;
  posicion_x_ = x;
  direccion_actual_ = direccion;
}



int 
Hormiga::get_Y () {

  return posicion_y_;
}



int 
Hormiga::get_X () {

  return posicion_x_;
}



int 
Hormiga::get_DireccionActual () {

  return direccion_actual_;
}



char 
Hormiga::get_Cabeza () {

  return direccion_hormiga_[direccion_actual_];
}



void
Hormiga::set_X (int x) {

  posicion_x_ = x;
}



void
Hormiga::set_Y (int y) {

  posicion_y_ = y;
}



const int 
Hormiga::get_X () const {

  return posicion_x_;
}



const int
Hormiga::get_Y () const {

  return posicion_y_;
}



const int
Hormiga::get_DireccionActual () const {

  return direccion_actual_;
}



void
Hormiga::DesplazarHormiga (unsigned valor) {

  MoverCabeza (valor);
  MoverHormiga ();
}