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

#include "universo.h"


Universo::Universo (std::vector<Hormiga *>& lista_hormigas, Mundo* mundo) {

  std::string lectura;

  int contador = 0;
  int posiX, posiY;
  while (contador != -1) {

    Imprimir (lista_hormigas, mundo);
    contador ++;

    while (contador == 3) {
      std::cout << "INTRODUZCA UN 1 PARA CONTINUAR CON EL PROGRAMA Y CUALQUI"
                  << "ER OTRA COSA PARA SALIR" << std::endl;
      std::cin >> lectura;

      if (lectura == "1") contador = 0;
      else contador = -1;
      lectura.clear();
    }

    if (contador != -1) {
      
      for (unsigned recorrido = 0; recorrido < lista_hormigas.size(); 
           recorrido++) {
        posiX = lista_hormigas[recorrido]->get_X();
        posiY = lista_hormigas[recorrido]->get_Y();

        lista_hormigas[recorrido]->DesplazarHormiga(mundo->get_Casilla(posiX, posiY));
        mundo->set_Casilla(posiX, posiY);

        mundo->Actualizar(lista_hormigas[recorrido]);;
      }
    }
  }
}



Universo::~Universo () {}



void
Universo::Imprimir (std::vector<Hormiga *>& lista_hormigas, Mundo* mundo) {

  bool aux = false;
  OrdenarHormigas (lista_hormigas);

    for (int desp_y = mundo->get_MinY(); desp_y < mundo->get_MaxY();
         desp_y++) {
      for (int desp_x = mundo->get_MinX(); desp_x < mundo->get_MaxX(); 
          desp_x++) {

      switch (mundo->get_Casilla(desp_x, desp_y)) {

        case 0: 
          for (unsigned recorrido = 0; recorrido < lista_hormigas.size(); 
               recorrido++)
            if (!aux && lista_hormigas[recorrido]->get_X() == 
                desp_x && lista_hormigas[recorrido]->get_Y() == 
                desp_y) {
              aux = true;
              std::cout << lista_hormigas[recorrido]->get_Cabeza();
            }
          if (!aux)
            std::cout << "=";
        break;

        case 1:
          for (unsigned recorrido = 0; recorrido < lista_hormigas.size(); 
               recorrido++)
            if (!aux && lista_hormigas[recorrido]->get_X () == 
                desp_x && lista_hormigas[recorrido]->get_Y() ==
                desp_y) {
              aux = true;
              std::cout << lista_hormigas[recorrido]->get_Cabeza();
            }
          if (!aux)
            std::cout << "X";
        break;
      }
      aux = false;
    }
    std::cout << std::endl;
  }
  std::cout << std::endl;
}



void
Universo::OrdenarHormigas (std::vector<Hormiga *>& lista_hormigas) {

  Hormiga* aux ;

  for (unsigned recorrido = 0; recorrido < lista_hormigas.size(); recorrido ++) {
    for (unsigned recorrido1 = recorrido + 1; recorrido1 < lista_hormigas.size(); recorrido1++) {
      if (lista_hormigas[recorrido]->get_Y() > lista_hormigas[recorrido1]->get_Y() || 
         (lista_hormigas[recorrido]->get_Y() == lista_hormigas[recorrido1]->get_Y() && 
         lista_hormigas[recorrido]->get_X() > lista_hormigas[recorrido1]->get_X())) {

        aux = lista_hormigas[recorrido];
        lista_hormigas[recorrido] = lista_hormigas[recorrido1];
        lista_hormigas[recorrido1] = aux;
      }
    }
  }
}