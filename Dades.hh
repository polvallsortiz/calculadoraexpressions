/** @file Operacions.hh
    @brief Especificació de la classe Operacions
*/

#ifndef _DADES_HH_
#define _DADES_HH_

#ifndef NO_DIAGRAM
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

    /** @brief Afegeix una dada al sistema.
     \pre <em>Dada i index són valors vàlids</em>
     \post S'ha afegit un valor indexat al sistema.
     */
     void afegir_dada_entera(string index, int dada);

    /** @brief Afegeix una dada al sistema.
    \pre <em>Dades i index són valors vàlids</em>
    \post S'ha afegit un valor indexat al sistema.
    */
     void afegir_dada_llista(string index, list<int>& dades);
    
//Consultora
     /** @brief Retorna si existeix dades amb aquesta etiqueta.
      \pre <em>Disposem d'una etiqueta amb la qual fer la cerca</em>
      \post S'ha fet la recerca en els maps
      */
    bool etiqueta_list_enters(string etiqueta);
    
    /** @brief Retorna el valor de la dada entera.
      \pre <em>L'etiqueta existeix en el sistema i indexa un enter</em>
      \post Retorna la dada
      */
    
    int valor_enter(string etiqueta);

    /** @brief Retorna el valor de la dada en format llista.
      \pre <em>L'etiqueta existeix en el sistema i indexa una llista d'enters</em>
      \post Retorna la dada
      */
    list valor_llista(string etiqueta);
    

private:
    map<string,int> valor_dades_definides;
    map<string,list<int>> valor_llistes_definides;
};
#endif
