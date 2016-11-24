/** @file Operacions.hh
    @brief Especificació de la classe Operacions
*/

#ifndef _OPERACIONS_HH_
#define _OPERACIONS_HH_

#include "Dades.hh"
#ifndef NO_DIAGRAM
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

    /** @brief Afegeix al sistema una operació.
     \pre <em>cert</em>
     \post S'ha afegit l'operació definida
     */
    void afegir_operacio(string index, string s);


//Consultores
    
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
    int comparacio_OR(int x, int y);
    
    
     /** @brief Evalua la condició lógica AND.
     \pre <em>x i y son booleans</em>
     \post La expressio ha estat executada
     */
     int comparacio_AND(int x, int y);
     
     
    /** @brief Evalua la funció IF.
     \pre <em>x es un boolea</em>
     \post S'ha evaluat l'element y o z(depenent de x), que pot ser llista, enter o boolea
     */
     void if_y_z_bool(int x);
private:
    map<string,string> operacions_definides;
    list<string> operacions_predefinides;
};
#endif
