/** 
*  Grado:       Grado de ingeniería informática.
*  Asignatura:  Computablilidad y algoritmia.
*  Autor:       Alejandro Lugo Fumero.
*  Correo:      alu0101329185@ull.edu.es
*  Práctica nº: 5
*  Comentario:  Este programa coge de un fichero distintos conjuntos y realiza 
*               operaciones con ellos, luego los guarda en un fichero de salida
*  Compilar:    g++ -std=c++14 -g -Wall -o set_calculator set_calculator.cc set_calculator_main.cc
*               make
*  Ejecución:   ./set_calculator infile.txt outfile.txt
*/


#include "set_calculator.h"

#include <cstdint>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>

int main (int argc, char* argv[]) {
  
  std::string archivo_de_salida = "outfileAlejandroLugoFumero.txt";
  std::string archivo_de_entrada = "infileAlejandroLugoFumero.txt";
  std::string ayuda = "--help";

  /// Revisamos que todos los datos introducidos sean correctos
  if (argc == 2 && argv[1] == ayuda) {
 
    std::cout << "INTRODUZCA UNICAMENTE 2 PARAMETRO, EL PRIMERO DE ELLOS DEBE "
    "SER input.txt Y EL SEGUNDO DEBE SER output.txt" << std::endl;

    std::cout << "Este programa coge de un fichero distintos conjuntos y "
    "realiza operaciones con ellos, luego los guarda en un fichero de "
    "salida" << std::endl;

    std::cout << "./set_calculator infile.txt outfile.txt" << std::endl;
    
    return 0;
  }

  if (argc != 3 || argv[1] != archivo_de_entrada || 
      argv[2] != archivo_de_salida) {
    
    std::cout << "INTRODUZCA UNICAMENTE 2 PARAMETRO, EL PRIMERO DE ELLOS DEBE "
    "SER input.txt Y EL SEGUNDO DEBE SER output.txt" << std::endl;

    std::cout << "./set_calculator infile.txt outfile.txt" << std::endl;

    return 0;
  }
  std::vector<char> operador;
  std::string linea;
  std::ifstream lectura (archivo_de_entrada);
  std::ofstream escritura (archivo_de_salida);

  /// Leemos los operadores con los que vamos a trabajar.
  while (getline(lectura, linea)){
    for (unsigned recorrido = 0; recorrido < linea.size(); recorrido ++) {
      switch (linea[recorrido]) {
        case '+':
          operador.push_back(linea[recorrido]);
          break;
        case '-':
          operador.push_back(linea[recorrido]);
          break;
        case '*':
          operador.push_back(linea[recorrido]);
          break;
        case '!':
          operador.push_back(linea[recorrido]);
          break;
        case '=':
          if (linea[recorrido] == linea[recorrido + 1])
            operador.push_back('/');
          break;
      }
    }
  }
  
  lectura.close();
  std::ifstream lectura1 (archivo_de_entrada);
  
  /// Realizamos las distintas operaciones y las enviamos al fichero de salida.
  for (unsigned recorrido = 0; recorrido < operador.size(); recorrido ++) {
    SetCalculator A(100), B(100), C;
    switch (operador[recorrido]) {
        case '+':
          lectura1 >> A >> B;
          C = A + B;
          escritura << A << " " << operador[recorrido] << " " << B << " = " << C 
                    << std::endl;
          break;
        case '-':
          lectura1 >> A >> B;
          C = A - B;
          escritura << A << " " << operador[recorrido] << " " << B << " = " << C 
                    << std::endl;
          break;
        case '*':
          lectura1 >> A >> B;
          C = A * B;
          escritura << A << " " << operador[recorrido] << " " << B << " = " << C 
                    << std::endl;
          break;
        case '!':
          lectura1 >> A;
          C = !A;
          escritura << operador[recorrido] << " " << A << " = " << C << std::endl;
          break;
        case '/':
          lectura1 >> A >> B;
          if (A == B)
            escritura << A << " == " << B << std::endl;
          else 
            escritura << A << " != " << B << std::endl;
          break;
    }
  }
  lectura1.close();
  escritura.close();
}