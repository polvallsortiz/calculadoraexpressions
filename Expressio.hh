#ifndef _EXPRESSIO_HH_
#define _EXPRESSIO_HH_

#include "Operacions.hh"
#include "Dades.hh"
#ifndef NO_DIAGRAM
#include <sstream>
#include <sstream>
#include <string>
#include <list>
using namespace std;
#endif

/** @class Expressio
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
     Expressio();

private:
//Modificadores

    /** @brief Converteix un string en una expressió.
     \pre <em>Tenim una comanda a la entrada</em>
     \post L'expressió està formada a partir dels strings corresponents
     */
     list<string> llegir_expressio(string s);
    
//Consultora
     /** @brief Evalua una expressio.
      \pre <em>Disposem d'una expressió</em>
      \post Retorna el resultat de l'expressió
      */
      void evaluar();
    
    /** @brief Evalua una expressio.
    \pre <em>Disposem d'una expressió</em>
    \post Retorna el resultat de l'expressió
    */
    list<int> evaluar_expressio(string op, string left, string right);
};
#endif