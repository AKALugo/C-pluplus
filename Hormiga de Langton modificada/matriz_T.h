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

#include "matriz_T_exception.h"
#include "vector_T.h"

#include <cassert>
#include <iostream>
#include <exception>

template<class T>
class matriz_T {

  public:
    matriz_T (int minimo_x = 0, int maximo_x = 0, int minimo_y = 0,
              int maximo_y = 0);
    matriz_T (T&, int minimo_x = 0, int maximo_x = 0, int minimo_y = 0,
              int maximo_y = 0);
    matriz_T (T&, matriz_T<T>&, int minimo_x = 0, int maximo_x = 0,
              int minimo_y = 0, int maximo_y = 0);
    matriz_T (matriz_T<T>&);

    ~matriz_T ();

    void Limites (int, int);

    int get_Size () const;
    int get_MinX () const;
    int get_MinY () const;
    int get_MaxX () const;
    int get_MaxY () const;
    void set_Valor (const int, const int, T&);

    T& at (const int&, const int&);
    T& operator() (const int&, const int&);

    void Resize (int minimo_x = 0, int maximo_x = 0, int minimo_y = 0,
                 int maximo_y = 0);
    void Resize (T&, int minimo_x = 0, int maximo_x = 0, int minimo_y = 0,
                 int maximo_y = 0);

    // Método que construye una matriz apartir de otra, colocando los valores
    // en la misma posición de la matriz pasada como parámetro.
    void Resize (T&, matriz_T<T>&, int minimo_x = 0, int maximo_x = 0,
                 int minimo_y = 0, int maximo_y = 0);

    matriz_T<T> operator= (matriz_T<T>&);

  private:
    vector_T<T> vector_;
    int minimo_x_;
    int minimo_y_;
    int maximo_x_;
    int maximo_y_;
    int total_x_;
    int total_y_;
    int total_;

    void Construir (int minimo_x = 0, int maximo_x = 0, int minimo_y = 0,
                    int maximo_y = 0);
};



template<class T>
matriz_T<T>::matriz_T (int minimo_x, int maximo_x, int minimo_y, int maximo_y) {

  Construir (minimo_x, maximo_x, minimo_y, maximo_y);
}



template<class T>
matriz_T<T>::matriz_T (T& valor, int minimo_x, int maximo_x, int minimo_y,
                       int maximo_y) {

  Construir (minimo_x, maximo_x, minimo_y, maximo_y);

  for (int recorrido = vector_.get_Minimo(); recorrido < vector_.get_Maximo();
       recorrido++)
    vector_.set_Valor(recorrido, valor);
}



template<class T>
matriz_T<T>::matriz_T (T& valor, matriz_T<T>& matriz, int minimo_x, int maximo_x,
                       int minimo_y, int maximo_y) {

  Resize (valor, matriz, minimo_x, maximo_x, minimo_y, maximo_y);
}



template<class T>
matriz_T<T>::matriz_T (matriz_T<T>& aux) {

  Construir (aux.get_MinX(), aux.get_MaxX(), aux.get_MinY(), aux.get_MaxY());

  for (int i = aux.get_MinX(); i < aux.get_MaxX(); i++) {
    for (int j = aux.get_MinY(); j < aux.get_MaxY(); j ++) {
      set_Valor(i, j, aux(i,j));
    }
  }
}



template<class T>
matriz_T<T>::~matriz_T (){}



template<class T>
void
matriz_T<T>::Construir (int minimo_x, int maximo_x, int minimo_y, int maximo_y) {

  assert (minimo_x <= maximo_x && minimo_y <= maximo_y);

  minimo_x_ = minimo_x;
  minimo_y_ = minimo_y;
  maximo_x_ = maximo_x;
  maximo_y_ = maximo_y;

  total_x_ = maximo_x_ - minimo_x_;
  total_y_ = maximo_y_ - minimo_y_;
  total_ = total_x_ * total_y_;

  vector_.Resize(0, total_);
}



template<class T>
void
matriz_T<T>::Limites (int x, int y) {

  if (x < minimo_x_ || x >= maximo_x_ || y < minimo_y_ || y >= maximo_y_) 
    throw matriz_segmentation_fault();
}



template<class T>
inline int
matriz_T<T>::get_Size () const {

  return total_;
}



template<class T>
inline int
matriz_T<T>::get_MinX () const {

  return minimo_x_;
}



template<class T>
inline int
matriz_T<T>::get_MinY () const {

  return minimo_y_;
}



template<class T>
inline int
matriz_T<T>::get_MaxX () const {

  return maximo_x_;
}



template<class T>
inline int
matriz_T<T>::get_MaxY () const {

  return maximo_y_;
}



template<class T>
void
matriz_T<T>::set_Valor (const int x, const int y, T& valor) {

  assert (x >= minimo_x_ && x < maximo_x_ && y >= minimo_y_ && y < maximo_y_);

  vector_[(minimo_x_ * (-1) + x) + (total_x_ * (minimo_y_ * (-1) + y))] = valor;
}



template<class T>
T&
matriz_T<T>::at (const int& x, const int& y) {

    assert (x >= minimo_x_ && x < maximo_x_ && y >= minimo_y_ && y < maximo_y_);

    return vector_[(minimo_x_ * (-1) + x) + (total_x_ * (minimo_y_ * (-1) + y))];
}



template<class T>
T&
matriz_T<T>::operator() (const int& x, const int& y) {

  return at(x, y);
}



template<class T>
void
matriz_T<T>::Resize (int minimo_x, int maximo_x, int minimo_y, int maximo_y) {

  Construir (minimo_x, maximo_x, minimo_y, maximo_y);
}



template<class T>
void
matriz_T<T>::Resize (T& valor, int minimo_x, int maximo_x, int minimo_y,
                     int maximo_y) {

  Construir (minimo_x, maximo_x, minimo_y, maximo_y);

  for (int recorrido = vector_.get_Minimo(); recorrido < vector_.get_Maximo();
       recorrido++)
    vector_.set_Valor(recorrido, valor);
}



template<class T>
void
matriz_T<T>::Resize (T& valor, matriz_T<T>& matriz, int minimo_x, int maximo_x,
                     int minimo_y, int maximo_y) {

  assert (minimo_x <= matriz.get_MinX() && maximo_x >= matriz.get_MaxX());
  assert (minimo_y <= matriz.get_MinY() && maximo_y >= matriz.get_MaxY());

  Construir (minimo_x, maximo_x, minimo_y, maximo_y);

  int aux_x = minimo_x_;
  int aux_y = minimo_y_;

  while (aux_x < maximo_x_ && aux_y < maximo_y_) {
    
    if (aux_x >= matriz.get_MinX() && aux_x < matriz.get_MaxX() && aux_y >= 
        matriz.get_MinY() && aux_y < matriz.get_MaxY())
      set_Valor (aux_x, aux_y, matriz(aux_x, aux_y));
    else
      set_Valor (aux_x, aux_y, valor);

    aux_x ++;
    if (aux_x >= maximo_x_) {
      aux_x = minimo_x_;
      aux_y ++;
    }
  }
}



template<class T>
matriz_T<T>
matriz_T<T>::operator= (matriz_T<T>& aux) {

  return matriz_T (aux);
}