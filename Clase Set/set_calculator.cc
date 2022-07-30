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

SetCalculator::SetCalculator() {

  kDatoMaximo_ = 64;
  kCantidadDeLong_ = 1;
  conjunto_.resize(kCantidadDeLong_);
}



SetCalculator::SetCalculator(const int kTamano) {
  
  kDatoMaximo_ = kTamano;
  kCantidadDeLong_ = (kTamano / 64) + 1;
  conjunto_.resize(kCantidadDeLong_);
}



SetCalculator::SetCalculator(std::vector<int64_t>& conjunto, const int
               cantidad_de_long, const int dato_maximo) {
  
  kDatoMaximo_ = dato_maximo;
  conjunto_ = conjunto;
  kCantidadDeLong_ = cantidad_de_long;
}



SetCalculator::~SetCalculator() {

  conjunto_.clear();
}



/// Primero pasamos el numero que se encuentra en un string a un long, luego
/// miramos en que posicion del vector de longs tiene que ir y por último
/// nos colocamos en la posicion debida y lo insertamos.
void
SetCalculator::Construir(std::vector<std::string>& numeros) {
  
  for (unsigned recorrido = 0; recorrido < numeros.size(); recorrido ++) {

    int64_t numero = stoi(numeros[recorrido]);
    assert(numero <= kDatoMaximo_); 
    if (numero != 0){
      int posicion = numero / 64;
      assert (posicion <= kCantidadDeLong_);
      int nuevo_numero;
      int64_t auxiliar = 1;

      if (numero % 64 != 0){
        nuevo_numero = (numero - (64 * posicion)) - 1;
        auxiliar = auxiliar << nuevo_numero;
        conjunto_[posicion] = conjunto_[posicion] | auxiliar;
        }
      else {
        nuevo_numero = (numero - (64 * (posicion -1))) - 1;
        auxiliar = auxiliar << nuevo_numero;
        conjunto_[posicion-1] = conjunto_[posicion-1] | auxiliar;
      }
    }
  }
}



std::vector<int64_t>
SetCalculator::getConjunto() const {
  return conjunto_;
}



int
SetCalculator::getCantidadDeLong() const {
  return kCantidadDeLong_;
}



int
SetCalculator::getDatoMaximo() const {
  return kDatoMaximo_;
}




int64_t
SetCalculator::operator[](int64_t posicion) const {
  assert(posicion < kCantidadDeLong_);
  return conjunto_[posicion];
}



SetCalculator
SetCalculator::operator=(const SetCalculator& Objeto) {
  kCantidadDeLong_ = Objeto.getCantidadDeLong();
  conjunto_ = Objeto.getConjunto();
  kDatoMaximo_ = Objeto.getDatoMaximo();

  return 1;
}



/// Creamos un vector auxiliar donde guardar la unión de los conjuntos y luego
/// realizamos la unión.
SetCalculator
SetCalculator::operator+(const SetCalculator& Objeto) {
  
  std::vector<int64_t> auxiliar_vector;
  int auxiliar_long, auxiliar_dato;

  if (kCantidadDeLong_ >= Objeto.getCantidadDeLong()){
    auxiliar_long = kCantidadDeLong_;
    auxiliar_dato = kDatoMaximo_;
  }
  else {
    auxiliar_long = Objeto.getCantidadDeLong();
    auxiliar_dato = Objeto.getDatoMaximo();
  }

  auxiliar_vector.resize(auxiliar_long);

  for (int contador = 0; contador < kCantidadDeLong_; contador++){
    auxiliar_vector[contador] = auxiliar_vector[contador] | conjunto_[contador];
  }
  for (int contador = 0; contador < Objeto.getCantidadDeLong(); contador++){
    auxiliar_vector[contador] = auxiliar_vector[contador] | Objeto[contador];
  }

  return SetCalculator(auxiliar_vector, auxiliar_long, auxiliar_dato);
}



