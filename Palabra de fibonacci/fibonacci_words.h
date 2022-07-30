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

#include <fstream>
#include <iostream>
#include <string>
#include <vector> 

class Fibonacci_words{
  public:
    Fibonacci_words(const std::string, const std::string);
    ~Fibonacci_words();
    
    void CalculateFibonacci();
    void AlgoritmoFibonacci(const std::string, bool&, int&);
    void EscribirEnFichero(std::ofstream&, const std::string, const bool, const int);

  private:
    std::vector<std::string> secuencia_fibonacci_;
    std::string nombre_archivo_de_salida_;
    std::string nombre_archivo_de_entrada_;
};



Fibonacci_words::Fibonacci_words (const std::string salida, const std::string entrada) {

  nombre_archivo_de_salida_ = salida;
  nombre_archivo_de_entrada_ = entrada;
}



Fibonacci_words::~Fibonacci_words () {

  secuencia_fibonacci_.clear();
}



void
Fibonacci_words::CalculateFibonacci() {

  std::ifstream archivo_de_entrada(nombre_archivo_de_entrada_);
  std::ofstream archivo_de_salida(nombre_archivo_de_salida_);

  bool fibonacci;
  int posicion = 0, contador = 0;
  std::string auxiliar_lectura;

  while (getline(archivo_de_entrada, auxiliar_lectura)) {

    if (contador <= 1){
      fibonacci = true;
      secuencia_fibonacci_.push_back(auxiliar_lectura);
      posicion ++;
      contador ++;
    }
    else {
      fibonacci = false;
      AlgoritmoFibonacci(auxiliar_lectura, fibonacci, posicion);
    }
    EscribirEnFichero(archivo_de_salida, auxiliar_lectura, fibonacci, posicion);
  }

  archivo_de_salida.close();
  archivo_de_entrada.close();
}



void
Fibonacci_words::EscribirEnFichero(std::ofstream& archivo_salida, const std::string dato, const bool verdadero ,const int posicion){

  if (verdadero)
    archivo_salida << dato << " es la palabra nº: " << posicion << std::endl;
  
  else 
    archivo_salida << dato << " no es una palabra de Fibonacci" << std::endl;
}



void
Fibonacci_words::AlgoritmoFibonacci(const std::string cadena, bool& es_fibonacci, int& posicion){
  
  std::string auxiliar = secuencia_fibonacci_[secuencia_fibonacci_.size()-1];
  while (auxiliar.size() < cadena.size()){

    secuencia_fibonacci_.push_back(secuencia_fibonacci_[secuencia_fibonacci_.size() -2] + secuencia_fibonacci_[secuencia_fibonacci_.size() -1]);
    auxiliar = secuencia_fibonacci_[secuencia_fibonacci_.size()-1];
  }
  for (unsigned recorrer = 0; recorrer < secuencia_fibonacci_.size(); recorrer++){

    if (cadena == secuencia_fibonacci_[recorrer]){
      
      es_fibonacci = true;
      posicion = recorrer +1;
    }
  }
}