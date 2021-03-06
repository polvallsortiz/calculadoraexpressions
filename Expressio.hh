/** @file Expressio.hh
    @brief Especificació de la classe Expressio
*/

#ifndef _EXPRESSIO_HH_
#define _EXPRESSIO_HH_

#include "Resultat.hh"
#include "Dades.hh"
#include "Operacio.hh"
#ifndef NO_DIAGRAM
#include <sstream>
#include <string>
#include <list>
#include <iostream>
#include <vector>
#endif
using namespace std;


/** @class Expressio
    @brief Conté les operacions de lectura i de avaluació de l'expressió en un mòdul funcional.
*/

class Expressio
{
public:

    /** @brief Creadora per defecte.
      \pre <em>cert</em>
      \post Conjunt creat correctament al sistema.
      */
    Expressio();


    /** @brief Inicialització de la calculadora.
     \pre <em>Tenim una comanda vàlida al string comanda</em>
     \post Retorna el resultat pel canal estandard de sortida <em>cout</em>.
     */
    void inicialitzar(string comanda, Dades& dat);

    /** @brief Converteix un string en una expressió.
     \pre <em>Tenim una comanda al string s i una llista buida</em>
     \post L'expressió està formada a partir dels strings corresponents
     */
    string llegir_expressio(string s, list<string>& llista_expressio);

    /** @brief Retorna el resultat.
     \pre <em>Expressió a la llista</em>
     \post Retorna un booleà, un enter, una llista d'enters o un indefinit.
     */
    Resultat evaluar(list<string> llista_expressio, Dades& dat);

private:

};
#endif //_EXPRESSIO_HH