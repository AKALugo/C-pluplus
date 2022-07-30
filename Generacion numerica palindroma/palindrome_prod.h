/**
 *  Grado:       Grado de ingeniería informática.
 *  Asignatura:  Computablilidad y algoritmia.
 *  Autor:       Alejandro Lugo Fumero.
 *  Correo:      alu0101329185@ull.edu.es
 *  Práctica nº: 3
 *  Comentario:  Diseñar e implementar en C++ un programa que, dado un número
 *               entero n > 0, encuentre los números capicúas resultantes de 
 *               multiplicar dos números de n dígitos cada uno. 
 *  Compilar:    g++ -std=c++14 -g -Wall -o palindrome_prod palindrome_prod.cpp
 *               make
 *  Ejecución:   ./palindrome_prod 3 output.txt
 */


#include <math.h>

#include <fstream>
#include <iostream>
#include <vector> 


class Palindrome_prod{
  public:
    Palindrome_prod(const int, const char*);

    void Write(std::ostream& = std::cout) const;
    void Calcular();

  private:
    int kCantidaddeDigitos_;
    const char* archivo_de_salida_;

    std::vector<int> palindromos_;
    std::vector<std::pair<int,int>> multiplicadores_;
};


/**
 * @brief Construct a new Palindrome_prod::Palindrome_prod object
 * 
 * @param kNumMax 
 * @param archivo 
 */
Palindrome_prod::Palindrome_prod(const int kNumMax, const char* archivo) {

  kCantidaddeDigitos_ = kNumMax;
  archivo_de_salida_ = archivo;
}



void
Palindrome_prod::Calcular () {

  int digito_maximo , numero, numero_invertido, auxiliar, resto;
  int numero_de_palindromos = 0;

  digito_maximo = pow(10 , kCantidaddeDigitos_ ) -1 ;
  
  /// Bucles for que usaremos para recorrer todo nuestro rango.
  for (int digito_base1 = pow(10 , kCantidaddeDigitos_ - 1); 
       digito_base1 <= digito_maximo; digito_base1 ++) {
    for (int digito_base2 = digito_base1; digito_base2 <= digito_maximo;
         digito_base2 ++) {
         
      numero = digito_base1 * digito_base2;
      auxiliar = numero;
      numero_invertido = 0;

      /// Bucle while que comprueba si el numero es palindromo o no.
      while (auxiliar > 0) {
            
        resto = auxiliar % 10;
        auxiliar = auxiliar / 10;
        numero_invertido = numero_invertido * 10 + resto;
      }

      /// Si el numero es palindromo lo añadimos.    
      if (numero_invertido == numero) {
            palindromos_.push_back(numero);
            multiplicadores_.push_back(std::make_pair(digito_base1 , digito_base2));
            numero_de_palindromos ++;
      }
    }
  }
}



/// Método que utilizaremos para meter los números palindromos y sus 
/// multiplicandos en un os.
void
Palindrome_prod::Write(std::ostream& os) const {

   for (unsigned i = 0; i < palindromos_.size(); i++) 
      os << multiplicadores_[i].first << "  x  " << multiplicadores_[i].second << "  =  " <<
            palindromos_[i] << std::endl;
}



std::ostream&
operator<<(std::ostream& os, const Palindrome_prod& V) {
  
  V.Write(os);
  return os;
}