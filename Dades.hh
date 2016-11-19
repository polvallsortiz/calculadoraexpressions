/** @file Operacions.hh
    @brief Especificació de la classe Operacions
*/

#ifndef _DADES_HH_
#define _DADES_HH_

#include "Operacions.hh"
#include <map>
#include <string>
#include <list>
#endif


/** @class Dades
    @brief Guarda tots els valors de variables definides 
*/
class Dades
{
public:
//Constructores

    /** @brief Creadora per defecte. 

      S'executa automaticament al declarar un conjunt d'operacions.
      \pre <em>cert</em>
      \post El resultat son dos maps(un de enters, i un altre de llistes) 
            sense cap valor, buit.
      */  
     Dades();
     
//Modificadores

    /** @brief Evalua una expressio.
     \pre <em>e es una expressio ben parentitzada</em>
     \post S'ha afegit un valor indexat al map.
     */
     void afegir_dada_entera(map<string,int>& valor_dades_definides);
     
     
     
     void afegir_dada_llista(map<string,int>& valor_dades_definides);
    
//Consultora
     /** @brief Evalua una expressio.
      \pre <em>Disposem d'una etiqueta amb la qual fer la cerca</em>
      \post S'ha fet la recerca en els vectors
      */

    bool etiqueta_vector_enters(string etiqueta);
    
    /** @brief Evalua una expressio.
      \pre <em>Disposem d'una etiqueta amb la qual fer la cerca</em>
      \post S'ha fet la recerca en els vectors
      */
    
    int valor_enter(string etiqueta);
    
    
    /** @brief Evalua una expressio.
      \pre <em>Disposem d'una etiqueta amb la qual fer la cerca</em>
      \post S'ha fet la recerca en els vectors
      */
      
    list valor_llista(string etiqueta);
    

private:
    map<string,int> valor_dades_definides;
    map<string,list> valor_llistes_definides;
};
#endif
