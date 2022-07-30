/**
 *  Grado:       Grado de ingeniería informática.
 *  Asignatura:  Computablilidad y algoritmia.
 *  Autor:       Alejandro Lugo Fumero.
 *  Correo:      alu0101329185@ull.edu.es
 *  Práctica nº: 3
 *  Comentario:  Diseñar e implementar en C++ un programa que, dado un número
 *               entero n > 0, encuentre los números capicúas resultantes de 
 *               multiplicar dos números de n dígitos cada uno. 
 *  Compilar:    g++ -std=c++14 -g -Wall -o palindrome_prod palindrome_prod.cc
 *               make
 *  Ejecución:   ./palindrome_prod 3 output.txt
 */


#include "palindrome_prod.h"

#include <iostream>

int main (int argc, char* argv[]) {

  if (argc != 3) {
    
    std::cout << "INTRODUZCA UNICAMENTE 2 PARAMETRO, EL PRIMERO DE ELLOS DEBE "
    "SER UN NUMERO > 0 Y EL SEGUNDO DEBE SER UN ARCHIVO DE SALIDA" << std::endl;

    return 0;
  }

  int kArgumento = atoi(argv[1]);
  if (kArgumento <= 0) {

    return 0;
  }

  Palindrome_prod A(kArgumento, argv[2]);
  std::ofstream fs (argv[2]);
  A.Calcular();
  fs << A;
  fs.close();
}