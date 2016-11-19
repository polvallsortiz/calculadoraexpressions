#ifndef _EXPRESSIO_HH_
#define _EXPRESSIO_HH_

#include "Operacions.hh"
#include "Dades.hh"
#include <string>
#include <list>
#endif

/** @class Expressió
    @brief Conté les operacions de lectura i de avaluació de l'expressió. 
*/

class Expressio
{
public:
//Constructores
 /** @brief Creadora per defecte. 

      S'executa automaticament al començament del programa, al cridar a la funció.
      \pre <em>cert</em>
      \post El resultat és una llista buida de strings 
      */  
     expressio();
     
//Modificadores

    /** @brief Evalua una expressio.
     \pre <em>e tenim una expressió a la entrada</em>
     \post Afegim la expressió a una llista, separada per strings
     */
     
     void afegir_expressio_llista(string s);
    
     /** @brief Evalua una expressio.
     \pre <em>e tenim una llista de strings amb dades guardades</em>
     \post Tenim una nova llista, amb les subexpresions de la llista evaluada.
     */
     
     
     
////Consultora
     /** @brief Evalua una expressio.
      \pre <em>Disposem d'una llista ben desenvolupada</em>
      \post S'ha evaluat la expressió que teniem a la llista
      */
      string evaluar_expressio(list<string> llista_expresio);
private:
    list<string> llista_expresio;
};
#endif