/// Creamos un vector auxiliar donde guardar la operacion, luego mediante el 
/// operador XOR obtenemos los numeros que no comparten los dos conjuntos, pero
/// como a nosotros solo nos interesan los que están en el primer conjunto y 
/// no en el segundo utilizamos el operador & sobre el conjunto auxliar y el 
/// primer conjunto, de esta forma solo nos quedan los numeros que están en el 
/// primer conjunto.
SetCalculator
SetCalculator::operator-(const SetCalculator& Objeto) {
  
  std::vector<int64_t> auxiliar_vector;
  int auxiliar_long, auxiliar_dato;
  bool menor;
  int auxiliar_contador = 0;

  if (kCantidadDeLong_ >= Objeto.getCantidadDeLong()) {
    auxiliar_long = kCantidadDeLong_;
    auxiliar_dato = kDatoMaximo_;
    menor = true;
  }
  else { 
    auxiliar_long = Objeto.getCantidadDeLong();
    auxiliar_dato = Objeto.getDatoMaximo();
    menor = false;
  }

  auxiliar_vector.resize(auxiliar_long);
  
  if (menor){
    for (int contador = 0; contador < Objeto.getCantidadDeLong() ; contador++){
      auxiliar_vector[contador] = conjunto_[contador] ^ Objeto[contador];
      auxiliar_contador ++;
    }
  }
  else {
    for (int contador = 0; contador < kCantidadDeLong_; contador++){
      auxiliar_vector[contador] = conjunto_[contador] ^ Objeto[contador];
    }
  }
  if (auxiliar_contador != 0)
    for (; auxiliar_contador < kCantidadDeLong_; auxiliar_contador ++){
      auxiliar_vector[auxiliar_contador] = conjunto_[auxiliar_contador] | 
                                           auxiliar_vector[auxiliar_contador];
    }

  for (int contador = 0; contador < kCantidadDeLong_; contador++){
    auxiliar_vector[contador] = auxiliar_vector[contador] & conjunto_[contador];
  }
  return SetCalculator(auxiliar_vector, auxiliar_long, auxiliar_dato);
}



/// Creamos un vector auxiliar donde guardar la operacion, en este caso solo
/// nos interesan los números que están en los dos conjuntos para ello usaremos
/// el operador AND, solo hay que recorrer hasta el tamaño del conjunto con 
/// menos contidad de longs.
SetCalculator
SetCalculator::operator*(const SetCalculator& Objeto) {

  std::vector<int64_t> auxiliar_vector;
  int auxiliar_long, auxiliar_dato;
  bool menor;

  if (kCantidadDeLong_ >= Objeto.getCantidadDeLong()) {
    auxiliar_long = Objeto.getCantidadDeLong();
    auxiliar_dato = Objeto.getDatoMaximo();
    menor = true;
  }
  else { 
    auxiliar_long = kCantidadDeLong_;
    auxiliar_dato = kDatoMaximo_;
    menor = false;
  }

  auxiliar_vector.resize(auxiliar_long);

  if (menor){
    for (int contador = 0; contador < Objeto.getCantidadDeLong() ; contador++){
      auxiliar_vector[contador] = conjunto_[contador] & Objeto[contador];
    }
  }
  else {
    for (int contador = 0; contador < kCantidadDeLong_; contador++){
      auxiliar_vector[contador] = conjunto_[contador] & Objeto[contador];
    }
  }
  return SetCalculator(auxiliar_vector, auxiliar_long, auxiliar_dato);
}



/// Creamos un vector auxiliar para la operacion, algo muy impotante a tener en
/// cuenta es que el conjunto tiene un numero máximo de numeros, entonces lo 
/// primero que haremos es añadir '1' por detrás hasta llegar al tamaño, de
/// esta forma luego con simplemente invertir los bits optenemos el conjunto
/// deseado.
SetCalculator
SetCalculator::operator!() {

  int64_t ultima_posicion = 1;
  int mover = 1;
  int eliminar = kCantidadDeLong_ * 64 - kDatoMaximo_;
  std::vector<int64_t> complemento;
  complemento.resize(kCantidadDeLong_);

  complemento = conjunto_;

  for (int contador = 1; contador <= 63; contador++){
    ultima_posicion = ultima_posicion << mover;
  }
  
  for (int recorrido = kCantidadDeLong_ - 1; recorrido >= 0; recorrido--){
    int64_t copia = ultima_posicion;
    for (int contador = 1; contador <= 64; contador++){
      if (eliminar != 0){
        complemento[recorrido] = complemento[recorrido] | copia;
        copia = copia >> mover;
        eliminar--;
      }
    }
  }

  for (int contador = 0; contador < kCantidadDeLong_; contador++){
    complemento[contador] = ~complemento[contador];
    }
  
  return SetCalculator(complemento, kCantidadDeLong_, kDatoMaximo_);
}



