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

    /** @brief Converteix un string en una expressió.
     \pre <em>Tenim una comanda a la entrada</em>
     \post L'expressió està formada a partir dels strings corresponents
     */
     void llegir_expressio(string s);
    
//Consultora
     /** @brief Evalua una expressio.
      \pre <em>Disposem d'una expressió</em>
      \post Retorna el resultat de l'expressió
      */
      void evaluar_expressio();
    
private:
    list<string> llista_expresio;
};
#endif