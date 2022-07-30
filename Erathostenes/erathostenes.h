/* Univerdidad: Universidad de La Laguna.
   Grado:       Grado de ingeniería informática.
   Asignatura:  Computablilidad y algoritmia.
   Autor:       Alejandro Lugo Fumero.
   Correo:      alu0101329185@ull.edu.es
   Práctica nº: 2
   Comentario:  Realizar un programa en c++ que sea capaz de realizar 
                el metodo de La criba de Eratóstenes.
   Compilar:    g++ -std=c++14 -g -Wall -o erathostenes erathostenes.cc
   Ejecución:   ./erathostenes 1000
*/

#include <iostream>
#include <vector>

using namespace std;

class Erathostenes{
    public:
        Erathostenes(const int = 0);
        ~Erathostenes();

        void Sieves();
        void Remove(const int);

        void Write(ostream& = cout) const;

    private:
        // Cantidad de numeros que vamos a analizar.
        int kMayor;
       
        // Vector de ints donde guardaremos los numeros a analizar. 
        vector<int> VectordeValores;
        // Vector de bools donde guardaremos si son primos o no. 
        vector<bool> VectordeBools;
        // Vector de ints donde guardaremos finalmente los números primos.
        vector<int> VectorFinal;
};



// Inicializamos los atributos privados.
Erathostenes::Erathostenes(const int kNumMax){

    kMayor = kNumMax;
    VectordeBools.resize(kNumMax);
    VectordeValores.resize(kNumMax);

    for (int i = 0 ; i < kMayor ; i++){
        VectordeValores[i] = i + 1;
        VectordeBools[i] = true;
    }
}



// Limpiamos los vectores usados.
Erathostenes::~Erathostenes(){

    VectordeBools.clear();
    VectordeValores.clear();
}



// Si un numero esta marcado como primo llamamos a Remove.
void
Erathostenes::Sieves(){

    for (unsigned i = 1 ; i < VectordeValores.size() ; i++){
        if (VectordeBools[i] == true) {
            Remove(i);
            VectorFinal.push_back(VectordeValores[i]);
        }
    }
}



// Aplicamos el metodo de Erathostenes para marcar a los no primo.
void
Erathostenes::Remove(const int Posicion){

    int Contador = 1 ;
    int Multiplo = Posicion + VectordeValores[Posicion] * Contador;
    while (Multiplo < kMayor){
        VectordeBools[Multiplo]= false;
        Contador++ ;
        Multiplo = Posicion + VectordeValores[Posicion] * Contador;
    }
}



// Imprimimos por pantalla todos los numeros y si han sido marcados 
// true decimos que son primos y sino no primos.
void
Erathostenes::Write(ostream& os)const{

    cout << "La lista de números primos es la siguiente:\n";
    for ( unsigned i = 0; i < VectorFinal.size() ; i++){
        cout << VectorFinal[i] << endl;
    }
}



// Sobrecarga del operador "<<" que llama a Write.
ostream&
operator<<(ostream& os, const Erathostenes& V){

  V.Write(os);
  return os;
}