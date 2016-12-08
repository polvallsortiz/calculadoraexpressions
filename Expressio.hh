/** @file Expressio.hh
    @brief Especificació de la classe Expressio
*/

#ifndef _EXPRESSIO_HH_
#define _EXPRESSIO_HH_

#include "Dades.hh"
#include "Resultat.hh"
#ifndef NO_DIAGRAM
#include <sstream>
#include <string>
#include <list>
using namespace std;
#endif

/** @class Expressio
    @brief Conté les operacions de lectura i de avaluació de l'expressió en un mòdul funcional.
*/

class Expressio
{
public:
    /** @brief Inicialització de la calculadora.
     \pre <em>Tenim una comanda vàlida al string comanda</em>
     \post Retorna el resultat pel canal estandard de sortida <em>cout</em>.
     */
    void inicialitzar(string comanda);

private:

    /** @brief Converteix un string en una expressió.
     \pre <em>Tenim una comanda al string s i una llista buida</em>
     \post L'expressió està formada a partir dels strings corresponents
     */
    void llegir_expressio(string s, list<string>& llista_expressio);

    /** @brief Retorna el resultat.
     \pre <em>Expressió a la llista</em>
     \post Retorna un booleà, un enter, una llista d'enters o un indefinit.
     */
    Resultat evaluar(list<string> llista_expressio);


};
#endif