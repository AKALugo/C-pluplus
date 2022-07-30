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


#pragma once

#include <cassert>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <string>
#include <vector> 

/**
 * @class SetCalculator
 * @brief Lee de un fichero unos conjuntos y hace opeeraciones con ellos,
 * luego los almacena en un fichero de salida.
 */

class SetCalculator {

  public:
    SetCalculator();
    SetCalculator(const int);
    SetCalculator(std::vector<int64_t>&, const int, const int);
    ~SetCalculator();

    /// Guardamos los numeros en cada posición del bit a bit según corresponda
    void Construir(std::vector<std::string>&);

    int getCantidadDeLong() const;
    std::vector<int64_t> getConjunto() const;
    int getDatoMaximo() const;
    
    int64_t operator[] (const int64_t) const;
    bool operator== (const SetCalculator& Objeto);
    SetCalculator operator= (const SetCalculator&);
    SetCalculator operator+ (const SetCalculator& Objeto);
    SetCalculator operator- (const SetCalculator& Objeto);
    SetCalculator operator* (const SetCalculator& Objeto);
    SetCalculator operator! ();

    void Insertar(std::string);
    void Eliminar(std::string);
    void VaciarConjunto();
    bool ConjuntoVacio();
    bool PertenecerConjunto(std::string);
    
    void Escritura(std::ostream& = std::cout) const;
    void Lectura(std::istream& = std::cin); 
  
  private:
    int kCantidadDeLong_;
    std::vector<int64_t> conjunto_;
    int kDatoMaximo_;
};

std::ostream& operator<<(std::ostream&, const SetCalculator&);
std::istream& operator>>(std::istream&, SetCalculator&);