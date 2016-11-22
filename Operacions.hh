/** @file Operacions.hh
    @brief Especificació de la classe Operacions
*/

#define _OPERACIONS_HH_

#include "Dades.hh"
#ifndef _OPERACIONS_HH_

#include <map>
#include <list>
#include <string>
#include <sstream>
#endif


/** @class Operacions
    @brief Representa el conjunt d'operacions de la calculadora. 
*/
class Operacions
{
public:
//Constructores

    /** @brief Creadora per defecte. 

      S'executa automaticament al declarar un conjunt d'operacions.
      \pre <em>cert</em>
      \post El resultat és un conjunt d'operacions predefinides
      */  
     Operacions();
     
//Modificadores
     
     /** @brief Completa l'expressio.
     \pre <em>expr es la primera línia de l'expressio</em>
     \post La expressio esta completa
     */
    string exp_completa(string expr);
    
    /** @brief Completa l'expressio.
     \pre <em>expr es la primera línia de l'expressio</em>
     \post La expressio esta completa
     */
    string fill_complet(string au);
    
   
    /** @brief Evalua una expressio.
     \pre <em>expr es una expressio ben parentitzada</em>
     \post La expressio ha estat executada
     */
    void evaluador_exp(string expr);
    
    /** @brief Operacio predefinida de suma.
     \pre <em>Els dos valors x i y son dos enters</em>
     \post Retorna el valor resultat de la suma de x+y
     */
     int suma(int x, int y);
     
     
    /** @brief Canviador de signe
     \pre <em>La dada x es un enter</em>
     \post Retorna l'enter canviat de signe
     */
     int intercanviador(int x);
     
     
    /** @brief Afegeix un valor al <em>top</em> de la llista.
     \pre <em>La dada x es un enter i y una llista</em>
     \post x es <em>top</em> de la llista y
     */
     void afegidor(int x, list<int> y); 
     
//Consultores 

    /** @brief Retorna el primer element de la llista.
     \pre <em>x no es buida</em>
     \post Retorna el primer element de la llista x
     */
     int top_llista(list<int> x);
    
    
    /** @brief Elimina el primer element d'x.
     \pre <em>x no es buda</em>
     \post Retorna la llista sense el primer element <em>(Similar al pop)</em>
     */
     list<int> pop_llista(list<int> x);
     
     
    /** @brief Evalua si x es igual a y.
     \pre <em> x i y son 2 enters</em>
     \post Retorna 1 si x == y, 0 si x != y
     */
     int igualtat (int x, int y);
     
     
    /** @brief Evalua si x es mes petit que y. 
     \pre <em>x i y son 2 enters</em>
     \post Retorna 1 si x < y, 0 si x >= y
     */
     int petit (int x, int y);
     
     
    /** @brief Nega el valor x.
     \pre <em>x es un boolea</em>
     \post Retorna x negat
     */
     int negacio (int x);


     /** @brief Evalua la condició lógica OR.
     \pre <em>x i y son booleans</em>
     \post La expressio ha estat executada
     */
    bool comparacio_OR(bool x, bool y);
    
    
     /** @brief Evalua la condició lógica AND.
     \pre <em>x i y son booleans</em>
     \post La expressio ha estat executada
     */
     bool comparacio_AND(bool x, bool y);
     
     
    /** @brief Evalua el if.               //CAL MILLORAR
     \pre <em>ref1,ref2,ref3 son etiquetes dels valors x,y,z</em>
     \post Retorna per referencia y si x == 1, z si x == 0. A paraula retorna
        "enter/boolea" si es tracta d'un enter o un boolea, o "llista"si es
        tracta de una llista.
     */
     void if_y_z(string ref1, string ref2, string ref3, int &enter, list<int> &llistaenter, string &paraula);
     
private:
    map<string,string> operacions_definides;
    list<string> operacions_predefinides;
};
#endif