/// Para saber si dos conjuntos son iguales los recorreremos hasta el final
/// comparandolos, una cuestion muy imporatnte a tener en cuenta es que no dos
/// conjuntos tienen que tener la misma cantidad de longs para ser iguales por
/// ello hay que tener mirar si el conjunto que sea de mayor tamaño tiene algún
/// bit a '1' en el resto de longs. 
bool
SetCalculator::operator==(const SetCalculator& Objeto) {
  
  int tamano = 0;
  bool menor;

  if (kCantidadDeLong_ >= Objeto.getCantidadDeLong()) {
    menor = true;
  }
  else { 
    menor = false;
  }

  if (menor){
    for (int contador = 0; contador < Objeto.getCantidadDeLong() ; contador++){
      if (conjunto_[contador] != Objeto[contador])
        return false;
      tamano++;
    }
  }
  else {
    for (int contador = 0; contador < kCantidadDeLong_; contador++){
      if (conjunto_[contador] != Objeto[contador])
        return false;
      tamano++;
    }
  }

  if (menor) {
    for (; tamano < kCantidadDeLong_; tamano++){
      if (conjunto_[tamano] != 0)
        return false;
    }
  }
  else {
    for (; tamano < Objeto.getCantidadDeLong(); tamano++){
      if (Objeto[tamano] != 0)
        return false;
    }
  }
  return true;
}



/// Le pasamos un número mediante un string, lo convertimos a long y lo 
/// añadimos.
void
SetCalculator::Insertar(std::string elemento) {

  int numero = stoi(elemento);
  assert(numero <= kDatoMaximo_);
  int64_t auxiliar = 1;
  assert(numero != 0); 
  int posicion = numero / 64;
  assert (posicion <= kCantidadDeLong_);
  int mover = numero % 64;

  if (mover != 0){
    mover --;
    auxiliar = auxiliar << mover;
    conjunto_[posicion] = conjunto_[posicion] | auxiliar;
  }

  if (mover == 0){
    posicion = posicion -1;
    mover = 64;
    auxiliar = auxiliar << mover;
    conjunto_[posicion] = conjunto_[posicion] | auxiliar;
  }
}



/// Le pasamos un número mediante un string, lo convertimos a long y lo
/// eliminamos del conjunto usando un auxiliar y el operador XOR.
void
SetCalculator::Eliminar(std::string elemento) {

  if (PertenecerConjunto(elemento)) {
    int numero = stoi(elemento);
    int64_t auxiliar = 1;
    assert(numero != 0); 
    int posicion = numero / 64;
    assert (posicion <= kCantidadDeLong_);
    int mover = numero % 64;

    if (mover != 0){
      mover --;
      auxiliar = auxiliar << mover;
      conjunto_[posicion] = conjunto_[posicion] ^ auxiliar;
    }

    if (mover == 0){
      posicion = posicion -1;
      mover = 63;
      auxiliar = auxiliar << mover;
      conjunto_[posicion] = conjunto_[posicion] ^ auxiliar;
    }
  }
}



void
SetCalculator::VaciarConjunto() {

  for (int contador = 0; contador < kCantidadDeLong_; contador++){
    conjunto_[contador] = 0;
  }
}



bool
SetCalculator::ConjuntoVacio() {

  for (int contador = 0; contador < kCantidadDeLong_; contador++){
    if(conjunto_[contador] != 0)
      return false;
  }
  return true;
}



