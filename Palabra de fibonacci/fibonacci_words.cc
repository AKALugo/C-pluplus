/**
 *  Grado:       Grado de ingeniería informática.
 *  Asignatura:  Computablilidad y algoritmia.
 *  Autor:       Alejandro Lugo Fumero.
 *  Correo:      alu0101329185@ull.edu.es
 *  Práctica nº: 4
 *  Comentario:  Diseñar e implementar en C++ un programa fibonacci_words.cc que 
 *               dada una secuencia de palabras indique si son palabras de Fibonacci
 *               o no. Para aquellas que lo sean, el programa ha de indicar su posición
 *               en la secuencia.
 *  Compilar:    g++ -std=c++14 -g -Wall -o fibonacci_words fibonacci_words.cc
 *               make
 *  Ejecución:   ./fibonacci_words input.txt output.txt
 */

#include "fibonacci_words.h"

#include <iostream>

int main (int argc, char* argv[]) {
  
  std::string archivo_de_salida = "output.txt";
  std::string archivo_de_entrada = "input.txt";
  std::string ayuda = "--help";

  if (argc == 2 && argv[1] == ayuda){
 
    std::cout << "INTRODUZCA UNICAMENTE 2 PARAMETRO, EL PRIMERO DE ELLOS DEBE "
    "SER input.txt Y EL SEGUNDO DEBE SER output.txt" << std::endl;

    std::cout << "Este programa dada una secuencia de palabras indica si son "
    "palabras de Fibonacci o no. Para aquellas secuencias que lea el programa"
    " indicará su posicion" << std::endl;
    
    return 0;
  }

  if (argc != 3 || argv[1] != archivo_de_entrada || argv[2] != archivo_de_salida) {
    
    std::cout << "INTRODUZCA UNICAMENTE 2 PARAMETRO, EL PRIMERO DE ELLOS DEBE "
    "SER input.txt Y EL SEGUNDO DEBE SER output.txt" << std::endl;

    return 0;
  }
  Fibonacci_words A(archivo_de_salida, archivo_de_entrada);
  A.CalculateFibonacci();
}