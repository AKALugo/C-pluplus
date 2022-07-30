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

#include <iostream>
#include <vector>

class Hormiga {

  public:
    Hormiga (int x = 0, int y = 0);
    virtual ~Hormiga();

    virtual void DesplazarHormiga (unsigned);
    void Resize (int x = 0, int y = 0, int direccion = 0);

    // getters.
    int get_X ();
    int get_Y ();
    int get_DireccionActual ();
    char get_Cabeza ();

    void set_X (int);
    void set_Y (int);

    // getters constatantes
    const int get_X () const;
    const int get_Y () const;
    const int get_DireccionActual () const;


  protected:
    int direccion_actual_;
    int posicion_x_;
    int posicion_y_;

    std::vector<char> direccion_hormiga_ {'<', 'A','^','B','>', 'C','v' ,'D'};
    
    virtual void MoverCabeza (unsigned) = 0;
    virtual void MoverHormiga () = 0;
};



class HormigaOriginal : public Hormiga {

  public:
    HormigaOriginal (int x = 0, int y = 0);
    HormigaOriginal (const HormigaOriginal&);

    HormigaOriginal operator = (const HormigaOriginal& );

  private:
    virtual void MoverCabeza (unsigned);
    virtual void MoverHormiga ();
};



class HormigaModificada: public Hormiga {

  public:
    HormigaModificada (int x = 0, int y = 0);
    HormigaModificada (const HormigaModificada&);

    HormigaModificada operator = (const HormigaModificada& );

  private:
    virtual void MoverCabeza (unsigned);
    virtual void MoverHormiga ();
};