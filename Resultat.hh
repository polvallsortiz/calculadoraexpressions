/** @file Resultat.hh
    @brief Especificació de la classe Resultat
*/


#ifndef _RESULTAT_HH
#define _RESULTAT_HH

#ifndef NO_DIAGRAM
#include <list>
#include <string>
#include <iostream>
#endif
using namespace std;

/** @class Resultat
    @brief Classe per a l'expressió correcta del resultat
*/
class Resultat {
public:
//Constructores

    /** @brief Creadora per defecte.
      S'executa automaticament al declarar un resultat.
      \pre <em>cert</em>
      \post Crea un Resultat expressable.
      */
    Resultat();

//Modificadores

    /** @brief Modifica el valor enter/booleà del parametre implícit.
         \pre <em>cert</em>
         \post Modificat.
         */
    void afegir_enter_bool(int enterbool);

    /** @brief Modifica el valor enter/booleà del parametre implícit.
        \pre <em>cert</em>
        \post Modificat.
        */
    void afegir_llista(list<int> llista_ints);

    /** @brief Modifica el valor llista del parametre implícit.
         \pre <em>cert</em>
         \post Modificat.
         */
    void afegir_enter_llista(int enter_llista);

    /** @brief Modifica el valor llista del parametre implícit.
         \pre <em>cert</em>
         \post Modificat.
         */
    void afegir_enter_llista_davanter(int enter_llista);

    /** @brief Modifica la descripció del parametre implícit.
         \pre <em>Descripció Possible</em>
         \post Modificat.
         */
    void afegir_descripcio(string desc);

    /** @brief Modifica el valor llista del parametre implícit.
         \pre <em>cert</em>
         \post Eliminat.
         */
    void esborrar_enter_llista();

//Consultores

    /** @brief Retorna el valor primer de la llista.
         \pre <em>cert</em>
         \post Retorna el valor.
         */
    int consultar_top();

    /** @brief Retorna el valor de la llista.
         \pre <em>cert</em>
         \post Retorna el valor.
         */
    list<int> consultar_llista();

    /** @brief Retorna el valor del enter.
         \pre <em>cert</em>
         \post Retorna el valor.
         */
    int consultar_enter();

    /** @brief Retorna el valor de la descripcio.
         \pre <em>cert</em>
         \post Retorna el valor.
         */
    string consultar_descripcio();

    /** @brief Retorna si el valor és booleà.
         \pre <em>cert</em>
         \post Retorna <em>true</em> si el valor ho és, <em>false</em> altrament.
         */
    bool es_boolea();


private:
    int enterbool;
    list<int> llistaenters;
    string descripcio;
};

#endif //_RESULTAT_HH
