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

#include <cassert>
#include <iostream>

template<class T>
class vector_T {

  public:
    vector_T (int numero_minimo = 0, int numero_maximo = 0);
    vector_T (vector_T&);
    ~vector_T ();

    T& at (const int &);
    T& operator[] (const int &);

    int get_Minimo () const;
    int get_Maximo () const;
    int get_Size () const;

    void set_Valor (const int, const T);
    void Resize (const int, const int);

    vector_T operator=( vector_T&);

  private:
    T *vector_;
    int minimo_;
    int maximo_;
    int total_;

    void Construir (int numero_minimo = 0, int numero_maximo = 0);
    void Destruir ();
};



template<class T>
vector_T<T>::vector_T(int numero_minimo, int numero_maximo) {

  Construir (numero_minimo, numero_maximo);
}

template<class T>
vector_T<T>::vector_T (vector_T& aux) {

  Construir (aux.get_Minimo(), aux.get_Maximo());

  for (int recorrido = aux.get_Minimo; recorrido < aux.get_Maximo(); recorrido++)
    vector_[recorrido] = aux[recorrido];
}



template<class T>
vector_T<T>::~vector_T () {

  Destruir ();
}



template<class T>
T& 
vector_T<T>::at (const int & indice) {
  
  assert (indice >= minimo_ && indice < maximo_);
  return vector_[(minimo_ * (-1)) + indice];
}



template<class T>
T& 
vector_T<T>::operator[] (const int & indice) {

  return at(indice);
}



template<class T>
void
vector_T<T>::Construir (int numero_minimo, int numero_maximo) {

  assert (numero_minimo <=  numero_maximo);

  minimo_ = numero_minimo;
  maximo_ = numero_maximo;
  
  if (numero_minimo < 0)
    numero_minimo = numero_minimo * (-1);
  if (numero_maximo < 0)
    numero_maximo = numero_maximo * (-1);

  total_ = numero_maximo + numero_minimo;

  vector_ = NULL;

  if (total_ != 0) {
    vector_ = new T[total_];
    assert (vector_ != NULL);
  }
}



template<class T>
void
vector_T<T>::Destruir () {

  if (vector_ != NULL) {
    delete[] vector_;
    vector_ = NULL;
  }
  total_ = 0;
}



template<class T>
inline int 
vector_T<T>::get_Minimo () const {

  return minimo_;
}



template<class T>
inline int 
vector_T<T>::get_Maximo () const {

  return maximo_;
}



template<class T>
inline int 
vector_T<T>::get_Size () const {

  return total_;
}



template<class T>
void 
vector_T<T>::set_Valor (const int indice, const T valor) {

  assert (indice >= minimo_ && indice < maximo_);
  vector_[(minimo_ * (-1)) + indice] = valor;
}



template<class T>
void 
vector_T<T>::Resize (const int numero_minimo, const int numero_maximo) {

  Destruir ();
  Construir (numero_minimo, numero_maximo);
}



template<class T>
vector_T<T>
vector_T<T>::operator= (vector_T& aux) {

  return vector_T (aux);
}
