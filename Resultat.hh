//
// Created by Pol Valls Ortiz on 08/12/2016.
//
/** @file Resultat.hh
    @brief Especificació de la classe Resultat
*/


#ifndef _RESULTAT_HH
#define _RESULTAT_HH

#ifndef NO_DIAGRAM
#include <list>
#include <string>
#endif

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
    void afegir_enter_bool(int enter_bool);

    /** @brief Modifica el valor llista del parametre implícit.
         \pre <em>cert</em>
         \post Modificat.
         */
    void afegir_enter_llista(int enter_llista);

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




private:
    int enterbool;
    list<int> llistaenters;
    string descripcio;
};

#endif //_RESULTAT_HH