// Pasamos el numero mediante un string y luego lo convertimos a int, para
/// saber si el numero pertenece al conjunto lo meteremos en un long auxiliar
/// y a ese mismo auxiliar lo unimos con el long del vector principal 
/// correspondiente, luego miramos si el auxiliar y el vector son iguales, si 
/// son iguales es porque unimos un numero que ya estaba en el conjunto, sino
/// el numero no estaba en el conjunto.
bool
SetCalculator::PertenecerConjunto(std::string elemento){
  
  int numero = stoi(elemento);
  int64_t auxiliar = 1;
  assert(numero != 0); 
  int posicion = numero / 64;
  assert (posicion <= kCantidadDeLong_);
  int mover = numero % 64;

  if (mover != 0){
    mover --;
    auxiliar = auxiliar << mover;
    auxiliar = conjunto_[posicion] | auxiliar;
    if (conjunto_[posicion] == auxiliar)
      return true;
  }

  if (mover == 0){
    posicion = posicion -1;
    mover = 63;
    auxiliar = auxiliar << mover;
    auxiliar = conjunto_[posicion] | auxiliar;
    if (conjunto_[posicion] == auxiliar)
      return true;
  }
  return false;
}



/// Iremos recorriendo los distintos longs que componen el vector y mediante
/// un auxiliar y un contador iremos sacando los distintos numeros, para ello
/// moveremos los bits del long de izquierda a derecha hasta que el primer bit
/// sea un 1 entonces sacaremos ese numero y para saber que numero es realmente
/// usaremos esta fórmula: contador + (64 * recorrido).
void
SetCalculator::Escritura(std::ostream& os) const {

  int64_t numero_correcto ;
  int mover = 1;
  int vacio = 0;
  std::vector<int> mostrar;
  bool cero = false;

  for (unsigned recorrido = 0; recorrido < conjunto_.size(); recorrido++){
    if (conjunto_[recorrido] != 0)
      vacio ++;
  }
  if (vacio == 0)
    cero = true;
  
  if (vacio != 0){
    for (unsigned recorrido = 0; recorrido < conjunto_.size(); recorrido++){
      int64_t copia = conjunto_[recorrido];
      for (int contador = 1; contador <= 64; contador++){

        numero_correcto = copia & mover;

        if (numero_correcto == 1)
          mostrar.push_back(contador + (64 * recorrido));

        copia = copia >> mover;
      }
    }
  }
  if (cero)
    os << "{}" ;
  else{
    for (unsigned contador = 0; contador < mostrar.size(); contador++){
      if (contador == 0)
        os << "{" << mostrar[contador];
      if (contador == 0 && mostrar.size() - 1 == 0)
        os << "}" ;
      else if (contador == mostrar.size() - 1)
        os << ", " << mostrar[contador] << "}" ;
      if (contador != 0 && contador != mostrar.size() - 1)
        os << ", " << mostrar[contador];
    }  
  }
}



/// Leeremos del fichero hasta encontrar un '}' de esta manera sabremos que el
/// conjunto ha terminado.
void
SetCalculator::Lectura(std::istream& is) {

  std::string lectura, texto, cero;
  bool es_numero = false;
  is >> lectura;
  cero = '0';
  std::vector<std::string> numeros1;

  if (lectura[0] == '{' && lectura[1] == '}')
    numeros1.push_back(cero);

  else {
    while (lectura[lectura.size()-1] != '}'){
      for (unsigned recorrido = 0; recorrido < lectura.size(); recorrido ++) {
        if (isdigit(lectura[recorrido])){
          texto.push_back(lectura[recorrido]);
          es_numero = true;  
        }
      }
      if (es_numero)
        numeros1.push_back(texto);
      es_numero = false;
      texto.clear();
      is >> lectura;
    }
  }
  for (unsigned recorrido = 0; recorrido < lectura.size(); recorrido ++) {
    if (isdigit(lectura[recorrido])){
      texto.push_back(lectura[recorrido]);
      es_numero = true; 
    }
  }
   if (es_numero)
    numeros1.push_back(texto);
  texto.clear();
  Construir(numeros1);
}



std::ostream&
operator<<(std::ostream& os, const SetCalculator& A) {

  A.Escritura(os);
  return os;
}



std::istream&
operator>>(std::istream& is, SetCalculator& A) {
  
  A.Lectura(is);
  return is;
}