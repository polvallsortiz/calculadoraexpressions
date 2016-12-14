//
// Created by Pol Valls Ortiz on 10/12/2016.
//
/** @file Dades.hh
    @brief Especificació de la classe Dades
*/


#ifndef _DADES_HH
#define _DADES_HH

#include "Operacio.hh"
#include "Resultat.hh"
#ifndef NO_DIAGRAM
#include <sstream>
#include <string>
#include <iostream>
#include <map>
#endif
using namespace std;

/** @class Dades
    @brief Guarda tots els valors de variables definides per l'usuari.
*/
class Dades
{
public:
//Constructores

    /** @brief Creadora per defecte.
      \pre <em>cert</em>
      \post Conjunt creat correctament al sistema.
      */
    Dades();

//Modificadores

    /** @brief Afegir operació.
      \pre <em>Numero de parametres i expressió correctes</em>
      \post S'ha afegit l'operació al sistema de dades.
      */
    void afegir_op(string ref,string exp, list<string> param);

    /** @brief Afegir dada.
      \pre <em>Expressió correctament parentitzada</em>
      \post S'ha afegit la dada al sistema de dades.
      */
    void afegir_dada(string ref, Resultat dada);

//Consultores

    /** @brief Retorna si existeix l'operació amb la referència.
      \pre <em>cert</em>
      \post Retorna <em>true</em> si existeix, <em>false</em> altrament.
      */
    bool existeix_op(string ref);

    /** @brief Retorna si existeix la dada amb la referència.
      \pre <em>cert</em>
      \post Retorna <em>true</em> si existeix, <em>false</em> altrament.
      */
    bool existeix_dada(string ref);

    /** @brief Retorna l'operació amb referència ref amb parametres param2.
     \pre <em>ref és una referència vàlida i param té la quantitat de parametres estipulats a la operació</em>
     \post Retorna l'operació definida llesta per evaluar.
     */
    string definir_operacio(string ref, list<int> param2);

    /** @brief Retorna l'operació amb referència ref.
     \pre <em>ref és una referència vàlida</em>
     \post Retorna l'operació.
     */
    Operacio consultar_operacio(string ref);

    /** @brief Retorna la dada amb referència ref.
     \pre <em>ref és una referència vàlida</em>
     \post Retorna la dada.
     */
    Resultat consultar_dada(string ref);

    void finalitzar();


    /** @brief Retorna la dada amb referència ref.
     \pre <em>ref és una referència vàlida</em>
     \post Retorna la dada.
     */
    bool es_correcte(string ref, string s, list<string> param);

    bool es_predefinida(string s);


private:
    map<string,Operacio> map_op;
    map<string,Resultat> map_data;
    list<string> op_pref;

};
#endif //_DADES_HH
