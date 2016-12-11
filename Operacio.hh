/** @file Operacio.hh
    @brief Especificació de la classe Operació
*/

#ifndef _OPERACIO_HH_
#define _OPERACIO_HH_

#ifndef NO_DIAGRAM
#include <string>
#include <iostream>
#include <list>
#endif
using namespace std;

/** @class Operacions
    @brief Emmagatzema els camps de les operacions definides pels usuaris.
*/
class Operacio
{
public:
//Constructores

    /** @brief Creadora per defecte.
      \pre <em>cert</em>
      \post Conjunt creat correctament al sistema.
      */  
     Operacio();
     
//Modificadores

    /** @brief Afegir operació.
     \pre <em>Numero de parametres i expressió correctes</em>
     \post S'ha afegit els camps de l'operació al sistema.
     */
     void afegir_op(string exp, list<string> param);
    
//Consultores

     /** @brief Retorna el numero de parametres de l'operació.
      \pre <em>cert</em>
      \post Retorna el numparametres.
      */
    int consultar_numero_parametres();
    
    /** @brief Retorna el valor de l'expressió.
      \pre <em>cert</em>
      \post Retorna expressió.
      */
    string consultar_expressio();

    /** @brief Retorna el valor de l'expressió.
      \pre <em>cert</em>
      \post Retorna expressió.
      */
    list<string> consultar_parametres();

private:
    list<string> parametres;
    string expressio;
};
#endif
