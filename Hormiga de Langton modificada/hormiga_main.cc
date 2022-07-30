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
#include "universo.h"

#include <vector>



int main(void) {

  int min_x, max_x, min_y, max_y, cantidad_hormigas, tipo;

  do {
    std::cout << "Introduzca 1 para mundo FINITO o 2 para mundo INFINITO" 
              << std::endl;
    std::cin >> tipo;
  } while (tipo != 1 && tipo != 2);

  // Introducimos el numero de filas.
  do {
    std::cout << "Intrduzca MIN_X: " << std::endl;
    std::cin >> min_x;
    std::cout << "Intrduzca MAX_X: " << std::endl;
    std::cin >> max_x;
  } while (min_x > max_x);

  // Introducimos el numero de columnas.
  do {
    std::cout << "Intrduzca MIN_Y: " << std::endl;
    std::cin >> min_y;
    std::cout << "Intrduzca MAX_Y: " << std::endl;
    std::cin >> max_y;
  } while (min_x > max_x);

  do {
    std::cout << "Cuantas hormigas quiere: " << std::endl;
    std::cin >> cantidad_hormigas;
  } while (cantidad_hormigas <= 0);


  int aux1, aux2;
  int contador = 0;

  Hormiga *aux;
  Mundo *mundo;
  std::vector<Hormiga*> lista_hormigas;

  if (tipo == 1 )
    mundo = new MundoFinito (min_x, max_x, min_y, max_y);
  else
    mundo = new MundoInfinito (min_x, max_x, min_y, max_y);

  while (cantidad_hormigas != 0) {

    do {
      std::cout << "Introduzca 1 para hormiga ORIGINAL o 2 para HORMIGA MODIFICADA" 
                << std::endl;
      std::cin >> tipo;
    } while (tipo != 1 && tipo != 2);

    if (tipo == 1)
      aux = new HormigaOriginal;
    else
      aux = new HormigaModificada;

    contador ++;

    do {    
      std::cout << "Introduzaca X de la hormiga nº: " << contador << std::endl;
      std::cin >> aux1;
      std::cout << "Introduzaca Y de la hormiga nº: " << contador << std::endl;
      std::cin >> aux2;
    } while (aux1 < min_x || aux1 >= max_x || aux2 < min_y || aux2 >= max_y);

    aux -> Resize(aux1, aux2);
    lista_hormigas.push_back(aux);
    cantidad_hormigas --;
  }

  Universo universo(lista_hormigas, mundo);

  delete mundo;
  mundo =  NULL;

  for (unsigned i = 0; i < lista_hormigas.size(); i++) {
    delete lista_hormigas[i];
    lista_hormigas[i] = NULL;
  }

  return 0;
}